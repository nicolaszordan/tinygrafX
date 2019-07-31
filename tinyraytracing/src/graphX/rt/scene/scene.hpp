//
// graphX - rt - scene - scene.hpp
//

#pragma once

#include <vector>
#include <memory>

#include "graphX/geometry/vector.hpp"

#include "shape.hpp"
#include "light.hpp"

namespace graphX::rt {
    struct Scene {
        vec3f camera_position;
        float fov_angle;
        std::vector<Shape> shapes;
        std::vector<Light> lights;
        // background

    public:
        template<typename S, typename ...Args>
        void add_shape(Args&&... args_) {
            shapes.emplace_back(std::make_shared<S>(std::forward<Args>(args_)...));
        }

        template<typename S, typename M, typename ...Args>
        void add_shape(M&& material_, Args&&... args_) {
            shapes.emplace_back(std::make_shared<S>(std::forward<Args>(args_)...), std::forward<M>(material_));
        }

        template<typename ...Args>
        void add_light(Args&&... args_) {
            lights.emplace_back(std::forward<Args>(args_)...);
        }
    };
}
