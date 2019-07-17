//
// graphX - rt - raytracer.hpp
//

#pragma once

#include "graphX/core/Irenderer.hpp"
#include "graphX/core/framebuffer.hpp"

namespace graphX {
    // TODO: SOME SORT OF APPLICATION CLASS THAT RayTracer INHERITS FROM
    class RayTracer {
    public:
        void render() {
            _render_bg();

            _renderer->render(_buffer);
        }

        void set_renderer(IRenderer *renderer_) { _renderer = renderer_; }

    private: // RENDER FUNCTIONS
        void _render_bg() {
            for (size_t y = 0; y < _buffer.height(); ++y) {
                for (size_t x = 0; x < _buffer.width(); ++x) {
                    // MEH C CAST
                    _buffer(y, x) = vec3f{y/(float)_buffer.height(), x/(float)_buffer.width(), 0};
                }
            }
        }

    private:
        IRenderer* _renderer; // MEH RAW POINTER -> shared_ptr / unique_ptr ?
        FrameBuffer _buffer;
    };

} // namespace graphX
