//
// graphX - geometry - shapes - sphere.cpp
//

#include <cmath>

#include "shpere.hpp"

namespace graphX::geometry {
    bool Sphere::ray_intersect(const vec3f& orig_, const vec3f& dir_, float& t0_, vec3f& N_) const {
        vec3f L = center - orig_;
        float tca = L * dir_;
        float d2 = L * L - tca * tca;
        if (d2 > radius * radius)
            return false;

        float thc = std::sqrt(radius * radius - d2);
        t0_ = tca - thc;
        float t1 = tca + thc;

        if (t0_ < 0)
            t0_ = t1;

        if (t0_ >= 0) {
            vec3f hit_point = orig_ + dir_ * t0_;
            N_ = normalize(hit_point - center);
            return true;
        }
        return false;
    }
} // namespace graphX::geometry
