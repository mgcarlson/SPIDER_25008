// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from depthai_ros_msgs:msg/TrackDetection2DArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "depthai_ros_msgs/msg/detail/track_detection2_d_array__rosidl_typesupport_introspection_c.h"
#include "depthai_ros_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "depthai_ros_msgs/msg/detail/track_detection2_d_array__functions.h"
#include "depthai_ros_msgs/msg/detail/track_detection2_d_array__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `detections`
#include "depthai_ros_msgs/msg/track_detection2_d.h"
// Member `detections`
#include "depthai_ros_msgs/msg/detail/track_detection2_d__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void TrackDetection2DArray__rosidl_typesupport_introspection_c__TrackDetection2DArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  depthai_ros_msgs__msg__TrackDetection2DArray__init(message_memory);
}

void TrackDetection2DArray__rosidl_typesupport_introspection_c__TrackDetection2DArray_fini_function(void * message_memory)
{
  depthai_ros_msgs__msg__TrackDetection2DArray__fini(message_memory);
}

size_t TrackDetection2DArray__rosidl_typesupport_introspection_c__size_function__TrackDetection2D__detections(
  const void * untyped_member)
{
  const depthai_ros_msgs__msg__TrackDetection2D__Sequence * member =
    (const depthai_ros_msgs__msg__TrackDetection2D__Sequence *)(untyped_member);
  return member->size;
}

const void * TrackDetection2DArray__rosidl_typesupport_introspection_c__get_const_function__TrackDetection2D__detections(
  const void * untyped_member, size_t index)
{
  const depthai_ros_msgs__msg__TrackDetection2D__Sequence * member =
    (const depthai_ros_msgs__msg__TrackDetection2D__Sequence *)(untyped_member);
  return &member->data[index];
}

void * TrackDetection2DArray__rosidl_typesupport_introspection_c__get_function__TrackDetection2D__detections(
  void * untyped_member, size_t index)
{
  depthai_ros_msgs__msg__TrackDetection2D__Sequence * member =
    (depthai_ros_msgs__msg__TrackDetection2D__Sequence *)(untyped_member);
  return &member->data[index];
}

bool TrackDetection2DArray__rosidl_typesupport_introspection_c__resize_function__TrackDetection2D__detections(
  void * untyped_member, size_t size)
{
  depthai_ros_msgs__msg__TrackDetection2D__Sequence * member =
    (depthai_ros_msgs__msg__TrackDetection2D__Sequence *)(untyped_member);
  depthai_ros_msgs__msg__TrackDetection2D__Sequence__fini(member);
  return depthai_ros_msgs__msg__TrackDetection2D__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember TrackDetection2DArray__rosidl_typesupport_introspection_c__TrackDetection2DArray_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(depthai_ros_msgs__msg__TrackDetection2DArray, header),  // bytes offset in struct
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
    offsetof(depthai_ros_msgs__msg__TrackDetection2DArray, detections),  // bytes offset in struct
    NULL,  // default value
    TrackDetection2DArray__rosidl_typesupport_introspection_c__size_function__TrackDetection2D__detections,  // size() function pointer
    TrackDetection2DArray__rosidl_typesupport_introspection_c__get_const_function__TrackDetection2D__detections,  // get_const(index) function pointer
    TrackDetection2DArray__rosidl_typesupport_introspection_c__get_function__TrackDetection2D__detections,  // get(index) function pointer
    TrackDetection2DArray__rosidl_typesupport_introspection_c__resize_function__TrackDetection2D__detections  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers TrackDetection2DArray__rosidl_typesupport_introspection_c__TrackDetection2DArray_message_members = {
  "depthai_ros_msgs__msg",  // message namespace
  "TrackDetection2DArray",  // message name
  2,  // number of fields
  sizeof(depthai_ros_msgs__msg__TrackDetection2DArray),
  TrackDetection2DArray__rosidl_typesupport_introspection_c__TrackDetection2DArray_message_member_array,  // message members
  TrackDetection2DArray__rosidl_typesupport_introspection_c__TrackDetection2DArray_init_function,  // function to initialize message memory (memory has to be allocated)
  TrackDetection2DArray__rosidl_typesupport_introspection_c__TrackDetection2DArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t TrackDetection2DArray__rosidl_typesupport_introspection_c__TrackDetection2DArray_message_type_support_handle = {
  0,
  &TrackDetection2DArray__rosidl_typesupport_introspection_c__TrackDetection2DArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_depthai_ros_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, depthai_ros_msgs, msg, TrackDetection2DArray)() {
  TrackDetection2DArray__rosidl_typesupport_introspection_c__TrackDetection2DArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  TrackDetection2DArray__rosidl_typesupport_introspection_c__TrackDetection2DArray_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, depthai_ros_msgs, msg, TrackDetection2D)();
  if (!TrackDetection2DArray__rosidl_typesupport_introspection_c__TrackDetection2DArray_message_type_support_handle.typesupport_identifier) {
    TrackDetection2DArray__rosidl_typesupport_introspection_c__TrackDetection2DArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &TrackDetection2DArray__rosidl_typesupport_introspection_c__TrackDetection2DArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
