// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from spider_interfaces:srv/LocService.idl
// generated code does not contain a copyright notice

#ifndef SPIDER_INTERFACES__SRV__DETAIL__LOC_SERVICE__STRUCT_H_
#define SPIDER_INTERFACES__SRV__DETAIL__LOC_SERVICE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'move_type'
#include "std_msgs/msg/detail/string__struct.h"

// Struct defined in srv/LocService in the package spider_interfaces.
typedef struct spider_interfaces__srv__LocService_Request
{
  std_msgs__msg__String move_type;
  int64_t move_amount;
  double delta_angle;
} spider_interfaces__srv__LocService_Request;

// Struct for a sequence of spider_interfaces__srv__LocService_Request.
typedef struct spider_interfaces__srv__LocService_Request__Sequence
{
  spider_interfaces__srv__LocService_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} spider_interfaces__srv__LocService_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'status'
// already included above
// #include "std_msgs/msg/detail/string__struct.h"

// Struct defined in srv/LocService in the package spider_interfaces.
typedef struct spider_interfaces__srv__LocService_Response
{
  std_msgs__msg__String status;
} spider_interfaces__srv__LocService_Response;

// Struct for a sequence of spider_interfaces__srv__LocService_Response.
typedef struct spider_interfaces__srv__LocService_Response__Sequence
{
  spider_interfaces__srv__LocService_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} spider_interfaces__srv__LocService_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SPIDER_INTERFACES__SRV__DETAIL__LOC_SERVICE__STRUCT_H_
