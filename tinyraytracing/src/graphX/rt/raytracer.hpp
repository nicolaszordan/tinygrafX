//
// graphX - rt - raytracer.hpp
//

#pragma once

#include <memory>
#include <cmath>

#include "graphX/core/Irenderer.hpp"
#include "graphX/core/framebuffer.hpp"

#include "scene/scene.hpp"

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
        const Scene& get_scene() const { return _scene; }
        Scene& get_scene() { return const_cast<Scene&>(std::as_const(*this).get_scene()); }

    private: // Render functions
        void _render_bg();
        void _cast_ray(const vec3f& orig_, const vec3f& dir_, vec3f& out_);

    private:
        Scene _scene;
        FrameBuffer _buffer;
    };
} // namespace graphX::rt
