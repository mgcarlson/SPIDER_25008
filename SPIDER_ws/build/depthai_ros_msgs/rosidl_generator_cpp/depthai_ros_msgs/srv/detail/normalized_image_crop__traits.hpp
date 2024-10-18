// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from depthai_ros_msgs:srv/NormalizedImageCrop.idl
// generated code does not contain a copyright notice

#ifndef DEPTHAI_ROS_MSGS__SRV__DETAIL__NORMALIZED_IMAGE_CROP__TRAITS_HPP_
#define DEPTHAI_ROS_MSGS__SRV__DETAIL__NORMALIZED_IMAGE_CROP__TRAITS_HPP_

#include "depthai_ros_msgs/srv/detail/normalized_image_crop__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'top_left'
// Member 'bottom_right'
#include "geometry_msgs/msg/detail/pose2_d__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<depthai_ros_msgs::srv::NormalizedImageCrop_Request>()
{
  return "depthai_ros_msgs::srv::NormalizedImageCrop_Request";
}

template<>
inline const char * name<depthai_ros_msgs::srv::NormalizedImageCrop_Request>()
{
  return "depthai_ros_msgs/srv/NormalizedImageCrop_Request";
}

template<>
struct has_fixed_size<depthai_ros_msgs::srv::NormalizedImageCrop_Request>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Pose2D>::value> {};

template<>
struct has_bounded_size<depthai_ros_msgs::srv::NormalizedImageCrop_Request>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Pose2D>::value> {};

template<>
struct is_message<depthai_ros_msgs::srv::NormalizedImageCrop_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<depthai_ros_msgs::srv::NormalizedImageCrop_Response>()
{
  return "depthai_ros_msgs::srv::NormalizedImageCrop_Response";
}

template<>
inline const char * name<depthai_ros_msgs::srv::NormalizedImageCrop_Response>()
{
  return "depthai_ros_msgs/srv/NormalizedImageCrop_Response";
}

template<>
struct has_fixed_size<depthai_ros_msgs::srv::NormalizedImageCrop_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<depthai_ros_msgs::srv::NormalizedImageCrop_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<depthai_ros_msgs::srv::NormalizedImageCrop_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<depthai_ros_msgs::srv::NormalizedImageCrop>()
{
  return "depthai_ros_msgs::srv::NormalizedImageCrop";
}

template<>
inline const char * name<depthai_ros_msgs::srv::NormalizedImageCrop>()
{
  return "depthai_ros_msgs/srv/NormalizedImageCrop";
}

template<>
struct has_fixed_size<depthai_ros_msgs::srv::NormalizedImageCrop>
  : std::integral_constant<
    bool,
    has_fixed_size<depthai_ros_msgs::srv::NormalizedImageCrop_Request>::value &&
    has_fixed_size<depthai_ros_msgs::srv::NormalizedImageCrop_Response>::value
  >
{
};

template<>
struct has_bounded_size<depthai_ros_msgs::srv::NormalizedImageCrop>
  : std::integral_constant<
    bool,
    has_bounded_size<depthai_ros_msgs::srv::NormalizedImageCrop_Request>::value &&
    has_bounded_size<depthai_ros_msgs::srv::NormalizedImageCrop_Response>::value
  >
{
};

template<>
struct is_service<depthai_ros_msgs::srv::NormalizedImageCrop>
  : std::true_type
{
};

template<>
struct is_service_request<depthai_ros_msgs::srv::NormalizedImageCrop_Request>
  : std::true_type
{
};

template<>
struct is_service_response<depthai_ros_msgs::srv::NormalizedImageCrop_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DEPTHAI_ROS_MSGS__SRV__DETAIL__NORMALIZED_IMAGE_CROP__TRAITS_HPP_
