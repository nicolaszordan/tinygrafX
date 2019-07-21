//
// graphX - geometry - test_vector.cpp
//

#include <catch2/catch.hpp>

#include "graphX/geometry/vector.hpp"

TEST_CASE("vector accessors", "[vector]") {
    using namespace graphX;

    vec3i vec;
    CHECK(vec.x() == 0);
    CHECK(vec.y() == 0);
    CHECK(vec.z() == 0);

    vec.x() = 1234;
    vec.y() = -123;
    vec.z() = 0;
    CHECK(vec.x() == 1234);
    CHECK(vec.y() == -123);
    CHECK(vec.z() == 0);

    vec[0] = 0;
    vec[1] = 1234;
    vec[2] = -123;
    CHECK(vec[0] == 0);
    CHECK(vec[1] == 1234);
    CHECK(vec[2] == -123);
}

TEST_CASE("vector creation / assignation", "[vector]") {
    using namespace graphX;

    vec3i vec = {1, -2, 3};
    CHECK(vec.x() == 1);
    CHECK(vec.y() == -2);
    CHECK(vec.z() == 3);

    vec = {-2, 1, 3};
    CHECK(vec.x() == -2);
    CHECK(vec.y() == 1);
    CHECK(vec.z() == 3);
}

TEST_CASE("vector comparaison operators", "[vector]") {
    using namespace graphX;

    vec3i vec1 = {1, -2, 2};
    vec3i vec2 = vec1;
    CHECK(vec1 == vec2);
    CHECK_FALSE(vec1 != vec2);
    
    vec2.x() = 2;
    CHECK(vec1 != vec2);
    CHECK_FALSE(vec1 == vec2);
}

TEST_CASE("vector multiplication operator", "[vector]") {
    using namespace graphX;

    CHECK(vec3i{  1, -2,  2} * vec3i{ -1,  3,  1} == -5);
    CHECK(vec3i{  3, -2,  2} * vec3i{ -1, -3,  1} == 5);
    CHECK(vec3i{  1, -2,  2} * vec3i{  2,  1,  0} == 0);
    CHECK(vec3i{  2,  1,  0} * vec3i{  1, -2,  2} == 0);
}

TEST_CASE("vector addition operator", "[vector]") {
    using namespace graphX;

    CHECK(vec3i{  1, -2,  2} + vec3i{ -1,  3,  1} == vec3i{ 0,  1,  3});
    CHECK(vec3i{  3, -2,  2} + vec3i{ -1, -3,  1} == vec3i{ 2, -5,  3});
    CHECK(vec3i{  1, -2,  2} + vec3i{  2,  1,  0} == vec3i{ 3, -1,  2});
    CHECK(vec3i{  2,  1,  0} + vec3i{  1, -2,  2} == vec3i{ 3, -1,  2});
}

TEST_CASE("vector substraction operator", "[vector]") {
    using namespace graphX;

    CHECK(vec3i{  1, -2,  2} - vec3i{ -1,  3,  1} == vec3i{ 2, -5,  1});
    CHECK(vec3i{  3, -2,  2} - vec3i{ -1, -3,  1} == vec3i{ 4,  1,  1});
    CHECK(vec3i{  1, -2,  2} - vec3i{  2,  1,  0} == vec3i{-1, -3,  2});
    CHECK(vec3i{  2,  1,  0} - vec3i{  1, -2,  2} == vec3i{ 1,  3, -2});
}

TEST_CASE("vector multiplication by scalar operator", "[vector]") {
    using namespace graphX;

    CHECK(vec3i{  1, -2,  2} *  2 == vec3i{ 2, -4,  4});
    CHECK(vec3i{  3, -2,  2} *  1 == vec3i{ 3, -2,  2});
    CHECK(vec3i{  1, -2,  2} *  0 == vec3i{ 0,  0,  0});
    CHECK(vec3i{  2,  1,  0} * -1 == vec3i{-2, -1,  0});
}

TEST_CASE("vector opposite operator", "[vector]") {
    using namespace graphX;

    CHECK(-vec3i{  1, -2,  2} == vec3i{-1,  2, -2});
    CHECK(-vec3i{  3, -2,  2} == vec3i{-3,  2, -2});
    CHECK(-vec3i{  0,  0,  0} == vec3i{ 0,  0,  0});
}

TEST_CASE("vector norm", "[vector]") {
    using namespace graphX;
    using graphX::geometry::norm;

    vec3i vec = {1, -2, 2};
    CHECK(norm(vec) == 3);

    vec = {2, -4, 4};
    CHECK(norm(vec) == 6);

    CHECK(norm(vec3i{1, -2, 2}) == 3);
}

// TODO: FIND A WAY TO TEST normalize
//TEST_CASE("vector normalize", "[vector]") {
//    using namespace graphX;
//    using graphX::geometry::normalize;
//
//    vec3i vec = {1, -2, 2};
//    CHECK(normalize(vec) == vec3i{});
//
//    vec = {2, -4, 4};
//    CHECK(normalize(vec) == vec3i{});
//
//    CHECK(normalize(vec3i{1, -2, 2}) == vec3i{});
//}
