// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from depthai_ros_msgs:srv/NormalizedImageCrop.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "depthai_ros_msgs/srv/detail/normalized_image_crop__rosidl_typesupport_introspection_c.h"
#include "depthai_ros_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "depthai_ros_msgs/srv/detail/normalized_image_crop__functions.h"
#include "depthai_ros_msgs/srv/detail/normalized_image_crop__struct.h"


// Include directives for member types
// Member `top_left`
// Member `bottom_right`
#include "geometry_msgs/msg/pose2_d.h"
// Member `top_left`
// Member `bottom_right`
#include "geometry_msgs/msg/detail/pose2_d__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void NormalizedImageCrop_Request__rosidl_typesupport_introspection_c__NormalizedImageCrop_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  depthai_ros_msgs__srv__NormalizedImageCrop_Request__init(message_memory);
}

void NormalizedImageCrop_Request__rosidl_typesupport_introspection_c__NormalizedImageCrop_Request_fini_function(void * message_memory)
{
  depthai_ros_msgs__srv__NormalizedImageCrop_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember NormalizedImageCrop_Request__rosidl_typesupport_introspection_c__NormalizedImageCrop_Request_message_member_array[2] = {
  {
    "top_left",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(depthai_ros_msgs__srv__NormalizedImageCrop_Request, top_left),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "bottom_right",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(depthai_ros_msgs__srv__NormalizedImageCrop_Request, bottom_right),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers NormalizedImageCrop_Request__rosidl_typesupport_introspection_c__NormalizedImageCrop_Request_message_members = {
  "depthai_ros_msgs__srv",  // message namespace
  "NormalizedImageCrop_Request",  // message name
  2,  // number of fields
  sizeof(depthai_ros_msgs__srv__NormalizedImageCrop_Request),
  NormalizedImageCrop_Request__rosidl_typesupport_introspection_c__NormalizedImageCrop_Request_message_member_array,  // message members
  NormalizedImageCrop_Request__rosidl_typesupport_introspection_c__NormalizedImageCrop_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  NormalizedImageCrop_Request__rosidl_typesupport_introspection_c__NormalizedImageCrop_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t NormalizedImageCrop_Request__rosidl_typesupport_introspection_c__NormalizedImageCrop_Request_message_type_support_handle = {
  0,
  &NormalizedImageCrop_Request__rosidl_typesupport_introspection_c__NormalizedImageCrop_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_depthai_ros_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, depthai_ros_msgs, srv, NormalizedImageCrop_Request)() {
  NormalizedImageCrop_Request__rosidl_typesupport_introspection_c__NormalizedImageCrop_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose2D)();
  NormalizedImageCrop_Request__rosidl_typesupport_introspection_c__NormalizedImageCrop_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose2D)();
  if (!NormalizedImageCrop_Request__rosidl_typesupport_introspection_c__NormalizedImageCrop_Request_message_type_support_handle.typesupport_identifier) {
    NormalizedImageCrop_Request__rosidl_typesupport_introspection_c__NormalizedImageCrop_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &NormalizedImageCrop_Request__rosidl_typesupport_introspection_c__NormalizedImageCrop_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "depthai_ros_msgs/srv/detail/normalized_image_crop__rosidl_typesupport_introspection_c.h"
// already included above
// #include "depthai_ros_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "depthai_ros_msgs/srv/detail/normalized_image_crop__functions.h"
// already included above
// #include "depthai_ros_msgs/srv/detail/normalized_image_crop__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void NormalizedImageCrop_Response__rosidl_typesupport_introspection_c__NormalizedImageCrop_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  depthai_ros_msgs__srv__NormalizedImageCrop_Response__init(message_memory);
}

void NormalizedImageCrop_Response__rosidl_typesupport_introspection_c__NormalizedImageCrop_Response_fini_function(void * message_memory)
{
  depthai_ros_msgs__srv__NormalizedImageCrop_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember NormalizedImageCrop_Response__rosidl_typesupport_introspection_c__NormalizedImageCrop_Response_message_member_array[1] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(depthai_ros_msgs__srv__NormalizedImageCrop_Response, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers NormalizedImageCrop_Response__rosidl_typesupport_introspection_c__NormalizedImageCrop_Response_message_members = {
  "depthai_ros_msgs__srv",  // message namespace
  "NormalizedImageCrop_Response",  // message name
  1,  // number of fields
  sizeof(depthai_ros_msgs__srv__NormalizedImageCrop_Response),
  NormalizedImageCrop_Response__rosidl_typesupport_introspection_c__NormalizedImageCrop_Response_message_member_array,  // message members
  NormalizedImageCrop_Response__rosidl_typesupport_introspection_c__NormalizedImageCrop_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  NormalizedImageCrop_Response__rosidl_typesupport_introspection_c__NormalizedImageCrop_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t NormalizedImageCrop_Response__rosidl_typesupport_introspection_c__NormalizedImageCrop_Response_message_type_support_handle = {
  0,
  &NormalizedImageCrop_Response__rosidl_typesupport_introspection_c__NormalizedImageCrop_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_depthai_ros_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, depthai_ros_msgs, srv, NormalizedImageCrop_Response)() {
  if (!NormalizedImageCrop_Response__rosidl_typesupport_introspection_c__NormalizedImageCrop_Response_message_type_support_handle.typesupport_identifier) {
    NormalizedImageCrop_Response__rosidl_typesupport_introspection_c__NormalizedImageCrop_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &NormalizedImageCrop_Response__rosidl_typesupport_introspection_c__NormalizedImageCrop_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "depthai_ros_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "depthai_ros_msgs/srv/detail/normalized_image_crop__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers depthai_ros_msgs__srv__detail__normalized_image_crop__rosidl_typesupport_introspection_c__NormalizedImageCrop_service_members = {
  "depthai_ros_msgs__srv",  // service namespace
  "NormalizedImageCrop",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // depthai_ros_msgs__srv__detail__normalized_image_crop__rosidl_typesupport_introspection_c__NormalizedImageCrop_Request_message_type_support_handle,
  NULL  // response message
  // depthai_ros_msgs__srv__detail__normalized_image_crop__rosidl_typesupport_introspection_c__NormalizedImageCrop_Response_message_type_support_handle
};

static rosidl_service_type_support_t depthai_ros_msgs__srv__detail__normalized_image_crop__rosidl_typesupport_introspection_c__NormalizedImageCrop_service_type_support_handle = {
  0,
  &depthai_ros_msgs__srv__detail__normalized_image_crop__rosidl_typesupport_introspection_c__NormalizedImageCrop_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, depthai_ros_msgs, srv, NormalizedImageCrop_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, depthai_ros_msgs, srv, NormalizedImageCrop_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_depthai_ros_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, depthai_ros_msgs, srv, NormalizedImageCrop)() {
  if (!depthai_ros_msgs__srv__detail__normalized_image_crop__rosidl_typesupport_introspection_c__NormalizedImageCrop_service_type_support_handle.typesupport_identifier) {
    depthai_ros_msgs__srv__detail__normalized_image_crop__rosidl_typesupport_introspection_c__NormalizedImageCrop_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)depthai_ros_msgs__srv__detail__normalized_image_crop__rosidl_typesupport_introspection_c__NormalizedImageCrop_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, depthai_ros_msgs, srv, NormalizedImageCrop_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, depthai_ros_msgs, srv, NormalizedImageCrop_Response)()->data;
  }

  return &depthai_ros_msgs__srv__detail__normalized_image_crop__rosidl_typesupport_introspection_c__NormalizedImageCrop_service_type_support_handle;
}
