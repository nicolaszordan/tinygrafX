//
// graphX - rt - scene - light.hpp
//

#pragma once

#include "graphX/geometry/vector.hpp"

namespace graphX::rt {
    struct Light {
        template<typename P, typename I>
        Light(P&& position_, I&& intensity_) : position(position_), intensity(intensity_) {
        }

        vec3f position;
        float intensity;
        // TODO: color
    };
}