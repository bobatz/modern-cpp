cmake_minimum_required(VERSION 3.22)
project(homework_7)
set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

include_directories(serialize)
add_library(serialization serialize/serialize.cpp)
target_link_libraries(serialization ${OpenCV_LIBS})
add_library(convert_dataset serialize/convert_dataset.cpp)
target_link_libraries(convert_dataset serialization)

include_directories(include)

add_subdirectory(src)

add_library(homework_7 INTERFACE include/homework_7.h)
target_link_libraries(homework_7 INTERFACE serialize convert_dataset kmeans)

add_subdirectory(tests)
