// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from spider_interfaces:srv/LocService.idl
// generated code does not contain a copyright notice
#include "spider_interfaces/srv/detail/loc_service__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `move_type`
#include "std_msgs/msg/detail/string__functions.h"

bool
spider_interfaces__srv__LocService_Request__init(spider_interfaces__srv__LocService_Request * msg)
{
  if (!msg) {
    return false;
  }
  // move_type
  if (!std_msgs__msg__String__init(&msg->move_type)) {
    spider_interfaces__srv__LocService_Request__fini(msg);
    return false;
  }
  // move_amount
  // delta_angle
  return true;
}

void
spider_interfaces__srv__LocService_Request__fini(spider_interfaces__srv__LocService_Request * msg)
{
  if (!msg) {
    return;
  }
  // move_type
  std_msgs__msg__String__fini(&msg->move_type);
  // move_amount
  // delta_angle
}

bool
spider_interfaces__srv__LocService_Request__are_equal(const spider_interfaces__srv__LocService_Request * lhs, const spider_interfaces__srv__LocService_Request * rhs)
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
  // delta_angle
  if (lhs->delta_angle != rhs->delta_angle) {
    return false;
  }
  return true;
}

bool
spider_interfaces__srv__LocService_Request__copy(
  const spider_interfaces__srv__LocService_Request * input,
  spider_interfaces__srv__LocService_Request * output)
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
  // delta_angle
  output->delta_angle = input->delta_angle;
  return true;
}

spider_interfaces__srv__LocService_Request *
spider_interfaces__srv__LocService_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_interfaces__srv__LocService_Request * msg = (spider_interfaces__srv__LocService_Request *)allocator.allocate(sizeof(spider_interfaces__srv__LocService_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(spider_interfaces__srv__LocService_Request));
  bool success = spider_interfaces__srv__LocService_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
spider_interfaces__srv__LocService_Request__destroy(spider_interfaces__srv__LocService_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    spider_interfaces__srv__LocService_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
spider_interfaces__srv__LocService_Request__Sequence__init(spider_interfaces__srv__LocService_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_interfaces__srv__LocService_Request * data = NULL;

  if (size) {
    data = (spider_interfaces__srv__LocService_Request *)allocator.zero_allocate(size, sizeof(spider_interfaces__srv__LocService_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = spider_interfaces__srv__LocService_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        spider_interfaces__srv__LocService_Request__fini(&data[i - 1]);
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
spider_interfaces__srv__LocService_Request__Sequence__fini(spider_interfaces__srv__LocService_Request__Sequence * array)
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
      spider_interfaces__srv__LocService_Request__fini(&array->data[i]);
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

spider_interfaces__srv__LocService_Request__Sequence *
spider_interfaces__srv__LocService_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_interfaces__srv__LocService_Request__Sequence * array = (spider_interfaces__srv__LocService_Request__Sequence *)allocator.allocate(sizeof(spider_interfaces__srv__LocService_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = spider_interfaces__srv__LocService_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
spider_interfaces__srv__LocService_Request__Sequence__destroy(spider_interfaces__srv__LocService_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    spider_interfaces__srv__LocService_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
spider_interfaces__srv__LocService_Request__Sequence__are_equal(const spider_interfaces__srv__LocService_Request__Sequence * lhs, const spider_interfaces__srv__LocService_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!spider_interfaces__srv__LocService_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
spider_interfaces__srv__LocService_Request__Sequence__copy(
  const spider_interfaces__srv__LocService_Request__Sequence * input,
  spider_interfaces__srv__LocService_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(spider_interfaces__srv__LocService_Request);
    spider_interfaces__srv__LocService_Request * data =
      (spider_interfaces__srv__LocService_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!spider_interfaces__srv__LocService_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          spider_interfaces__srv__LocService_Request__fini(&data[i]);
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
    if (!spider_interfaces__srv__LocService_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `status`
// already included above
// #include "std_msgs/msg/detail/string__functions.h"

bool
spider_interfaces__srv__LocService_Response__init(spider_interfaces__srv__LocService_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  if (!std_msgs__msg__String__init(&msg->status)) {
    spider_interfaces__srv__LocService_Response__fini(msg);
    return false;
  }
  return true;
}

void
spider_interfaces__srv__LocService_Response__fini(spider_interfaces__srv__LocService_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  std_msgs__msg__String__fini(&msg->status);
}

bool
spider_interfaces__srv__LocService_Response__are_equal(const spider_interfaces__srv__LocService_Response * lhs, const spider_interfaces__srv__LocService_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (!std_msgs__msg__String__are_equal(
      &(lhs->status), &(rhs->status)))
  {
    return false;
  }
  return true;
}

bool
spider_interfaces__srv__LocService_Response__copy(
  const spider_interfaces__srv__LocService_Response * input,
  spider_interfaces__srv__LocService_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  if (!std_msgs__msg__String__copy(
      &(input->status), &(output->status)))
  {
    return false;
  }
  return true;
}

spider_interfaces__srv__LocService_Response *
spider_interfaces__srv__LocService_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_interfaces__srv__LocService_Response * msg = (spider_interfaces__srv__LocService_Response *)allocator.allocate(sizeof(spider_interfaces__srv__LocService_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(spider_interfaces__srv__LocService_Response));
  bool success = spider_interfaces__srv__LocService_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
spider_interfaces__srv__LocService_Response__destroy(spider_interfaces__srv__LocService_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    spider_interfaces__srv__LocService_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
spider_interfaces__srv__LocService_Response__Sequence__init(spider_interfaces__srv__LocService_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_interfaces__srv__LocService_Response * data = NULL;

  if (size) {
    data = (spider_interfaces__srv__LocService_Response *)allocator.zero_allocate(size, sizeof(spider_interfaces__srv__LocService_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = spider_interfaces__srv__LocService_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        spider_interfaces__srv__LocService_Response__fini(&data[i - 1]);
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
spider_interfaces__srv__LocService_Response__Sequence__fini(spider_interfaces__srv__LocService_Response__Sequence * array)
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
      spider_interfaces__srv__LocService_Response__fini(&array->data[i]);
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

spider_interfaces__srv__LocService_Response__Sequence *
spider_interfaces__srv__LocService_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_interfaces__srv__LocService_Response__Sequence * array = (spider_interfaces__srv__LocService_Response__Sequence *)allocator.allocate(sizeof(spider_interfaces__srv__LocService_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = spider_interfaces__srv__LocService_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
spider_interfaces__srv__LocService_Response__Sequence__destroy(spider_interfaces__srv__LocService_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    spider_interfaces__srv__LocService_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
spider_interfaces__srv__LocService_Response__Sequence__are_equal(const spider_interfaces__srv__LocService_Response__Sequence * lhs, const spider_interfaces__srv__LocService_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!spider_interfaces__srv__LocService_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
spider_interfaces__srv__LocService_Response__Sequence__copy(
  const spider_interfaces__srv__LocService_Response__Sequence * input,
  spider_interfaces__srv__LocService_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(spider_interfaces__srv__LocService_Response);
    spider_interfaces__srv__LocService_Response * data =
      (spider_interfaces__srv__LocService_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!spider_interfaces__srv__LocService_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          spider_interfaces__srv__LocService_Response__fini(&data[i]);
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
    if (!spider_interfaces__srv__LocService_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
