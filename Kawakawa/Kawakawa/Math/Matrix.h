#pragma once
#include <cassert>

#include "Vector.h"

namespace Kawaii {

    template <typename T, unsigned D>
    struct Matrix {
        using RowVec = Vector<T, D>;
        std::array<RowVec, D> data;

        Matrix() = default;
        explicit Matrix(const T num) {
            std::fill_n(&data[0][0], D * D, static_cast<T>(0));
            for (size_t i = 0; i < D; i++)
                data[i][i] = num;
        }
        Matrix(std::initializer_list<RowVec>&& l) { std::move(l.begin(), l.end(), data.begin()); }
        Matrix(std::array<RowVec, D> a) : data(a) {}

        Vector<T, D>& operator[](unsigned row) { return data[row]; }
        const Vector<T, D>& operator[](unsigned row) const { return data[row]; }

        operator T* () noexcept { return &data[0][0]; }
        operator const T* () const noexcept { return static_cast<const T*>(&data[0][0]); }

        friend std::ostream& operator<<(std::ostream& out, const Matrix& mat) {
            return out << mat.data;
        }

        // Matrix Operation
        const Matrix operator+(const Matrix& rhs) const noexcept {
            Matrix result;
            for (unsigned row = 0; row < D; row++) result.data[row] = data[row] + rhs[row];
            return result;
        }

        const Matrix operator-() const noexcept {
            Matrix result;
            for (unsigned row = 0; row < D; row++) result.data[row] = -data[row];
            return result;
        }
        const Matrix operator-(const Matrix& rhs) const noexcept {
            Matrix result;
            for (unsigned row = 0; row < D; row++) result.data[row] = data[row] - rhs[row];
            return result;
        }
        const Matrix operator*(const Matrix& rhs) const noexcept {
            Matrix       result;
            Vector<T, D> colVec;
            for (unsigned col = 0; col < D; col++) {
                for (unsigned i = 0; i < D; i++) colVec[i] = rhs[i][col];
                for (unsigned row = 0; row < D; row++) {
                    result[row][col] = dot(data[row], colVec);
                }
            }
            return result;
        }

        const Vector<T, D> operator*(const Vector<T, D>& rhs) const noexcept {
            Vector<T, D> result;
            for (unsigned row = 0; row < D; row++) result[row] = dot(data[row], rhs);
            return result;
        }
        const Matrix operator*(const T& rhs) const noexcept {
            Matrix result;
            for (unsigned row = 0; row < D; row++) result[row] = data[row] * rhs;
            return result;
        }
        friend const Matrix operator*(const T& lhs, const Matrix& rhs) noexcept { return rhs * lhs; }

        const Matrix operator/(const T& rhs) const noexcept {
            Matrix result;
            for (unsigned row = 0; row < D; row++) result[row] = data[row] / rhs;
            return result;
        }

        Matrix& operator+=(const Matrix& rhs) noexcept {
            for (unsigned row = 0; row < D; row++) data[row] += rhs[row];
            return *this;
        }
        Matrix& operator-=(const Matrix& rhs) noexcept {
            for (unsigned row = 0; row < D; row++) data[row] -= rhs[row];
            return *this;
        }
        Matrix& operator*=(const T& rhs) noexcept {
            for (unsigned row = 0; row < D; row++) data[row] *= rhs;
            return *this;
        }
        Matrix& operator/=(const T& rhs) noexcept {
            for (unsigned row = 0; row < D; row++) data[row] /= rhs;
            return *this;
        }
    };

    using mat3f = Matrix<float, 3>;
    using mat4f = Matrix<float, 4>;
    using mat8f = Matrix<float, 8>;

    using mat3d = Matrix<double, 3>;
    using mat4d = Matrix<double, 4>;
    using mat8d = Matrix<double, 8>;

    template <typename T, unsigned D>
    Matrix<T, D> mulByElement(const Matrix<T, D>& m1, const Matrix<T, D>& m2) {
        Matrix result(0);
        for (unsigned row = 0; row < D; row++) result[row] = m1[row] * m2[row];
        return result;
    }
}  // namespace Kawaii