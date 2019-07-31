//
// graphX - geometry - shapes - Ishape.hpp
//

#pragma once

#include "graphX/geometry/vector.hpp"

namespace graphX::geometry {
    class IShape {
    public:
        virtual bool ray_intersect(const vec3f& orig_, const vec3f& dir_, float& t0_, vec3f& N_) const = 0;

    public:
        IShape() = default;
        IShape(const IShape&) = default;
        IShape(IShape&&) = default;

        virtual ~IShape() = default;

        IShape& operator=(const IShape&) = default;
        IShape& operator=(IShape&&) = default;
    };
} // namespace graphX::geometry