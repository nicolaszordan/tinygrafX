//
// graphX - core - Irenderer.hpp
//

#pragma once

#include "graphX/core/Iframebuffer.hpp"

namespace graphX {
    class IRenderer {
    public:
        virtual void render(const IFrameBuffer&) = 0;

    public:
        IRenderer() = default;
        IRenderer(const IRenderer&) = default;
        IRenderer(IRenderer&&) = default;

        virtual ~IRenderer() = default;

        IRenderer& operator=(const IRenderer&) = default;
        IRenderer& operator=(IRenderer&&) = default;
    };
} // namespace graphX
