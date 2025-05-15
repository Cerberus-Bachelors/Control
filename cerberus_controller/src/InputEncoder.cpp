#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include <builtin_interfaces/msg/time.hpp>
#include "cerberus_msgs/msg/cerberus_observation_tensor.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include <chrono>
#include "eigen3/Eigen/Dense"
#include "NvInfer.h"
#include "NvOnnxParser.h"
#include <cuda_runtime.h>

using std::placeholders::_1;
using namespace std::chrono_literals;

class InputEncoder : public rclcpp::Node
{
public:
    InputEncoder() : Node("InputEncoder")
    {
        std::cout << "Test " << 1 << std::endl;
        tensor_ = cerberus_msgs::msg::CerberusObservationTensor();

        grav_ = Eigen::Vector3d(0, 0, -1);

        imuSubscription_ = this->create_subscription<sensor_msgs::msg::Imu>(
            "cerberus/imu", 10, std::bind(&InputEncoder::imuCallback, this, _1));

        commandSubscription_ = this->create_subscription<geometry_msgs::msg::Vector3>(
            "cerberus/command", 10, std::bind(&InputEncoder::commandCallback, this, _1));

        actionSubscription_ = this->create_subscription<std_msgs::msg::Float64MultiArray>(
            "cerberus/actions", 10, std::bind(&InputEncoder::actionCallback, this, _1));

        jointSubscription_ = this->create_subscription<sensor_msgs::msg::JointState>(
            "joint_states", 10, std::bind(&InputEncoder::jointCallback, this, _1));

        tensorPublisher_ = this->create_publisher<cerberus_msgs::msg::CerberusObservationTensor>("cerberus/tensor_input", 10);
        tensorTimer_ = this->create_wall_timer(0.005s, std::bind(&InputEncoder::tensorPublish, this));

        /*sensorSubscription_ = this->create_subscription<std_msgs::msg::String>(
            "sensors_data", 10, std::bind(&InputEncoder::imuCallback, this, _1));*/
        std::cout << "Test " << 2 << std::endl;
    }

private:
    void imuCallback(const sensor_msgs::msg::Imu::SharedPtr msg)
    {
        std::cout << "Test " << 3 << std::endl;

        tensor_.lin_acc = msg->linear_acceleration;
        tensor_.ang_vel = msg->angular_velocity;
        std::cout << "Test " << 4 << std::endl;

        Eigen::Quaterniond orientation(msg->orientation.w, msg->orientation.x, msg->orientation.y, msg->orientation.z);
        Eigen::Vector3d proj_g = orientation * grav_;
        std::cout << "Test " << 5 << std::endl;

        tensor_.proj_grav.x = proj_g(0);
        tensor_.proj_grav.y = proj_g(1);
        tensor_.proj_grav.z = proj_g(2);

    }

    void commandCallback(const geometry_msgs::msg::Vector3::SharedPtr msg)
    {
        std::cout << "Test " << 6 << std::endl;
        tensor_.command = *msg;
    }

    void actionCallback(const std_msgs::msg::Float64MultiArray::SharedPtr msg)
    {
        std::cout << "Test " << 7 << std::endl;
        for (size_t i = 0; i < tensor_.actions.size() && i < msg->data.size(); ++i)
        {
            tensor_.actions[i] = static_cast<float>(msg->data[i]);
        }
        std::cout << "Test " << 8 << std::endl;      
    }

    void jointCallback(const sensor_msgs::msg::JointState::SharedPtr msg)
    {
        std::cout << "Test " << 9 << std::endl;

        std::unordered_map<std::string, float> joint_pos;
        std::unordered_map<std::string, float> joint_vel;

        std::cout << "Test " << 10 << std::endl;

        tensor_.joint_pos.resize(12);
        tensor_.joint_vel.resize(12);
        
        for (size_t i = 0; i < msg->name.size(); i++)
        {
            joint_pos[msg->name[i]] = msg->position[i];
            joint_vel[msg->name[i]] = msg->velocity[i];
        }
        std::cout << "Test " << 11 << std::endl;

        for (size_t i = 0; i < 12; ++i)
        {
            const std::string &name = names_ordered[i];

            if (joint_pos.find(name) != joint_pos.end() && joint_vel.find(name) != joint_vel.end())
            {
                tensor_.joint_pos[i] = joint_pos[name];
                tensor_.joint_vel[i] = joint_vel[name];
            }
            else
            {
                RCLCPP_WARN(this->get_logger(), "JointState failing %s", name.c_str());
                tensor_.joint_pos[i] = 0.0;
                tensor_.joint_vel[i] = 0.0;
            }
        }
        std::cout << "Test " << 12 << std::endl;

    }

    void tensorPublish()
    {
        std::cout << "Test " << 13 << std::endl;

        tensorPublisher_->publish(tensor_);
    }

    std::string names_ordered[12] = {
        "FL_hip_joint",
        "FR_hip_joint",
        "RL_hip_joint",
        "RR_hip_joint",
        "FL_thigh_joint",
        "FR_thigh_joint",
        "RL_thigh_joint",
        "RR_thigh_joint",
        "FL_calf_joint",
        "FR_calf_joint",
        "RL_calf_joint",
        "RR_calf_joint"};

    cerberus_msgs::msg::CerberusObservationTensor tensor_;
    Eigen::Vector3d grav_;

    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imuSubscription_;
    rclcpp::Subscription<geometry_msgs::msg::Vector3>::SharedPtr commandSubscription_;
    rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr actionSubscription_;
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr jointSubscription_;

    rclcpp::Publisher<cerberus_msgs::msg::CerberusObservationTensor>::SharedPtr tensorPublisher_;
    rclcpp::TimerBase::SharedPtr tensorTimer_;

    rclcpp::Time prevTime_;
    rclcpp::Time currentTime_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<InputEncoder>());
    rclcpp::shutdown();
    return 0;
}
