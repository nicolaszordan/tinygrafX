//
// graphX - core - Iframebuffer.hpp
//

#pragma once

#include <cstdint>

#include "graphX/geometry/vector.hpp"

namespace graphX {
    class IFrameBuffer {
    public:
        virtual uint32_t height() const = 0;
        virtual uint32_t width() const = 0;

        virtual const vec3f& at(uint32_t posY_, uint32_t posX_) const = 0;
        virtual vec3f& at(uint32_t posY_, uint32_t posX_) = 0;

    public:
        IFrameBuffer() = default;
        IFrameBuffer(const IFrameBuffer&) = default;
        IFrameBuffer(IFrameBuffer&&) = default;

        virtual ~IFrameBuffer() = default;

        IFrameBuffer& operator=(const IFrameBuffer&) = default;
        IFrameBuffer& operator=(IFrameBuffer&&) = default;
    };
} // namespace graphX
