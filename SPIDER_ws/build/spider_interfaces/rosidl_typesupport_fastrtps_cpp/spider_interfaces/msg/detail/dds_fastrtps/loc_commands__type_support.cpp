// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from spider_interfaces:msg/LocCommands.idl
// generated code does not contain a copyright notice
#include "spider_interfaces/msg/detail/loc_commands__rosidl_typesupport_fastrtps_cpp.hpp"
#include "spider_interfaces/msg/detail/loc_commands__struct.hpp"

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
  const std_msgs::msg::String &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::String &);
size_t get_serialized_size(
  const std_msgs::msg::String &,
  size_t current_alignment);
size_t
max_serialized_size_String(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs


namespace spider_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_spider_interfaces
cdr_serialize(
  const spider_interfaces::msg::LocCommands & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: move_type
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.move_type,
    cdr);
  // Member: move_amount
  cdr << ros_message.move_amount;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_spider_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  spider_interfaces::msg::LocCommands & ros_message)
{
  // Member: move_type
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.move_type);

  // Member: move_amount
  cdr >> ros_message.move_amount;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_spider_interfaces
get_serialized_size(
  const spider_interfaces::msg::LocCommands & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: move_type

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.move_type, current_alignment);
  // Member: move_amount
  {
    size_t item_size = sizeof(ros_message.move_amount);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_spider_interfaces
max_serialized_size_LocCommands(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: move_type
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_String(
        full_bounded, current_alignment);
    }
  }

  // Member: move_amount
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _LocCommands__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const spider_interfaces::msg::LocCommands *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _LocCommands__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<spider_interfaces::msg::LocCommands *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _LocCommands__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const spider_interfaces::msg::LocCommands *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _LocCommands__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_LocCommands(full_bounded, 0);
}

static message_type_support_callbacks_t _LocCommands__callbacks = {
  "spider_interfaces::msg",
  "LocCommands",
  _LocCommands__cdr_serialize,
  _LocCommands__cdr_deserialize,
  _LocCommands__get_serialized_size,
  _LocCommands__max_serialized_size
};

static rosidl_message_type_support_t _LocCommands__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_LocCommands__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace spider_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_spider_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<spider_interfaces::msg::LocCommands>()
{
  return &spider_interfaces::msg::typesupport_fastrtps_cpp::_LocCommands__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, spider_interfaces, msg, LocCommands)() {
  return &spider_interfaces::msg::typesupport_fastrtps_cpp::_LocCommands__handle;
}

#ifdef __cplusplus
}
#endif
