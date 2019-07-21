//
// graphX - geometry - shapes - sphere.hpp
//

#pragma once

#include "Ashape.hpp"

namespace graphX::geometry {
    struct Sphere : AShape {
    public:
        Sphere(const vec3f& center_, float radius_)
            : AShape{}, center{center_}, radius{radius_} {
        }

        template<typename M>
        Sphere(const vec3f& center_, float radius_, M&& material_)
            : AShape{material_}, center{center_}, radius{radius_} {
        }

    public:
        bool ray_intersect(const vec3f& orig_, const vec3f& dir_, float& t0_) const override;

    public:
        vec3f   center;
        float   radius;
    };
} // namespace graphX::geometry
