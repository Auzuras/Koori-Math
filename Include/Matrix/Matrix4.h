#ifndef KOORI_MATH_MATRIX4_H
#define KOORI_MATH_MATRIX4_H

#include <Arithmetic/Arithmetic.h>

#pragma region Forward Declarations

template<Arithmetic T>
struct Vector3;

template<Arithmetic T>
struct Quaternion;

#pragma endregion

template<Arithmetic T>
struct Matrix4
{
public:

    T m00, m01, m02, m03,
      m10, m11, m12, m13,
      m20, m21, m22, m23,
      m30, m31, m32, m33;

public:

#pragma region Static Matrices

    static const Matrix4<T> Zero;

    static const Matrix4<T> One;

    static const Matrix4<T> Identity;

#pragma endregion

#pragma region Constructors

    constexpr Matrix4() noexcept;

    explicit constexpr Matrix4(T _value) noexcept;

    explicit constexpr Matrix4(T _xValue, T _yValue, T _zValue, T _wValue) noexcept;

    explicit constexpr Matrix4(T _m00, T _m01, T _m02, T _m03,
        T _m10, T _m11, T _m12, T _m13,
        T _m20, T _m21, T _m22, T _m23,
        T _m30, T _m31, T _m32, T _m33) noexcept;

    explicit constexpr Matrix4(const Matrix4<T>& _matrix) noexcept;

    explicit constexpr Matrix4(Matrix4<T>&& _matrix) noexcept;

    explicit constexpr Matrix4(const Matrix4<T>* _matrix) noexcept;

#pragma endregion

#pragma region Getters
#pragma endregion

#pragma region Setters
#pragma endregion

#pragma region Data

    [[nodiscard]] T* Data() noexcept { return &m00; };

    [[nodiscard]] const T* Data() const noexcept { return &m00; };

    [[nodiscard]] T* Begin() noexcept { return &m00; };

    [[nodiscard]] T* End() noexcept { return &m00 + 16; };

#pragma endregion

#pragma region Matrix4 Methods

    [[nodiscard]] constexpr T Trace() const noexcept;

    [[nodiscard]] constexpr T Determinant() const noexcept;

    [[nodiscard]] Matrix4<T> Transpose() const noexcept;
                  
    [[nodiscard]] Matrix4<T> Inverse() const noexcept;
                  
    [[nodiscard]] Matrix4<T> Translation(const T _x, const T _y, const T _z) const noexcept;
                  
    [[nodiscard]] Matrix4<T> Translation(const Vector3<T>& _translation) const noexcept;
                  
    [[nodiscard]] Matrix4<T> XRotation(const T _angle) const noexcept;
                  
    [[nodiscard]] Matrix4<T> YRotation(const T _angle) const noexcept;
                  
    [[nodiscard]] Matrix4<T> ZRotation(const T _angle) const noexcept;
                  
    [[nodiscard]] Matrix4<T> Rotation(const T _angle, const Vector3<T>& _axis) const noexcept;
                  
    [[nodiscard]] Matrix4<T> Rotation(const Quaternion<T>& _rotation) const noexcept;
                  
    [[nodiscard]] Matrix4<T> Scaling(const T _x, const T _y, const T _z) const noexcept;
                  
    [[nodiscard]] Matrix4<T> Scaling(const Vector3<T>& _scaling) const noexcept;
                  
    [[nodiscard]] Matrix4<T> TRS(const Vector3<T>& _translation, const Matrix4<T>& _rotation, const Matrix4<T>& _scaling) const noexcept;
                  
    [[nodiscard]] Matrix4<T> TRS(const Vector3<T>& _translation, const Quaternion<T>& _rotation, const Vector3<T>& _scaling) const noexcept;
                  
    [[nodiscard]] Matrix4<T> PerspectiveProjection(const T _near, const T _far, const T _aspect, const T _fov) const noexcept;
                  
    [[nodiscard]] Matrix4<T> OrthographicProjection(const T _near, const T _far, const T _top, const T _bottom, const T _right, const T _left) const noexcept;

    [[nodiscard]] Matrix4<T> ViewMatrix(const Vector3<T>& _eye, const Vector3<T>& _lookAt, const Vector3<T>& _up) const noexcept;

#pragma endregion

#pragma region Boolean Operations

    [[nodiscard]] constexpr bool IsZero() const noexcept;

    [[nodiscard]] constexpr bool Equal(const Matrix4<T>& _matrix) const noexcept;

    [[nodiscard]] constexpr static bool IsZero(const Matrix4<T>& _matrix) noexcept;

    [[nodiscard]] constexpr static bool Equal(const Matrix4<T>& _lhs, const Matrix4<T>& _rhs) noexcept;

#pragma endregion

#pragma region String

    [[nodiscard]] std::string ToString() const;

#pragma endregion

#pragma region Operators

    constexpr Matrix4<T> operator+(const Matrix4<T>& _matrix) const noexcept;

    constexpr Matrix4<T> operator+(T _scalar) const noexcept;

    constexpr Matrix4<T> operator-(const Matrix4<T>& _matrix) const noexcept;

    constexpr Matrix4<T> operator-(T _scalar) const noexcept;

    constexpr Matrix4<T> operator*(const Matrix4<T>& _matrix) const noexcept;

    constexpr Matrix4<T> operator*(T _scalar) const noexcept;

    Matrix4<T> operator/(const Matrix4<T>& _matrix) const noexcept;

    Matrix4<T> operator/(T _scalar) const noexcept;

    Matrix4<T>& operator+=(const Matrix4<T>& _matrix) noexcept;

    Matrix4<T>& operator+=(T _scalar) noexcept;

    Matrix4<T>& operator-=(const Matrix4<T>& _matrix) noexcept;

    Matrix4<T>& operator-=(T _scalar) noexcept;

    Matrix4<T>& operator*=(const Matrix4<T>& _matrix) noexcept;

    Matrix4<T>& operator*=(T _scalar) noexcept;

    Matrix4<T>& operator/=(const Matrix4<T>& _matrix) noexcept;

    Matrix4<T>& operator/=(T _scalar) noexcept;

    constexpr Matrix4<T> operator-() noexcept;

    Matrix4<T>& operator=(const Matrix4<T>& _matrix) noexcept;

    Matrix4<T>& operator=(Matrix4<T>&& _matrix) noexcept;

    constexpr bool operator==(const Matrix4<T>& _matrix) const noexcept;

    constexpr bool operator!=(const Matrix4<T>& _matrix) const noexcept;

    constexpr T& operator[](size_t _index) noexcept;

    constexpr const T& operator[](size_t _index) const noexcept;

    friend std::ostream& operator<<(std::ostream& _stream, const Matrix4<T>& _matrix)
    {
        _stream << _matrix.ToString();
        return _stream;
    }

#pragma endregion
};

#include "Matrix4.inl"

#endif //KOORI_MATH_MATRIX4_H