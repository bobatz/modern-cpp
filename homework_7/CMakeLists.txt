cmake_minimum_required(VERSION 3.22)
project(homework_7)
set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

include_directories(include)

add_subdirectory(src)
