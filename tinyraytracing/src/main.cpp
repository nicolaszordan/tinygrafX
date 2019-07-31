//
// tinyraytracing - main.cpp
//

#include <cmath>
#include <iostream>

#include "graphX/renderer/ppm_renderer.hpp"
#include "graphX/rt/raytracer.hpp"

#include "graphX/geometry/shapes/shpere.hpp"
#include "graphX/rt/scene/material.hpp"

int main() {
    graphX::rt::RayTracer rt;
    graphX::renderer::PPM_Renderer renderer;

    std::cout << "---- scene setup ----" << std::endl;
    rt.get_scene().add_shape<graphX::geometry::Sphere>(graphX::Materials::IVORY,      graphX::vec3f{  -3,    0, -16}, 1);
    rt.get_scene().add_shape<graphX::geometry::Sphere>(graphX::Materials::VANTABLACK, graphX::vec3f{ 1.5, -0.5, -18}, 3);
    rt.get_scene().add_shape<graphX::geometry::Sphere>(graphX::Materials::RED_RUBBER, graphX::vec3f{-1.0, -1.5, -12}, 2);
    rt.get_scene().add_shape<graphX::geometry::Sphere>(graphX::Materials::IVORY,      graphX::vec3f{   7,    5, -18}, 5);
    rt.get_scene().add_shape<graphX::geometry::Sphere>(graphX::Materials::RED_RUBBER, graphX::vec3f{  -7,    5, -10}, 3);

    rt.get_scene().add_light(graphX::vec3f{-20, 20, 20}, 1.5);
    std::cout << "---- raytracing -----" << std::endl;
    rt.render(renderer);
    std::cout << "-- raytracing done --" << std::endl;
    return 0;
}
