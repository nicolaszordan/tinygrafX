# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.

cmake_minimum_required(VERSION 3.8)

project("tinyraytracing")


# Include sub-projects.
include_directories("src")

enable_testing()
add_subdirectory("tests")

add_subdirectory("src")
