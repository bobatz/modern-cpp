add_executable(task_1 task_1/main.cpp)
add_executable(task_2 task_2/main.cpp)
install(TARGETS task_1 RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
install(TARGETS task_2 RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

