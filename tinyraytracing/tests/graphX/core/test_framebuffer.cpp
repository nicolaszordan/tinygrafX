//
// graphX - core - test_framebuffer.cpp
//

#include <catch2/catch.hpp>

#define private public
#include "graphX/core/framebuffer.hpp"

TEST_CASE("framebuffer sizes", "[framebuffer]") {
    using graphX::FrameBuffer;

    {
        FrameBuffer fb;
        REQUIRE(fb.width() == FrameBuffer::DEFAULT_WIDTH);
        REQUIRE(fb.height() == FrameBuffer::DEFAULT_HEIGHT);
        REQUIRE(fb._buffer.size() == fb.width() * fb.height());
    }

    FrameBuffer fb(3, 4);
    REQUIRE(fb.width() == 3);
    REQUIRE(fb.height() == 4);
    REQUIRE(fb._buffer.size() == fb.width() * fb.height());

    fb.set_width(2);
    REQUIRE(fb.width() == 2);
    REQUIRE(fb.height() == 4);
    REQUIRE(fb._buffer.size() == fb.width() * fb.height());

    fb.set_height(3);
    REQUIRE(fb.width() == 2);
    REQUIRE(fb.height() == 3);
    REQUIRE(fb._buffer.size() == fb.width() * fb.height());

    fb.set_height(3);
    REQUIRE(fb.width() == 2);
    REQUIRE(fb.height() == 3);
    REQUIRE(fb._buffer.size() == fb.width() * fb.height());

    fb.set_buffer_dimensions(1, 2);
    REQUIRE(fb.width() == 1);
    REQUIRE(fb.height() == 2);
    REQUIRE(fb._buffer.size() == fb.width() * fb.height());
}

TEST_CASE("framebuffer 1d access", "[framebuffer]") {
    using graphX::FrameBuffer;

    FrameBuffer fb;

    fb.at(3) = graphX::vec3f{1, 2, 3};
    REQUIRE(fb.at(3) == graphX::vec3f{1, 2, 3});

    fb[3] = graphX::vec3f{3, 2, 1};
    REQUIRE(fb.at(3) == graphX::vec3f{3, 2, 1});

    REQUIRE_THROWS_AS(fb.at(fb.width() * fb.height()), std::out_of_range);
    REQUIRE_THROWS_AS(fb[fb.width() * fb.height()], std::out_of_range);
}

TEST_CASE("framebuffer 2d access", "[framebuffer]") {
    using graphX::FrameBuffer;

    FrameBuffer fb;

    fb.at(0, 3) = graphX::vec3f{1, 2, 3};
    REQUIRE(fb.at(0, 3) == graphX::vec3f{1, 2, 3});
    REQUIRE(fb.at(0, 3) == fb.at(3));

    fb(1, 3) = graphX::vec3f{3, 2, 1};
    REQUIRE(fb.at(1, 3) == graphX::vec3f{3, 2, 1});
    REQUIRE(fb.at(1, 3) == fb.at(fb.width() + 3));

    REQUIRE_THROWS_AS(fb.at(fb.width(), fb.height()), std::out_of_range);
    REQUIRE_THROWS_AS(fb(fb.width(), fb.height()), std::out_of_range);
}
