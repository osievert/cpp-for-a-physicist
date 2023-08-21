cmake_minimum_required(VERSION 2.8.2)

project(example)

include(ExternalProject)
ExternalProject_Add(maze
  GIT_REPOSITORY    https://github.com/aleksandrbazhin/mazegen
  GIT_TAG           master
  SOURCE_DIR        "${CMAKE_BINARY_DIR}/maze-src"
  BINARY_DIR        "${CMAKE_BINARY_DIR}/maze-build"
  INSTALL_COMMAND   cmake -E echo "-- Header only - skipping install step"
)

add_executable(example main.cpp)
set_target_properties(example PROPERTIES CXX_STANDARD 17)
target_include_directories(example PRIVATE ${CMAKE_BINARY_DIR}/maze-src)
add_dependencies(example maze)
