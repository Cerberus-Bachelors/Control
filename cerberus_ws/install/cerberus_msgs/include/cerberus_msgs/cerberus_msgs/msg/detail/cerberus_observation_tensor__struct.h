// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cerberus_msgs:msg/CerberusObservationTensor.idl
// generated code does not contain a copyright notice

#ifndef CERBERUS_MSGS__MSG__DETAIL__CERBERUS_OBSERVATION_TENSOR__STRUCT_H_
#define CERBERUS_MSGS__MSG__DETAIL__CERBERUS_OBSERVATION_TENSOR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'base_ang_vel'
// Member 'proj_grav'
// Member 'command'
#include "geometry_msgs/msg/detail/vector3__struct.h"

/// Struct defined in msg/CerberusObservationTensor in the package cerberus_msgs.
typedef struct cerberus_msgs__msg__CerberusObservationTensor
{
  geometry_msgs__msg__Vector3 base_ang_vel;
  geometry_msgs__msg__Vector3 proj_grav;
  geometry_msgs__msg__Vector3 command;
  double joint_pos[12];
  double joint_vel[12];
  double actions[12];
} cerberus_msgs__msg__CerberusObservationTensor;

// Struct for a sequence of cerberus_msgs__msg__CerberusObservationTensor.
typedef struct cerberus_msgs__msg__CerberusObservationTensor__Sequence
{
  cerberus_msgs__msg__CerberusObservationTensor * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cerberus_msgs__msg__CerberusObservationTensor__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CERBERUS_MSGS__MSG__DETAIL__CERBERUS_OBSERVATION_TENSOR__STRUCT_H_
