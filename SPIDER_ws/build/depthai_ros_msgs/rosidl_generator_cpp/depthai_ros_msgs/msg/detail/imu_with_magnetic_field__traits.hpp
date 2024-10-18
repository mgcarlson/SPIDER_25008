// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from depthai_ros_msgs:msg/ImuWithMagneticField.idl
// generated code does not contain a copyright notice

#ifndef DEPTHAI_ROS_MSGS__MSG__DETAIL__IMU_WITH_MAGNETIC_FIELD__TRAITS_HPP_
#define DEPTHAI_ROS_MSGS__MSG__DETAIL__IMU_WITH_MAGNETIC_FIELD__TRAITS_HPP_

#include "depthai_ros_msgs/msg/detail/imu_with_magnetic_field__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'imu'
#include "sensor_msgs/msg/detail/imu__traits.hpp"
// Member 'field'
#include "sensor_msgs/msg/detail/magnetic_field__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<depthai_ros_msgs::msg::ImuWithMagneticField>()
{
  return "depthai_ros_msgs::msg::ImuWithMagneticField";
}

template<>
inline const char * name<depthai_ros_msgs::msg::ImuWithMagneticField>()
{
  return "depthai_ros_msgs/msg/ImuWithMagneticField";
}

template<>
struct has_fixed_size<depthai_ros_msgs::msg::ImuWithMagneticField>
  : std::integral_constant<bool, has_fixed_size<sensor_msgs::msg::Imu>::value && has_fixed_size<sensor_msgs::msg::MagneticField>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<depthai_ros_msgs::msg::ImuWithMagneticField>
  : std::integral_constant<bool, has_bounded_size<sensor_msgs::msg::Imu>::value && has_bounded_size<sensor_msgs::msg::MagneticField>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<depthai_ros_msgs::msg::ImuWithMagneticField>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DEPTHAI_ROS_MSGS__MSG__DETAIL__IMU_WITH_MAGNETIC_FIELD__TRAITS_HPP_
