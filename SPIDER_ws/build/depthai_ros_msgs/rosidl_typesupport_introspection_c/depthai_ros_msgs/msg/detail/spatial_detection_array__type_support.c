// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from depthai_ros_msgs:msg/SpatialDetectionArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "depthai_ros_msgs/msg/detail/spatial_detection_array__rosidl_typesupport_introspection_c.h"
#include "depthai_ros_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "depthai_ros_msgs/msg/detail/spatial_detection_array__functions.h"
#include "depthai_ros_msgs/msg/detail/spatial_detection_array__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `detections`
#include "depthai_ros_msgs/msg/spatial_detection.h"
// Member `detections`
#include "depthai_ros_msgs/msg/detail/spatial_detection__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void SpatialDetectionArray__rosidl_typesupport_introspection_c__SpatialDetectionArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  depthai_ros_msgs__msg__SpatialDetectionArray__init(message_memory);
}

void SpatialDetectionArray__rosidl_typesupport_introspection_c__SpatialDetectionArray_fini_function(void * message_memory)
{
  depthai_ros_msgs__msg__SpatialDetectionArray__fini(message_memory);
}

size_t SpatialDetectionArray__rosidl_typesupport_introspection_c__size_function__SpatialDetection__detections(
  const void * untyped_member)
{
  const depthai_ros_msgs__msg__SpatialDetection__Sequence * member =
    (const depthai_ros_msgs__msg__SpatialDetection__Sequence *)(untyped_member);
  return member->size;
}

const void * SpatialDetectionArray__rosidl_typesupport_introspection_c__get_const_function__SpatialDetection__detections(
  const void * untyped_member, size_t index)
{
  const depthai_ros_msgs__msg__SpatialDetection__Sequence * member =
    (const depthai_ros_msgs__msg__SpatialDetection__Sequence *)(untyped_member);
  return &member->data[index];
}

void * SpatialDetectionArray__rosidl_typesupport_introspection_c__get_function__SpatialDetection__detections(
  void * untyped_member, size_t index)
{
  depthai_ros_msgs__msg__SpatialDetection__Sequence * member =
    (depthai_ros_msgs__msg__SpatialDetection__Sequence *)(untyped_member);
  return &member->data[index];
}

bool SpatialDetectionArray__rosidl_typesupport_introspection_c__resize_function__SpatialDetection__detections(
  void * untyped_member, size_t size)
{
  depthai_ros_msgs__msg__SpatialDetection__Sequence * member =
    (depthai_ros_msgs__msg__SpatialDetection__Sequence *)(untyped_member);
  depthai_ros_msgs__msg__SpatialDetection__Sequence__fini(member);
  return depthai_ros_msgs__msg__SpatialDetection__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember SpatialDetectionArray__rosidl_typesupport_introspection_c__SpatialDetectionArray_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(depthai_ros_msgs__msg__SpatialDetectionArray, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "detections",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(depthai_ros_msgs__msg__SpatialDetectionArray, detections),  // bytes offset in struct
    NULL,  // default value
    SpatialDetectionArray__rosidl_typesupport_introspection_c__size_function__SpatialDetection__detections,  // size() function pointer
    SpatialDetectionArray__rosidl_typesupport_introspection_c__get_const_function__SpatialDetection__detections,  // get_const(index) function pointer
    SpatialDetectionArray__rosidl_typesupport_introspection_c__get_function__SpatialDetection__detections,  // get(index) function pointer
    SpatialDetectionArray__rosidl_typesupport_introspection_c__resize_function__SpatialDetection__detections  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers SpatialDetectionArray__rosidl_typesupport_introspection_c__SpatialDetectionArray_message_members = {
  "depthai_ros_msgs__msg",  // message namespace
  "SpatialDetectionArray",  // message name
  2,  // number of fields
  sizeof(depthai_ros_msgs__msg__SpatialDetectionArray),
  SpatialDetectionArray__rosidl_typesupport_introspection_c__SpatialDetectionArray_message_member_array,  // message members
  SpatialDetectionArray__rosidl_typesupport_introspection_c__SpatialDetectionArray_init_function,  // function to initialize message memory (memory has to be allocated)
  SpatialDetectionArray__rosidl_typesupport_introspection_c__SpatialDetectionArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t SpatialDetectionArray__rosidl_typesupport_introspection_c__SpatialDetectionArray_message_type_support_handle = {
  0,
  &SpatialDetectionArray__rosidl_typesupport_introspection_c__SpatialDetectionArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_depthai_ros_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, depthai_ros_msgs, msg, SpatialDetectionArray)() {
  SpatialDetectionArray__rosidl_typesupport_introspection_c__SpatialDetectionArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  SpatialDetectionArray__rosidl_typesupport_introspection_c__SpatialDetectionArray_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, depthai_ros_msgs, msg, SpatialDetection)();
  if (!SpatialDetectionArray__rosidl_typesupport_introspection_c__SpatialDetectionArray_message_type_support_handle.typesupport_identifier) {
    SpatialDetectionArray__rosidl_typesupport_introspection_c__SpatialDetectionArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &SpatialDetectionArray__rosidl_typesupport_introspection_c__SpatialDetectionArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
