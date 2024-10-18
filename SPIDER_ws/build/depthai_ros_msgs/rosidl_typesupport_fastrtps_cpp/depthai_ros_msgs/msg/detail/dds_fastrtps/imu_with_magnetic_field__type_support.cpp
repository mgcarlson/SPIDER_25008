// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from depthai_ros_msgs:msg/ImuWithMagneticField.idl
// generated code does not contain a copyright notice
#include "depthai_ros_msgs/msg/detail/imu_with_magnetic_field__rosidl_typesupport_fastrtps_cpp.hpp"
#include "depthai_ros_msgs/msg/detail/imu_with_magnetic_field__struct.hpp"

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
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs

namespace sensor_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const sensor_msgs::msg::Imu &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  sensor_msgs::msg::Imu &);
size_t get_serialized_size(
  const sensor_msgs::msg::Imu &,
  size_t current_alignment);
size_t
max_serialized_size_Imu(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace sensor_msgs

namespace sensor_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const sensor_msgs::msg::MagneticField &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  sensor_msgs::msg::MagneticField &);
size_t get_serialized_size(
  const sensor_msgs::msg::MagneticField &,
  size_t current_alignment);
size_t
max_serialized_size_MagneticField(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace sensor_msgs


namespace depthai_ros_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_depthai_ros_msgs
cdr_serialize(
  const depthai_ros_msgs::msg::ImuWithMagneticField & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: imu
  sensor_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.imu,
    cdr);
  // Member: field
  sensor_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.field,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_depthai_ros_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  depthai_ros_msgs::msg::ImuWithMagneticField & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: imu
  sensor_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.imu);

  // Member: field
  sensor_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.field);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_depthai_ros_msgs
get_serialized_size(
  const depthai_ros_msgs::msg::ImuWithMagneticField & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header, current_alignment);
  // Member: imu

  current_alignment +=
    sensor_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.imu, current_alignment);
  // Member: field

  current_alignment +=
    sensor_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.field, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_depthai_ros_msgs
max_serialized_size_ImuWithMagneticField(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: header
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        full_bounded, current_alignment);
    }
  }

  // Member: imu
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        sensor_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Imu(
        full_bounded, current_alignment);
    }
  }

  // Member: field
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        sensor_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_MagneticField(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static bool _ImuWithMagneticField__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const depthai_ros_msgs::msg::ImuWithMagneticField *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ImuWithMagneticField__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<depthai_ros_msgs::msg::ImuWithMagneticField *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ImuWithMagneticField__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const depthai_ros_msgs::msg::ImuWithMagneticField *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ImuWithMagneticField__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_ImuWithMagneticField(full_bounded, 0);
}

static message_type_support_callbacks_t _ImuWithMagneticField__callbacks = {
  "depthai_ros_msgs::msg",
  "ImuWithMagneticField",
  _ImuWithMagneticField__cdr_serialize,
  _ImuWithMagneticField__cdr_deserialize,
  _ImuWithMagneticField__get_serialized_size,
  _ImuWithMagneticField__max_serialized_size
};

static rosidl_message_type_support_t _ImuWithMagneticField__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ImuWithMagneticField__callbacks,
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
get_message_type_support_handle<depthai_ros_msgs::msg::ImuWithMagneticField>()
{
  return &depthai_ros_msgs::msg::typesupport_fastrtps_cpp::_ImuWithMagneticField__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, depthai_ros_msgs, msg, ImuWithMagneticField)() {
  return &depthai_ros_msgs::msg::typesupport_fastrtps_cpp::_ImuWithMagneticField__handle;
}

#ifdef __cplusplus
}
#endif
