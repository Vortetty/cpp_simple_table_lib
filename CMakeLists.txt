cmake_minimum_required(VERSION 3.0.0)
project(SIMPLE-TABLE VERSION 1.0.0)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include)

add_library(SIMPLE-TABLE src/table.cpp)
add_library(SIMPLE-TABLE-STATIC STATIC src/table.cpp)

find_library(COLOR_LIB_DIR TERM-COLOR)

if(COLOR_LIB_DIR)
    add_compile_options(COLOR_LIB_EXISTS)
    add_subdirectory(COLOR_LIB_DIR)
    target_link_libraries(TABLE PUBLIC TERM-COLOR)
    target_include_directories(FSTAB-Manager PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/$(COLOR_LIB_DIR)"
    )
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
