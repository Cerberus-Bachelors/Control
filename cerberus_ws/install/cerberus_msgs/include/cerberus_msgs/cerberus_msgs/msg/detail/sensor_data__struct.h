// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cerberus_msgs:msg/SensorData.idl
// generated code does not contain a copyright notice

#ifndef CERBERUS_MSGS__MSG__DETAIL__SENSOR_DATA__STRUCT_H_
#define CERBERUS_MSGS__MSG__DETAIL__SENSOR_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/SensorData in the package cerberus_msgs.
typedef struct cerberus_msgs__msg__SensorData
{
  float accel_x;
  float accel_y;
  float accel_z;
  float gyro_x;
  float gyro_y;
  float gyro_z;
  float heading;
  float latitude;
  float longitude;
  float altitude;
} cerberus_msgs__msg__SensorData;

// Struct for a sequence of cerberus_msgs__msg__SensorData.
typedef struct cerberus_msgs__msg__SensorData__Sequence
{
  cerberus_msgs__msg__SensorData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cerberus_msgs__msg__SensorData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CERBERUS_MSGS__MSG__DETAIL__SENSOR_DATA__STRUCT_H_
