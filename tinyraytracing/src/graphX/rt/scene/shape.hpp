#include <utility>

//
// graphX - rt - scene - shape.hpp
//

#pragma once

#include <memory>

#include "graphX/geometry/shapes/Ishape.hpp"
#include "material.hpp"

namespace graphX::rt {
    class Shape{
    public:
        Shape() : _shape{}, _material{} {
        }

        explicit Shape(std::shared_ptr<geometry::IShape>  shape_) : _shape{std::move(shape_)}, _material{} {
        }

        template<typename S, typename M>
        Shape(S&& shape_, M&& material_) : _shape{shape_}, _material{material_} {
        }

    public: // MATERIAL
        const Material& get_material() const { return _material; }

        template<typename M>
        void set_matetrial(M&& material_) { _material = material_; }

    public: // SHAPE
        const std::shared_ptr<geometry::IShape>& get_shape() const { return _shape; }
        std::shared_ptr<geometry::IShape>& get_shape() {
            return const_cast<std::shared_ptr<geometry::IShape>&>(std::as_const(*this).get_shape());
        }

        template<typename S>
        void set_shape(S&& shape_) { _shape = shape_; }

    private:
        std::shared_ptr<geometry::IShape> _shape;
        Material _material;
    };
} // namespace graphX::rt
