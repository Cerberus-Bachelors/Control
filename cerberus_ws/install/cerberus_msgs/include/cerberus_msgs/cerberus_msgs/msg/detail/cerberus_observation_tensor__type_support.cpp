// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from cerberus_msgs:msg/CerberusObservationTensor.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "cerberus_msgs/msg/detail/cerberus_observation_tensor__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace cerberus_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void CerberusObservationTensor_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) cerberus_msgs::msg::CerberusObservationTensor(_init);
}

void CerberusObservationTensor_fini_function(void * message_memory)
{
  auto typed_message = static_cast<cerberus_msgs::msg::CerberusObservationTensor *>(message_memory);
  typed_message->~CerberusObservationTensor();
}

size_t size_function__CerberusObservationTensor__joint_pos(const void * untyped_member)
{
  (void)untyped_member;
  return 12;
}

const void * get_const_function__CerberusObservationTensor__joint_pos(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 12> *>(untyped_member);
  return &member[index];
}

void * get_function__CerberusObservationTensor__joint_pos(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 12> *>(untyped_member);
  return &member[index];
}

void fetch_function__CerberusObservationTensor__joint_pos(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__CerberusObservationTensor__joint_pos(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__CerberusObservationTensor__joint_pos(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__CerberusObservationTensor__joint_pos(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

size_t size_function__CerberusObservationTensor__joint_vel(const void * untyped_member)
{
  (void)untyped_member;
  return 12;
}

const void * get_const_function__CerberusObservationTensor__joint_vel(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 12> *>(untyped_member);
  return &member[index];
}

void * get_function__CerberusObservationTensor__joint_vel(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 12> *>(untyped_member);
  return &member[index];
}

void fetch_function__CerberusObservationTensor__joint_vel(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__CerberusObservationTensor__joint_vel(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__CerberusObservationTensor__joint_vel(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__CerberusObservationTensor__joint_vel(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

size_t size_function__CerberusObservationTensor__actions(const void * untyped_member)
{
  (void)untyped_member;
  return 12;
}

const void * get_const_function__CerberusObservationTensor__actions(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 12> *>(untyped_member);
  return &member[index];
}

void * get_function__CerberusObservationTensor__actions(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 12> *>(untyped_member);
  return &member[index];
}

void fetch_function__CerberusObservationTensor__actions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__CerberusObservationTensor__actions(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__CerberusObservationTensor__actions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__CerberusObservationTensor__actions(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember CerberusObservationTensor_message_member_array[6] = {
  {
    "base_ang_vel",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Vector3>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cerberus_msgs::msg::CerberusObservationTensor, base_ang_vel),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "proj_grav",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Vector3>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cerberus_msgs::msg::CerberusObservationTensor, proj_grav),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "command",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Vector3>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cerberus_msgs::msg::CerberusObservationTensor, command),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "joint_pos",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    12,  // array size
    false,  // is upper bound
    offsetof(cerberus_msgs::msg::CerberusObservationTensor, joint_pos),  // bytes offset in struct
    nullptr,  // default value
    size_function__CerberusObservationTensor__joint_pos,  // size() function pointer
    get_const_function__CerberusObservationTensor__joint_pos,  // get_const(index) function pointer
    get_function__CerberusObservationTensor__joint_pos,  // get(index) function pointer
    fetch_function__CerberusObservationTensor__joint_pos,  // fetch(index, &value) function pointer
    assign_function__CerberusObservationTensor__joint_pos,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "joint_vel",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    12,  // array size
    false,  // is upper bound
    offsetof(cerberus_msgs::msg::CerberusObservationTensor, joint_vel),  // bytes offset in struct
    nullptr,  // default value
    size_function__CerberusObservationTensor__joint_vel,  // size() function pointer
    get_const_function__CerberusObservationTensor__joint_vel,  // get_const(index) function pointer
    get_function__CerberusObservationTensor__joint_vel,  // get(index) function pointer
    fetch_function__CerberusObservationTensor__joint_vel,  // fetch(index, &value) function pointer
    assign_function__CerberusObservationTensor__joint_vel,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "actions",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    12,  // array size
    false,  // is upper bound
    offsetof(cerberus_msgs::msg::CerberusObservationTensor, actions),  // bytes offset in struct
    nullptr,  // default value
    size_function__CerberusObservationTensor__actions,  // size() function pointer
    get_const_function__CerberusObservationTensor__actions,  // get_const(index) function pointer
    get_function__CerberusObservationTensor__actions,  // get(index) function pointer
    fetch_function__CerberusObservationTensor__actions,  // fetch(index, &value) function pointer
    assign_function__CerberusObservationTensor__actions,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers CerberusObservationTensor_message_members = {
  "cerberus_msgs::msg",  // message namespace
  "CerberusObservationTensor",  // message name
  6,  // number of fields
  sizeof(cerberus_msgs::msg::CerberusObservationTensor),
  CerberusObservationTensor_message_member_array,  // message members
  CerberusObservationTensor_init_function,  // function to initialize message memory (memory has to be allocated)
  CerberusObservationTensor_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t CerberusObservationTensor_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &CerberusObservationTensor_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace cerberus_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<cerberus_msgs::msg::CerberusObservationTensor>()
{
  return &::cerberus_msgs::msg::rosidl_typesupport_introspection_cpp::CerberusObservationTensor_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, cerberus_msgs, msg, CerberusObservationTensor)() {
  return &::cerberus_msgs::msg::rosidl_typesupport_introspection_cpp::CerberusObservationTensor_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
