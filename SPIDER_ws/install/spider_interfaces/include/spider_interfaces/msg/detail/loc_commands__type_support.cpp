// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from spider_interfaces:msg/LocCommands.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "spider_interfaces/msg/detail/loc_commands__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace spider_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void LocCommands_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) spider_interfaces::msg::LocCommands(_init);
}

void LocCommands_fini_function(void * message_memory)
{
  auto typed_message = static_cast<spider_interfaces::msg::LocCommands *>(message_memory);
  typed_message->~LocCommands();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember LocCommands_message_member_array[2] = {
  {
    "move_type",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::String>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(spider_interfaces::msg::LocCommands, move_type),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "move_amount",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(spider_interfaces::msg::LocCommands, move_amount),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers LocCommands_message_members = {
  "spider_interfaces::msg",  // message namespace
  "LocCommands",  // message name
  2,  // number of fields
  sizeof(spider_interfaces::msg::LocCommands),
  LocCommands_message_member_array,  // message members
  LocCommands_init_function,  // function to initialize message memory (memory has to be allocated)
  LocCommands_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t LocCommands_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &LocCommands_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace spider_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<spider_interfaces::msg::LocCommands>()
{
  return &::spider_interfaces::msg::rosidl_typesupport_introspection_cpp::LocCommands_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, spider_interfaces, msg, LocCommands)() {
  return &::spider_interfaces::msg::rosidl_typesupport_introspection_cpp::LocCommands_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
