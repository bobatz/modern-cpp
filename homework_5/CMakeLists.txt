cmake_minimum_required(VERSION 3.22)
project(homework_5)
set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

include_directories(include)

add_subdirectory(src)

add_library(homework_5 INTERFACE include/homework_5.h)
target_link_libraries(homework_5 INTERFACE mat_serialization)

add_subdirectory(tests)
