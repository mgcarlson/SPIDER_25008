// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from depthai_ros_msgs:msg/AutoFocusCtrl.idl
// generated code does not contain a copyright notice

#ifndef DEPTHAI_ROS_MSGS__MSG__DETAIL__AUTO_FOCUS_CTRL__TRAITS_HPP_
#define DEPTHAI_ROS_MSGS__MSG__DETAIL__AUTO_FOCUS_CTRL__TRAITS_HPP_

#include "depthai_ros_msgs/msg/detail/auto_focus_ctrl__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<depthai_ros_msgs::msg::AutoFocusCtrl>()
{
  return "depthai_ros_msgs::msg::AutoFocusCtrl";
}

template<>
inline const char * name<depthai_ros_msgs::msg::AutoFocusCtrl>()
{
  return "depthai_ros_msgs/msg/AutoFocusCtrl";
}

template<>
struct has_fixed_size<depthai_ros_msgs::msg::AutoFocusCtrl>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<depthai_ros_msgs::msg::AutoFocusCtrl>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<depthai_ros_msgs::msg::AutoFocusCtrl>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DEPTHAI_ROS_MSGS__MSG__DETAIL__AUTO_FOCUS_CTRL__TRAITS_HPP_
