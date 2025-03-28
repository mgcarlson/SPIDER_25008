// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from depthai_ros_msgs:msg/AutoFocusCtrl.idl
// generated code does not contain a copyright notice
#include "depthai_ros_msgs/msg/detail/auto_focus_ctrl__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "depthai_ros_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "depthai_ros_msgs/msg/detail/auto_focus_ctrl__struct.h"
#include "depthai_ros_msgs/msg/detail/auto_focus_ctrl__functions.h"
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


// forward declare type support functions


using _AutoFocusCtrl__ros_msg_type = depthai_ros_msgs__msg__AutoFocusCtrl;

static bool _AutoFocusCtrl__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _AutoFocusCtrl__ros_msg_type * ros_message = static_cast<const _AutoFocusCtrl__ros_msg_type *>(untyped_ros_message);
  // Field name: auto_focus_mode
  {
    cdr << ros_message->auto_focus_mode;
  }

  // Field name: trigger_auto_focus
  {
    cdr << (ros_message->trigger_auto_focus ? true : false);
  }

  return true;
}

static bool _AutoFocusCtrl__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _AutoFocusCtrl__ros_msg_type * ros_message = static_cast<_AutoFocusCtrl__ros_msg_type *>(untyped_ros_message);
  // Field name: auto_focus_mode
  {
    cdr >> ros_message->auto_focus_mode;
  }

  // Field name: trigger_auto_focus
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->trigger_auto_focus = tmp ? true : false;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_depthai_ros_msgs
size_t get_serialized_size_depthai_ros_msgs__msg__AutoFocusCtrl(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _AutoFocusCtrl__ros_msg_type * ros_message = static_cast<const _AutoFocusCtrl__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name auto_focus_mode
  {
    size_t item_size = sizeof(ros_message->auto_focus_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name trigger_auto_focus
  {
    size_t item_size = sizeof(ros_message->trigger_auto_focus);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _AutoFocusCtrl__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_depthai_ros_msgs__msg__AutoFocusCtrl(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_depthai_ros_msgs
size_t max_serialized_size_depthai_ros_msgs__msg__AutoFocusCtrl(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: auto_focus_mode
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: trigger_auto_focus
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _AutoFocusCtrl__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_depthai_ros_msgs__msg__AutoFocusCtrl(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_AutoFocusCtrl = {
  "depthai_ros_msgs::msg",
  "AutoFocusCtrl",
  _AutoFocusCtrl__cdr_serialize,
  _AutoFocusCtrl__cdr_deserialize,
  _AutoFocusCtrl__get_serialized_size,
  _AutoFocusCtrl__max_serialized_size
};

static rosidl_message_type_support_t _AutoFocusCtrl__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_AutoFocusCtrl,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, depthai_ros_msgs, msg, AutoFocusCtrl)() {
  return &_AutoFocusCtrl__type_support;
}

#if defined(__cplusplus)
}
#endif
