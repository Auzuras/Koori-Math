#pragma region Quaternion Types

#include "Arithmetic/Equal.h"

using Quaternionf = Quaternion<float>;
using Quaterniond = Quaternion<double>;
using Quaternioni = Quaternion<int>;
using Quaternionui = Quaternion<unsigned int>;

#pragma endregion

#pragma region Static Quaternion

template<Arithmetic T>
inline constexpr Quaternion<T> Quaternion<T>::Zero = Quaternion<T>(T(0));

template<Arithmetic T>
inline constexpr Quaternion<T> Quaternion<T>::One = Quaternion<T>(T(1));

template<Arithmetic T>
inline constexpr Quaternion<T> Quaternion<T>::Identity = Quaternion<T>(T(1), T(0), T(0), T(0));

#pragma endregion

#pragma region Constructors

template<Arithmetic T>
constexpr Quaternion<T>::Quaternion() noexcept
    : w(T()), x(T()), y(T()), z(T())
{}

template<Arithmetic T>
constexpr Quaternion<T>::Quaternion(T _value) noexcept
    : w(_value), x(_value), y(_value), z(_value)
{}

template<Arithmetic T>
constexpr Quaternion<T>::Quaternion(T _wValue, T _xValue, T _yValue, T _zValue) noexcept
    : w(_wValue), x(_xValue), y(_yValue), z(_zValue)
{}

template<Arithmetic T>
constexpr Quaternion<T>::Quaternion(const Quaternion<T>& _quaternion) noexcept
    : w(_quaternion.w), x(_quaternion.x), y(_quaternion.y), z(_quaternion.z)
{}

template<Arithmetic T>
constexpr Quaternion<T>::Quaternion(Quaternion<T>&& _quaternion) noexcept
    : w(_quaternion.w), x(_quaternion.x), y(_quaternion.y), z(_quaternion.z)
{
    _quaternion.w = _quaternion.x = _quaternion.y = _quaternion.z = T();
}

template<Arithmetic T>
constexpr Quaternion<T>::Quaternion(const Quaternion<T>* _quaternion) noexcept
    : w(_quaternion->w), x(_quaternion->x), y(_quaternion->y), z(_quaternion->z)
{}

#pragma endregion

#pragma region Boolean Operations

template<Arithmetic T>
constexpr bool Quaternion<T>::IsZero() const noexcept
{
    return Koori::Math::Equal(w, T(0)) && Koori::Math::Equal(x, T(0)) && Koori::Math::Equal(y, T(0)) && Koori::Math::Equal(z, T(0));
}

template<Arithmetic T>
constexpr bool Quaternion<T>::Equal(const Quaternion<T>& _quaternion) const noexcept
{
    return Koori::Math::Equal(w, _quaternion.w) && Koori::Math::Equal(x, _quaternion.x) && Koori::Math::Equal(y, _quaternion.y) && Koori::Math::Equal(z, _quaternion.z);
}

template<Arithmetic T>
constexpr bool Quaternion<T>::IsZero(const Quaternion<T>& _quaternion) noexcept
{
    return _quaternion.IsZero();
}

template<Arithmetic T>
constexpr bool Quaternion<T>::Equal(const Quaternion<T>& _lhs, const Quaternion<T>& _rhs) noexcept
{
    return _lhs.Equal(_rhs);
}

#pragma endregion


#pragma region Quaternion Operators

template<Arithmetic T>
constexpr Quaternion<T> Quaternion<T>::operator+(const Quaternion<T>& _quaternion) const noexcept
{
    return Quaternion<T>(w + _quaternion.w, x + _quaternion.x, y + _quaternion.y, z + _quaternion.z);
}

template<Arithmetic T>
constexpr Quaternion<T> Quaternion<T>::operator+(const T _scalar) const noexcept
{
    return Quaternion<T>(w + _scalar, x + _scalar, y + _scalar, z + _scalar);
}

template<Arithmetic T>
constexpr Quaternion<T> Quaternion<T>::operator-(const Quaternion<T>& _quaternion) const noexcept
{
    return Quaternion<T>(w - _quaternion.w, x - _quaternion.x, y - _quaternion.y, z - _quaternion.z);
}

template<Arithmetic T>
constexpr Quaternion<T> Quaternion<T>::operator-(const T _scalar) const noexcept
{
    return Quaternion<T>(w - _scalar, x - _scalar, y - _scalar, z - _scalar);
}

template<Arithmetic T>
constexpr Quaternion<T> Quaternion<T>::operator*(const Quaternion<T>& _quaternion) const noexcept
{
    return Quaternion<T>(
        w * _quaternion.w - x * _quaternion.x - y * _quaternion.y - z * _quaternion.z,
        w * _quaternion.x + x * _quaternion.w + y * _quaternion.z - z * _quaternion.y,
        w * _quaternion.y - x * _quaternion.z + y * _quaternion.w + z * _quaternion.x,
        w * _quaternion.z + x * _quaternion.y - y * _quaternion.x + z * _quaternion.w
    );
}

