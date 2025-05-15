#include "cerberus_controller/BufferManager.hpp"
#include <stdexcept>
#include <cstring>

BufferManager::BufferManager() {}

BufferManager::~BufferManager()
{
  cudaFree(inputBuffer_);
  cudaFree(outputBuffer_);
  delete[] hostInput_;
  delete[] hostOutput_;
}

void** BufferManager::bindings()
{
#if NV_TENSORRT_MAJOR < 9
  return bindings_;
#else
  return nullptr;
#endif
}

void BufferManager::bindBuffers(nvinfer1::ICudaEngine* engine, nvinfer1::IExecutionContext* context, const char* inputName, const char* outputName)
{
#if NV_TENSORRT_MAJOR >= 9
  // TensorRT 9+ : use name-based APIs
  std::cout << "Buffer" << std::endl;
  auto inputDataType = engine->getTensorDataType(inputName);
  auto inputDims = engine->getTensorShape(inputName);
  context->setInputShape(inputName, inputDims);
  std::cout << "Buffer2" << std::endl;

  #else
  // TensorRT 8: use index-based APIs
  int inputIndex = engine->getBindingIndex(inputName);
  if (inputIndex < 0) throw std::runtime_error("Invalid input name");
  
  auto inputDims = engine->getBindingDimensions(inputIndex);
  auto inputDataType = engine->getBindingDataType(inputIndex);
  #endif
  
  std::cout << "Buffer4" << std::endl;

  inputSize_ = 1;
  for (int i = 0; i < inputDims.nbDims; ++i)
  {
    std::cout << "Buffer Loop:" << i << std::endl;
    inputSize_ *= inputDims.d[i];
  }
  std::cout << "Setting input to size:" << inputSize_ << std::endl;

  switch (inputDataType)
  {
    case nvinfer1::DataType::kFLOAT: inputElementSize_ = sizeof(float); break;
    case nvinfer1::DataType::kINT32: inputElementSize_ = sizeof(int32_t); break;
    default: throw std::runtime_error("Unsupported input data type");
  }

  cudaMalloc(&inputBuffer_, inputSize_ * inputElementSize_);
  hostInput_ = new float[inputSize_];

#if NV_TENSORRT_MAJOR >= 9
  context->setTensorAddress(inputName, inputBuffer_);
#else
  bindings_[inputIndex] = inputBuffer_;
#endif

  // ------------------- OUTPUT ------------------ //
#if NV_TENSORRT_MAJOR >= 9
  auto outputDims = context->getTensorShape(outputName);
  auto outputDataType = engine->getTensorDataType(outputName);
#else
  int outputIndex = engine->getBindingIndex(outputName);
  if (outputIndex < 0) throw std::runtime_error("Invalid output name");

  auto outputDims = engine->getBindingDimensions(outputIndex);
  auto outputDataType = engine->getBindingDataType(outputIndex);
#endif

  outputSize_ = 1;
  for (int i = 0; i < outputDims.nbDims; ++i)
    outputSize_ *= outputDims.d[i];

  switch (outputDataType)
  {
    case nvinfer1::DataType::kFLOAT: outputElementSize_ = sizeof(float); break;
    case nvinfer1::DataType::kHALF: outputElementSize_ = sizeof(uint16_t); break;
    case nvinfer1::DataType::kINT8: outputElementSize_ = sizeof(int8_t); break;
    case nvinfer1::DataType::kINT32: outputElementSize_ = sizeof(int32_t); break;
    case nvinfer1::DataType::kBOOL: outputElementSize_ = sizeof(bool); break;
    default: throw std::runtime_error("Unsupported output data type");
  }

  cudaMalloc(&outputBuffer_, outputSize_ * outputElementSize_);
  hostOutput_ = new float[outputSize_];

#if NV_TENSORRT_MAJOR >= 9
  context->setTensorAddress(outputName, outputBuffer_);
#else
  bindings_[outputIndex] = outputBuffer_;
#endif
}

void BufferManager::updateInputBuffer(std::array<float, 48>& input)
{
  for (size_t i = 0; i < inputSize_; ++i)
    hostInput_[i] = input[i];

  cudaMemcpy(inputBuffer_, hostInput_, inputSize_ * inputElementSize_, cudaMemcpyHostToDevice);
}

void BufferManager::updateOutputBuffer()
{
  cudaMemcpy(hostOutput_, outputBuffer_, outputSize_ * outputElementSize_, cudaMemcpyDeviceToHost);
}

std::vector<double> BufferManager::getOutput() const
{
  return std::vector<double>(hostOutput_, hostOutput_ + outputSize_);
}
