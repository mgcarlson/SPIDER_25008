// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from spider_interfaces:msg/LocCommands.idl
// generated code does not contain a copyright notice

#ifndef SPIDER_INTERFACES__MSG__DETAIL__LOC_COMMANDS__STRUCT_H_
#define SPIDER_INTERFACES__MSG__DETAIL__LOC_COMMANDS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'move_type'
#include "std_msgs/msg/detail/string__struct.h"

// Struct defined in msg/LocCommands in the package spider_interfaces.
typedef struct spider_interfaces__msg__LocCommands
{
  std_msgs__msg__String move_type;
  int64_t move_amount;
} spider_interfaces__msg__LocCommands;

// Struct for a sequence of spider_interfaces__msg__LocCommands.
typedef struct spider_interfaces__msg__LocCommands__Sequence
{
  spider_interfaces__msg__LocCommands * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} spider_interfaces__msg__LocCommands__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SPIDER_INTERFACES__MSG__DETAIL__LOC_COMMANDS__STRUCT_H_
