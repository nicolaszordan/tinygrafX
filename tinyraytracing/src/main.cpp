//
// tinyraytracing - main.cpp
//

#include <cmath>
#include <iostream>

#include "graphX/renderer/ppm_renderer.hpp"
#include "graphX/rt/raytracer.hpp"

#include "graphX/geometry/shapes/shpere.hpp"
#include "graphX/rt/material.hpp"

int main() {
    graphX::rt::RayTracer rt;
    graphX::renderer::PPM_Renderer renderer;

    std::cout << "scene setup" << std::endl;
    rt.emplace_shape<graphX::geometry::Sphere>(graphX::vec3f{-3, 0, -16}, 2, graphX::Materials::IVORY);
    rt.emplace_shape<graphX::geometry::Sphere>(graphX::vec3f{-1.0, -1.5, -12}, 2, graphX::Materials::RED_RUBBER);
    rt.emplace_shape<graphX::geometry::Sphere>(graphX::vec3f{1.5, -0.5, -18}, 2, graphX::Materials::VANTABLACK);
    std::cout << "raytracing" << std::endl;
    rt.render(renderer);
    std::cout << "raytracing done" << std::endl;
    return 0;
}
