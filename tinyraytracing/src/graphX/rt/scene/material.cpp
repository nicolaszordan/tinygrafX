//
// graphX - rt - material.cpp
//

#include "material.hpp"

namespace graphX {
    const rt::Material Materials::IVORY        = {vec3f{0.4, 0.4, 0.3}, vec3f{0.6,  0.3, 0.0},   50.};
    const rt::Material Materials::RED_RUBBER   = {vec3f{0.3, 0.1, 0.1}, vec3f{0.9,  0.1, 0.0},   10.};
    const rt::Material Materials::VANTABLACK   = {vec3f{  0,   0,   0}, vec3f{0.0,  0.0, 0.0},    0.};
    const rt::Material Materials::MIRROR       = {vec3f{1.0, 1.0, 1.0}, vec3f{0.0, 10.0, 0.8}, 1425.};
}
