// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from depthai_ros_msgs:msg/TrackDetection2D.idl
// generated code does not contain a copyright notice

#ifndef DEPTHAI_ROS_MSGS__MSG__DETAIL__TRACK_DETECTION2_D__STRUCT_H_
#define DEPTHAI_ROS_MSGS__MSG__DETAIL__TRACK_DETECTION2_D__STRUCT_H_

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
#include "vision_msgs/msg/detail/object_hypothesis_with_pose__struct.h"
// Member 'bbox'
#include "vision_msgs/msg/detail/bounding_box2_d__struct.h"
// Member 'tracking_id'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/TrackDetection2D in the package depthai_ros_msgs.
typedef struct depthai_ros_msgs__msg__TrackDetection2D
{
  vision_msgs__msg__ObjectHypothesisWithPose__Sequence results;
  vision_msgs__msg__BoundingBox2D bbox;
  bool is_tracking;
  rosidl_runtime_c__String tracking_id;
  int32_t tracking_age;
  int32_t tracking_status;
} depthai_ros_msgs__msg__TrackDetection2D;

// Struct for a sequence of depthai_ros_msgs__msg__TrackDetection2D.
typedef struct depthai_ros_msgs__msg__TrackDetection2D__Sequence
{
  depthai_ros_msgs__msg__TrackDetection2D * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} depthai_ros_msgs__msg__TrackDetection2D__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DEPTHAI_ROS_MSGS__MSG__DETAIL__TRACK_DETECTION2_D__STRUCT_H_
