#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
#include "cerberus_msgs/msg/cerberus_observation_tensor.hpp"
#include "NvInfer.h"
#include "NvOnnxParser.h"
#include <cuda_runtime.h>
#include <chrono>
#include "cerberus_controller/BufferManager.hpp"

using std::placeholders::_1;
using namespace std::chrono_literals;


class Logger : public nvinfer1::ILogger
{
  void log(Severity severity, const char *msg) noexcept override
  {
    // suppress info-level messages
    if (severity <= Severity::kWARNING)
      std::cout << msg << std::endl;
  }
} logger;

class Inference : public rclcpp::Node
{
public:
  Inference() : Node("Inference")
  {
    if (init("/home/v/Dev/Github/Cerberus/src/Isaac/models/256-32/exported/policy.onnx"))
    {
      subscription_ = this->create_subscription<cerberus_msgs::msg::CerberusObservationTensor>("cerberus/tensor_input", 10, std::bind(&Inference::updateInput, this, _1));
      publisher_ = this->create_publisher<std_msgs::msg::Float64MultiArray>("cerberus/actions", 10);
      controlPublish_ = this->create_publisher<std_msgs::msg::Float64MultiArray>("group_position_controller/commands", 10);
      //controlTimer_ = this->create_wall_timer(0.02s, std::bind(&Inference::ControlUpdate, this));
      actions_ = std_msgs::msg::Float64MultiArray();
    }
  }

  bool init(const char *modelFile);
  bool infer();
  
  private:
  void controlUpdate(){
    
    publisher_->publish(actions_);
    for (auto &action : actions_.data)
    {
      action *= 0.25;
    }
    if(actions_.data.size()==12)
    {
      controlPublish_->publish(actions_);
    }
  }
  void updateInput(const cerberus_msgs::msg::CerberusObservationTensor::SharedPtr msg)
  {
    size_t idx = 0;
    auto append_vec3 = [&](const geometry_msgs::msg::Vector3 &v)
    {
      inputTensor_[idx++] = static_cast<float>(v.x);
      inputTensor_[idx++] = static_cast<float>(v.y);
      inputTensor_[idx++] = static_cast<float>(v.z);
    };

    append_vec3(msg->lin_acc);
    append_vec3(msg->ang_vel);
    append_vec3(msg->proj_grav);
    append_vec3(msg->command);

    for (const auto &jp : msg->joint_pos)
    {
      inputTensor_[idx++] = static_cast<float>(jp);
    }

    for (const auto &jv : msg->joint_vel)
    {
      inputTensor_[idx++] = static_cast<float>(jv);
    }

    for (const auto &act : msg->actions)
    {
      inputTensor_[idx++] = static_cast<float>(act);
    }
    bufferManager_.updateInputBuffer(inputTensor_);

    infer();

    actions_.data = bufferManager_.getOutput();
    
    controlUpdate();
  }

  std::array<float, 48> inputTensor_;
  std_msgs::msg::Float64MultiArray actions_;

  rclcpp::Subscription<cerberus_msgs::msg::CerberusObservationTensor>::SharedPtr subscription_;
  rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr publisher_;
  rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr controlPublish_;

  rclcpp::TimerBase::SharedPtr controlTimer_;

  BufferManager bufferManager_;

  nvinfer1::IRuntime *runtime_;
  nvinfer1::ICudaEngine *engine_;
  nvinfer1::IExecutionContext *context_;
  cudaStream_t stream_;
  
};

bool Inference::init(const char *modelFile)
{
  auto builder = nvinfer1::createInferBuilder(logger);
  auto network = builder->createNetworkV2(0);
  auto parser = nvonnxparser::createParser(*network, logger);


  std::cout << "Test1" << std::endl;
  parser->parseFromFile(modelFile, static_cast<int32_t>(nvinfer1::ILogger::Severity::kWARNING));
  for (int32_t i = 0; i < parser->getNbErrors(); ++i)
  {
    RCLCPP_ERROR(this->get_logger(), parser->getError(i)->desc());
  }
  std::cout << "Test2" << std::endl;
  nvinfer1::IBuilderConfig *config = builder->createBuilderConfig();
  std::cout << "Test3" << std::endl;
  
  // Resource limit
  config->setMemoryPoolLimit(nvinfer1::MemoryPoolType::kWORKSPACE, 1U << 20);
  std::cout << "Test4" << std::endl;

  #if NV_TENSORRT_MAJOR >= 8 && NV_TENSORRT_MINOR >= 2
  config->setMemoryPoolLimit(nvinfer1::MemoryPoolType::kTACTIC_SHARED_MEMORY, 2 << 20);
  #endif
  std::cout << "Test5" << std::endl;

  nvinfer1::IHostMemory *serializedModel = builder->buildSerializedNetwork(*network, *config);
  std::cout << "Test6" << std::endl;

  // // Print input names
  // for (int i = 0; i < network->getNbInputs(); ++i)
  // {
  //   auto input = network->getInput(i);
  //   std::cout << "Input " << i << " name: " << input->getName() << std::endl;
  // }

  // Print output names
  for (int i = 0; i < network->getNbOutputs(); ++i)
  {
    auto output = network->getOutput(i);
    std::cout << "Output " << i << " name: " << output->getName() << std::endl;
  }

  delete parser;
  delete network;
  delete config;
  delete builder;

  runtime_ = nvinfer1::createInferRuntime(logger);
  engine_ = runtime_->deserializeCudaEngine(serializedModel->data(), serializedModel->size());

  context_ = engine_->createExecutionContext();

  const char *inputName = "obs";
  const char *outputName = "actions";

  bufferManager_.bindBuffers(engine_, context_, inputName, outputName);

  cudaStreamCreate(&stream_);
  return true;
}

bool Inference::infer()
{
#if NV_TENSORRT_MAJOR >= 9
  context_->enqueueV3(stream_);
#else
  context_->enqueueV2(bufferManager_.bindings(), stream_, nullptr);
#endif
  cudaStreamSynchronize(stream_);
  bufferManager_.updateOutputBuffer();
  return true;
}
int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Inference>());
  rclcpp::shutdown();
  return 0;
}
