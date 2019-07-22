##
## tinyraytracing main CMakeLists.txt
##

cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(".")

set(SRC
    graphX/geometry/vector.hpp
    graphX/geometry/geometry.hpp

    graphX/geometry/shapes/Ishape.hpp
    graphX/geometry/shapes/shpere.hpp
    graphX/geometry/shapes/shpere.cpp

    graphX/core/Iframebuffer.hpp
    graphX/core/Irenderer.hpp
    graphX/core/framebuffer.hpp

    graphX/rt/scene/material.hpp
    graphX/rt/scene/material.cpp
    graphX/rt/scene/shape.hpp
    graphX/rt/scene/light.hpp
    graphX/rt/scene/scene.hpp

    graphX/rt/raytracer.hpp
    graphX/rt/raytracer.cpp

    graphX/renderer/ppm_renderer.hpp
    graphX/renderer/ppm_renderer.cpp
)

add_executable(tinyraytracer ${SRC} main.cpp)
