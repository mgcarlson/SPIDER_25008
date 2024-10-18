// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from depthai_ros_msgs:msg/TrackDetection2DArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "depthai_ros_msgs/msg/detail/track_detection2_d_array__struct.hpp"
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

void TrackDetection2DArray_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) depthai_ros_msgs::msg::TrackDetection2DArray(_init);
}

void TrackDetection2DArray_fini_function(void * message_memory)
{
  auto typed_message = static_cast<depthai_ros_msgs::msg::TrackDetection2DArray *>(message_memory);
  typed_message->~TrackDetection2DArray();
}

size_t size_function__TrackDetection2DArray__detections(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<depthai_ros_msgs::msg::TrackDetection2D> *>(untyped_member);
  return member->size();
}

const void * get_const_function__TrackDetection2DArray__detections(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<depthai_ros_msgs::msg::TrackDetection2D> *>(untyped_member);
  return &member[index];
}

void * get_function__TrackDetection2DArray__detections(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<depthai_ros_msgs::msg::TrackDetection2D> *>(untyped_member);
  return &member[index];
}

void resize_function__TrackDetection2DArray__detections(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<depthai_ros_msgs::msg::TrackDetection2D> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember TrackDetection2DArray_message_member_array[2] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(depthai_ros_msgs::msg::TrackDetection2DArray, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "detections",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<depthai_ros_msgs::msg::TrackDetection2D>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(depthai_ros_msgs::msg::TrackDetection2DArray, detections),  // bytes offset in struct
    nullptr,  // default value
    size_function__TrackDetection2DArray__detections,  // size() function pointer
    get_const_function__TrackDetection2DArray__detections,  // get_const(index) function pointer
    get_function__TrackDetection2DArray__detections,  // get(index) function pointer
    resize_function__TrackDetection2DArray__detections  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers TrackDetection2DArray_message_members = {
  "depthai_ros_msgs::msg",  // message namespace
  "TrackDetection2DArray",  // message name
  2,  // number of fields
  sizeof(depthai_ros_msgs::msg::TrackDetection2DArray),
  TrackDetection2DArray_message_member_array,  // message members
  TrackDetection2DArray_init_function,  // function to initialize message memory (memory has to be allocated)
  TrackDetection2DArray_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t TrackDetection2DArray_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &TrackDetection2DArray_message_members,
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
get_message_type_support_handle<depthai_ros_msgs::msg::TrackDetection2DArray>()
{
  return &::depthai_ros_msgs::msg::rosidl_typesupport_introspection_cpp::TrackDetection2DArray_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, depthai_ros_msgs, msg, TrackDetection2DArray)() {
  return &::depthai_ros_msgs::msg::rosidl_typesupport_introspection_cpp::TrackDetection2DArray_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
