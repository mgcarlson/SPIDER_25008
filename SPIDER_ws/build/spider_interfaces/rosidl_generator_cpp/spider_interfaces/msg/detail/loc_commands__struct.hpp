// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from spider_interfaces:msg/LocCommands.idl
// generated code does not contain a copyright notice

#ifndef SPIDER_INTERFACES__MSG__DETAIL__LOC_COMMANDS__STRUCT_HPP_
#define SPIDER_INTERFACES__MSG__DETAIL__LOC_COMMANDS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'move_type'
#include "std_msgs/msg/detail/string__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__spider_interfaces__msg__LocCommands __attribute__((deprecated))
#else
# define DEPRECATED__spider_interfaces__msg__LocCommands __declspec(deprecated)
#endif

namespace spider_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LocCommands_
{
  using Type = LocCommands_<ContainerAllocator>;

  explicit LocCommands_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : move_type(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->move_amount = 0ll;
    }
  }

  explicit LocCommands_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : move_type(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->move_amount = 0ll;
    }
  }

  // field types and members
  using _move_type_type =
    std_msgs::msg::String_<ContainerAllocator>;
  _move_type_type move_type;
  using _move_amount_type =
    int64_t;
  _move_amount_type move_amount;

  // setters for named parameter idiom
  Type & set__move_type(
    const std_msgs::msg::String_<ContainerAllocator> & _arg)
  {
    this->move_type = _arg;
    return *this;
  }
  Type & set__move_amount(
    const int64_t & _arg)
  {
    this->move_amount = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    spider_interfaces::msg::LocCommands_<ContainerAllocator> *;
  using ConstRawPtr =
    const spider_interfaces::msg::LocCommands_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<spider_interfaces::msg::LocCommands_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<spider_interfaces::msg::LocCommands_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      spider_interfaces::msg::LocCommands_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<spider_interfaces::msg::LocCommands_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      spider_interfaces::msg::LocCommands_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<spider_interfaces::msg::LocCommands_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<spider_interfaces::msg::LocCommands_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<spider_interfaces::msg::LocCommands_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__spider_interfaces__msg__LocCommands
    std::shared_ptr<spider_interfaces::msg::LocCommands_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__spider_interfaces__msg__LocCommands
    std::shared_ptr<spider_interfaces::msg::LocCommands_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LocCommands_ & other) const
  {
    if (this->move_type != other.move_type) {
      return false;
    }
    if (this->move_amount != other.move_amount) {
      return false;
    }
    return true;
  }
  bool operator!=(const LocCommands_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LocCommands_

// alias to use template instance with default allocator
using LocCommands =
  spider_interfaces::msg::LocCommands_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace spider_interfaces

#endif  // SPIDER_INTERFACES__MSG__DETAIL__LOC_COMMANDS__STRUCT_HPP_
