cmake_minimum_required(VERSION 3.8)
project(soccer_vision_2d_layers)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake_ros REQUIRED)
find_package(rqt_image_overlay_layer REQUIRED)
find_package(soccer_vision_2d_msgs REQUIRED)
find_package(vision_msgs_layers REQUIRED)

add_library(soccer_vision_2d_layers
  src/ball.cpp
  src/ball_array.cpp
  src/confidence.cpp
  src/field_boundary.cpp
  src/goalpost.cpp
  src/goalpost_array.cpp
  src/marking_ellipse.cpp
  src/marking_ellipse_array.cpp
  src/marking_intersection.cpp
  src/marking_intersection_array.cpp
  src/marking_segment.cpp
  src/marking_segment_array.cpp
  src/obstacle.cpp
  src/obstacle_array.cpp
  src/robot.cpp
  src/robot_array.cpp)
target_compile_features(soccer_vision_2d_layers PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
target_include_directories(soccer_vision_2d_layers PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
ament_target_dependencies(
  soccer_vision_2d_layers
  rqt_image_overlay_layer
  soccer_vision_2d_msgs
  vision_msgs_layers
)

pluginlib_export_plugin_description_file(rqt_image_overlay_layer plugins.xml)

# Causes the visibility macros to use dllexport rather than dllimport,
# which is appropriate when building the dll but not consuming it.
target_compile_definitions(soccer_vision_2d_layers PRIVATE "SOCCER_VISION_2D_LAYERS_BUILDING_LIBRARY")

install(
  DIRECTORY include/
  DESTINATION include
)
install(
  TARGETS soccer_vision_2d_layers
  EXPORT export_${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_export_include_directories(
  include
)
ament_export_libraries(
  soccer_vision_2d_layers
)
ament_export_targets(
  export_${PROJECT_NAME}
)

ament_package()
