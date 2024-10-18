// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from spider_interfaces:srv/LocService.idl
// generated code does not contain a copyright notice

#ifndef SPIDER_INTERFACES__SRV__DETAIL__LOC_SERVICE__STRUCT_HPP_
#define SPIDER_INTERFACES__SRV__DETAIL__LOC_SERVICE__STRUCT_HPP_

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
# define DEPRECATED__spider_interfaces__srv__LocService_Request __attribute__((deprecated))
#else
# define DEPRECATED__spider_interfaces__srv__LocService_Request __declspec(deprecated)
#endif

namespace spider_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct LocService_Request_
{
  using Type = LocService_Request_<ContainerAllocator>;

  explicit LocService_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : move_type(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->move_amount = 0ll;
      this->delta_angle = 0.0;
    }
  }

  explicit LocService_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : move_type(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->move_amount = 0ll;
      this->delta_angle = 0.0;
    }
  }

  // field types and members
  using _move_type_type =
    std_msgs::msg::String_<ContainerAllocator>;
  _move_type_type move_type;
  using _move_amount_type =
    int64_t;
  _move_amount_type move_amount;
  using _delta_angle_type =
    double;
  _delta_angle_type delta_angle;

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
  Type & set__delta_angle(
    const double & _arg)
  {
    this->delta_angle = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    spider_interfaces::srv::LocService_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const spider_interfaces::srv::LocService_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<spider_interfaces::srv::LocService_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<spider_interfaces::srv::LocService_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      spider_interfaces::srv::LocService_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<spider_interfaces::srv::LocService_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      spider_interfaces::srv::LocService_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<spider_interfaces::srv::LocService_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<spider_interfaces::srv::LocService_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<spider_interfaces::srv::LocService_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__spider_interfaces__srv__LocService_Request
    std::shared_ptr<spider_interfaces::srv::LocService_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__spider_interfaces__srv__LocService_Request
    std::shared_ptr<spider_interfaces::srv::LocService_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LocService_Request_ & other) const
  {
    if (this->move_type != other.move_type) {
      return false;
    }
    if (this->move_amount != other.move_amount) {
      return false;
    }
    if (this->delta_angle != other.delta_angle) {
      return false;
    }
    return true;
  }
  bool operator!=(const LocService_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LocService_Request_

// alias to use template instance with default allocator
using LocService_Request =
  spider_interfaces::srv::LocService_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace spider_interfaces


// Include directives for member types
// Member 'status'
// already included above
// #include "std_msgs/msg/detail/string__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__spider_interfaces__srv__LocService_Response __attribute__((deprecated))
#else
# define DEPRECATED__spider_interfaces__srv__LocService_Response __declspec(deprecated)
#endif

namespace spider_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct LocService_Response_
{
  using Type = LocService_Response_<ContainerAllocator>;

  explicit LocService_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : status(_init)
  {
    (void)_init;
  }

  explicit LocService_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : status(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _status_type =
    std_msgs::msg::String_<ContainerAllocator>;
  _status_type status;

  // setters for named parameter idiom
  Type & set__status(
    const std_msgs::msg::String_<ContainerAllocator> & _arg)
  {
    this->status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    spider_interfaces::srv::LocService_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const spider_interfaces::srv::LocService_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<spider_interfaces::srv::LocService_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<spider_interfaces::srv::LocService_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      spider_interfaces::srv::LocService_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<spider_interfaces::srv::LocService_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      spider_interfaces::srv::LocService_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<spider_interfaces::srv::LocService_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<spider_interfaces::srv::LocService_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<spider_interfaces::srv::LocService_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__spider_interfaces__srv__LocService_Response
    std::shared_ptr<spider_interfaces::srv::LocService_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__spider_interfaces__srv__LocService_Response
    std::shared_ptr<spider_interfaces::srv::LocService_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LocService_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const LocService_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LocService_Response_

// alias to use template instance with default allocator
using LocService_Response =
  spider_interfaces::srv::LocService_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace spider_interfaces

namespace spider_interfaces
{

namespace srv
{

struct LocService
{
  using Request = spider_interfaces::srv::LocService_Request;
  using Response = spider_interfaces::srv::LocService_Response;
};

}  // namespace srv

}  // namespace spider_interfaces

#endif  // SPIDER_INTERFACES__SRV__DETAIL__LOC_SERVICE__STRUCT_HPP_
