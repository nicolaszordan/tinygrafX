##
## tinyraytracing main CMakeLists.txt
##

cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(".")

set(SRC
    "graphX/geometry/geometry.hpp"
    "graphX/geometry/vector.hpp"

    "graphX/core/Iframebuffer.hpp"
    "graphX/core/Irenderer.hpp"

    "graphX/core/framebuffer.hpp"

    "graphX/rt/raytracer.hpp"

    "graphX/renderer/ppm_renderer.hpp"
    "graphX/renderer/ppm_renderer.cpp"
)

add_executable(tinyraytracer ${SRC} "main.cpp")
