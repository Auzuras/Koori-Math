#ifndef KOORI_MATH_QUATERNION_H
#define KOORI_MATH_QUATERNION_H

#include <Arithmetic/Arithmetic.h>

#pragma region Forward Declarations

template<Arithmetic T>
struct Matrix4;

#pragma endregion

template<Arithmetic T>
struct Quaternion
{
public:

    T w, x, y, z;

public:

#pragma region Static Quaternion

    static const Quaternion<T> Zero;

    static const Quaternion<T> One;

    static const Quaternion<T> Identity;

#pragma endregion

#pragma region Constructors

    constexpr Quaternion() noexcept;

    constexpr Quaternion(T _value) noexcept;

    constexpr Quaternion(T _wValue, T _xValue, T _yValue, T _zValue) noexcept;

    constexpr Quaternion(const Quaternion<T>& _quaternion) noexcept;

    constexpr Quaternion(Quaternion<T>&& _quaternion) noexcept;
    
    constexpr Quaternion(const Quaternion<T>* _quaternion) noexcept;

#pragma endregion

#pragma region Getters
#pragma endregion

#pragma region Setters
#pragma endregion

#pragma region Data

    [[nodiscard]] T* Data() noexcept { return &w; };

    [[nodiscard]] const T* Data() const noexcept { return &w; };

    [[nodiscard]] T* Begin() noexcept { return &w; };

    [[nodiscard]] T* End() noexcept { return &w + 4; };

#pragma endregion

#pragma region Quaternion Methods

    [[nodiscard]] constexpr T SqrLength() const noexcept;

    [[nodiscard]] constexpr T Length() const noexcept;

    Quaternion<T>& Normalize() noexcept;

    [[nodiscard]] Quaternion<T> Normalized() const noexcept;

    [[nodiscard]] constexpr Quaternion<T> Conjugate() const noexcept;

    [[nodiscard]] Quaternion<T> Inverse() const noexcept;

    [[nodiscard]] Vector3<T> Rotate(const Vector3<T>& _vector) const noexcept;

#pragma endregion

#pragma region Quaternion Static Methods
#pragma endregion

#pragma region Boolean Operations

    [[nodiscard]] constexpr bool IsZero() const noexcept;

    [[nodiscard]] constexpr bool Equal(const Quaternion<T>& _quaternion) const noexcept;

    [[nodiscard]] constexpr static bool IsZero(const Quaternion<T>& _quaternion) noexcept;

    [[nodiscard]] constexpr static bool Equal(const Quaternion<T>& _lhs, const Quaternion<T>& _rhs) noexcept;

#pragma endregion

#pragma region String

    [[nodiscard]] std::string ToString() const;

#pragma endregion

#pragma region Operators

    constexpr Quaternion<T> operator+(const Quaternion<T>& _quaternion) const noexcept;

    constexpr Quaternion<T> operator+(T _scalar) const noexcept;

    constexpr Quaternion<T> operator-(const Quaternion<T>& _quaternion) const noexcept;

    constexpr Quaternion<T> operator-(T _scalar) const noexcept;

    constexpr Quaternion<T> operator*(const Quaternion<T>& _quaternion) const noexcept;

    constexpr Quaternion<T> operator*(T _scalar) const noexcept;

    Quaternion<T> operator/(const Quaternion<T>& _quaternion) const noexcept;

    Quaternion<T> operator/(T _scalar) const noexcept;

    Quaternion<T>& operator+=(const Quaternion<T>& _quaternion) noexcept;

    Quaternion<T>& operator+=(T _scalar) noexcept;

    Quaternion<T>& operator-=(const Quaternion<T>& _quaternion) noexcept;

    Quaternion<T>& operator-=(T _scalar) noexcept;

    Quaternion<T>& operator*=(const Quaternion<T>& _quaternion) noexcept;

    Quaternion<T>& operator*=(T _scalar) noexcept;

    Quaternion<T>& operator/=(const Quaternion<T>& _quaternion) noexcept;

    Quaternion<T>& operator/=(T _scalar) noexcept;

    constexpr Quaternion<T> operator-() noexcept;

    Quaternion<T>& operator=(const Quaternion<T>& _quaternion) noexcept;

    Quaternion<T>& operator=(Quaternion<T>&& _quaternion) noexcept;

    constexpr bool operator==(const Quaternion<T>& _quaternion) const noexcept;

    constexpr bool operator!=(const Quaternion<T>& _quaternion) const noexcept;

    constexpr T& operator[](size_t _index) noexcept;

    constexpr const T& operator[](size_t _index) const noexcept;

    friend std::ostream& operator<<(std::ostream& _stream, const Quaternion<T>& _quaternion)
    {
        _stream << _quaternion.ToString();
        return _stream;
    }

#pragma endregion
};

#include "Quaternion.inl"

#endif //KOORI_MATH_QUATERNION_H