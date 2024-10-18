// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from depthai_ros_msgs:msg/TrackDetection2D.idl
// generated code does not contain a copyright notice
#include "depthai_ros_msgs/msg/detail/track_detection2_d__rosidl_typesupport_fastrtps_cpp.hpp"
#include "depthai_ros_msgs/msg/detail/track_detection2_d__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace vision_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const vision_msgs::msg::ObjectHypothesisWithPose &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  vision_msgs::msg::ObjectHypothesisWithPose &);
size_t get_serialized_size(
  const vision_msgs::msg::ObjectHypothesisWithPose &,
  size_t current_alignment);
size_t
max_serialized_size_ObjectHypothesisWithPose(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace vision_msgs

namespace vision_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const vision_msgs::msg::BoundingBox2D &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  vision_msgs::msg::BoundingBox2D &);
size_t get_serialized_size(
  const vision_msgs::msg::BoundingBox2D &,
  size_t current_alignment);
size_t
max_serialized_size_BoundingBox2D(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace vision_msgs


namespace depthai_ros_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_depthai_ros_msgs
cdr_serialize(
  const depthai_ros_msgs::msg::TrackDetection2D & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: results
  {
    size_t size = ros_message.results.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      vision_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.results[i],
        cdr);
    }
  }
  // Member: bbox
  vision_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.bbox,
    cdr);
  // Member: is_tracking
  cdr << (ros_message.is_tracking ? true : false);
  // Member: tracking_id
  cdr << ros_message.tracking_id;
  // Member: tracking_age
  cdr << ros_message.tracking_age;
  // Member: tracking_status
  cdr << ros_message.tracking_status;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_depthai_ros_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  depthai_ros_msgs::msg::TrackDetection2D & ros_message)
{
  // Member: results
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    ros_message.results.resize(size);
    for (size_t i = 0; i < size; i++) {
      vision_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.results[i]);
    }
  }

  // Member: bbox
  vision_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.bbox);

  // Member: is_tracking
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.is_tracking = tmp ? true : false;
  }

  // Member: tracking_id
  cdr >> ros_message.tracking_id;

  // Member: tracking_age
  cdr >> ros_message.tracking_age;

  // Member: tracking_status
  cdr >> ros_message.tracking_status;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_depthai_ros_msgs
get_serialized_size(
  const depthai_ros_msgs::msg::TrackDetection2D & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: results
  {
    size_t array_size = ros_message.results.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        vision_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.results[index], current_alignment);
    }
  }
  // Member: bbox

  current_alignment +=
    vision_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.bbox, current_alignment);
  // Member: is_tracking
  {
    size_t item_size = sizeof(ros_message.is_tracking);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: tracking_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.tracking_id.size() + 1);
  // Member: tracking_age
  {
    size_t item_size = sizeof(ros_message.tracking_age);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: tracking_status
  {
    size_t item_size = sizeof(ros_message.tracking_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_depthai_ros_msgs
max_serialized_size_TrackDetection2D(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: results
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        vision_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_ObjectHypothesisWithPose(
        full_bounded, current_alignment);
    }
  }

  // Member: bbox
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        vision_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_BoundingBox2D(
        full_bounded, current_alignment);
    }
  }

  // Member: is_tracking
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: tracking_id
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: tracking_age
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: tracking_status
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _TrackDetection2D__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const depthai_ros_msgs::msg::TrackDetection2D *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _TrackDetection2D__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<depthai_ros_msgs::msg::TrackDetection2D *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _TrackDetection2D__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const depthai_ros_msgs::msg::TrackDetection2D *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _TrackDetection2D__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_TrackDetection2D(full_bounded, 0);
}

static message_type_support_callbacks_t _TrackDetection2D__callbacks = {
  "depthai_ros_msgs::msg",
  "TrackDetection2D",
  _TrackDetection2D__cdr_serialize,
  _TrackDetection2D__cdr_deserialize,
  _TrackDetection2D__get_serialized_size,
  _TrackDetection2D__max_serialized_size
};

static rosidl_message_type_support_t _TrackDetection2D__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_TrackDetection2D__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace depthai_ros_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_depthai_ros_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<depthai_ros_msgs::msg::TrackDetection2D>()
{
  return &depthai_ros_msgs::msg::typesupport_fastrtps_cpp::_TrackDetection2D__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, depthai_ros_msgs, msg, TrackDetection2D)() {
  return &depthai_ros_msgs::msg::typesupport_fastrtps_cpp::_TrackDetection2D__handle;
}

#ifdef __cplusplus
}
#endif
