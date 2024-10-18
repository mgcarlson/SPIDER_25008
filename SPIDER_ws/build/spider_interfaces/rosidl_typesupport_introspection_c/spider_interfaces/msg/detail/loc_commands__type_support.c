// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from spider_interfaces:msg/LocCommands.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "spider_interfaces/msg/detail/loc_commands__rosidl_typesupport_introspection_c.h"
#include "spider_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "spider_interfaces/msg/detail/loc_commands__functions.h"
#include "spider_interfaces/msg/detail/loc_commands__struct.h"


// Include directives for member types
// Member `move_type`
#include "std_msgs/msg/string.h"
// Member `move_type`
#include "std_msgs/msg/detail/string__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void LocCommands__rosidl_typesupport_introspection_c__LocCommands_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  spider_interfaces__msg__LocCommands__init(message_memory);
}

void LocCommands__rosidl_typesupport_introspection_c__LocCommands_fini_function(void * message_memory)
{
  spider_interfaces__msg__LocCommands__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember LocCommands__rosidl_typesupport_introspection_c__LocCommands_message_member_array[2] = {
  {
    "move_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(spider_interfaces__msg__LocCommands, move_type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "move_amount",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(spider_interfaces__msg__LocCommands, move_amount),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers LocCommands__rosidl_typesupport_introspection_c__LocCommands_message_members = {
  "spider_interfaces__msg",  // message namespace
  "LocCommands",  // message name
  2,  // number of fields
  sizeof(spider_interfaces__msg__LocCommands),
  LocCommands__rosidl_typesupport_introspection_c__LocCommands_message_member_array,  // message members
  LocCommands__rosidl_typesupport_introspection_c__LocCommands_init_function,  // function to initialize message memory (memory has to be allocated)
  LocCommands__rosidl_typesupport_introspection_c__LocCommands_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t LocCommands__rosidl_typesupport_introspection_c__LocCommands_message_type_support_handle = {
  0,
  &LocCommands__rosidl_typesupport_introspection_c__LocCommands_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_spider_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, spider_interfaces, msg, LocCommands)() {
  LocCommands__rosidl_typesupport_introspection_c__LocCommands_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, String)();
  if (!LocCommands__rosidl_typesupport_introspection_c__LocCommands_message_type_support_handle.typesupport_identifier) {
    LocCommands__rosidl_typesupport_introspection_c__LocCommands_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &LocCommands__rosidl_typesupport_introspection_c__LocCommands_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
