//
// graphX - geometry - test_vector.cpp
//

#include <catch2/catch.hpp>

#include "test_vector.hpp"

TEST_CASE("vector accessors", "[vector]") {
    using namespace graphX;

    vec3i vec;

    vec.x() = 1234;
    vec.y() = -123;
    vec.z() = 0;
    REQUIRE(vec.x() == 1234);
    REQUIRE(vec.y() == -123);
    REQUIRE(vec.z() == 0);

    vec[0] = 0;
    vec[1] = 1234;
    vec[2] = -123;
    REQUIRE(vec[0] == 0);
    REQUIRE(vec[1] == 1234);
    REQUIRE(vec[2] == -123);
}

TEST_CASE("vector creation / assignation", "[vector]") {
    using namespace graphX;

    vec3i vec = {1, -2, 3};
    REQUIRE(vec.x() == 1);
    REQUIRE(vec.y() == -2);
    REQUIRE(vec.z() == 3);

    vec = {-2, 1, 3};
    REQUIRE(vec.x() == -2);
    REQUIRE(vec.y() == 1);
    REQUIRE(vec.z() == 3);
}

TEST_CASE("vector norm", "[vector]") {
    using namespace graphX;
    using graphX::geometry::norm;

    vec3i vec = {1, -2, 2};
    REQUIRE(norm(vec) == 3);

    vec = {2, -4, 4};
    REQUIRE(norm(vec) == 6);
}

TEST_CASE("vector comparaison operators", "[vector]") {
    using namespace graphX;

    vec3i vec1 = {1, -2, 2};
    vec3i vec2 = vec1;
    REQUIRE(vec1 == vec2);
    REQUIRE_FALSE(vec1 != vec2);
    
    vec2.x() = 2;
    REQUIRE(vec1 != vec2);
    REQUIRE_FALSE(vec1 == vec2);
}

TEST_CASE("vector multiplication operator", "[vector]") {
    using namespace graphX;

    REQUIRE(vec3i{  1, -2,  2} * vec3i{ -1,  3,  1} == -5);
    REQUIRE(vec3i{  3, -2,  2} * vec3i{ -1, -3,  1} == 5);
    REQUIRE(vec3i{  1, -2,  2} * vec3i{  2,  1,  0} == 0);
    REQUIRE(vec3i{  2,  1,  0} * vec3i{  1, -2,  2} == 0);
}

TEST_CASE("vector addition operator", "[vector]") {
    using namespace graphX;

    REQUIRE(vec3i{  1, -2,  2} + vec3i{ -1,  3,  1} == vec3i{ 0,  1,  3});
    REQUIRE(vec3i{  3, -2,  2} + vec3i{ -1, -3,  1} == vec3i{ 2, -5,  3});
    REQUIRE(vec3i{  1, -2,  2} + vec3i{  2,  1,  0} == vec3i{ 3, -1,  2});
    REQUIRE(vec3i{  2,  1,  0} + vec3i{  1, -2,  2} == vec3i{ 3, -1,  2});
}

TEST_CASE("vector substraction operator", "[vector]") {
    using namespace graphX;

    REQUIRE(vec3i{  1, -2,  2} - vec3i{ -1,  3,  1} == vec3i{ 2, -5,  1});
    REQUIRE(vec3i{  3, -2,  2} - vec3i{ -1, -3,  1} == vec3i{ 4,  1,  1});
    REQUIRE(vec3i{  1, -2,  2} - vec3i{  2,  1,  0} == vec3i{-1, -3,  2});
    REQUIRE(vec3i{  2,  1,  0} - vec3i{  1, -2,  2} == vec3i{ 1,  3, -2});
}

TEST_CASE("vector multiplication by scalar operator", "[vector]") {
    using namespace graphX;

    REQUIRE(vec3i{  1, -2,  2} *  2 == vec3i{ 2, -4,  4});
    REQUIRE(vec3i{  3, -2,  2} *  1 == vec3i{ 3, -2,  2});
    REQUIRE(vec3i{  1, -2,  2} *  0 == vec3i{ 0,  0,  0});
    REQUIRE(vec3i{  2,  1,  0} * -1 == vec3i{-2, -1,  0});
}

TEST_CASE("vector opposite operator", "[vector]") {
    using namespace graphX;

    REQUIRE(-vec3i{  1, -2,  2} == vec3i{-1,  2, -2});
    REQUIRE(-vec3i{  3, -2,  2} == vec3i{-3,  2, -2});
    REQUIRE(-vec3i{  0,  0,  0} == vec3i{ 0,  0,  0});
}
