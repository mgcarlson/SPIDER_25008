// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from spider_interfaces:srv/LocService.idl
// generated code does not contain a copyright notice

#ifndef SPIDER_INTERFACES__SRV__DETAIL__LOC_SERVICE__TRAITS_HPP_
#define SPIDER_INTERFACES__SRV__DETAIL__LOC_SERVICE__TRAITS_HPP_

#include "spider_interfaces/srv/detail/loc_service__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'move_type'
#include "std_msgs/msg/detail/string__traits.hpp"

namespace rosidl_generator_traits
{

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

namespace rosidl_generator_traits
{

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
