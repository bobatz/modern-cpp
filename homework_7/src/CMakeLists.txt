add_library(kmeans kmeans.cpp)
target_link_libraries(kmeans ${OpenCV_LIBS})

add_library(bow_dictionary bow_dictionary.cpp)
target_link_libraries(bow_dictionary kmeans)

add_executable(main main.cpp)
target_link_libraries(main convert_dataset kmeans bow_dictionary)
