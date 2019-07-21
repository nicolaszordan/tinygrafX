//
// graphX - geometry - shapes - Ashape.hpp
//

#pragma once

#include "Ishape.hpp"

namespace graphX::geometry {
    class AShape : public IShape {
    public:
        AShape() = default;

        explicit AShape(const vec3f& material_) : _material{material_} {
        }

        explicit AShape(vec3f&& material_) : _material{material_} {
        }


    public: // IShape INTERFACE
        bool ray_intersect(const vec3f& orig_, const vec3f& dir_, float& t0_) const override = 0;

    public: // MATERIAL
        const vec3f& get_material() const { return _material; }

        template<typename M>
        void set_matetrial(M&& material_) { _material = material_; }

    private:
        vec3f _material;
    };
}
