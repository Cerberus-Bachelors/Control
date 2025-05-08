cmake_minimum_required(VERSION 3.8)
project(cerberus_controller)
enable_language(CUDA)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(trajectory_msgs REQUIRED)
find_package(cerberus_msgs REQUIRED)
find_package(Eigen3 REQUIRED)


# Set paths to TensorRT includes and libraries

if(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "x86_64")
include_directories(/usr/include/x86_64-linux-gnu)
link_directories(/usr/lib/x86_64-linux-gnu)
elseif(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "aarch64")
include_directories(/usr/include/aarch64-linux-gnu)
link_directories(/usr/lib/aarch64-linux-gnu)
include_directories(/usr/local/cuda-12.6/include)
link_directories(/usr/local/cuda-12.6/lib64)
endif()

# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

add_executable(input_encoder src/InputEncoder.cpp)
target_link_libraries(input_encoder nvinfer nvonnxparser cuda cudart)
ament_target_dependencies(input_encoder rclcpp std_msgs sensor_msgs cerberus_msgs trajectory_msgs Eigen3)

target_include_directories(input_encoder PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(input_encoder PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17


add_executable(inference src/inference.cpp src/BufferManager.cpp)
target_link_libraries(inference nvinfer nvonnxparser cuda cudart)
ament_target_dependencies(inference rclcpp std_msgs trajectory_msgs cerberus_msgs)

target_include_directories(inference PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(inference PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17

install(TARGETS inference input_encoder
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
