// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from spider_interfaces:srv/LocService.idl
// generated code does not contain a copyright notice

#ifndef SPIDER_INTERFACES__SRV__DETAIL__LOC_SERVICE__BUILDER_HPP_
#define SPIDER_INTERFACES__SRV__DETAIL__LOC_SERVICE__BUILDER_HPP_

#include "spider_interfaces/srv/detail/loc_service__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace spider_interfaces
{

namespace srv
{

namespace builder
{

class Init_LocService_Request_delta_angle
{
public:
  explicit Init_LocService_Request_delta_angle(::spider_interfaces::srv::LocService_Request & msg)
  : msg_(msg)
  {}
  ::spider_interfaces::srv::LocService_Request delta_angle(::spider_interfaces::srv::LocService_Request::_delta_angle_type arg)
  {
    msg_.delta_angle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::spider_interfaces::srv::LocService_Request msg_;
};

class Init_LocService_Request_move_amount
{
public:
  explicit Init_LocService_Request_move_amount(::spider_interfaces::srv::LocService_Request & msg)
  : msg_(msg)
  {}
  Init_LocService_Request_delta_angle move_amount(::spider_interfaces::srv::LocService_Request::_move_amount_type arg)
  {
    msg_.move_amount = std::move(arg);
    return Init_LocService_Request_delta_angle(msg_);
  }

private:
  ::spider_interfaces::srv::LocService_Request msg_;
};

class Init_LocService_Request_move_type
{
public:
  Init_LocService_Request_move_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LocService_Request_move_amount move_type(::spider_interfaces::srv::LocService_Request::_move_type_type arg)
  {
    msg_.move_type = std::move(arg);
    return Init_LocService_Request_move_amount(msg_);
  }

private:
  ::spider_interfaces::srv::LocService_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::spider_interfaces::srv::LocService_Request>()
{
  return spider_interfaces::srv::builder::Init_LocService_Request_move_type();
}

}  // namespace spider_interfaces


namespace spider_interfaces
{

namespace srv
{

namespace builder
{

class Init_LocService_Response_status
{
public:
  Init_LocService_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::spider_interfaces::srv::LocService_Response status(::spider_interfaces::srv::LocService_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::spider_interfaces::srv::LocService_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::spider_interfaces::srv::LocService_Response>()
{
  return spider_interfaces::srv::builder::Init_LocService_Response_status();
}

}  // namespace spider_interfaces

#endif  // SPIDER_INTERFACES__SRV__DETAIL__LOC_SERVICE__BUILDER_HPP_
