include_directories(${PROJECT_SOURCE_DIR}/include/)
add_library(ipb_arithmetic sum.cpp subtract.cpp)
add_executable(main main.cpp)
target_link_libraries(main ipb_arithmetic)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ DESTINATION include)
install(TARGETS ipb_arithmetic DESTINATION lib)
