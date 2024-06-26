include_directories(${PROJECT_SOURCE_DIR}/api)
add_library(html_writer html_writer.cpp)
target_link_libraries(html_writer fmt::fmt)

add_library(image_browser image_browser.cpp)
target_link_libraries(image_browser html_writer)

add_executable(main main.cpp)
target_link_libraries(main image_browser)

install(TARGETS main RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
