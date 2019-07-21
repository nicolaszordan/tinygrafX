//
// graphX - rt - raytracer.hpp
//

#pragma once

#include <memory>
#include <cmath>

#include "graphX/core/Irenderer.hpp"
#include "graphX/core/framebuffer.hpp"

#include "graphX/geometry/shapes/Ashape.hpp"


namespace graphX::rt {
    // TODO: SOME SORT OF APPLICATION CLASS THAT RayTracer INHERITS FROM
    class RayTracer {
    public:
        RayTracer() : _scene{/*CAMERA*/{0, 0, 0}, /*FOV*/M_PI/2, /*SHAPES*/{}} {
        }

    public:
        void render(IRenderer& renderer_);

        void render_current_buffer(IRenderer& renderer_) {
            renderer_.render(_buffer);
        }

    public: // Scene control
        void load_scene_from_file(std::string_view file_name_) {
            throw std::runtime_error("NOT IMPLEMENTED");
        }

        template<typename T>
        void set_camera_position(T&& position_) {
            _scene.camera_position = position_;
        }

        void set_fov_angle(float angle_) {
            _scene.fov_angle = angle_;
        }

        template<typename T, typename ...Args>
        void emplace_shape(Args&&... args_) {
            _scene.shapes.emplace_back(std::make_shared<T>(std::forward<Args>(args_)...));
        }

        template<typename T>
        void add_shape(T&& shape_) {
            _scene.shapes.emplace_back(shape_);
        }

    private: // Scene
        struct Scene {
            vec3f camera_position;
            float fov_angle;
            std::vector<std::shared_ptr<geometry::AShape>> shapes;
            // background
            // lights
        };

    private: // Render functions
        void _render_bg();
        void _cast_ray(const vec3f& orig_, const vec3f& dir_, vec3f& out_);

    private:
        Scene _scene;
        FrameBuffer _buffer;
    };
} // namespace graphX::rt
