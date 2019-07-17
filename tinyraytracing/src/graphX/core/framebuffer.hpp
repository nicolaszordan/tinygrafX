//
// grpahX - core - framebuffer.hpp
//

#pragma once

#include <cstdint>
#include <vector>
#include <stdexcept>
#include <utility>

#include "graphX/core/Iframebuffer.hpp"
#include "graphX/geometry/vector.hpp"

namespace graphX {

    // TODO: vec3f AS TEMPLATE PARAMETER?
    class FrameBuffer : public IFrameBuffer {
    public:
        static constexpr uint32_t DEFAULT_WIDTH  = 1024;
        static constexpr uint32_t DEFAULT_HEIGHT = 728;

    public: // TODO: REDO INDENTATION: LOOKS MEH
        FrameBuffer(uint32_t width_ = DEFAULT_WIDTH,
                    uint32_t height_ = DEFAULT_HEIGHT
            ) : _width(width_),
                _height(height_),
                _buffer(_width * _height) {
        }
        FrameBuffer(const FrameBuffer&) = default;
        FrameBuffer(FrameBuffer&&) = default;

        ~FrameBuffer() override = default;

        FrameBuffer& operator=(const FrameBuffer&) = default;
        FrameBuffer& operator=(FrameBuffer&&) = default;

    public: // 1D ACCESS
        const vec3f& at(uint32_t pos_) const {
            return _buffer.at(pos_);
        }

        vec3f& at(uint32_t pos_) {
            return const_cast<vec3f&>(std::as_const(*this).at(pos_));
        }

        const vec3f& operator[](uint32_t pos_) const {
            return at(pos_);
        }

        vec3f& operator[](uint32_t pos_) {
            return const_cast<vec3f&>(std::as_const(*this)[pos_]);
        }

    public: // 2D ACCESS
        const vec3f& at(uint32_t posY_, uint32_t posX_) const override {
            return at(posY_ * _width + posX_);
        }

        vec3f& at(uint32_t posY_, uint32_t posX_) override {
            return const_cast<vec3f&>(std::as_const(*this).at(posY_, posX_));
        }

        const vec3f& operator()(uint32_t posY_, uint32_t posX_) const {
            return at(posY_, posX_);
        }

        vec3f& operator()(uint32_t posY_, uint32_t posX_) {
            return const_cast<vec3f&>(std::as_const(*this)(posY_, posX_));
        }

    public: // WIDTH / HEIGHT MANAGEMENT
        uint32_t width() const override { return _width; }
        uint32_t height() const override { return _height; }

        void set_width(uint32_t width_) { set_buffer_dimensions(width_, _height); }
        void set_height(uint32_t height_) { set_buffer_dimensions(_width, height_); }

        void set_buffer_dimensions(uint32_t width_, uint32_t height_) {
            if (width_ == _width && height_ == _height) {
                return;
            }

            _width = width_;
            _height = height_;
            _buffer.resize(_width * _height);
        }

    private:
        uint32_t _width;
        uint32_t _height;
        std::vector<vec3f> _buffer;
    };

} // namespace graphX
