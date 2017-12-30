cmake_minimum_required(VERSION 3.0)

project(snake C CXX)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMake)

file(GLOB_RECURSE SOURCES src/*.cpp src/*.hpp)

set(CMAKE_CXX_STANDARD 11)
find_package(SDL2 REQUIRED)
find_package(GLM REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} ${GLM_INCLUDE_DIR})

add_executable(snake ${SOURCES})
target_link_libraries(snake PUBLIC ${SDL2_LIBRARY})