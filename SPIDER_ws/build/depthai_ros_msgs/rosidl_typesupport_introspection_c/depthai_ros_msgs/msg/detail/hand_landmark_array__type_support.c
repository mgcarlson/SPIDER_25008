// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from depthai_ros_msgs:msg/HandLandmarkArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "depthai_ros_msgs/msg/detail/hand_landmark_array__rosidl_typesupport_introspection_c.h"
#include "depthai_ros_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "depthai_ros_msgs/msg/detail/hand_landmark_array__functions.h"
#include "depthai_ros_msgs/msg/detail/hand_landmark_array__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `landmarks`
#include "depthai_ros_msgs/msg/hand_landmark.h"
// Member `landmarks`
#include "depthai_ros_msgs/msg/detail/hand_landmark__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void HandLandmarkArray__rosidl_typesupport_introspection_c__HandLandmarkArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  depthai_ros_msgs__msg__HandLandmarkArray__init(message_memory);
}

void HandLandmarkArray__rosidl_typesupport_introspection_c__HandLandmarkArray_fini_function(void * message_memory)
{
  depthai_ros_msgs__msg__HandLandmarkArray__fini(message_memory);
}

size_t HandLandmarkArray__rosidl_typesupport_introspection_c__size_function__HandLandmark__landmarks(
  const void * untyped_member)
{
  const depthai_ros_msgs__msg__HandLandmark__Sequence * member =
    (const depthai_ros_msgs__msg__HandLandmark__Sequence *)(untyped_member);
  return member->size;
}

const void * HandLandmarkArray__rosidl_typesupport_introspection_c__get_const_function__HandLandmark__landmarks(
  const void * untyped_member, size_t index)
{
  const depthai_ros_msgs__msg__HandLandmark__Sequence * member =
    (const depthai_ros_msgs__msg__HandLandmark__Sequence *)(untyped_member);
  return &member->data[index];
}

void * HandLandmarkArray__rosidl_typesupport_introspection_c__get_function__HandLandmark__landmarks(
  void * untyped_member, size_t index)
{
  depthai_ros_msgs__msg__HandLandmark__Sequence * member =
    (depthai_ros_msgs__msg__HandLandmark__Sequence *)(untyped_member);
  return &member->data[index];
}

bool HandLandmarkArray__rosidl_typesupport_introspection_c__resize_function__HandLandmark__landmarks(
  void * untyped_member, size_t size)
{
  depthai_ros_msgs__msg__HandLandmark__Sequence * member =
    (depthai_ros_msgs__msg__HandLandmark__Sequence *)(untyped_member);
  depthai_ros_msgs__msg__HandLandmark__Sequence__fini(member);
  return depthai_ros_msgs__msg__HandLandmark__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember HandLandmarkArray__rosidl_typesupport_introspection_c__HandLandmarkArray_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(depthai_ros_msgs__msg__HandLandmarkArray, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "landmarks",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(depthai_ros_msgs__msg__HandLandmarkArray, landmarks),  // bytes offset in struct
    NULL,  // default value
    HandLandmarkArray__rosidl_typesupport_introspection_c__size_function__HandLandmark__landmarks,  // size() function pointer
    HandLandmarkArray__rosidl_typesupport_introspection_c__get_const_function__HandLandmark__landmarks,  // get_const(index) function pointer
    HandLandmarkArray__rosidl_typesupport_introspection_c__get_function__HandLandmark__landmarks,  // get(index) function pointer
    HandLandmarkArray__rosidl_typesupport_introspection_c__resize_function__HandLandmark__landmarks  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers HandLandmarkArray__rosidl_typesupport_introspection_c__HandLandmarkArray_message_members = {
  "depthai_ros_msgs__msg",  // message namespace
  "HandLandmarkArray",  // message name
  2,  // number of fields
  sizeof(depthai_ros_msgs__msg__HandLandmarkArray),
  HandLandmarkArray__rosidl_typesupport_introspection_c__HandLandmarkArray_message_member_array,  // message members
  HandLandmarkArray__rosidl_typesupport_introspection_c__HandLandmarkArray_init_function,  // function to initialize message memory (memory has to be allocated)
  HandLandmarkArray__rosidl_typesupport_introspection_c__HandLandmarkArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t HandLandmarkArray__rosidl_typesupport_introspection_c__HandLandmarkArray_message_type_support_handle = {
  0,
  &HandLandmarkArray__rosidl_typesupport_introspection_c__HandLandmarkArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_depthai_ros_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, depthai_ros_msgs, msg, HandLandmarkArray)() {
  HandLandmarkArray__rosidl_typesupport_introspection_c__HandLandmarkArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  HandLandmarkArray__rosidl_typesupport_introspection_c__HandLandmarkArray_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, depthai_ros_msgs, msg, HandLandmark)();
  if (!HandLandmarkArray__rosidl_typesupport_introspection_c__HandLandmarkArray_message_type_support_handle.typesupport_identifier) {
    HandLandmarkArray__rosidl_typesupport_introspection_c__HandLandmarkArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &HandLandmarkArray__rosidl_typesupport_introspection_c__HandLandmarkArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
