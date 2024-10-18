// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from depthai_ros_msgs:msg/TrackDetection2D.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "depthai_ros_msgs/msg/detail/track_detection2_d__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace depthai_ros_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void TrackDetection2D_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) depthai_ros_msgs::msg::TrackDetection2D(_init);
}

void TrackDetection2D_fini_function(void * message_memory)
{
  auto typed_message = static_cast<depthai_ros_msgs::msg::TrackDetection2D *>(message_memory);
  typed_message->~TrackDetection2D();
}

size_t size_function__TrackDetection2D__results(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<vision_msgs::msg::ObjectHypothesisWithPose> *>(untyped_member);
  return member->size();
}

const void * get_const_function__TrackDetection2D__results(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<vision_msgs::msg::ObjectHypothesisWithPose> *>(untyped_member);
  return &member[index];
}

void * get_function__TrackDetection2D__results(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<vision_msgs::msg::ObjectHypothesisWithPose> *>(untyped_member);
  return &member[index];
}

void resize_function__TrackDetection2D__results(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<vision_msgs::msg::ObjectHypothesisWithPose> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember TrackDetection2D_message_member_array[6] = {
  {
    "results",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<vision_msgs::msg::ObjectHypothesisWithPose>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(depthai_ros_msgs::msg::TrackDetection2D, results),  // bytes offset in struct
    nullptr,  // default value
    size_function__TrackDetection2D__results,  // size() function pointer
    get_const_function__TrackDetection2D__results,  // get_const(index) function pointer
    get_function__TrackDetection2D__results,  // get(index) function pointer
    resize_function__TrackDetection2D__results  // resize(index) function pointer
  },
  {
    "bbox",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<vision_msgs::msg::BoundingBox2D>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(depthai_ros_msgs::msg::TrackDetection2D, bbox),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "is_tracking",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(depthai_ros_msgs::msg::TrackDetection2D, is_tracking),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "tracking_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(depthai_ros_msgs::msg::TrackDetection2D, tracking_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "tracking_age",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(depthai_ros_msgs::msg::TrackDetection2D, tracking_age),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "tracking_status",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(depthai_ros_msgs::msg::TrackDetection2D, tracking_status),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers TrackDetection2D_message_members = {
  "depthai_ros_msgs::msg",  // message namespace
  "TrackDetection2D",  // message name
  6,  // number of fields
  sizeof(depthai_ros_msgs::msg::TrackDetection2D),
  TrackDetection2D_message_member_array,  // message members
  TrackDetection2D_init_function,  // function to initialize message memory (memory has to be allocated)
  TrackDetection2D_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t TrackDetection2D_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &TrackDetection2D_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace depthai_ros_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<depthai_ros_msgs::msg::TrackDetection2D>()
{
  return &::depthai_ros_msgs::msg::rosidl_typesupport_introspection_cpp::TrackDetection2D_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, depthai_ros_msgs, msg, TrackDetection2D)() {
  return &::depthai_ros_msgs::msg::rosidl_typesupport_introspection_cpp::TrackDetection2D_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
