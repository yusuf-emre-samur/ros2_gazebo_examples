cmake_minimum_required(VERSION 3.8)
project(gazebo_ros_plugins)


if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# gazebo
find_package(gazebo_dev REQUIRED)
find_package(gazebo_ros REQUIRED)
# rcl
find_package(rclcpp REQUIRED)
# interfaces
find_package(std_msgs REQUIRED)

 




# gazebo
# include_directories(${GAZEBO_INCLUDE_DIRS})
link_directories(${gazebo_dev_LIBRARY_DIRS})
# link_directories(${GAZEBO_LIBRARY_DIRS})
# set(APPEND CMAKE_CXX_FLAGS "${GAZEBO_CXX_FLAGS}")



if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()




# ros model plugin
add_library(ros_model_plugin SHARED
  src/ros_model_plugin.cpp
)
target_include_directories(ros_model_plugin PUBLIC include)
ament_target_dependencies(
  ros_model_plugin
  gazebo_dev
  gazebo_ros
  rclcpp
  std_msgs
)

# ros world plugin
add_library(ros_world_plugin SHARED
  src/ros_world_plugin.cpp
)
target_include_directories(ros_world_plugin PUBLIC include)
ament_target_dependencies(
  ros_world_plugin
  gazebo_dev
  gazebo_ros
  rclcpp
  std_msgs
)


install(
  TARGETS
  ros_model_plugin
  ros_world_plugin
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

ament_package()
