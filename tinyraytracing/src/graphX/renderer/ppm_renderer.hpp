//
// graphX - renderer - ppm_renderer.hpp
//

#pragma once

#include <string_view>

#include "graphX/core/Irenderer.hpp"
#include "graphX/core/Iframebuffer.hpp"

namespace graphX {
    namespace renderer {
        // TODO: IFileRenderer class that renders a IFrameBuffer to a file ?

        class PPM_Renderer : public IRenderer {
        public:
            PPM_Renderer(std::string_view file_name_ = "out.ppm")
                : _file_name(file_name_) {
            }

        public: // IRenderer IMPLEMENTATION
            void render(const IFrameBuffer &fb_) override;

        public:
            std::string_view get_file_name() const { return _file_name; }
            void set_file_name(std::string_view file_name_) { _file_name = file_name_; }

        private:
            std::string_view _file_name;
        };
    } // namespace renderer
} // namespace graphX
