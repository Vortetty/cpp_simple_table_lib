cmake_minimum_required(VERSION 3.0.0)
project(SIMPLE-TABLE VERSION 1.0.0)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(cpp_terminal_color_lib)

include_directories(include)

add_library(SIMPLE-TABLE src/table.cpp)
add_library(SIMPLE-TABLE-STATIC STATIC src/table.cpp)

target_link_libraries(SIMPLE-TABLE PRIVATE TERM-COLOR)
target_link_libraries(SIMPLE-TABLE-STATIC PRIVATE TERM-COLOR-STATIC)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
