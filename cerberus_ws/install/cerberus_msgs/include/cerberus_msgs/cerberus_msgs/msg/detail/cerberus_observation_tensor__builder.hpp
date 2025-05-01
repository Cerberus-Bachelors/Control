// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cerberus_msgs:msg/CerberusObservationTensor.idl
// generated code does not contain a copyright notice

#ifndef CERBERUS_MSGS__MSG__DETAIL__CERBERUS_OBSERVATION_TENSOR__BUILDER_HPP_
#define CERBERUS_MSGS__MSG__DETAIL__CERBERUS_OBSERVATION_TENSOR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cerberus_msgs/msg/detail/cerberus_observation_tensor__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cerberus_msgs
{

namespace msg
{

namespace builder
{

class Init_CerberusObservationTensor_actions
{
public:
  explicit Init_CerberusObservationTensor_actions(::cerberus_msgs::msg::CerberusObservationTensor & msg)
  : msg_(msg)
  {}
  ::cerberus_msgs::msg::CerberusObservationTensor actions(::cerberus_msgs::msg::CerberusObservationTensor::_actions_type arg)
  {
    msg_.actions = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cerberus_msgs::msg::CerberusObservationTensor msg_;
};

class Init_CerberusObservationTensor_joint_vel
{
public:
  explicit Init_CerberusObservationTensor_joint_vel(::cerberus_msgs::msg::CerberusObservationTensor & msg)
  : msg_(msg)
  {}
  Init_CerberusObservationTensor_actions joint_vel(::cerberus_msgs::msg::CerberusObservationTensor::_joint_vel_type arg)
  {
    msg_.joint_vel = std::move(arg);
    return Init_CerberusObservationTensor_actions(msg_);
  }

private:
  ::cerberus_msgs::msg::CerberusObservationTensor msg_;
};

class Init_CerberusObservationTensor_joint_pos
{
public:
  explicit Init_CerberusObservationTensor_joint_pos(::cerberus_msgs::msg::CerberusObservationTensor & msg)
  : msg_(msg)
  {}
  Init_CerberusObservationTensor_joint_vel joint_pos(::cerberus_msgs::msg::CerberusObservationTensor::_joint_pos_type arg)
  {
    msg_.joint_pos = std::move(arg);
    return Init_CerberusObservationTensor_joint_vel(msg_);
  }

private:
  ::cerberus_msgs::msg::CerberusObservationTensor msg_;
};

class Init_CerberusObservationTensor_command
{
public:
  explicit Init_CerberusObservationTensor_command(::cerberus_msgs::msg::CerberusObservationTensor & msg)
  : msg_(msg)
  {}
  Init_CerberusObservationTensor_joint_pos command(::cerberus_msgs::msg::CerberusObservationTensor::_command_type arg)
  {
    msg_.command = std::move(arg);
    return Init_CerberusObservationTensor_joint_pos(msg_);
  }

private:
  ::cerberus_msgs::msg::CerberusObservationTensor msg_;
};

class Init_CerberusObservationTensor_proj_grav
{
public:
  explicit Init_CerberusObservationTensor_proj_grav(::cerberus_msgs::msg::CerberusObservationTensor & msg)
  : msg_(msg)
  {}
  Init_CerberusObservationTensor_command proj_grav(::cerberus_msgs::msg::CerberusObservationTensor::_proj_grav_type arg)
  {
    msg_.proj_grav = std::move(arg);
    return Init_CerberusObservationTensor_command(msg_);
  }

private:
  ::cerberus_msgs::msg::CerberusObservationTensor msg_;
};

class Init_CerberusObservationTensor_base_ang_vel
{
public:
  Init_CerberusObservationTensor_base_ang_vel()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CerberusObservationTensor_proj_grav base_ang_vel(::cerberus_msgs::msg::CerberusObservationTensor::_base_ang_vel_type arg)
  {
    msg_.base_ang_vel = std::move(arg);
    return Init_CerberusObservationTensor_proj_grav(msg_);
  }

private:
  ::cerberus_msgs::msg::CerberusObservationTensor msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cerberus_msgs::msg::CerberusObservationTensor>()
{
  return cerberus_msgs::msg::builder::Init_CerberusObservationTensor_base_ang_vel();
}

}  // namespace cerberus_msgs

#endif  // CERBERUS_MSGS__MSG__DETAIL__CERBERUS_OBSERVATION_TENSOR__BUILDER_HPP_
