// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from spider_interfaces:msg/LocCommands.idl
// generated code does not contain a copyright notice
#include "spider_interfaces/msg/detail/loc_commands__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "spider_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "spider_interfaces/msg/detail/loc_commands__struct.h"
#include "spider_interfaces/msg/detail/loc_commands__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "std_msgs/msg/detail/string__functions.h"  // move_type

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_spider_interfaces
size_t get_serialized_size_std_msgs__msg__String(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_spider_interfaces
size_t max_serialized_size_std_msgs__msg__String(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_spider_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, String)();


using _LocCommands__ros_msg_type = spider_interfaces__msg__LocCommands;

static bool _LocCommands__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _LocCommands__ros_msg_type * ros_message = static_cast<const _LocCommands__ros_msg_type *>(untyped_ros_message);
  // Field name: move_type
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, String
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->move_type, cdr))
    {
      return false;
    }
  }

  // Field name: move_amount
  {
    cdr << ros_message->move_amount;
  }

  return true;
}

static bool _LocCommands__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _LocCommands__ros_msg_type * ros_message = static_cast<_LocCommands__ros_msg_type *>(untyped_ros_message);
  // Field name: move_type
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, String
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->move_type))
    {
      return false;
    }
  }

  // Field name: move_amount
  {
    cdr >> ros_message->move_amount;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_spider_interfaces
size_t get_serialized_size_spider_interfaces__msg__LocCommands(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _LocCommands__ros_msg_type * ros_message = static_cast<const _LocCommands__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name move_type

  current_alignment += get_serialized_size_std_msgs__msg__String(
    &(ros_message->move_type), current_alignment);
  // field.name move_amount
  {
    size_t item_size = sizeof(ros_message->move_amount);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _LocCommands__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_spider_interfaces__msg__LocCommands(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_spider_interfaces
size_t max_serialized_size_spider_interfaces__msg__LocCommands(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: move_type
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_std_msgs__msg__String(
        full_bounded, current_alignment);
    }
  }
  // member: move_amount
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _LocCommands__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_spider_interfaces__msg__LocCommands(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_LocCommands = {
  "spider_interfaces::msg",
  "LocCommands",
  _LocCommands__cdr_serialize,
  _LocCommands__cdr_deserialize,
  _LocCommands__get_serialized_size,
  _LocCommands__max_serialized_size
};

static rosidl_message_type_support_t _LocCommands__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_LocCommands,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, spider_interfaces, msg, LocCommands)() {
  return &_LocCommands__type_support;
}

#if defined(__cplusplus)
}
#endif
