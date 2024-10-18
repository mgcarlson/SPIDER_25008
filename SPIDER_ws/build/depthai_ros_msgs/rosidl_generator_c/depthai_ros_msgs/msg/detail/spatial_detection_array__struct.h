// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from depthai_ros_msgs:msg/SpatialDetectionArray.idl
// generated code does not contain a copyright notice

#ifndef DEPTHAI_ROS_MSGS__MSG__DETAIL__SPATIAL_DETECTION_ARRAY__STRUCT_H_
#define DEPTHAI_ROS_MSGS__MSG__DETAIL__SPATIAL_DETECTION_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'detections'
#include "depthai_ros_msgs/msg/detail/spatial_detection__struct.h"

// Struct defined in msg/SpatialDetectionArray in the package depthai_ros_msgs.
typedef struct depthai_ros_msgs__msg__SpatialDetectionArray
{
  std_msgs__msg__Header header;
  depthai_ros_msgs__msg__SpatialDetection__Sequence detections;
} depthai_ros_msgs__msg__SpatialDetectionArray;

// Struct for a sequence of depthai_ros_msgs__msg__SpatialDetectionArray.
typedef struct depthai_ros_msgs__msg__SpatialDetectionArray__Sequence
{
  depthai_ros_msgs__msg__SpatialDetectionArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} depthai_ros_msgs__msg__SpatialDetectionArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DEPTHAI_ROS_MSGS__MSG__DETAIL__SPATIAL_DETECTION_ARRAY__STRUCT_H_
