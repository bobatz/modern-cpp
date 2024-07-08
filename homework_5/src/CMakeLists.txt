add_library(serialize serialize.cpp)
target_link_libraries(serialize ${OpenCV_LIBS})

add_executable(main main.cpp)
target_link_libraries(main serialize)
