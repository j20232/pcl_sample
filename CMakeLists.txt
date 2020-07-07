cmake_minimum_required(VERSION 3.1)
project(pcl_sample)

# build option
set(CMAKE_CXX_STANDARD 14)

# build path
message("Current directory: " ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_BUILD_TYPE})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_BUILD_TYPE})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_BUILD_TYPE})

set(PCL_ROOT $ENV{PCL_ROOT})
find_package(PCL 1.11 REQUIRED)

message("Include Dirs" ${PCL_INCLUDE_DIRS})
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable(hello_pcl examples/001_hello.cpp)
target_link_libraries(hello_pcl ${PCL_LIBRARIES})
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT hello_pcl)
