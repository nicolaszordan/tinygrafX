//
// graphX - rt - raytracer.cpp
//

#include "raytracer.hpp"

namespace graphX::rt {
    void RayTracer::render(IRenderer& renderer_) {
        _render_bg();

        for (size_t y = 0; y < _buffer.height(); ++y) {
            for (size_t x = 0; x < _buffer.width(); ++x) {
                float ray_y = -(2*(y + 0.5)/(float)_buffer.height() - 1) * std::tan(_scene.fov_angle/2.);
                float ray_x =  (2*(x + 0.5)/(float)_buffer.width()  - 1) * std::tan(_scene.fov_angle/2.) * _buffer.width() / (float)_buffer.height();
                vec3f ray_dir = geometry::normalize(vec3f{ray_x, ray_y, -1});

                _cast_ray(_scene.camera_position, ray_dir, _buffer(y, x));
            }
        }

        renderer_.render(_buffer);
    }

    void RayTracer::_render_bg() {
        for (size_t y = 0; y < _buffer.height(); ++y) {
            for (size_t x = 0; x < _buffer.width(); ++x) {
                // MEH C CAST
                _buffer(y, x) = vec3f{y/(float)_buffer.height(), x/(float)_buffer.width(), 0};
            }
        }
    }

    void RayTracer::_cast_ray(const vec3f& orig_, const vec3f& dir_, vec3f& out_) {
        float dist = std::numeric_limits<float>::max();

        for (const auto& it : _scene.shapes) {
            if (it->ray_intersect(orig_, dir_, dist)) {
                out_ = it->get_material();
            } // else leave already set background
        }
    }
}