// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cerberus_msgs:msg/SensorData.idl
// generated code does not contain a copyright notice

#ifndef CERBERUS_MSGS__MSG__DETAIL__SENSOR_DATA__BUILDER_HPP_
#define CERBERUS_MSGS__MSG__DETAIL__SENSOR_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cerberus_msgs/msg/detail/sensor_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cerberus_msgs
{

namespace msg
{

namespace builder
{

class Init_SensorData_altitude
{
public:
  explicit Init_SensorData_altitude(::cerberus_msgs::msg::SensorData & msg)
  : msg_(msg)
  {}
  ::cerberus_msgs::msg::SensorData altitude(::cerberus_msgs::msg::SensorData::_altitude_type arg)
  {
    msg_.altitude = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cerberus_msgs::msg::SensorData msg_;
};

class Init_SensorData_longitude
{
public:
  explicit Init_SensorData_longitude(::cerberus_msgs::msg::SensorData & msg)
  : msg_(msg)
  {}
  Init_SensorData_altitude longitude(::cerberus_msgs::msg::SensorData::_longitude_type arg)
  {
    msg_.longitude = std::move(arg);
    return Init_SensorData_altitude(msg_);
  }

private:
  ::cerberus_msgs::msg::SensorData msg_;
};

class Init_SensorData_latitude
{
public:
  explicit Init_SensorData_latitude(::cerberus_msgs::msg::SensorData & msg)
  : msg_(msg)
  {}
  Init_SensorData_longitude latitude(::cerberus_msgs::msg::SensorData::_latitude_type arg)
  {
    msg_.latitude = std::move(arg);
    return Init_SensorData_longitude(msg_);
  }

private:
  ::cerberus_msgs::msg::SensorData msg_;
};

class Init_SensorData_heading
{
public:
  explicit Init_SensorData_heading(::cerberus_msgs::msg::SensorData & msg)
  : msg_(msg)
  {}
  Init_SensorData_latitude heading(::cerberus_msgs::msg::SensorData::_heading_type arg)
  {
    msg_.heading = std::move(arg);
    return Init_SensorData_latitude(msg_);
  }

private:
  ::cerberus_msgs::msg::SensorData msg_;
};

class Init_SensorData_gyro_z
{
public:
  explicit Init_SensorData_gyro_z(::cerberus_msgs::msg::SensorData & msg)
  : msg_(msg)
  {}
  Init_SensorData_heading gyro_z(::cerberus_msgs::msg::SensorData::_gyro_z_type arg)
  {
    msg_.gyro_z = std::move(arg);
    return Init_SensorData_heading(msg_);
  }

private:
  ::cerberus_msgs::msg::SensorData msg_;
};

class Init_SensorData_gyro_y
{
public:
  explicit Init_SensorData_gyro_y(::cerberus_msgs::msg::SensorData & msg)
  : msg_(msg)
  {}
  Init_SensorData_gyro_z gyro_y(::cerberus_msgs::msg::SensorData::_gyro_y_type arg)
  {
    msg_.gyro_y = std::move(arg);
    return Init_SensorData_gyro_z(msg_);
  }

private:
  ::cerberus_msgs::msg::SensorData msg_;
};

class Init_SensorData_gyro_x
{
public:
  explicit Init_SensorData_gyro_x(::cerberus_msgs::msg::SensorData & msg)
  : msg_(msg)
  {}
  Init_SensorData_gyro_y gyro_x(::cerberus_msgs::msg::SensorData::_gyro_x_type arg)
  {
    msg_.gyro_x = std::move(arg);
    return Init_SensorData_gyro_y(msg_);
  }

private:
  ::cerberus_msgs::msg::SensorData msg_;
};

class Init_SensorData_accel_z
{
public:
  explicit Init_SensorData_accel_z(::cerberus_msgs::msg::SensorData & msg)
  : msg_(msg)
  {}
  Init_SensorData_gyro_x accel_z(::cerberus_msgs::msg::SensorData::_accel_z_type arg)
  {
    msg_.accel_z = std::move(arg);
    return Init_SensorData_gyro_x(msg_);
  }

private:
  ::cerberus_msgs::msg::SensorData msg_;
};

class Init_SensorData_accel_y
{
public:
  explicit Init_SensorData_accel_y(::cerberus_msgs::msg::SensorData & msg)
  : msg_(msg)
  {}
  Init_SensorData_accel_z accel_y(::cerberus_msgs::msg::SensorData::_accel_y_type arg)
  {
    msg_.accel_y = std::move(arg);
    return Init_SensorData_accel_z(msg_);
  }

private:
  ::cerberus_msgs::msg::SensorData msg_;
};

class Init_SensorData_accel_x
{
public:
  Init_SensorData_accel_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SensorData_accel_y accel_x(::cerberus_msgs::msg::SensorData::_accel_x_type arg)
  {
    msg_.accel_x = std::move(arg);
    return Init_SensorData_accel_y(msg_);
  }

private:
  ::cerberus_msgs::msg::SensorData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cerberus_msgs::msg::SensorData>()
{
  return cerberus_msgs::msg::builder::Init_SensorData_accel_x();
}

}  // namespace cerberus_msgs

#endif  // CERBERUS_MSGS__MSG__DETAIL__SENSOR_DATA__BUILDER_HPP_
