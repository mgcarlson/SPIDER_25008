# Install script for directory: /home/dfolse/repos/SPIDER/SPIDER_ws/src/luxonis/depthai-ros-examples/depthai_examples

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/dfolse/repos/SPIDER/SPIDER_ws/install/depthai_examples")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/depthai_examples" TYPE DIRECTORY FILES "/home/dfolse/repos/SPIDER/SPIDER_ws/src/luxonis/depthai-ros-examples/depthai_examples/params")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/depthai_examples" TYPE DIRECTORY FILES "/home/dfolse/repos/SPIDER/SPIDER_ws/src/luxonis/depthai-ros-examples/depthai_examples/rviz")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/depthai_examples" TYPE DIRECTORY FILES "/home/dfolse/repos/SPIDER/SPIDER_ws/src/luxonis/depthai-ros-examples/depthai_examples/resources")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/depthai_examples/launch" TYPE DIRECTORY FILES "/home/dfolse/repos/SPIDER/SPIDER_ws/src/luxonis/depthai-ros-examples/depthai_examples/launch/" FILES_MATCHING REGEX "/[^/]*\\.py$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/crop_control_service" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/crop_control_service")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/crop_control_service"
         RPATH "/opt/ros/foxy/lib:/opt/ros/foxy/opt/yaml_cpp_vendor/lib:/opt/ros/foxy/lib/aarch64-linux-gnu")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/depthai_examples" TYPE EXECUTABLE FILES "/home/dfolse/repos/SPIDER/SPIDER_ws/build/depthai_examples/crop_control_service")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/crop_control_service" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/crop_control_service")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/crop_control_service"
         OLD_RPATH "/opt/ros/foxy/lib:/opt/ros/foxy/opt/yaml_cpp_vendor/lib:/opt/ros/foxy/lib/aarch64-linux-gnu:"
         NEW_RPATH "/opt/ros/foxy/lib:/opt/ros/foxy/opt/yaml_cpp_vendor/lib:/opt/ros/foxy/lib/aarch64-linux-gnu")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/crop_control_service")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/mobilenet_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/mobilenet_node")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/mobilenet_node"
         RPATH "/opt/ros/foxy/lib:/opt/ros/foxy/opt/yaml_cpp_vendor/lib:/opt/ros/foxy/lib/aarch64-linux-gnu")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/depthai_examples" TYPE EXECUTABLE FILES "/home/dfolse/repos/SPIDER/SPIDER_ws/build/depthai_examples/mobilenet_node")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/mobilenet_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/mobilenet_node")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/mobilenet_node"
         OLD_RPATH "/opt/ros/foxy/lib:/opt/ros/foxy/opt/yaml_cpp_vendor/lib:/opt/ros/foxy/lib/aarch64-linux-gnu:"
         NEW_RPATH "/opt/ros/foxy/lib:/opt/ros/foxy/opt/yaml_cpp_vendor/lib:/opt/ros/foxy/lib/aarch64-linux-gnu")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/mobilenet_node")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/rgb_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/rgb_node")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/rgb_node"
         RPATH "/opt/ros/foxy/lib:/opt/ros/foxy/opt/yaml_cpp_vendor/lib:/opt/ros/foxy/lib/aarch64-linux-gnu")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/depthai_examples" TYPE EXECUTABLE FILES "/home/dfolse/repos/SPIDER/SPIDER_ws/build/depthai_examples/rgb_node")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/rgb_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/rgb_node")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/rgb_node"
         OLD_RPATH "/opt/ros/foxy/lib:/opt/ros/foxy/opt/yaml_cpp_vendor/lib:/opt/ros/foxy/lib/aarch64-linux-gnu:"
         NEW_RPATH "/opt/ros/foxy/lib:/opt/ros/foxy/opt/yaml_cpp_vendor/lib:/opt/ros/foxy/lib/aarch64-linux-gnu")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/rgb_node")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/rgb_stereo_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/rgb_stereo_node")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/rgb_stereo_node"
         RPATH "/opt/ros/foxy/lib:/opt/ros/foxy/opt/yaml_cpp_vendor/lib:/opt/ros/foxy/lib/aarch64-linux-gnu")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/depthai_examples" TYPE EXECUTABLE FILES "/home/dfolse/repos/SPIDER/SPIDER_ws/build/depthai_examples/rgb_stereo_node")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/rgb_stereo_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/rgb_stereo_node")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/rgb_stereo_node"
         OLD_RPATH "/opt/ros/foxy/lib:/opt/ros/foxy/opt/yaml_cpp_vendor/lib:/opt/ros/foxy/lib/aarch64-linux-gnu:"
         NEW_RPATH "/opt/ros/foxy/lib:/opt/ros/foxy/opt/yaml_cpp_vendor/lib:/opt/ros/foxy/lib/aarch64-linux-gnu")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/rgb_stereo_node")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/stereo_inertial_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/stereo_inertial_node")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/stereo_inertial_node"
         RPATH "/opt/ros/foxy/lib:/opt/ros/foxy/opt/yaml_cpp_vendor/lib:/opt/ros/foxy/lib/aarch64-linux-gnu")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/depthai_examples" TYPE EXECUTABLE FILES "/home/dfolse/repos/SPIDER/SPIDER_ws/build/depthai_examples/stereo_inertial_node")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/stereo_inertial_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/stereo_inertial_node")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/stereo_inertial_node"
         OLD_RPATH "/opt/ros/foxy/lib:/opt/ros/foxy/opt/yaml_cpp_vendor/lib:/opt/ros/foxy/lib/aarch64-linux-gnu:"
         NEW_RPATH "/opt/ros/foxy/lib:/opt/ros/foxy/opt/yaml_cpp_vendor/lib:/opt/ros/foxy/lib/aarch64-linux-gnu")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/stereo_inertial_node")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/stereo_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/stereo_node")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/stereo_node"
         RPATH "/opt/ros/foxy/lib:/opt/ros/foxy/opt/yaml_cpp_vendor/lib:/opt/ros/foxy/lib/aarch64-linux-gnu")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/depthai_examples" TYPE EXECUTABLE FILES "/home/dfolse/repos/SPIDER/SPIDER_ws/build/depthai_examples/stereo_node")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/stereo_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/stereo_node")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/stereo_node"
         OLD_RPATH "/opt/ros/foxy/lib:/opt/ros/foxy/opt/yaml_cpp_vendor/lib:/opt/ros/foxy/lib/aarch64-linux-gnu:"
         NEW_RPATH "/opt/ros/foxy/lib:/opt/ros/foxy/opt/yaml_cpp_vendor/lib:/opt/ros/foxy/lib/aarch64-linux-gnu")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/stereo_node")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/yolov4_spatial_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/yolov4_spatial_node")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/yolov4_spatial_node"
         RPATH "/opt/ros/foxy/lib:/opt/ros/foxy/opt/yaml_cpp_vendor/lib:/opt/ros/foxy/lib/aarch64-linux-gnu")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/depthai_examples" TYPE EXECUTABLE FILES "/home/dfolse/repos/SPIDER/SPIDER_ws/build/depthai_examples/yolov4_spatial_node")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/yolov4_spatial_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/yolov4_spatial_node")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/yolov4_spatial_node"
         OLD_RPATH "/opt/ros/foxy/lib:/opt/ros/foxy/opt/yaml_cpp_vendor/lib:/opt/ros/foxy/lib/aarch64-linux-gnu:"
         NEW_RPATH "/opt/ros/foxy/lib:/opt/ros/foxy/opt/yaml_cpp_vendor/lib:/opt/ros/foxy/lib/aarch64-linux-gnu")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/depthai_examples/yolov4_spatial_node")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/package_run_dependencies" TYPE FILE FILES "/home/dfolse/repos/SPIDER/SPIDER_ws/build/depthai_examples/ament_cmake_index/share/ament_index/resource_index/package_run_dependencies/depthai_examples")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/parent_prefix_path" TYPE FILE FILES "/home/dfolse/repos/SPIDER/SPIDER_ws/build/depthai_examples/ament_cmake_index/share/ament_index/resource_index/parent_prefix_path/depthai_examples")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/depthai_examples/environment" TYPE FILE FILES "/opt/ros/foxy/share/ament_cmake_core/cmake/environment_hooks/environment/ament_prefix_path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/depthai_examples/environment" TYPE FILE FILES "/home/dfolse/repos/SPIDER/SPIDER_ws/build/depthai_examples/ament_cmake_environment_hooks/ament_prefix_path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/depthai_examples/environment" TYPE FILE FILES "/opt/ros/foxy/share/ament_cmake_core/cmake/environment_hooks/environment/path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/depthai_examples/environment" TYPE FILE FILES "/home/dfolse/repos/SPIDER/SPIDER_ws/build/depthai_examples/ament_cmake_environment_hooks/path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/depthai_examples" TYPE FILE FILES "/home/dfolse/repos/SPIDER/SPIDER_ws/build/depthai_examples/ament_cmake_environment_hooks/local_setup.bash")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/depthai_examples" TYPE FILE FILES "/home/dfolse/repos/SPIDER/SPIDER_ws/build/depthai_examples/ament_cmake_environment_hooks/local_setup.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/depthai_examples" TYPE FILE FILES "/home/dfolse/repos/SPIDER/SPIDER_ws/build/depthai_examples/ament_cmake_environment_hooks/local_setup.zsh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/depthai_examples" TYPE FILE FILES "/home/dfolse/repos/SPIDER/SPIDER_ws/build/depthai_examples/ament_cmake_environment_hooks/local_setup.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/depthai_examples" TYPE FILE FILES "/home/dfolse/repos/SPIDER/SPIDER_ws/build/depthai_examples/ament_cmake_environment_hooks/package.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/packages" TYPE FILE FILES "/home/dfolse/repos/SPIDER/SPIDER_ws/build/depthai_examples/ament_cmake_index/share/ament_index/resource_index/packages/depthai_examples")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/depthai_examples/cmake" TYPE FILE FILES
    "/home/dfolse/repos/SPIDER/SPIDER_ws/build/depthai_examples/ament_cmake_core/depthai_examplesConfig.cmake"
    "/home/dfolse/repos/SPIDER/SPIDER_ws/build/depthai_examples/ament_cmake_core/depthai_examplesConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/depthai_examples" TYPE FILE FILES "/home/dfolse/repos/SPIDER/SPIDER_ws/src/luxonis/depthai-ros-examples/depthai_examples/package.xml")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/dfolse/repos/SPIDER/SPIDER_ws/build/depthai_examples/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
