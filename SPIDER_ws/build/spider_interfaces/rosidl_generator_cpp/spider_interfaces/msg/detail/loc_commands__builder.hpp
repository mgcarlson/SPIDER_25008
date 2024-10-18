// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from spider_interfaces:msg/LocCommands.idl
// generated code does not contain a copyright notice

#ifndef SPIDER_INTERFACES__MSG__DETAIL__LOC_COMMANDS__BUILDER_HPP_
#define SPIDER_INTERFACES__MSG__DETAIL__LOC_COMMANDS__BUILDER_HPP_

#include "spider_interfaces/msg/detail/loc_commands__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace spider_interfaces
{

namespace msg
{

namespace builder
{

class Init_LocCommands_move_amount
{
public:
  explicit Init_LocCommands_move_amount(::spider_interfaces::msg::LocCommands & msg)
  : msg_(msg)
  {}
  ::spider_interfaces::msg::LocCommands move_amount(::spider_interfaces::msg::LocCommands::_move_amount_type arg)
  {
    msg_.move_amount = std::move(arg);
    return std::move(msg_);
  }

private:
  ::spider_interfaces::msg::LocCommands msg_;
};

class Init_LocCommands_move_type
{
public:
  Init_LocCommands_move_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LocCommands_move_amount move_type(::spider_interfaces::msg::LocCommands::_move_type_type arg)
  {
    msg_.move_type = std::move(arg);
    return Init_LocCommands_move_amount(msg_);
  }

private:
  ::spider_interfaces::msg::LocCommands msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::spider_interfaces::msg::LocCommands>()
{
  return spider_interfaces::msg::builder::Init_LocCommands_move_type();
}

}  // namespace spider_interfaces

#endif  // SPIDER_INTERFACES__MSG__DETAIL__LOC_COMMANDS__BUILDER_HPP_
