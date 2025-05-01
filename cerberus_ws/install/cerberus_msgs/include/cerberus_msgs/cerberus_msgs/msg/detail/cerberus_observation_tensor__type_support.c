// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from cerberus_msgs:msg/CerberusObservationTensor.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "cerberus_msgs/msg/detail/cerberus_observation_tensor__rosidl_typesupport_introspection_c.h"
#include "cerberus_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "cerberus_msgs/msg/detail/cerberus_observation_tensor__functions.h"
#include "cerberus_msgs/msg/detail/cerberus_observation_tensor__struct.h"


// Include directives for member types
// Member `base_ang_vel`
// Member `proj_grav`
// Member `command`
#include "geometry_msgs/msg/vector3.h"
// Member `base_ang_vel`
// Member `proj_grav`
// Member `command`
#include "geometry_msgs/msg/detail/vector3__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__CerberusObservationTensor_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  cerberus_msgs__msg__CerberusObservationTensor__init(message_memory);
}

void cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__CerberusObservationTensor_fini_function(void * message_memory)
{
  cerberus_msgs__msg__CerberusObservationTensor__fini(message_memory);
}

size_t cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__size_function__CerberusObservationTensor__joint_pos(
  const void * untyped_member)
{
  (void)untyped_member;
  return 12;
}

const void * cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__get_const_function__CerberusObservationTensor__joint_pos(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__get_function__CerberusObservationTensor__joint_pos(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__fetch_function__CerberusObservationTensor__joint_pos(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__get_const_function__CerberusObservationTensor__joint_pos(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__assign_function__CerberusObservationTensor__joint_pos(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__get_function__CerberusObservationTensor__joint_pos(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

size_t cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__size_function__CerberusObservationTensor__joint_vel(
  const void * untyped_member)
{
  (void)untyped_member;
  return 12;
}

const void * cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__get_const_function__CerberusObservationTensor__joint_vel(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__get_function__CerberusObservationTensor__joint_vel(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__fetch_function__CerberusObservationTensor__joint_vel(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__get_const_function__CerberusObservationTensor__joint_vel(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__assign_function__CerberusObservationTensor__joint_vel(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__get_function__CerberusObservationTensor__joint_vel(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

size_t cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__size_function__CerberusObservationTensor__actions(
  const void * untyped_member)
{
  (void)untyped_member;
  return 12;
}

const void * cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__get_const_function__CerberusObservationTensor__actions(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__get_function__CerberusObservationTensor__actions(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__fetch_function__CerberusObservationTensor__actions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__get_const_function__CerberusObservationTensor__actions(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__assign_function__CerberusObservationTensor__actions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__get_function__CerberusObservationTensor__actions(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__CerberusObservationTensor_message_member_array[6] = {
  {
    "base_ang_vel",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cerberus_msgs__msg__CerberusObservationTensor, base_ang_vel),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "proj_grav",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cerberus_msgs__msg__CerberusObservationTensor, proj_grav),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "command",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cerberus_msgs__msg__CerberusObservationTensor, command),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "joint_pos",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    12,  // array size
    false,  // is upper bound
    offsetof(cerberus_msgs__msg__CerberusObservationTensor, joint_pos),  // bytes offset in struct
    NULL,  // default value
    cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__size_function__CerberusObservationTensor__joint_pos,  // size() function pointer
    cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__get_const_function__CerberusObservationTensor__joint_pos,  // get_const(index) function pointer
    cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__get_function__CerberusObservationTensor__joint_pos,  // get(index) function pointer
    cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__fetch_function__CerberusObservationTensor__joint_pos,  // fetch(index, &value) function pointer
    cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__assign_function__CerberusObservationTensor__joint_pos,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "joint_vel",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    12,  // array size
    false,  // is upper bound
    offsetof(cerberus_msgs__msg__CerberusObservationTensor, joint_vel),  // bytes offset in struct
    NULL,  // default value
    cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__size_function__CerberusObservationTensor__joint_vel,  // size() function pointer
    cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__get_const_function__CerberusObservationTensor__joint_vel,  // get_const(index) function pointer
    cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__get_function__CerberusObservationTensor__joint_vel,  // get(index) function pointer
    cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__fetch_function__CerberusObservationTensor__joint_vel,  // fetch(index, &value) function pointer
    cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__assign_function__CerberusObservationTensor__joint_vel,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "actions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    12,  // array size
    false,  // is upper bound
    offsetof(cerberus_msgs__msg__CerberusObservationTensor, actions),  // bytes offset in struct
    NULL,  // default value
    cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__size_function__CerberusObservationTensor__actions,  // size() function pointer
    cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__get_const_function__CerberusObservationTensor__actions,  // get_const(index) function pointer
    cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__get_function__CerberusObservationTensor__actions,  // get(index) function pointer
    cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__fetch_function__CerberusObservationTensor__actions,  // fetch(index, &value) function pointer
    cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__assign_function__CerberusObservationTensor__actions,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__CerberusObservationTensor_message_members = {
  "cerberus_msgs__msg",  // message namespace
  "CerberusObservationTensor",  // message name
  6,  // number of fields
  sizeof(cerberus_msgs__msg__CerberusObservationTensor),
  cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__CerberusObservationTensor_message_member_array,  // message members
  cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__CerberusObservationTensor_init_function,  // function to initialize message memory (memory has to be allocated)
  cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__CerberusObservationTensor_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__CerberusObservationTensor_message_type_support_handle = {
  0,
  &cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__CerberusObservationTensor_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cerberus_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cerberus_msgs, msg, CerberusObservationTensor)() {
  cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__CerberusObservationTensor_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__CerberusObservationTensor_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__CerberusObservationTensor_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  if (!cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__CerberusObservationTensor_message_type_support_handle.typesupport_identifier) {
    cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__CerberusObservationTensor_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &cerberus_msgs__msg__CerberusObservationTensor__rosidl_typesupport_introspection_c__CerberusObservationTensor_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
