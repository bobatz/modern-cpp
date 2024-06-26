cmake_minimum_required(VERSION 3.22)
project(homework_3)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

add_subdirectory(src)

add_subdirectory(fmt-10.2.1)
find_library(FMT NAMES fmt PATHS ${PROJECT_SOURCE_DIR}/fmt-10.2.1/build)
