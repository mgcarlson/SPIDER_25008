// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from spider_interfaces:srv/LocService.idl
// generated code does not contain a copyright notice
#include "spider_interfaces/srv/detail/loc_service__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "spider_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "spider_interfaces/srv/detail/loc_service__struct.h"
#include "spider_interfaces/srv/detail/loc_service__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "std_msgs/msg/detail/string__functions.h"  // move_type

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_spider_interfaces
size_t get_serialized_size_std_msgs__msg__String(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_spider_interfaces
size_t max_serialized_size_std_msgs__msg__String(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_spider_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, String)();


using _LocService_Request__ros_msg_type = spider_interfaces__srv__LocService_Request;

static bool _LocService_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _LocService_Request__ros_msg_type * ros_message = static_cast<const _LocService_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: move_type
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, String
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->move_type, cdr))
    {
      return false;
    }
  }

  // Field name: move_amount
  {
    cdr << ros_message->move_amount;
  }

  // Field name: delta_angle
  {
    cdr << ros_message->delta_angle;
  }

  return true;
}

static bool _LocService_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _LocService_Request__ros_msg_type * ros_message = static_cast<_LocService_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: move_type
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, String
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->move_type))
    {
      return false;
    }
  }

  // Field name: move_amount
  {
    cdr >> ros_message->move_amount;
  }

  // Field name: delta_angle
  {
    cdr >> ros_message->delta_angle;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_spider_interfaces
size_t get_serialized_size_spider_interfaces__srv__LocService_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _LocService_Request__ros_msg_type * ros_message = static_cast<const _LocService_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name move_type

  current_alignment += get_serialized_size_std_msgs__msg__String(
    &(ros_message->move_type), current_alignment);
  // field.name move_amount
  {
    size_t item_size = sizeof(ros_message->move_amount);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name delta_angle
  {
    size_t item_size = sizeof(ros_message->delta_angle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _LocService_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_spider_interfaces__srv__LocService_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_spider_interfaces
size_t max_serialized_size_spider_interfaces__srv__LocService_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: move_type
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_std_msgs__msg__String(
        full_bounded, current_alignment);
    }
  }
  // member: move_amount
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: delta_angle
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _LocService_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_spider_interfaces__srv__LocService_Request(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_LocService_Request = {
  "spider_interfaces::srv",
  "LocService_Request",
  _LocService_Request__cdr_serialize,
  _LocService_Request__cdr_deserialize,
  _LocService_Request__get_serialized_size,
  _LocService_Request__max_serialized_size
};

static rosidl_message_type_support_t _LocService_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_LocService_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, spider_interfaces, srv, LocService_Request)() {
  return &_LocService_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "spider_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "spider_interfaces/srv/detail/loc_service__struct.h"
// already included above
// #include "spider_interfaces/srv/detail/loc_service__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

// already included above
// #include "std_msgs/msg/detail/string__functions.h"  // status

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_spider_interfaces
size_t get_serialized_size_std_msgs__msg__String(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_spider_interfaces
size_t max_serialized_size_std_msgs__msg__String(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_spider_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, String)();


using _LocService_Response__ros_msg_type = spider_interfaces__srv__LocService_Response;

static bool _LocService_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _LocService_Response__ros_msg_type * ros_message = static_cast<const _LocService_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: status
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, String
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->status, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _LocService_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _LocService_Response__ros_msg_type * ros_message = static_cast<_LocService_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: status
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, String
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->status))
    {
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_spider_interfaces
size_t get_serialized_size_spider_interfaces__srv__LocService_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _LocService_Response__ros_msg_type * ros_message = static_cast<const _LocService_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name status

  current_alignment += get_serialized_size_std_msgs__msg__String(
    &(ros_message->status), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _LocService_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_spider_interfaces__srv__LocService_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_spider_interfaces
size_t max_serialized_size_spider_interfaces__srv__LocService_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: status
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_std_msgs__msg__String(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _LocService_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_spider_interfaces__srv__LocService_Response(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_LocService_Response = {
  "spider_interfaces::srv",
  "LocService_Response",
  _LocService_Response__cdr_serialize,
  _LocService_Response__cdr_deserialize,
  _LocService_Response__get_serialized_size,
  _LocService_Response__max_serialized_size
};

static rosidl_message_type_support_t _LocService_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_LocService_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, spider_interfaces, srv, LocService_Response)() {
  return &_LocService_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "spider_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "spider_interfaces/srv/loc_service.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t LocService__callbacks = {
  "spider_interfaces::srv",
  "LocService",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, spider_interfaces, srv, LocService_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, spider_interfaces, srv, LocService_Response)(),
};

static rosidl_service_type_support_t LocService__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &LocService__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, spider_interfaces, srv, LocService)() {
  return &LocService__handle;
}

#if defined(__cplusplus)
}
#endif
