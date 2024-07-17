add_library(image image.cpp)
target_link_libraries(image io_tools)

add_executable(main main.cpp)
target_link_libraries(main image)
