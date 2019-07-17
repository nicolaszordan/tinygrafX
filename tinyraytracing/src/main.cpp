//
// tinyraytracing - main.cpp
//

#include <iostream>

#include "graphX/renderer/ppm_renderer.hpp"
#include "graphX/rt/raytracer.hpp"

int main() {
    graphX::RayTracer rt;
    graphX::renderer::PPM_Renderer renderer;

    rt.set_renderer(&renderer);
    std::cout << "raytracing" << std::endl;
    rt.render();
    std::cout << "raytracing done" << std::endl;
    return 0;
}
