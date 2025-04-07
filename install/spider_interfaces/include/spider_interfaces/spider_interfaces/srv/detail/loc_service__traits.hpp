// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from spider_interfaces:srv/LocService.idl
// generated code does not contain a copyright notice

#ifndef SPIDER_INTERFACES__SRV__DETAIL__LOC_SERVICE__TRAITS_HPP_
#define SPIDER_INTERFACES__SRV__DETAIL__LOC_SERVICE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "spider_interfaces/srv/detail/loc_service__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'move_type'
#include "std_msgs/msg/detail/string__traits.hpp"

namespace spider_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const LocService_Request & msg,
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
    out << ", ";
  }

  // member: delta_angle
  {
    out << "delta_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.delta_angle, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LocService_Request & msg,
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

  // member: delta_angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "delta_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.delta_angle, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LocService_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace spider_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use spider_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const spider_interfaces::srv::LocService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  spider_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use spider_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const spider_interfaces::srv::LocService_Request & msg)
{
  return spider_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<spider_interfaces::srv::LocService_Request>()
{
  return "spider_interfaces::srv::LocService_Request";
}

template<>
inline const char * name<spider_interfaces::srv::LocService_Request>()
{
  return "spider_interfaces/srv/LocService_Request";
}

template<>
struct has_fixed_size<spider_interfaces::srv::LocService_Request>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::String>::value> {};

template<>
struct has_bounded_size<spider_interfaces::srv::LocService_Request>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::String>::value> {};

template<>
struct is_message<spider_interfaces::srv::LocService_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'status'
// already included above
// #include "std_msgs/msg/detail/string__traits.hpp"

namespace spider_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const LocService_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    to_flow_style_yaml(msg.status, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LocService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status:\n";
    to_block_style_yaml(msg.status, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LocService_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace spider_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use spider_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const spider_interfaces::srv::LocService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  spider_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use spider_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const spider_interfaces::srv::LocService_Response & msg)
{
  return spider_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<spider_interfaces::srv::LocService_Response>()
{
  return "spider_interfaces::srv::LocService_Response";
}

template<>
inline const char * name<spider_interfaces::srv::LocService_Response>()
{
  return "spider_interfaces/srv/LocService_Response";
}

template<>
struct has_fixed_size<spider_interfaces::srv::LocService_Response>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::String>::value> {};

template<>
struct has_bounded_size<spider_interfaces::srv::LocService_Response>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::String>::value> {};

template<>
struct is_message<spider_interfaces::srv::LocService_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<spider_interfaces::srv::LocService>()
{
  return "spider_interfaces::srv::LocService";
}

template<>
inline const char * name<spider_interfaces::srv::LocService>()
{
  return "spider_interfaces/srv/LocService";
}

template<>
struct has_fixed_size<spider_interfaces::srv::LocService>
  : std::integral_constant<
    bool,
    has_fixed_size<spider_interfaces::srv::LocService_Request>::value &&
    has_fixed_size<spider_interfaces::srv::LocService_Response>::value
  >
{
};

template<>
struct has_bounded_size<spider_interfaces::srv::LocService>
  : std::integral_constant<
    bool,
    has_bounded_size<spider_interfaces::srv::LocService_Request>::value &&
    has_bounded_size<spider_interfaces::srv::LocService_Response>::value
  >
{
};

template<>
struct is_service<spider_interfaces::srv::LocService>
  : std::true_type
{
};

template<>
struct is_service_request<spider_interfaces::srv::LocService_Request>
  : std::true_type
{
};

template<>
struct is_service_response<spider_interfaces::srv::LocService_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SPIDER_INTERFACES__SRV__DETAIL__LOC_SERVICE__TRAITS_HPP_
