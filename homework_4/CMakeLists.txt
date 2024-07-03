cmake_minimum_required(VERSION 3.22)
project(homework_4)
set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_library(ipb_named_vector INTERFACE include/ipb_named_vector.h)

add_library(ipb_algorithm INTERFACE include/ipb_algorithm.h)
target_link_libraries(ipb_algorithm INTERFACE ipb_named_vector)

add_library(ipb INTERFACE include/homework_4.h)
target_link_libraries(ipb INTERFACE ipb_named_vector ipb_algorithm)

add_subdirectory(src)
add_subdirectory(tests)
