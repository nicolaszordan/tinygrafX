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
    rt.get_scene().camera_position.z() -= 4;

    rt.get_scene().add_shape<graphX::geometry::Sphere>(graphX::Materials::RED_RUBBER,      graphX::vec3f{  0,   -2.1, -10},   2);
    rt.get_scene().add_shape<graphX::geometry::Sphere>(graphX::Materials::RED_RUBBER,      graphX::vec3f{  0,    2.1, -10},   2);
//    rt.get_scene().add_shape<graphX::geometry::Sphere>(graphX::Materials::IVORY,      graphX::vec3f{  -3,    0, -16},   2);
//    rt.get_scene().add_shape<graphX::geometry::Sphere>(graphX::Materials::IVORY,      graphX::vec3f{  -8,    0, -13},   2);
//    rt.get_scene().add_shape<graphX::geometry::Sphere>(graphX::Materials::RED_RUBBER, graphX::vec3f{ 1.5,  1.5, -19},   3);
//    rt.get_scene().add_shape<graphX::geometry::Sphere>(graphX::Materials::MIRROR,     graphX::vec3f{-1.0, -1.5, -12},   2);
//    rt.get_scene().add_shape<graphX::geometry::Sphere>(graphX::Materials::MIRROR,     graphX::vec3f{   4,    0, -15}, 2.5);
//    rt.get_scene().add_shape<graphX::geometry::Sphere>(graphX::Materials::MIRROR,     graphX::vec3f{   7,    5, -18},   4);
//    rt.get_scene().add_shape<graphX::geometry::Sphere>(graphX::Materials::RED_RUBBER, graphX::vec3f{  -3,    5,  -8},   3);

    rt.get_scene().add_light(graphX::vec3f{0, 40,  -10}, 10);
    rt.get_scene().add_light(graphX::vec3f{0, -40,  -10}, 1.8);
//    rt.get_scene().add_light(graphX::vec3f{-20, 20,  20}, 1.5);
//    rt.get_scene().add_light(graphX::vec3f{ 30, 50, -25}, 1.8);
//    rt.get_scene().add_light(graphX::vec3f{ 30, 20,  30}, 1.7);
    std::cout << "---- raytracing -----" << std::endl;
    rt.render(renderer);
    std::cout << "-- raytracing done --" << std::endl;
    return 0;
}
