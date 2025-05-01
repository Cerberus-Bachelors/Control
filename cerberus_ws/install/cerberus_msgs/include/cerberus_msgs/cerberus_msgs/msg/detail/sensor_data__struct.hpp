// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cerberus_msgs:msg/SensorData.idl
// generated code does not contain a copyright notice

#ifndef CERBERUS_MSGS__MSG__DETAIL__SENSOR_DATA__STRUCT_HPP_
#define CERBERUS_MSGS__MSG__DETAIL__SENSOR_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__cerberus_msgs__msg__SensorData __attribute__((deprecated))
#else
# define DEPRECATED__cerberus_msgs__msg__SensorData __declspec(deprecated)
#endif

namespace cerberus_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SensorData_
{
  using Type = SensorData_<ContainerAllocator>;

  explicit SensorData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accel_x = 0.0f;
      this->accel_y = 0.0f;
      this->accel_z = 0.0f;
      this->gyro_x = 0.0f;
      this->gyro_y = 0.0f;
      this->gyro_z = 0.0f;
      this->heading = 0.0f;
      this->latitude = 0.0f;
      this->longitude = 0.0f;
      this->altitude = 0.0f;
    }
  }

  explicit SensorData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accel_x = 0.0f;
      this->accel_y = 0.0f;
      this->accel_z = 0.0f;
      this->gyro_x = 0.0f;
      this->gyro_y = 0.0f;
      this->gyro_z = 0.0f;
      this->heading = 0.0f;
      this->latitude = 0.0f;
      this->longitude = 0.0f;
      this->altitude = 0.0f;
    }
  }

  // field types and members
  using _accel_x_type =
    float;
  _accel_x_type accel_x;
  using _accel_y_type =
    float;
  _accel_y_type accel_y;
  using _accel_z_type =
    float;
  _accel_z_type accel_z;
  using _gyro_x_type =
    float;
  _gyro_x_type gyro_x;
  using _gyro_y_type =
    float;
  _gyro_y_type gyro_y;
  using _gyro_z_type =
    float;
  _gyro_z_type gyro_z;
  using _heading_type =
    float;
  _heading_type heading;
  using _latitude_type =
    float;
  _latitude_type latitude;
  using _longitude_type =
    float;
  _longitude_type longitude;
  using _altitude_type =
    float;
  _altitude_type altitude;

  // setters for named parameter idiom
  Type & set__accel_x(
    const float & _arg)
  {
    this->accel_x = _arg;
    return *this;
  }
  Type & set__accel_y(
    const float & _arg)
  {
    this->accel_y = _arg;
    return *this;
  }
  Type & set__accel_z(
    const float & _arg)
  {
    this->accel_z = _arg;
    return *this;
  }
  Type & set__gyro_x(
    const float & _arg)
  {
    this->gyro_x = _arg;
    return *this;
  }
  Type & set__gyro_y(
    const float & _arg)
  {
    this->gyro_y = _arg;
    return *this;
  }
  Type & set__gyro_z(
    const float & _arg)
  {
    this->gyro_z = _arg;
    return *this;
  }
  Type & set__heading(
    const float & _arg)
  {
    this->heading = _arg;
    return *this;
  }
  Type & set__latitude(
    const float & _arg)
  {
    this->latitude = _arg;
    return *this;
  }
  Type & set__longitude(
    const float & _arg)
  {
    this->longitude = _arg;
    return *this;
  }
  Type & set__altitude(
    const float & _arg)
  {
    this->altitude = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cerberus_msgs::msg::SensorData_<ContainerAllocator> *;
  using ConstRawPtr =
    const cerberus_msgs::msg::SensorData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cerberus_msgs::msg::SensorData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cerberus_msgs::msg::SensorData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cerberus_msgs::msg::SensorData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cerberus_msgs::msg::SensorData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cerberus_msgs::msg::SensorData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cerberus_msgs::msg::SensorData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cerberus_msgs::msg::SensorData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cerberus_msgs::msg::SensorData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cerberus_msgs__msg__SensorData
    std::shared_ptr<cerberus_msgs::msg::SensorData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cerberus_msgs__msg__SensorData
    std::shared_ptr<cerberus_msgs::msg::SensorData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SensorData_ & other) const
  {
    if (this->accel_x != other.accel_x) {
      return false;
    }
    if (this->accel_y != other.accel_y) {
      return false;
    }
    if (this->accel_z != other.accel_z) {
      return false;
    }
    if (this->gyro_x != other.gyro_x) {
      return false;
    }
    if (this->gyro_y != other.gyro_y) {
      return false;
    }
    if (this->gyro_z != other.gyro_z) {
      return false;
    }
    if (this->heading != other.heading) {
      return false;
    }
    if (this->latitude != other.latitude) {
      return false;
    }
    if (this->longitude != other.longitude) {
      return false;
    }
    if (this->altitude != other.altitude) {
      return false;
    }
    return true;
  }
  bool operator!=(const SensorData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SensorData_

// alias to use template instance with default allocator
using SensorData =
  cerberus_msgs::msg::SensorData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cerberus_msgs

#endif  // CERBERUS_MSGS__MSG__DETAIL__SENSOR_DATA__STRUCT_HPP_
