// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from spider_interfaces:srv/LocService.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "spider_interfaces/srv/detail/loc_service__rosidl_typesupport_introspection_c.h"
#include "spider_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "spider_interfaces/srv/detail/loc_service__functions.h"
#include "spider_interfaces/srv/detail/loc_service__struct.h"


// Include directives for member types
// Member `move_type`
#include "std_msgs/msg/string.h"
// Member `move_type`
#include "std_msgs/msg/detail/string__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void LocService_Request__rosidl_typesupport_introspection_c__LocService_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  spider_interfaces__srv__LocService_Request__init(message_memory);
}

void LocService_Request__rosidl_typesupport_introspection_c__LocService_Request_fini_function(void * message_memory)
{
  spider_interfaces__srv__LocService_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember LocService_Request__rosidl_typesupport_introspection_c__LocService_Request_message_member_array[3] = {
  {
    "move_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(spider_interfaces__srv__LocService_Request, move_type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "move_amount",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(spider_interfaces__srv__LocService_Request, move_amount),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "delta_angle",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(spider_interfaces__srv__LocService_Request, delta_angle),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers LocService_Request__rosidl_typesupport_introspection_c__LocService_Request_message_members = {
  "spider_interfaces__srv",  // message namespace
  "LocService_Request",  // message name
  3,  // number of fields
  sizeof(spider_interfaces__srv__LocService_Request),
  LocService_Request__rosidl_typesupport_introspection_c__LocService_Request_message_member_array,  // message members
  LocService_Request__rosidl_typesupport_introspection_c__LocService_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  LocService_Request__rosidl_typesupport_introspection_c__LocService_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t LocService_Request__rosidl_typesupport_introspection_c__LocService_Request_message_type_support_handle = {
  0,
  &LocService_Request__rosidl_typesupport_introspection_c__LocService_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_spider_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, spider_interfaces, srv, LocService_Request)() {
  LocService_Request__rosidl_typesupport_introspection_c__LocService_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, String)();
  if (!LocService_Request__rosidl_typesupport_introspection_c__LocService_Request_message_type_support_handle.typesupport_identifier) {
    LocService_Request__rosidl_typesupport_introspection_c__LocService_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &LocService_Request__rosidl_typesupport_introspection_c__LocService_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "spider_interfaces/srv/detail/loc_service__rosidl_typesupport_introspection_c.h"
// already included above
// #include "spider_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "spider_interfaces/srv/detail/loc_service__functions.h"
// already included above
// #include "spider_interfaces/srv/detail/loc_service__struct.h"


// Include directives for member types
// Member `status`
// already included above
// #include "std_msgs/msg/string.h"
// Member `status`
// already included above
// #include "std_msgs/msg/detail/string__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void LocService_Response__rosidl_typesupport_introspection_c__LocService_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  spider_interfaces__srv__LocService_Response__init(message_memory);
}

void LocService_Response__rosidl_typesupport_introspection_c__LocService_Response_fini_function(void * message_memory)
{
  spider_interfaces__srv__LocService_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember LocService_Response__rosidl_typesupport_introspection_c__LocService_Response_message_member_array[1] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(spider_interfaces__srv__LocService_Response, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers LocService_Response__rosidl_typesupport_introspection_c__LocService_Response_message_members = {
  "spider_interfaces__srv",  // message namespace
  "LocService_Response",  // message name
  1,  // number of fields
  sizeof(spider_interfaces__srv__LocService_Response),
  LocService_Response__rosidl_typesupport_introspection_c__LocService_Response_message_member_array,  // message members
  LocService_Response__rosidl_typesupport_introspection_c__LocService_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  LocService_Response__rosidl_typesupport_introspection_c__LocService_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t LocService_Response__rosidl_typesupport_introspection_c__LocService_Response_message_type_support_handle = {
  0,
  &LocService_Response__rosidl_typesupport_introspection_c__LocService_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_spider_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, spider_interfaces, srv, LocService_Response)() {
  LocService_Response__rosidl_typesupport_introspection_c__LocService_Response_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, String)();
  if (!LocService_Response__rosidl_typesupport_introspection_c__LocService_Response_message_type_support_handle.typesupport_identifier) {
    LocService_Response__rosidl_typesupport_introspection_c__LocService_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &LocService_Response__rosidl_typesupport_introspection_c__LocService_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "spider_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "spider_interfaces/srv/detail/loc_service__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers spider_interfaces__srv__detail__loc_service__rosidl_typesupport_introspection_c__LocService_service_members = {
  "spider_interfaces__srv",  // service namespace
  "LocService",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // spider_interfaces__srv__detail__loc_service__rosidl_typesupport_introspection_c__LocService_Request_message_type_support_handle,
  NULL  // response message
  // spider_interfaces__srv__detail__loc_service__rosidl_typesupport_introspection_c__LocService_Response_message_type_support_handle
};

static rosidl_service_type_support_t spider_interfaces__srv__detail__loc_service__rosidl_typesupport_introspection_c__LocService_service_type_support_handle = {
  0,
  &spider_interfaces__srv__detail__loc_service__rosidl_typesupport_introspection_c__LocService_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, spider_interfaces, srv, LocService_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, spider_interfaces, srv, LocService_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_spider_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, spider_interfaces, srv, LocService)() {
  if (!spider_interfaces__srv__detail__loc_service__rosidl_typesupport_introspection_c__LocService_service_type_support_handle.typesupport_identifier) {
    spider_interfaces__srv__detail__loc_service__rosidl_typesupport_introspection_c__LocService_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)spider_interfaces__srv__detail__loc_service__rosidl_typesupport_introspection_c__LocService_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, spider_interfaces, srv, LocService_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, spider_interfaces, srv, LocService_Response)()->data;
  }

  return &spider_interfaces__srv__detail__loc_service__rosidl_typesupport_introspection_c__LocService_service_type_support_handle;
}
