// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from spider_interfaces:msg/LocCommands.idl
// generated code does not contain a copyright notice
#include "spider_interfaces/msg/detail/loc_commands__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `move_type`
#include "std_msgs/msg/detail/string__functions.h"

bool
spider_interfaces__msg__LocCommands__init(spider_interfaces__msg__LocCommands * msg)
{
  if (!msg) {
    return false;
  }
  // move_type
  if (!std_msgs__msg__String__init(&msg->move_type)) {
    spider_interfaces__msg__LocCommands__fini(msg);
    return false;
  }
  // move_amount
  return true;
}

void
spider_interfaces__msg__LocCommands__fini(spider_interfaces__msg__LocCommands * msg)
{
  if (!msg) {
    return;
  }
  // move_type
  std_msgs__msg__String__fini(&msg->move_type);
  // move_amount
}

bool
spider_interfaces__msg__LocCommands__are_equal(const spider_interfaces__msg__LocCommands * lhs, const spider_interfaces__msg__LocCommands * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // move_type
  if (!std_msgs__msg__String__are_equal(
      &(lhs->move_type), &(rhs->move_type)))
  {
    return false;
  }
  // move_amount
  if (lhs->move_amount != rhs->move_amount) {
    return false;
  }
  return true;
}

bool
spider_interfaces__msg__LocCommands__copy(
  const spider_interfaces__msg__LocCommands * input,
  spider_interfaces__msg__LocCommands * output)
{
  if (!input || !output) {
    return false;
  }
  // move_type
  if (!std_msgs__msg__String__copy(
      &(input->move_type), &(output->move_type)))
  {
    return false;
  }
  // move_amount
  output->move_amount = input->move_amount;
  return true;
}

spider_interfaces__msg__LocCommands *
spider_interfaces__msg__LocCommands__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_interfaces__msg__LocCommands * msg = (spider_interfaces__msg__LocCommands *)allocator.allocate(sizeof(spider_interfaces__msg__LocCommands), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(spider_interfaces__msg__LocCommands));
  bool success = spider_interfaces__msg__LocCommands__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
spider_interfaces__msg__LocCommands__destroy(spider_interfaces__msg__LocCommands * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    spider_interfaces__msg__LocCommands__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
spider_interfaces__msg__LocCommands__Sequence__init(spider_interfaces__msg__LocCommands__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_interfaces__msg__LocCommands * data = NULL;

  if (size) {
    data = (spider_interfaces__msg__LocCommands *)allocator.zero_allocate(size, sizeof(spider_interfaces__msg__LocCommands), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = spider_interfaces__msg__LocCommands__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        spider_interfaces__msg__LocCommands__fini(&data[i - 1]);
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
spider_interfaces__msg__LocCommands__Sequence__fini(spider_interfaces__msg__LocCommands__Sequence * array)
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
      spider_interfaces__msg__LocCommands__fini(&array->data[i]);
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

spider_interfaces__msg__LocCommands__Sequence *
spider_interfaces__msg__LocCommands__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_interfaces__msg__LocCommands__Sequence * array = (spider_interfaces__msg__LocCommands__Sequence *)allocator.allocate(sizeof(spider_interfaces__msg__LocCommands__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = spider_interfaces__msg__LocCommands__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
spider_interfaces__msg__LocCommands__Sequence__destroy(spider_interfaces__msg__LocCommands__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    spider_interfaces__msg__LocCommands__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
spider_interfaces__msg__LocCommands__Sequence__are_equal(const spider_interfaces__msg__LocCommands__Sequence * lhs, const spider_interfaces__msg__LocCommands__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!spider_interfaces__msg__LocCommands__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
spider_interfaces__msg__LocCommands__Sequence__copy(
  const spider_interfaces__msg__LocCommands__Sequence * input,
  spider_interfaces__msg__LocCommands__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(spider_interfaces__msg__LocCommands);
    spider_interfaces__msg__LocCommands * data =
      (spider_interfaces__msg__LocCommands *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!spider_interfaces__msg__LocCommands__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          spider_interfaces__msg__LocCommands__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!spider_interfaces__msg__LocCommands__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
