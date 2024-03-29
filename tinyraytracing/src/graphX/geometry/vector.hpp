//
// graphX - geometry - vector.hpp
//

#pragma once

#include <cmath>
#include <utility>
#include <initializer_list>
#include <array>
#include <cassert>
#include <ostream>
#include <type_traits>

namespace graphX {
    namespace geometry {

        template<size_t DIM, typename T>
        class vector {
            static_assert(DIM > 0);

        public: // MP types
            static constexpr size_t size = DIM;
            using type = T;

        public: // CTOR / DTOR / move / assignment
            constexpr vector() noexcept : _data{} {}
            vector(const vector<DIM, T>&) = default;
            vector(vector<DIM, T>&&) noexcept = default;

            // TODO: find a way to make this constexpr
            vector(std::initializer_list<T> list_) noexcept {
                using std::begin;
                using std::end;

                assert(list_.size() == size);
                std::copy(begin(list_), end(list_), begin(_data));
            }

            ~vector() = default;

            vector<DIM, T>& operator=(const vector<DIM, T>&) = default;
            vector<DIM, T>& operator=(vector<DIM, T>&&) noexcept = default;


            vector<DIM, T>& operator=(std::initializer_list<T> list_) noexcept {
                using std::begin;
                using std::end;

                assert(list_.size() == size);
                std::copy(begin(list_), end(list_), begin(_data));
                return *this;
            }

        public: // Operator overloading
            bool operator==(const vector<DIM, T> rhs_) const {
                return _data == rhs_._data;
            }

            bool operator!=(const vector<DIM, T> rhs_) const {
                return _data != rhs_._data;
            }

        public: // Position accessor
            const T& operator[](size_t n_) const {
                return _data[n_];
            }

            T& operator[](size_t n_) {
                return const_cast<T&>(std::as_const(*this)[n_]);
            }

        public: // Named accessors (x, y...)
            const T& x() const {
                static_assert(size >= 1);
                return _data[0];
            }

            T& x() {
                return const_cast<T&>(std::as_const(*this).x());
            }

            const T& y() const {
                static_assert(size >= 2);
                return _data[1];
            }

            T& y() {
                return const_cast<T&>(std::as_const(*this).y());
            }

            const T& z() const {
                static_assert(size >= 3);
                return _data[2];
            }

            T& z() {
                return const_cast<T&>(std::as_const(*this).z());
            }

            const T& w() const {
                static_assert(size >= 4);
                return _data[3];
            }

            T& w() {
                return const_cast<T&>(std::as_const(*this).w());
            }

        private:
            std::array<T, size> _data;
        };

        // VECTOR MULTIPLICATION
        template<size_t DIM, typename T>
        T operator*(const vector<DIM, T>& lhs_, const vector<DIM, T>& rhs_) {
            T ret{};
            for (auto i = 0; i < DIM; ++i) {
                ret += lhs_[i] * rhs_[i];
            }
            return ret;
        }

        // VECTOR ADDITION
        template<size_t DIM, typename T>
        vector<DIM, T> operator+(const vector<DIM, T>& lhs_, const vector<DIM, T>& rhs_) {
            vector<DIM, T> ret = lhs_;
            for (auto i = 0; i < DIM; ++i) {
                ret[i] += rhs_[i];
            }
            return ret;
        }


        // VECTOR SUBTRACTION
        template<size_t DIM, typename T>
        vector<DIM, T> operator-(const vector<DIM, T>& lhs_, const vector<DIM, T>& rhs_) {
            vector<DIM, T> ret = lhs_;
            for (auto i = 0; i < DIM; ++i) {
                ret[i] -= rhs_[i];
            }
            return ret;
        }

        // VECTOR MULTIPLICATION BY A SCALAR
        template<size_t DIM, typename T, typename U>
        vector<DIM, T> operator*(const vector<DIM, T>& lhs_, U rhs_) {
            vector<DIM, T> ret = lhs_;
            for (auto i = 0; i < DIM; ++i) {
                ret[i] *= rhs_;
            }
            return ret;
        }

        template<size_t DIM, typename T>
        vector<DIM, T> operator-(const vector<DIM, T>& lhs_) {
            return lhs_ * T{-1};
        }

        template <size_t DIM, typename T> 
        std::ostream& operator<<(std::ostream& out_, const vector<DIM,T>& vec_) {
            out_ << "[";
            for (auto i = 0; i < DIM - 1; ++i) {
                out_ << vec_[i] << ", ";
            }
            return out_ << vec_[DIM-1] << "]";
        }

        // TODO: USING
        template<typename VEC>
        typename std::decay_t<VEC>::type norm(VEC&& vec_) {
            typename std::decay_t<VEC>::type sum{};
            for (auto i = 0; i < std::decay_t<VEC>::size; ++i) {
                sum += vec_[i] * vec_[i];
            }
            return std::sqrt(sum);
        }

        template<typename VEC>
        VEC normalize(VEC&& vec_, typename std::decay_t<VEC>::type factor = 1) {
            return vec_ * (factor / norm(vec_));
        }


    } // namespace geometry


    // HELPER TYPES
    template<typename T>
    using vec2 = geometry::vector<2, T>;

    using vec2i = vec2<int>;
    using vec2f = vec2<float>;

    template<typename T>
    using vec3 = geometry::vector<3, T>;

    using vec3i = vec3<int>;
    using vec3f = vec3<float>;

    template<typename T>
    using vec4 = geometry::vector<4, T>;

    using vec4i = vec4<int>;
    using vec4f = vec4<float>;
} // namespace graphX
