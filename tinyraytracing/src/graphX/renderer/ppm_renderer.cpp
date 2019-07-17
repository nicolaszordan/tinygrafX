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
                ofs << (char)(255 * std::max(0.f, std::min(1.f, fb_.at(y, x).x())))
                    << (char)(255 * std::max(0.f, std::min(1.f, fb_.at(y, x).y())))
                    << (char)(255 * std::max(0.f, std::min(1.f, fb_.at(y, x).z())));
            }
        }
    }
} // namespace graphX::renderer
