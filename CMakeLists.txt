# Fundamental

cmake_minimum_required(VERSION 3.10)
project(cpw_notifications VERSION 0.0.27)
configure_file(Config.h.in Config.h)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(HEADER ${CMAKE_SOURCE_DIR}/include)
include_directories(include)
add_subdirectory(src)

target_include_directories(
    ${PROJECT_NAME} PUBLIC
    "${PROJECT_BINARY_DIR}"
)

enable_testing()
add_subdirectory(tests)