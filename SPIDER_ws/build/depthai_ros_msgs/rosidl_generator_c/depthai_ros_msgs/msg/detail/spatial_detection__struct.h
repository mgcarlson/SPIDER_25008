// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from depthai_ros_msgs:msg/SpatialDetection.idl
// generated code does not contain a copyright notice

#ifndef DEPTHAI_ROS_MSGS__MSG__DETAIL__SPATIAL_DETECTION__STRUCT_H_
#define DEPTHAI_ROS_MSGS__MSG__DETAIL__SPATIAL_DETECTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'results'
#include "vision_msgs/msg/detail/object_hypothesis__struct.h"
// Member 'bbox'
#include "vision_msgs/msg/detail/bounding_box2_d__struct.h"
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'tracking_id'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/SpatialDetection in the package depthai_ros_msgs.
typedef struct depthai_ros_msgs__msg__SpatialDetection
{
  vision_msgs__msg__ObjectHypothesis__Sequence results;
  vision_msgs__msg__BoundingBox2D bbox;
  geometry_msgs__msg__Point position;
  bool is_tracking;
  rosidl_runtime_c__String tracking_id;
} depthai_ros_msgs__msg__SpatialDetection;

// Struct for a sequence of depthai_ros_msgs__msg__SpatialDetection.
typedef struct depthai_ros_msgs__msg__SpatialDetection__Sequence
{
  depthai_ros_msgs__msg__SpatialDetection * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} depthai_ros_msgs__msg__SpatialDetection__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DEPTHAI_ROS_MSGS__MSG__DETAIL__SPATIAL_DETECTION__STRUCT_H_
