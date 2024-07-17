add_library(kmeans kmeans.cpp)
target_link_libraries(kmeans ${OpenCV_LIBS})

add_executable(main main.cpp)
target_link_libraries(main convert_dataset)
