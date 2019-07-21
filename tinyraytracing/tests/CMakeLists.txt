##
## tinyraytracing test CMakeLists.txt
##

cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories("../src")

set(TESTS_SRC
    graphX/renderer/test_ppm_renderer.cpp
    graphX/core/test_framebuffer.cpp
    graphX/geometry/test_vector.cpp
    graphX/geometry/shapes/test_sphere.cpp
    graphX/rt/test_raytracer.cpp
)

add_executable(test_tinyraytracer ${TESTS_SRC} test_main.cpp)
add_test(tinyraytracer test_tinyraytracer)
