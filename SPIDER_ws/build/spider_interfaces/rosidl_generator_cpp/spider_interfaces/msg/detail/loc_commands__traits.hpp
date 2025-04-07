// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from spider_interfaces:msg/LocCommands.idl
// generated code does not contain a copyright notice

#ifndef SPIDER_INTERFACES__MSG__DETAIL__LOC_COMMANDS__TRAITS_HPP_
#define SPIDER_INTERFACES__MSG__DETAIL__LOC_COMMANDS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "spider_interfaces/msg/detail/loc_commands__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'move_type'
#include "std_msgs/msg/detail/string__traits.hpp"

namespace spider_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const LocCommands & msg,
  std::ostream & out)
{
  out << "{";
  // member: move_type
  {
    out << "move_type: ";
    to_flow_style_yaml(msg.move_type, out);
    out << ", ";
  }

  // member: move_amount
  {
    out << "move_amount: ";
    rosidl_generator_traits::value_to_yaml(msg.move_amount, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LocCommands & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: move_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "move_type:\n";
    to_block_style_yaml(msg.move_type, out, indentation + 2);
  }

  // member: move_amount
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "move_amount: ";
    rosidl_generator_traits::value_to_yaml(msg.move_amount, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LocCommands & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace spider_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use spider_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const spider_interfaces::msg::LocCommands & msg,
  std::ostream & out, size_t indentation = 0)
{
  spider_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use spider_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const spider_interfaces::msg::LocCommands & msg)
{
  return spider_interfaces::msg::to_yaml(msg);
}

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
