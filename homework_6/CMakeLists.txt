cmake_minimum_required(VERSION 3.22)
project(homework_6)
set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_subdirectory(src)

add_library(homework_6 INTERFACE include/homework_6.h)
target_link_libraries(homework_6 INTERFACE image)

add_subdirectory(tests)
