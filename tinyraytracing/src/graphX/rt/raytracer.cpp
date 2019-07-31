//
// graphX - rt - raytracer.cpp
//

#include "raytracer.hpp"

namespace graphX::rt {
    void RayTracer::render(IRenderer& renderer_) {
        for (size_t y = 0; y < _buffer.height(); ++y) {
            for (size_t x = 0; x < _buffer.width(); ++x) {
                float ray_y = -(2*(y + 0.5)/(float)_buffer.height() - 1) * std::tan(_scene.fov_angle/2.);
                float ray_x =  (2*(x + 0.5)/(float)_buffer.width()  - 1) * std::tan(_scene.fov_angle/2.) * _buffer.width() / (float)_buffer.height();
                vec3f ray_dir = geometry::normalize(vec3f{ray_x, ray_y, -1});

                _buffer(y, x) = _cast_ray(_scene.camera_position, ray_dir);
            }
        }

        renderer_.render(_buffer);
    }

    vec3f RayTracer::_cast_ray(const vec3f& orig_, const vec3f& dir_) const {
        vec3f color;
        vec3f hit_point;
        vec3f N;

        if (_calc_scene_intersect(orig_, dir_, hit_point, N, color) > MAX_RAY_DISTANCE) {
            return vec3f{0.2, 0.7, 0.8}; // if intersection is to far away or if there is none at all, set background color
        }

        float light_intensity = 0;
        for (const auto& light: _scene.lights) {
            using std::max;

            vec3f light_dir = geometry::normalize(light.position - hit_point);
            light_intensity += light.intensity * max(0.f, light_dir * N);
        }

        return color * light_intensity;
    }

    float RayTracer::_calc_scene_intersect(const vec3f &orig_, const vec3f &dir_, vec3f& hit_point_, vec3f& N_, vec3f& color_) const {
        float hit_dist = std::numeric_limits<float>::max();

        for (const auto& it : _scene.shapes) {
            float dist_it;
            vec3f N;

            if (it.get_shape()->ray_intersect(orig_, dir_, dist_it, N) && dist_it < hit_dist) {
                hit_dist = dist_it;
                N_ = N;
                color_ = it.get_material().color; // TODO: SET MATERIAL INSTEAD OF JUST COLOR
            }
        }

        return hit_dist;
    }
}
