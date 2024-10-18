// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from spider_interfaces:msg/LocCommands.idl
// generated code does not contain a copyright notice

#ifndef SPIDER_INTERFACES__MSG__DETAIL__LOC_COMMANDS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define SPIDER_INTERFACES__MSG__DETAIL__LOC_COMMANDS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "spider_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "spider_interfaces/msg/detail/loc_commands__struct.hpp"

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

#include "fastcdr/Cdr.h"

namespace spider_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_spider_interfaces
cdr_serialize(
  const spider_interfaces::msg::LocCommands & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_spider_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  spider_interfaces::msg::LocCommands & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_spider_interfaces
get_serialized_size(
  const spider_interfaces::msg::LocCommands & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_spider_interfaces
max_serialized_size_LocCommands(
  bool & full_bounded,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace spider_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_spider_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, spider_interfaces, msg, LocCommands)();

#ifdef __cplusplus
}
#endif

#endif  // SPIDER_INTERFACES__MSG__DETAIL__LOC_COMMANDS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
