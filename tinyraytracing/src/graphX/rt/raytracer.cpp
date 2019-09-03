//
// graphX - rt - raytracer.cpp
//

#include <iostream>
#include "raytracer.hpp"

namespace graphX::rt {
    namespace {
        vec3f reflect(const vec3f& I, const vec3f& N) {
            return I - N * 2.f * (I * N);
        }
    }

    void RayTracer::render(IRenderer& renderer_) {
        // TODO: PARALLELIZE
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

    vec3f RayTracer::_cast_ray(const vec3f& orig_, const vec3f& dir_, unsigned int depth_) const {
        Material material;
        vec3f hit_point;
        vec3f N;

        if (depth_ > MAX_REFLECTION_DEPTH || _calc_scene_intersect(orig_, dir_, hit_point, N, material) > MAX_RAY_DISTANCE) {
            return vec3f{0.2, 0.7, 0.8}; // if intersection is to far away or if there is none at all, set background color or if we have to many reflections
        }

        float diffuse_light_intensity = 0;
        float specular_light_intensity = 0;

        vec3f reflect_dir = reflect(dir_, N);
        vec3f reflect_orig = reflect_dir * N < 0 ? hit_point - N * 1e-3 : hit_point + N * 1e-3;
        vec3f reflect_color = _cast_ray(reflect_orig, reflect_dir, depth_ + 1);

        for (const auto& light: _scene.lights) {
            using std::max;

            vec3f light_dir = geometry::normalize(light.position - hit_point);
            float light_dist = geometry::norm(light.position - hit_point);

            vec3f shadow_orig = light_dir * N < 0 ? hit_point - N * 1e-3 : hit_point + N * 1e-3;
            vec3f shadow_point, shadow_N;
            Material _material;

            float ZOB = _calc_scene_intersect(shadow_orig, light_dir, shadow_point, shadow_N, _material);
            if (ZOB != std::numeric_limits<float>::max())
                std::cout << ZOB << std::endl;
            if (ZOB < MAX_RAY_DISTANCE) {
                    std::cout << "INTERSECT" << std::endl;
                    if (geometry::norm(shadow_point - shadow_orig) < light_dist) {
                    std::cout << "SOMESHADOW" << std::endl;
                    continue;
                }
            }

//            float light_distance = (lights[i].position - point).norm();
//
//            Vec3f shadow_orig = light_dir*N < 0 ? point - N*1e-3 : point + N*1e-3; // checking if the point lies in the shadow of the lights[i]
//            Vec3f shadow_pt, shadow_N;
//            Material tmpmaterial;
//            if (scene_intersect(shadow_orig, light_dir, spheres, shadow_pt, shadow_N, tmpmaterial) && (shadow_pt-shadow_orig).norm() < light_distance)
//                continue;

            diffuse_light_intensity +=  light.intensity * max(0.f, light_dir * N);
            specular_light_intensity += powf(max(0.f, -reflect(-light_dir, N) * dir_), material.specular_exponent) * light.intensity;
        }

        return material.color * diffuse_light_intensity * material.albedo[0] + vec3f{1., 1., 1.} * specular_light_intensity * material.albedo[1] + reflect_color * material.albedo[2];
    }

    float RayTracer::_calc_scene_intersect(const vec3f &orig_, const vec3f &dir_, vec3f& hit_point_, vec3f& N_, Material& material_) const {
        float hit_dist = std::numeric_limits<float>::max();

        for (const auto& it : _scene.shapes) {
            float dist_it;
            vec3f N;

            if (it.get_shape()->ray_intersect(orig_, dir_, dist_it, N) && dist_it < hit_dist) {
                hit_dist = dist_it;
                N_ = N;
                material_ = it.get_material();
            }
        }

        return hit_dist;
    }
}
