##
## tinyraytracing main CMakeLists.txt
##

cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC
    "graphX/geometry/geometry.hpp"
    "graphX/geometry/vector.hpp"
)

add_executable(tinyraytracer ${SRC} "main.cpp")