template<Arithmetic T>
constexpr Quaternion<T> Quaternion<T>::operator*(const T _scalar) const noexcept
{
    return Quaternion<T>(
        w * _scalar - x * _scalar - y * _scalar - z * _scalar,
        w * _scalar + x * _scalar + y * _scalar - z * _scalar,
        w * _scalar - x * _scalar + y * _scalar + z * _scalar,
        w * _scalar + x * _scalar - y * _scalar + z * _scalar
    );
}

template<Arithmetic T>
Quaternion<T> Quaternion<T>::operator/(const Quaternion<T>& _quaternion) const noexcept
{
    // TODO: Implement
    return Quaternion<T>();
}

template<Arithmetic T>
Quaternion<T> Quaternion<T>::operator/(const T _scalar) const noexcept
{
    // TODO: Implement
    return Quaternion<T>();
}

template<Arithmetic T>
Quaternion<T>& Quaternion<T>::operator+=(const Quaternion<T>& _quaternion) noexcept
{
    w += _quaternion.w;
    x += _quaternion.x;
    y += _quaternion.y;
    z += _quaternion.z;

    return *this;
}

template<Arithmetic T>
Quaternion<T>& Quaternion<T>::operator+=(const T _scalar) noexcept
{
    w += _scalar;
    x += _scalar;
    y += _scalar;
    z += _scalar;

    return *this;
}

template<Arithmetic T>
Quaternion<T>& Quaternion<T>::operator-=(const Quaternion<T>& _quaternion) noexcept
{
    w -= _quaternion.w;
    x -= _quaternion.x;
    y -= _quaternion.y;
    z -= _quaternion.z;

    return *this;
}

template<Arithmetic T>
Quaternion<T>& Quaternion<T>::operator-=(const T _scalar) noexcept
{
    w -= _scalar;
    x -= _scalar;
    y -= _scalar;
    z -= _scalar;

    return *this;
}

template<Arithmetic T>
Quaternion<T>& Quaternion<T>::operator*=(const Quaternion<T>& _quaternion) noexcept
{
    w = w * _quaternion.w - x * _quaternion.x - y * _quaternion.y - z * _quaternion.z;
    x = w * _quaternion.x + x * _quaternion.w + y * _quaternion.z - z * _quaternion.y;
    y = w * _quaternion.y - x * _quaternion.z + y * _quaternion.w + z * _quaternion.x;
    z = w * _quaternion.z + x * _quaternion.y - y * _quaternion.x + z * _quaternion.w;

    return *this;
}

template<Arithmetic T>
Quaternion<T>& Quaternion<T>::operator*=(const T _scalar) noexcept
{
    w = w * _scalar - x * _scalar - y * _scalar - z * _scalar;
    x = w * _scalar + x * _scalar + y * _scalar - z * _scalar;
    y = w * _scalar - x * _scalar + y * _scalar + z * _scalar;
    z = w * _scalar + x * _scalar - y * _scalar + z * _scalar;

    return *this;
}

template<Arithmetic T>
Quaternion<T>& Quaternion<T>::operator/=(const Quaternion<T>& _quaternion) noexcept
{
    // TODO: Implement
    return *this;
}

template<Arithmetic T>
Quaternion<T>& Quaternion<T>::operator/=(const T _scalar) noexcept
{
    // TODO: Implement
    return *this;
}

template<Arithmetic T>
constexpr Quaternion<T> Quaternion<T>::operator-() noexcept
{
    return Quaternion<T>(-w, -x, -y, -z);
}

template<Arithmetic T>
Quaternion<T>& Quaternion<T>::operator=(const Quaternion<T>& _quaternion) noexcept
{
    w = _quaternion.w;
    x = _quaternion.x;
    y = _quaternion.y;
    z = _quaternion.z;

    return *this;
}

template<Arithmetic T>
Quaternion<T>& Quaternion<T>::operator=(Quaternion<T>&& _quaternion) noexcept
{
    w = _quaternion.w;
    x = _quaternion.x;
    y = _quaternion.y;
    z = _quaternion.z;

    _quaternion.w = _quaternion.x = _quaternion.y = _quaternion.z = T(0);

    return *this;
}

template<Arithmetic T>
constexpr bool Quaternion<T>::operator==(const Quaternion<T>& _quaternion) const noexcept
{
    return Equal(_quaternion);
}

template<Arithmetic T>
constexpr bool Quaternion<T>::operator!=(const Quaternion<T>& _quaternion) const noexcept
{
    return !Equal(_quaternion);
}

template<Arithmetic T>
constexpr T& Quaternion<T>::operator[](const size_t _index) noexcept
{
    return Data()[_index];
}

template<Arithmetic T>
constexpr const T& Quaternion<T>::operator[](const size_t _index) const noexcept
{
    return Data()[_index];
}

#pragma endregion

#pragma region String

template<Arithmetic T>
std::string Quaternion<T>::ToString() const
{
    return "(" + std::to_string(w) + ", " + std::to_string(x) + ", " + std::to_string(y) + std::to_string(z) + ")";
}

#pragma endregion