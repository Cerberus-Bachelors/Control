// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cerberus_msgs:msg/SensorData.idl
// generated code does not contain a copyright notice
#include "cerberus_msgs/msg/detail/sensor_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
cerberus_msgs__msg__SensorData__init(cerberus_msgs__msg__SensorData * msg)
{
  if (!msg) {
    return false;
  }
  // accel_x
  // accel_y
  // accel_z
  // gyro_x
  // gyro_y
  // gyro_z
  // heading
  // latitude
  // longitude
  // altitude
  return true;
}

void
cerberus_msgs__msg__SensorData__fini(cerberus_msgs__msg__SensorData * msg)
{
  if (!msg) {
    return;
  }
  // accel_x
  // accel_y
  // accel_z
  // gyro_x
  // gyro_y
  // gyro_z
  // heading
  // latitude
  // longitude
  // altitude
}

bool
cerberus_msgs__msg__SensorData__are_equal(const cerberus_msgs__msg__SensorData * lhs, const cerberus_msgs__msg__SensorData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accel_x
  if (lhs->accel_x != rhs->accel_x) {
    return false;
  }
  // accel_y
  if (lhs->accel_y != rhs->accel_y) {
    return false;
  }
  // accel_z
  if (lhs->accel_z != rhs->accel_z) {
    return false;
  }
  // gyro_x
  if (lhs->gyro_x != rhs->gyro_x) {
    return false;
  }
  // gyro_y
  if (lhs->gyro_y != rhs->gyro_y) {
    return false;
  }
  // gyro_z
  if (lhs->gyro_z != rhs->gyro_z) {
    return false;
  }
  // heading
  if (lhs->heading != rhs->heading) {
    return false;
  }
  // latitude
  if (lhs->latitude != rhs->latitude) {
    return false;
  }
  // longitude
  if (lhs->longitude != rhs->longitude) {
    return false;
  }
  // altitude
  if (lhs->altitude != rhs->altitude) {
    return false;
  }
  return true;
}

bool
cerberus_msgs__msg__SensorData__copy(
  const cerberus_msgs__msg__SensorData * input,
  cerberus_msgs__msg__SensorData * output)
{
  if (!input || !output) {
    return false;
  }
  // accel_x
  output->accel_x = input->accel_x;
  // accel_y
  output->accel_y = input->accel_y;
  // accel_z
  output->accel_z = input->accel_z;
  // gyro_x
  output->gyro_x = input->gyro_x;
  // gyro_y
  output->gyro_y = input->gyro_y;
  // gyro_z
  output->gyro_z = input->gyro_z;
  // heading
  output->heading = input->heading;
  // latitude
  output->latitude = input->latitude;
  // longitude
  output->longitude = input->longitude;
  // altitude
  output->altitude = input->altitude;
  return true;
}

cerberus_msgs__msg__SensorData *
cerberus_msgs__msg__SensorData__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cerberus_msgs__msg__SensorData * msg = (cerberus_msgs__msg__SensorData *)allocator.allocate(sizeof(cerberus_msgs__msg__SensorData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cerberus_msgs__msg__SensorData));
  bool success = cerberus_msgs__msg__SensorData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cerberus_msgs__msg__SensorData__destroy(cerberus_msgs__msg__SensorData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cerberus_msgs__msg__SensorData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cerberus_msgs__msg__SensorData__Sequence__init(cerberus_msgs__msg__SensorData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cerberus_msgs__msg__SensorData * data = NULL;

  if (size) {
    data = (cerberus_msgs__msg__SensorData *)allocator.zero_allocate(size, sizeof(cerberus_msgs__msg__SensorData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cerberus_msgs__msg__SensorData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cerberus_msgs__msg__SensorData__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
cerberus_msgs__msg__SensorData__Sequence__fini(cerberus_msgs__msg__SensorData__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      cerberus_msgs__msg__SensorData__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

cerberus_msgs__msg__SensorData__Sequence *
cerberus_msgs__msg__SensorData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cerberus_msgs__msg__SensorData__Sequence * array = (cerberus_msgs__msg__SensorData__Sequence *)allocator.allocate(sizeof(cerberus_msgs__msg__SensorData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cerberus_msgs__msg__SensorData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cerberus_msgs__msg__SensorData__Sequence__destroy(cerberus_msgs__msg__SensorData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cerberus_msgs__msg__SensorData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cerberus_msgs__msg__SensorData__Sequence__are_equal(const cerberus_msgs__msg__SensorData__Sequence * lhs, const cerberus_msgs__msg__SensorData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cerberus_msgs__msg__SensorData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cerberus_msgs__msg__SensorData__Sequence__copy(
  const cerberus_msgs__msg__SensorData__Sequence * input,
  cerberus_msgs__msg__SensorData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cerberus_msgs__msg__SensorData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cerberus_msgs__msg__SensorData * data =
      (cerberus_msgs__msg__SensorData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cerberus_msgs__msg__SensorData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cerberus_msgs__msg__SensorData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cerberus_msgs__msg__SensorData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
