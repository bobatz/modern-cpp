add_library(mat_serialization serialize.cpp)
target_link_libraries(mat_serialization ${OpenCV_LIBS})

add_executable(main main.cpp)
target_link_libraries(main mat_serialization)
