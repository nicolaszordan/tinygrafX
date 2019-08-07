//
// graphX - rt - material.hpp
//

#pragma once

#include "graphX/geometry/vector.hpp"

namespace graphX {
    namespace rt {
        struct Material {
            vec3f color;
            vec2f albedo;
            float specular_exponent;
        };
    }

    struct Materials {
        static const rt::Material IVORY;
        static const rt::Material RED_RUBBER;
        static const rt::Material VANTABLACK;
    };
}