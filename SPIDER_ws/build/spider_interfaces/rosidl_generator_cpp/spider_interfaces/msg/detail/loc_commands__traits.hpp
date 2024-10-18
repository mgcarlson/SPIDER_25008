// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from spider_interfaces:msg/LocCommands.idl
// generated code does not contain a copyright notice

#ifndef SPIDER_INTERFACES__MSG__DETAIL__LOC_COMMANDS__TRAITS_HPP_
#define SPIDER_INTERFACES__MSG__DETAIL__LOC_COMMANDS__TRAITS_HPP_

#include "spider_interfaces/msg/detail/loc_commands__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'move_type'
#include "std_msgs/msg/detail/string__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<spider_interfaces::msg::LocCommands>()
{
  return "spider_interfaces::msg::LocCommands";
}

template<>
inline const char * name<spider_interfaces::msg::LocCommands>()
{
  return "spider_interfaces/msg/LocCommands";
}

template<>
struct has_fixed_size<spider_interfaces::msg::LocCommands>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::String>::value> {};

template<>
struct has_bounded_size<spider_interfaces::msg::LocCommands>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::String>::value> {};

template<>
struct is_message<spider_interfaces::msg::LocCommands>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SPIDER_INTERFACES__MSG__DETAIL__LOC_COMMANDS__TRAITS_HPP_
