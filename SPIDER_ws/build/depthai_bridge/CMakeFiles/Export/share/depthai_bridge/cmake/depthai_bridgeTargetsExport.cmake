# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.5)
   message(FATAL_ERROR "CMake >= 2.6.0 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.6)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_targetsDefined)
set(_targetsNotDefined)
set(_expectedTargets)
foreach(_expectedTarget depthai_bridge::depthai_bridge)
  list(APPEND _expectedTargets ${_expectedTarget})
  if(NOT TARGET ${_expectedTarget})
    list(APPEND _targetsNotDefined ${_expectedTarget})
  endif()
  if(TARGET ${_expectedTarget})
    list(APPEND _targetsDefined ${_expectedTarget})
  endif()
endforeach()
if("${_targetsDefined}" STREQUAL "${_expectedTargets}")
  unset(_targetsDefined)
  unset(_targetsNotDefined)
  unset(_expectedTargets)
  set(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT "${_targetsDefined}" STREQUAL "")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_targetsDefined}\nTargets not yet defined: ${_targetsNotDefined}\n")
endif()
unset(_targetsDefined)
unset(_targetsNotDefined)
unset(_expectedTargets)


# Compute the installation prefix relative to this file.
get_filename_component(_IMPORT_PREFIX "${CMAKE_CURRENT_LIST_FILE}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
if(_IMPORT_PREFIX STREQUAL "/")
  set(_IMPORT_PREFIX "")
endif()

# Create imported target depthai_bridge::depthai_bridge
add_library(depthai_bridge::depthai_bridge SHARED IMPORTED)

set_target_properties(depthai_bridge::depthai_bridge PROPERTIES
  INTERFACE_COMPILE_DEFINITIONS "IS_ROS2"
  INTERFACE_INCLUDE_DIRECTORIES "/opt/ros/foxy/include;/opt/ros/foxy/opt/yaml_cpp_vendor/include;/usr/include/opencv4;${_IMPORT_PREFIX}/include"
  INTERFACE_LINK_LIBRARIES "depthai_ros_msgs::depthai_ros_msgs__rosidl_generator_c;depthai_ros_msgs::depthai_ros_msgs__rosidl_typesupport_introspection_c;depthai_ros_msgs::depthai_ros_msgs__rosidl_typesupport_c;depthai_ros_msgs::depthai_ros_msgs__rosidl_generator_cpp;depthai_ros_msgs::depthai_ros_msgs__rosidl_typesupport_introspection_cpp;depthai_ros_msgs::depthai_ros_msgs__rosidl_typesupport_cpp;rclcpp::rclcpp;sensor_msgs::sensor_msgs__rosidl_generator_c;sensor_msgs::sensor_msgs__rosidl_typesupport_introspection_c;sensor_msgs::sensor_msgs__rosidl_typesupport_c;sensor_msgs::sensor_msgs__rosidl_generator_cpp;sensor_msgs::sensor_msgs__rosidl_typesupport_introspection_cpp;sensor_msgs::sensor_msgs__rosidl_typesupport_cpp;stereo_msgs::stereo_msgs__rosidl_generator_c;stereo_msgs::stereo_msgs__rosidl_typesupport_introspection_c;stereo_msgs::stereo_msgs__rosidl_typesupport_c;stereo_msgs::stereo_msgs__rosidl_generator_cpp;stereo_msgs::stereo_msgs__rosidl_typesupport_introspection_cpp;stereo_msgs::stereo_msgs__rosidl_typesupport_cpp;std_msgs::std_msgs__rosidl_generator_c;std_msgs::std_msgs__rosidl_typesupport_introspection_c;std_msgs::std_msgs__rosidl_typesupport_c;std_msgs::std_msgs__rosidl_generator_cpp;std_msgs::std_msgs__rosidl_typesupport_introspection_cpp;std_msgs::std_msgs__rosidl_typesupport_cpp;vision_msgs::vision_msgs__rosidl_generator_c;vision_msgs::vision_msgs__rosidl_typesupport_introspection_c;vision_msgs::vision_msgs__rosidl_typesupport_c;vision_msgs::vision_msgs__rosidl_generator_cpp;vision_msgs::vision_msgs__rosidl_typesupport_introspection_cpp;vision_msgs::vision_msgs__rosidl_typesupport_cpp;tf2_ros::tf2_ros;tf2_ros::static_transform_broadcaster_node;tf2_geometry_msgs::tf2_geometry_msgs;tf2::tf2;composition_interfaces::composition_interfaces__rosidl_generator_c;composition_interfaces::composition_interfaces__rosidl_typesupport_introspection_c;composition_interfaces::composition_interfaces__rosidl_typesupport_c;composition_interfaces::composition_interfaces__rosidl_generator_cpp;composition_interfaces::composition_interfaces__rosidl_typesupport_introspection_cpp;composition_interfaces::composition_interfaces__rosidl_typesupport_cpp;/opt/ros/foxy/lib/libament_index_cpp.so;/opt/ros/foxy/lib/libcamera_calibration_parsers.so;/opt/ros/foxy/lib/librosgraph_msgs__rosidl_generator_c.so;/opt/ros/foxy/lib/librosgraph_msgs__rosidl_typesupport_introspection_c.so;/opt/ros/foxy/lib/librosgraph_msgs__rosidl_typesupport_c.so;/opt/ros/foxy/lib/librosgraph_msgs__rosidl_typesupport_introspection_cpp.so;/opt/ros/foxy/lib/librosgraph_msgs__rosidl_typesupport_cpp.so;/opt/ros/foxy/lib/librcl_yaml_param_parser.so;yaml;/opt/ros/foxy/lib/libstatistics_msgs__rosidl_generator_c.so;/opt/ros/foxy/lib/libstatistics_msgs__rosidl_typesupport_introspection_c.so;/opt/ros/foxy/lib/libstatistics_msgs__rosidl_typesupport_c.so;/opt/ros/foxy/lib/libstatistics_msgs__rosidl_typesupport_introspection_cpp.so;/opt/ros/foxy/lib/libstatistics_msgs__rosidl_typesupport_cpp.so;/opt/ros/foxy/lib/libtracetools.so;/opt/ros/foxy/lib/libbuiltin_interfaces__rosidl_generator_c.so;/opt/ros/foxy/lib/libbuiltin_interfaces__rosidl_typesupport_introspection_c.so;/opt/ros/foxy/lib/libbuiltin_interfaces__rosidl_typesupport_c.so;/opt/ros/foxy/lib/libbuiltin_interfaces__rosidl_typesupport_introspection_cpp.so;/opt/ros/foxy/lib/libbuiltin_interfaces__rosidl_typesupport_cpp.so;/opt/ros/foxy/lib/libgeometry_msgs__rosidl_generator_c.so;/opt/ros/foxy/lib/libgeometry_msgs__rosidl_typesupport_introspection_c.so;/opt/ros/foxy/lib/libgeometry_msgs__rosidl_typesupport_c.so;/opt/ros/foxy/lib/libgeometry_msgs__rosidl_typesupport_introspection_cpp.so;/opt/ros/foxy/lib/libgeometry_msgs__rosidl_typesupport_cpp.so;/opt/ros/foxy/lib/libstd_msgs__rosidl_generator_c.so;/opt/ros/foxy/lib/libstd_msgs__rosidl_typesupport_introspection_c.so;/opt/ros/foxy/lib/libstd_msgs__rosidl_typesupport_c.so;/opt/ros/foxy/lib/libstd_msgs__rosidl_typesupport_introspection_cpp.so;/opt/ros/foxy/lib/libstd_msgs__rosidl_typesupport_cpp.so;/opt/ros/foxy/lib/librosidl_typesupport_c.so;/opt/ros/foxy/lib/librosidl_typesupport_cpp.so;/opt/ros/foxy/lib/librosidl_runtime_c.so;/opt/ros/foxy/lib/librosidl_typesupport_introspection_c.so;/opt/ros/foxy/lib/librosidl_typesupport_introspection_cpp.so;/opt/ros/foxy/opt/yaml_cpp_vendor/lib/libyaml-cpp.so.0.6.2;/opt/ros/foxy/lib/libcamera_info_manager.so;opencv_imgproc;opencv_highgui;opencv_calib3d;/opt/ros/foxy/lib/libcv_bridge.so;/opt/ros/foxy/lib/libimage_transport.so;/opt/ros/foxy/lib/libmessage_filters.so;rclcpp::rclcpp;/opt/ros/foxy/lib/librclcpp.so;-lpthread;libstatistics_collector::libstatistics_collector;libstatistics_collector::libstatistics_collector_test_msgs__rosidl_generator_c;libstatistics_collector::libstatistics_collector_test_msgs__rosidl_typesupport_introspection_c;libstatistics_collector::libstatistics_collector_test_msgs__rosidl_typesupport_c;libstatistics_collector::libstatistics_collector_test_msgs__rosidl_generator_cpp;libstatistics_collector::libstatistics_collector_test_msgs__rosidl_typesupport_introspection_cpp;libstatistics_collector::libstatistics_collector_test_msgs__rosidl_typesupport_cpp;rcl::rcl;rcl_yaml_param_parser::rcl_yaml_param_parser;rosgraph_msgs::rosgraph_msgs__rosidl_generator_c;rosgraph_msgs::rosgraph_msgs__rosidl_typesupport_introspection_c;rosgraph_msgs::rosgraph_msgs__rosidl_typesupport_c;rosgraph_msgs::rosgraph_msgs__rosidl_generator_cpp;rosgraph_msgs::rosgraph_msgs__rosidl_typesupport_introspection_cpp;rosgraph_msgs::rosgraph_msgs__rosidl_typesupport_cpp;statistics_msgs::statistics_msgs__rosidl_generator_c;statistics_msgs::statistics_msgs__rosidl_typesupport_introspection_c;statistics_msgs::statistics_msgs__rosidl_typesupport_c;statistics_msgs::statistics_msgs__rosidl_generator_cpp;statistics_msgs::statistics_msgs__rosidl_typesupport_introspection_cpp;statistics_msgs::statistics_msgs__rosidl_typesupport_cpp;tracetools::tracetools;/opt/ros/foxy/lib/libsensor_msgs__rosidl_generator_c.so;/opt/ros/foxy/lib/libsensor_msgs__rosidl_typesupport_introspection_c.so;sensor_msgs::sensor_msgs__rosidl_generator_c;rosidl_typesupport_introspection_c::rosidl_typesupport_introspection_c;/opt/ros/foxy/lib/libsensor_msgs__rosidl_typesupport_c.so;rosidl_typesupport_c::rosidl_typesupport_c;/opt/ros/foxy/lib/libsensor_msgs__rosidl_typesupport_introspection_cpp.so;rosidl_typesupport_introspection_cpp::rosidl_typesupport_introspection_cpp;/opt/ros/foxy/lib/libsensor_msgs__rosidl_typesupport_cpp.so;rosidl_runtime_c::rosidl_runtime_c;rosidl_runtime_cpp::rosidl_runtime_cpp;rosidl_typesupport_cpp::rosidl_typesupport_cpp;rosidl_typesupport_interface::rosidl_typesupport_interface;builtin_interfaces::builtin_interfaces__rosidl_generator_c;builtin_interfaces::builtin_interfaces__rosidl_typesupport_introspection_c;builtin_interfaces::builtin_interfaces__rosidl_typesupport_c;builtin_interfaces::builtin_interfaces__rosidl_generator_cpp;builtin_interfaces::builtin_interfaces__rosidl_typesupport_introspection_cpp;builtin_interfaces::builtin_interfaces__rosidl_typesupport_cpp;geometry_msgs::geometry_msgs__rosidl_generator_c;geometry_msgs::geometry_msgs__rosidl_typesupport_introspection_c;geometry_msgs::geometry_msgs__rosidl_typesupport_c;geometry_msgs::geometry_msgs__rosidl_generator_cpp;geometry_msgs::geometry_msgs__rosidl_typesupport_introspection_cpp;geometry_msgs::geometry_msgs__rosidl_typesupport_cpp;std_msgs::std_msgs__rosidl_generator_c;std_msgs::std_msgs__rosidl_typesupport_introspection_c;std_msgs::std_msgs__rosidl_typesupport_c;std_msgs::std_msgs__rosidl_generator_cpp;std_msgs::std_msgs__rosidl_typesupport_introspection_cpp;std_msgs::std_msgs__rosidl_typesupport_cpp;/opt/ros/foxy/lib/aarch64-linux-gnu/libconsole_bridge.so.1.0;/opt/ros/foxy/lib/libclass_loader.so;console_bridge::console_bridge;/opt/ros/foxy/lib/librcutils.so;dl;/opt/ros/foxy/lib/librcpputils.so;ament_index_cpp::ament_index_cpp;class_loader::class_loader;rcutils::rcutils;rcpputils::rcpputils;tinyxml2::tinyxml2;stdc++fs;depthai::core;opencv_imgproc;opencv_highgui;opencv_calib3d"
)

if(CMAKE_VERSION VERSION_LESS 2.8.12)
  message(FATAL_ERROR "This file relies on consumers using CMake 2.8.12 or greater.")
endif()

# Load information for each installed configuration.
get_filename_component(_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
file(GLOB CONFIG_FILES "${_DIR}/depthai_bridgeTargetsExport-*.cmake")
foreach(f ${CONFIG_FILES})
  include(${f})
endforeach()

# Cleanup temporary variables.
set(_IMPORT_PREFIX)

# Loop over all imported files and verify that they actually exist
foreach(target ${_IMPORT_CHECK_TARGETS} )
  foreach(file ${_IMPORT_CHECK_FILES_FOR_${target}} )
    if(NOT EXISTS "${file}" )
      message(FATAL_ERROR "The imported target \"${target}\" references the file
   \"${file}\"
but this file does not exist.  Possible reasons include:
* The file was deleted, renamed, or moved to another location.
* An install or uninstall procedure did not complete successfully.
* The installation package was faulty and contained
   \"${CMAKE_CURRENT_LIST_FILE}\"
but not all the files it references.
")
    endif()
  endforeach()
  unset(_IMPORT_CHECK_FILES_FOR_${target})
endforeach()
unset(_IMPORT_CHECK_TARGETS)

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
