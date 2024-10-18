// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from depthai_ros_msgs:msg/AutoFocusCtrl.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "depthai_ros_msgs/msg/detail/auto_focus_ctrl__rosidl_typesupport_introspection_c.h"
#include "depthai_ros_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "depthai_ros_msgs/msg/detail/auto_focus_ctrl__functions.h"
#include "depthai_ros_msgs/msg/detail/auto_focus_ctrl__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void AutoFocusCtrl__rosidl_typesupport_introspection_c__AutoFocusCtrl_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  depthai_ros_msgs__msg__AutoFocusCtrl__init(message_memory);
}

void AutoFocusCtrl__rosidl_typesupport_introspection_c__AutoFocusCtrl_fini_function(void * message_memory)
{
  depthai_ros_msgs__msg__AutoFocusCtrl__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember AutoFocusCtrl__rosidl_typesupport_introspection_c__AutoFocusCtrl_message_member_array[2] = {
  {
    "auto_focus_mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(depthai_ros_msgs__msg__AutoFocusCtrl, auto_focus_mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "trigger_auto_focus",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(depthai_ros_msgs__msg__AutoFocusCtrl, trigger_auto_focus),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers AutoFocusCtrl__rosidl_typesupport_introspection_c__AutoFocusCtrl_message_members = {
  "depthai_ros_msgs__msg",  // message namespace
  "AutoFocusCtrl",  // message name
  2,  // number of fields
  sizeof(depthai_ros_msgs__msg__AutoFocusCtrl),
  AutoFocusCtrl__rosidl_typesupport_introspection_c__AutoFocusCtrl_message_member_array,  // message members
  AutoFocusCtrl__rosidl_typesupport_introspection_c__AutoFocusCtrl_init_function,  // function to initialize message memory (memory has to be allocated)
  AutoFocusCtrl__rosidl_typesupport_introspection_c__AutoFocusCtrl_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t AutoFocusCtrl__rosidl_typesupport_introspection_c__AutoFocusCtrl_message_type_support_handle = {
  0,
  &AutoFocusCtrl__rosidl_typesupport_introspection_c__AutoFocusCtrl_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_depthai_ros_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, depthai_ros_msgs, msg, AutoFocusCtrl)() {
  if (!AutoFocusCtrl__rosidl_typesupport_introspection_c__AutoFocusCtrl_message_type_support_handle.typesupport_identifier) {
    AutoFocusCtrl__rosidl_typesupport_introspection_c__AutoFocusCtrl_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &AutoFocusCtrl__rosidl_typesupport_introspection_c__AutoFocusCtrl_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
