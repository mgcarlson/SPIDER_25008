// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from depthai_ros_msgs:msg/SpatialDetection.idl
// generated code does not contain a copyright notice

#ifndef DEPTHAI_ROS_MSGS__MSG__DETAIL__SPATIAL_DETECTION__TRAITS_HPP_
#define DEPTHAI_ROS_MSGS__MSG__DETAIL__SPATIAL_DETECTION__TRAITS_HPP_

#include "depthai_ros_msgs/msg/detail/spatial_detection__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'bbox'
#include "vision_msgs/msg/detail/bounding_box2_d__traits.hpp"
// Member 'position'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<depthai_ros_msgs::msg::SpatialDetection>()
{
  return "depthai_ros_msgs::msg::SpatialDetection";
}

template<>
inline const char * name<depthai_ros_msgs::msg::SpatialDetection>()
{
  return "depthai_ros_msgs/msg/SpatialDetection";
}

template<>
struct has_fixed_size<depthai_ros_msgs::msg::SpatialDetection>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<depthai_ros_msgs::msg::SpatialDetection>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<depthai_ros_msgs::msg::SpatialDetection>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DEPTHAI_ROS_MSGS__MSG__DETAIL__SPATIAL_DETECTION__TRAITS_HPP_
