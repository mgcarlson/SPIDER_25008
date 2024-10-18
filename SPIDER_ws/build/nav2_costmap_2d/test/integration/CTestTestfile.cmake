# CMake generated Testfile for 
# Source directory: /home/dfolse/repos/SPIDER/SPIDER_ws/src/navigation2/nav2_costmap_2d/test/integration
# Build directory: /home/dfolse/repos/SPIDER/SPIDER_ws/build/nav2_costmap_2d/test/integration
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_collision_checker "/home/dfolse/.pyenv/shims/python3" "-u" "/opt/ros/foxy/share/ament_cmake_test/cmake/run_test.py" "/home/dfolse/repos/SPIDER/SPIDER_ws/build/nav2_costmap_2d/test_results/nav2_costmap_2d/test_collision_checker.xml" "--package-name" "nav2_costmap_2d" "--generate-result-on-success" "--env" "TEST_MAP=/home/dfolse/repos/SPIDER/SPIDER_ws/src/navigation2/nav2_costmap_2d/test/map/TenByTen.yaml" "TEST_LAUNCH_DIR=/home/dfolse/repos/SPIDER/SPIDER_ws/src/navigation2/nav2_costmap_2d/test/test_launch_files" "TEST_EXECUTABLE=/home/dfolse/repos/SPIDER/SPIDER_ws/build/nav2_costmap_2d/test/integration/test_collision_checker_exec" "--command" "/home/dfolse/repos/SPIDER/SPIDER_ws/src/navigation2/nav2_costmap_2d/test/integration/costmap_tests_launch.py")
set_tests_properties(test_collision_checker PROPERTIES  TIMEOUT "60" WORKING_DIRECTORY "/home/dfolse/repos/SPIDER/SPIDER_ws/build/nav2_costmap_2d/test/integration" _BACKTRACE_TRIPLES "/opt/ros/foxy/share/ament_cmake_test/cmake/ament_add_test.cmake;118;add_test;/home/dfolse/repos/SPIDER/SPIDER_ws/src/navigation2/nav2_costmap_2d/test/integration/CMakeLists.txt;57;ament_add_test;/home/dfolse/repos/SPIDER/SPIDER_ws/src/navigation2/nav2_costmap_2d/test/integration/CMakeLists.txt;0;")
add_test(footprint_tests "/home/dfolse/.pyenv/shims/python3" "-u" "/opt/ros/foxy/share/ament_cmake_test/cmake/run_test.py" "/home/dfolse/repos/SPIDER/SPIDER_ws/build/nav2_costmap_2d/test_results/nav2_costmap_2d/footprint_tests.xml" "--package-name" "nav2_costmap_2d" "--generate-result-on-success" "--env" "TEST_MAP=/home/dfolse/repos/SPIDER/SPIDER_ws/src/navigation2/nav2_costmap_2d/test/map/TenByTen.yaml" "TEST_LAUNCH_DIR=/home/dfolse/repos/SPIDER/SPIDER_ws/src/navigation2/nav2_costmap_2d/test/test_launch_files" "TEST_EXECUTABLE=/home/dfolse/repos/SPIDER/SPIDER_ws/build/nav2_costmap_2d/test/integration/footprint_tests_exec" "--command" "/home/dfolse/repos/SPIDER/SPIDER_ws/src/navigation2/nav2_costmap_2d/test/integration/costmap_tests_launch.py")
set_tests_properties(footprint_tests PROPERTIES  TIMEOUT "60" WORKING_DIRECTORY "/home/dfolse/repos/SPIDER/SPIDER_ws/build/nav2_costmap_2d/test/integration" _BACKTRACE_TRIPLES "/opt/ros/foxy/share/ament_cmake_test/cmake/ament_add_test.cmake;118;add_test;/home/dfolse/repos/SPIDER/SPIDER_ws/src/navigation2/nav2_costmap_2d/test/integration/CMakeLists.txt;67;ament_add_test;/home/dfolse/repos/SPIDER/SPIDER_ws/src/navigation2/nav2_costmap_2d/test/integration/CMakeLists.txt;0;")
add_test(inflation_tests "/home/dfolse/.pyenv/shims/python3" "-u" "/opt/ros/foxy/share/ament_cmake_test/cmake/run_test.py" "/home/dfolse/repos/SPIDER/SPIDER_ws/build/nav2_costmap_2d/test_results/nav2_costmap_2d/inflation_tests.xml" "--package-name" "nav2_costmap_2d" "--generate-result-on-success" "--env" "TEST_MAP=/home/dfolse/repos/SPIDER/SPIDER_ws/src/navigation2/nav2_costmap_2d/test/map/TenByTen.yaml" "TEST_LAUNCH_DIR=/home/dfolse/repos/SPIDER/SPIDER_ws/src/navigation2/nav2_costmap_2d/test/test_launch_files" "TEST_EXECUTABLE=/home/dfolse/repos/SPIDER/SPIDER_ws/build/nav2_costmap_2d/test/integration/inflation_tests_exec" "--command" "/home/dfolse/repos/SPIDER/SPIDER_ws/src/navigation2/nav2_costmap_2d/test/integration/costmap_tests_launch.py")
set_tests_properties(inflation_tests PROPERTIES  TIMEOUT "60" WORKING_DIRECTORY "/home/dfolse/repos/SPIDER/SPIDER_ws/build/nav2_costmap_2d/test/integration" _BACKTRACE_TRIPLES "/opt/ros/foxy/share/ament_cmake_test/cmake/ament_add_test.cmake;118;add_test;/home/dfolse/repos/SPIDER/SPIDER_ws/src/navigation2/nav2_costmap_2d/test/integration/CMakeLists.txt;77;ament_add_test;/home/dfolse/repos/SPIDER/SPIDER_ws/src/navigation2/nav2_costmap_2d/test/integration/CMakeLists.txt;0;")
add_test(obstacle_tests "/home/dfolse/.pyenv/shims/python3" "-u" "/opt/ros/foxy/share/ament_cmake_test/cmake/run_test.py" "/home/dfolse/repos/SPIDER/SPIDER_ws/build/nav2_costmap_2d/test_results/nav2_costmap_2d/obstacle_tests.xml" "--package-name" "nav2_costmap_2d" "--generate-result-on-success" "--env" "TEST_MAP=/home/dfolse/repos/SPIDER/SPIDER_ws/src/navigation2/nav2_costmap_2d/test/map/TenByTen.yaml" "TEST_LAUNCH_DIR=/home/dfolse/repos/SPIDER/SPIDER_ws/src/navigation2/nav2_costmap_2d/test/test_launch_files" "TEST_EXECUTABLE=/home/dfolse/repos/SPIDER/SPIDER_ws/build/nav2_costmap_2d/test/integration/obstacle_tests_exec" "--command" "/home/dfolse/repos/SPIDER/SPIDER_ws/src/navigation2/nav2_costmap_2d/test/integration/costmap_tests_launch.py")
set_tests_properties(obstacle_tests PROPERTIES  TIMEOUT "60" WORKING_DIRECTORY "/home/dfolse/repos/SPIDER/SPIDER_ws/build/nav2_costmap_2d/test/integration" _BACKTRACE_TRIPLES "/opt/ros/foxy/share/ament_cmake_test/cmake/ament_add_test.cmake;118;add_test;/home/dfolse/repos/SPIDER/SPIDER_ws/src/navigation2/nav2_costmap_2d/test/integration/CMakeLists.txt;87;ament_add_test;/home/dfolse/repos/SPIDER/SPIDER_ws/src/navigation2/nav2_costmap_2d/test/integration/CMakeLists.txt;0;")
add_test(range_tests "/home/dfolse/.pyenv/shims/python3" "-u" "/opt/ros/foxy/share/ament_cmake_test/cmake/run_test.py" "/home/dfolse/repos/SPIDER/SPIDER_ws/build/nav2_costmap_2d/test_results/nav2_costmap_2d/range_tests.xml" "--package-name" "nav2_costmap_2d" "--generate-result-on-success" "--env" "TEST_MAP=/home/dfolse/repos/SPIDER/SPIDER_ws/src/navigation2/nav2_costmap_2d/test/map/TenByTen.yaml" "TEST_LAUNCH_DIR=/home/dfolse/repos/SPIDER/SPIDER_ws/src/navigation2/nav2_costmap_2d/test/test_launch_files" "TEST_EXECUTABLE=/home/dfolse/repos/SPIDER/SPIDER_ws/build/nav2_costmap_2d/test/integration/range_tests_exec" "--command" "/home/dfolse/repos/SPIDER/SPIDER_ws/src/navigation2/nav2_costmap_2d/test/integration/costmap_tests_launch.py")
set_tests_properties(range_tests PROPERTIES  TIMEOUT "60" WORKING_DIRECTORY "/home/dfolse/repos/SPIDER/SPIDER_ws/build/nav2_costmap_2d/test/integration" _BACKTRACE_TRIPLES "/opt/ros/foxy/share/ament_cmake_test/cmake/ament_add_test.cmake;118;add_test;/home/dfolse/repos/SPIDER/SPIDER_ws/src/navigation2/nav2_costmap_2d/test/integration/CMakeLists.txt;97;ament_add_test;/home/dfolse/repos/SPIDER/SPIDER_ws/src/navigation2/nav2_costmap_2d/test/integration/CMakeLists.txt;0;")
