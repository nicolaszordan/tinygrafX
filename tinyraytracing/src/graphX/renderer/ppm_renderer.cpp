//
// graphX - renderer - ppm_renderer.cpp
//

#include <fstream>
#include <algorithm>

#include "ppm_renderer.hpp"

namespace graphX::renderer {
    void PPM_Renderer::render(const IFrameBuffer &fb_) {
        std::ofstream ofs(_file_name.data());

        ofs << "P6\n" << fb_.width() << " " << fb_.height() << "\n255\n";
        for (uint32_t y = 0; y < fb_.height(); ++y) {
            for (uint32_t x = 0; x < fb_.width(); ++x) { // TODO: MEH CSTYLE
                vec3f c = fb_.at(y, x);
                float max = std::max(c.x(), std::max(c.y(), c.z()));
                if (max > 1)
                    c = c * (1 / max);

                ofs << (char)(255 * std::max(0.f, std::min(1.f, c.x())))
                    << (char)(255 * std::max(0.f, std::min(1.f, c.y())))
                    << (char)(255 * std::max(0.f, std::min(1.f, c.z())));
            }
        }
    }
} // namespace graphX::renderer
