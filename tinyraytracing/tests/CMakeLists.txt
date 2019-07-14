##
## tinyraytracing test CMakeLists.txt
##

cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories("../src")

set(TESTS_SRC
    "graphX/geometry/test_geometry.hpp"
    "graphX/geometry/test_geometry.cpp"
    "graphX/geometry/test_vector.hpp"
    "graphX/geometry/test_vector.cpp"
)

add_executable(test_tinyraytracer ${TESTS_SRC} "test_main.cpp")
add_test(tinyraytracer test_tinyraytracer)
