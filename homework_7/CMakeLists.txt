cmake_minimum_required(VERSION 3.22)
project(homework_7)
set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

include_directories(serialize)
add_library(serialize serialize/serialize.cpp)
target_link_libraries(serialize ${OpenCV_LIBS})
add_library(convert_dataset serialize/convert_dataset.cpp)
target_link_libraries(convert_dataset serialize)

include_directories(include)

add_subdirectory(src)
