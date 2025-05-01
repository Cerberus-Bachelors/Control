// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from cerberus_msgs:msg/CerberusObservationTensor.idl
// generated code does not contain a copyright notice

#ifndef CERBERUS_MSGS__MSG__DETAIL__CERBERUS_OBSERVATION_TENSOR__FUNCTIONS_H_
#define CERBERUS_MSGS__MSG__DETAIL__CERBERUS_OBSERVATION_TENSOR__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "cerberus_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "cerberus_msgs/msg/detail/cerberus_observation_tensor__struct.h"

/// Initialize msg/CerberusObservationTensor message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * cerberus_msgs__msg__CerberusObservationTensor
 * )) before or use
 * cerberus_msgs__msg__CerberusObservationTensor__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_cerberus_msgs
bool
cerberus_msgs__msg__CerberusObservationTensor__init(cerberus_msgs__msg__CerberusObservationTensor * msg);

/// Finalize msg/CerberusObservationTensor message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cerberus_msgs
void
cerberus_msgs__msg__CerberusObservationTensor__fini(cerberus_msgs__msg__CerberusObservationTensor * msg);

/// Create msg/CerberusObservationTensor message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * cerberus_msgs__msg__CerberusObservationTensor__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cerberus_msgs
cerberus_msgs__msg__CerberusObservationTensor *
cerberus_msgs__msg__CerberusObservationTensor__create();

/// Destroy msg/CerberusObservationTensor message.
/**
 * It calls
 * cerberus_msgs__msg__CerberusObservationTensor__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cerberus_msgs
void
cerberus_msgs__msg__CerberusObservationTensor__destroy(cerberus_msgs__msg__CerberusObservationTensor * msg);

/// Check for msg/CerberusObservationTensor message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cerberus_msgs
bool
cerberus_msgs__msg__CerberusObservationTensor__are_equal(const cerberus_msgs__msg__CerberusObservationTensor * lhs, const cerberus_msgs__msg__CerberusObservationTensor * rhs);

/// Copy a msg/CerberusObservationTensor message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_cerberus_msgs
bool
cerberus_msgs__msg__CerberusObservationTensor__copy(
  const cerberus_msgs__msg__CerberusObservationTensor * input,
  cerberus_msgs__msg__CerberusObservationTensor * output);

/// Initialize array of msg/CerberusObservationTensor messages.
/**
 * It allocates the memory for the number of elements and calls
 * cerberus_msgs__msg__CerberusObservationTensor__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_cerberus_msgs
bool
cerberus_msgs__msg__CerberusObservationTensor__Sequence__init(cerberus_msgs__msg__CerberusObservationTensor__Sequence * array, size_t size);

/// Finalize array of msg/CerberusObservationTensor messages.
/**
 * It calls
 * cerberus_msgs__msg__CerberusObservationTensor__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cerberus_msgs
void
cerberus_msgs__msg__CerberusObservationTensor__Sequence__fini(cerberus_msgs__msg__CerberusObservationTensor__Sequence * array);

/// Create array of msg/CerberusObservationTensor messages.
/**
 * It allocates the memory for the array and calls
 * cerberus_msgs__msg__CerberusObservationTensor__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cerberus_msgs
cerberus_msgs__msg__CerberusObservationTensor__Sequence *
cerberus_msgs__msg__CerberusObservationTensor__Sequence__create(size_t size);

/// Destroy array of msg/CerberusObservationTensor messages.
/**
 * It calls
 * cerberus_msgs__msg__CerberusObservationTensor__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cerberus_msgs
void
cerberus_msgs__msg__CerberusObservationTensor__Sequence__destroy(cerberus_msgs__msg__CerberusObservationTensor__Sequence * array);

/// Check for msg/CerberusObservationTensor message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cerberus_msgs
bool
cerberus_msgs__msg__CerberusObservationTensor__Sequence__are_equal(const cerberus_msgs__msg__CerberusObservationTensor__Sequence * lhs, const cerberus_msgs__msg__CerberusObservationTensor__Sequence * rhs);

/// Copy an array of msg/CerberusObservationTensor messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_cerberus_msgs
bool
cerberus_msgs__msg__CerberusObservationTensor__Sequence__copy(
  const cerberus_msgs__msg__CerberusObservationTensor__Sequence * input,
  cerberus_msgs__msg__CerberusObservationTensor__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CERBERUS_MSGS__MSG__DETAIL__CERBERUS_OBSERVATION_TENSOR__FUNCTIONS_H_
