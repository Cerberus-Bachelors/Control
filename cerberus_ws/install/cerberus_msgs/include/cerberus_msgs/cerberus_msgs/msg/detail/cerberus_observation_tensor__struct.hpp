// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cerberus_msgs:msg/CerberusObservationTensor.idl
// generated code does not contain a copyright notice

#ifndef CERBERUS_MSGS__MSG__DETAIL__CERBERUS_OBSERVATION_TENSOR__STRUCT_HPP_
#define CERBERUS_MSGS__MSG__DETAIL__CERBERUS_OBSERVATION_TENSOR__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'base_ang_vel'
// Member 'proj_grav'
// Member 'command'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cerberus_msgs__msg__CerberusObservationTensor __attribute__((deprecated))
#else
# define DEPRECATED__cerberus_msgs__msg__CerberusObservationTensor __declspec(deprecated)
#endif

namespace cerberus_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CerberusObservationTensor_
{
  using Type = CerberusObservationTensor_<ContainerAllocator>;

  explicit CerberusObservationTensor_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : base_ang_vel(_init),
    proj_grav(_init),
    command(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 12>::iterator, double>(this->joint_pos.begin(), this->joint_pos.end(), 0.0);
      std::fill<typename std::array<double, 12>::iterator, double>(this->joint_vel.begin(), this->joint_vel.end(), 0.0);
      std::fill<typename std::array<double, 12>::iterator, double>(this->actions.begin(), this->actions.end(), 0.0);
    }
  }

  explicit CerberusObservationTensor_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : base_ang_vel(_alloc, _init),
    proj_grav(_alloc, _init),
    command(_alloc, _init),
    joint_pos(_alloc),
    joint_vel(_alloc),
    actions(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 12>::iterator, double>(this->joint_pos.begin(), this->joint_pos.end(), 0.0);
      std::fill<typename std::array<double, 12>::iterator, double>(this->joint_vel.begin(), this->joint_vel.end(), 0.0);
      std::fill<typename std::array<double, 12>::iterator, double>(this->actions.begin(), this->actions.end(), 0.0);
    }
  }

  // field types and members
  using _base_ang_vel_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _base_ang_vel_type base_ang_vel;
  using _proj_grav_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _proj_grav_type proj_grav;
  using _command_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _command_type command;
  using _joint_pos_type =
    std::array<double, 12>;
  _joint_pos_type joint_pos;
  using _joint_vel_type =
    std::array<double, 12>;
  _joint_vel_type joint_vel;
  using _actions_type =
    std::array<double, 12>;
  _actions_type actions;

  // setters for named parameter idiom
  Type & set__base_ang_vel(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->base_ang_vel = _arg;
    return *this;
  }
  Type & set__proj_grav(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->proj_grav = _arg;
    return *this;
  }
  Type & set__command(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->command = _arg;
    return *this;
  }
  Type & set__joint_pos(
    const std::array<double, 12> & _arg)
  {
    this->joint_pos = _arg;
    return *this;
  }
  Type & set__joint_vel(
    const std::array<double, 12> & _arg)
  {
    this->joint_vel = _arg;
    return *this;
  }
  Type & set__actions(
    const std::array<double, 12> & _arg)
  {
    this->actions = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cerberus_msgs::msg::CerberusObservationTensor_<ContainerAllocator> *;
  using ConstRawPtr =
    const cerberus_msgs::msg::CerberusObservationTensor_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cerberus_msgs::msg::CerberusObservationTensor_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cerberus_msgs::msg::CerberusObservationTensor_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cerberus_msgs::msg::CerberusObservationTensor_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cerberus_msgs::msg::CerberusObservationTensor_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cerberus_msgs::msg::CerberusObservationTensor_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cerberus_msgs::msg::CerberusObservationTensor_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cerberus_msgs::msg::CerberusObservationTensor_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cerberus_msgs::msg::CerberusObservationTensor_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cerberus_msgs__msg__CerberusObservationTensor
    std::shared_ptr<cerberus_msgs::msg::CerberusObservationTensor_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cerberus_msgs__msg__CerberusObservationTensor
    std::shared_ptr<cerberus_msgs::msg::CerberusObservationTensor_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CerberusObservationTensor_ & other) const
  {
    if (this->base_ang_vel != other.base_ang_vel) {
      return false;
    }
    if (this->proj_grav != other.proj_grav) {
      return false;
    }
    if (this->command != other.command) {
      return false;
    }
    if (this->joint_pos != other.joint_pos) {
      return false;
    }
    if (this->joint_vel != other.joint_vel) {
      return false;
    }
    if (this->actions != other.actions) {
      return false;
    }
    return true;
  }
  bool operator!=(const CerberusObservationTensor_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CerberusObservationTensor_

// alias to use template instance with default allocator
using CerberusObservationTensor =
  cerberus_msgs::msg::CerberusObservationTensor_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cerberus_msgs

#endif  // CERBERUS_MSGS__MSG__DETAIL__CERBERUS_OBSERVATION_TENSOR__STRUCT_HPP_
