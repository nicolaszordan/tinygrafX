//
// graphX - rt - material.hpp
//

#pragma once

#include "graphX/geometry/vector.hpp"

namespace graphX {
    namespace rt {
        struct Material {
            vec3f color;
            vec3f albedo;
            float specular_exponent;
        };
    }

    struct Materials {
        static const rt::Material IVORY;
        static const rt::Material RED_RUBBER;
        static const rt::Material VANTABLACK;
        static const rt::Material MIRROR;
    };
}