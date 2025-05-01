// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cerberus_msgs:msg/CerberusObservationTensor.idl
// generated code does not contain a copyright notice
#include "cerberus_msgs/msg/detail/cerberus_observation_tensor__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `base_ang_vel`
// Member `proj_grav`
// Member `command`
#include "geometry_msgs/msg/detail/vector3__functions.h"

bool
cerberus_msgs__msg__CerberusObservationTensor__init(cerberus_msgs__msg__CerberusObservationTensor * msg)
{
  if (!msg) {
    return false;
  }
  // base_ang_vel
  if (!geometry_msgs__msg__Vector3__init(&msg->base_ang_vel)) {
    cerberus_msgs__msg__CerberusObservationTensor__fini(msg);
    return false;
  }
  // proj_grav
  if (!geometry_msgs__msg__Vector3__init(&msg->proj_grav)) {
    cerberus_msgs__msg__CerberusObservationTensor__fini(msg);
    return false;
  }
  // command
  if (!geometry_msgs__msg__Vector3__init(&msg->command)) {
    cerberus_msgs__msg__CerberusObservationTensor__fini(msg);
    return false;
  }
  // joint_pos
  // joint_vel
  // actions
  return true;
}

void
cerberus_msgs__msg__CerberusObservationTensor__fini(cerberus_msgs__msg__CerberusObservationTensor * msg)
{
  if (!msg) {
    return;
  }
  // base_ang_vel
  geometry_msgs__msg__Vector3__fini(&msg->base_ang_vel);
  // proj_grav
  geometry_msgs__msg__Vector3__fini(&msg->proj_grav);
  // command
  geometry_msgs__msg__Vector3__fini(&msg->command);
  // joint_pos
  // joint_vel
  // actions
}

bool
cerberus_msgs__msg__CerberusObservationTensor__are_equal(const cerberus_msgs__msg__CerberusObservationTensor * lhs, const cerberus_msgs__msg__CerberusObservationTensor * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // base_ang_vel
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->base_ang_vel), &(rhs->base_ang_vel)))
  {
    return false;
  }
  // proj_grav
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->proj_grav), &(rhs->proj_grav)))
  {
    return false;
  }
  // command
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->command), &(rhs->command)))
  {
    return false;
  }
  // joint_pos
  for (size_t i = 0; i < 12; ++i) {
    if (lhs->joint_pos[i] != rhs->joint_pos[i]) {
      return false;
    }
  }
  // joint_vel
  for (size_t i = 0; i < 12; ++i) {
    if (lhs->joint_vel[i] != rhs->joint_vel[i]) {
      return false;
    }
  }
  // actions
  for (size_t i = 0; i < 12; ++i) {
    if (lhs->actions[i] != rhs->actions[i]) {
      return false;
    }
  }
  return true;
}

bool
cerberus_msgs__msg__CerberusObservationTensor__copy(
  const cerberus_msgs__msg__CerberusObservationTensor * input,
  cerberus_msgs__msg__CerberusObservationTensor * output)
{
  if (!input || !output) {
    return false;
  }
  // base_ang_vel
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->base_ang_vel), &(output->base_ang_vel)))
  {
    return false;
  }
  // proj_grav
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->proj_grav), &(output->proj_grav)))
  {
    return false;
  }
  // command
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->command), &(output->command)))
  {
    return false;
  }
  // joint_pos
  for (size_t i = 0; i < 12; ++i) {
    output->joint_pos[i] = input->joint_pos[i];
  }
  // joint_vel
  for (size_t i = 0; i < 12; ++i) {
    output->joint_vel[i] = input->joint_vel[i];
  }
  // actions
  for (size_t i = 0; i < 12; ++i) {
    output->actions[i] = input->actions[i];
  }
  return true;
}

cerberus_msgs__msg__CerberusObservationTensor *
cerberus_msgs__msg__CerberusObservationTensor__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cerberus_msgs__msg__CerberusObservationTensor * msg = (cerberus_msgs__msg__CerberusObservationTensor *)allocator.allocate(sizeof(cerberus_msgs__msg__CerberusObservationTensor), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cerberus_msgs__msg__CerberusObservationTensor));
  bool success = cerberus_msgs__msg__CerberusObservationTensor__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cerberus_msgs__msg__CerberusObservationTensor__destroy(cerberus_msgs__msg__CerberusObservationTensor * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cerberus_msgs__msg__CerberusObservationTensor__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cerberus_msgs__msg__CerberusObservationTensor__Sequence__init(cerberus_msgs__msg__CerberusObservationTensor__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cerberus_msgs__msg__CerberusObservationTensor * data = NULL;

  if (size) {
    data = (cerberus_msgs__msg__CerberusObservationTensor *)allocator.zero_allocate(size, sizeof(cerberus_msgs__msg__CerberusObservationTensor), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cerberus_msgs__msg__CerberusObservationTensor__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cerberus_msgs__msg__CerberusObservationTensor__fini(&data[i - 1]);
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
cerberus_msgs__msg__CerberusObservationTensor__Sequence__fini(cerberus_msgs__msg__CerberusObservationTensor__Sequence * array)
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
      cerberus_msgs__msg__CerberusObservationTensor__fini(&array->data[i]);
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

cerberus_msgs__msg__CerberusObservationTensor__Sequence *
cerberus_msgs__msg__CerberusObservationTensor__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cerberus_msgs__msg__CerberusObservationTensor__Sequence * array = (cerberus_msgs__msg__CerberusObservationTensor__Sequence *)allocator.allocate(sizeof(cerberus_msgs__msg__CerberusObservationTensor__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cerberus_msgs__msg__CerberusObservationTensor__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cerberus_msgs__msg__CerberusObservationTensor__Sequence__destroy(cerberus_msgs__msg__CerberusObservationTensor__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cerberus_msgs__msg__CerberusObservationTensor__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cerberus_msgs__msg__CerberusObservationTensor__Sequence__are_equal(const cerberus_msgs__msg__CerberusObservationTensor__Sequence * lhs, const cerberus_msgs__msg__CerberusObservationTensor__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cerberus_msgs__msg__CerberusObservationTensor__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cerberus_msgs__msg__CerberusObservationTensor__Sequence__copy(
  const cerberus_msgs__msg__CerberusObservationTensor__Sequence * input,
  cerberus_msgs__msg__CerberusObservationTensor__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cerberus_msgs__msg__CerberusObservationTensor);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cerberus_msgs__msg__CerberusObservationTensor * data =
      (cerberus_msgs__msg__CerberusObservationTensor *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cerberus_msgs__msg__CerberusObservationTensor__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cerberus_msgs__msg__CerberusObservationTensor__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cerberus_msgs__msg__CerberusObservationTensor__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
