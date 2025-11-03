#pragma region Vector Types

#include "Arithmetic/Equal.h"

using Vector3f = Vector3<float>;
using Vector3d = Vector3<double>;
using Vector3i = Vector3<int>;
using Vector3ui = Vector3<unsigned int>;

#pragma endregion

#pragma region Constructors

template<Arithmetic T>
constexpr Vector3<T>::Vector3() noexcept
    : x(T()), y(T()), z(T())
{}

template<Arithmetic T>
constexpr Vector3<T>::Vector3(T _value) noexcept
    : x(_value), y(_value), z(_value)
{}

template<Arithmetic T>
constexpr Vector3<T>::Vector3(T _xValue, T _yValue, T _zValue) noexcept
    : x(_xValue), y(_yValue), z(_zValue)
{}

template<Arithmetic T>
constexpr Vector3<T>::Vector3(const Vector3<T>& _vector) noexcept
    : x(_vector.x), y(_vector.y), z(_vector.z)
{}

template<Arithmetic T>
constexpr Vector3<T>::Vector3(Vector3<T>&& _vector) noexcept
    : x(_vector.x), y(_vector.y), z(_vector.z)
{
    _vector.x = _vector.y = _vector.z = T();
}

template<Arithmetic T>
constexpr Vector3<T>::Vector3(const Vector3<T>* _vector) noexcept
    : x(_vector->x), y(_vector->y), z(_vector->z)
{}

#pragma endregion

#pragma region Vector3 Methods

template<Arithmetic T>
constexpr T Vector3<T>::DotProduct(const Vector3<T>& _vector) const noexcept
{
    return x * _vector.x + y * _vector.y; + z * _vector.z;
}

template<Arithmetic T>
constexpr Vector3<T> Vector3<T>::CrossProduct(const Vector3<T>& _vector) const noexcept
{
    return Vector3<T>(y * _vector.z - z * _vector.y, z * _vector.x - x * _vector.z, x * _vector.y - y * _vector.x);
}

template<Arithmetic T>
constexpr float Vector3<T>::Angle(const Vector3<T>& _vector) const noexcept
{
    return Koori::Math::ACos(DotProduct(_vector) / (Length() * _vector.Length()));
}

template<Arithmetic T>
constexpr T Vector3<T>::SqrLength() const noexcept
{
    return x * x + y * y + z * z;
}

template<Arithmetic T>
constexpr T Vector3<T>::Length() const noexcept
{
    return Koori::Math::Sqrt(SqrLength());
}

template<Arithmetic T>
constexpr T Vector3<T>::SqrDistance(const Vector3<T>& _vector) const noexcept
{
    return (x - _vector.x) * (x - _vector.x) + (y - _vector.y) * (y - _vector.y) + (z - _vector.z) * (z - _vector.z);
}

template<Arithmetic T>
constexpr T Vector3<T>::Distance(const Vector3<T>& _vector) const noexcept
{
    return Koori::Math::Sqrt(SqrDistance(_vector));
}

template<Arithmetic T>
Vector3<T>& Vector3<T>::Negate() noexcept
{
    *this *= static_cast<T>(-1);
    return *this;
}

template<Arithmetic T>
Vector3<T> Vector3<T>::Negated() const noexcept
{
    Vector3<T> ret = *this;
    ret.Negate();
    return ret;
}

template<Arithmetic T>
Vector3<T>& Vector3<T>::Inverse() noexcept
{
    // TODO: Add verification for division by 0
    const T one = static_cast<T>(1);
    x = one / x;
    y = one / y;
    z = one / z;
    return *this;
}

template<Arithmetic T>
Vector3<T> Vector3<T>::Inversed() const noexcept
{
    Vector3<T> ret = *this;
    ret.Inverse();
    return ret;
}

template<Arithmetic T>
Vector3<T>& Vector3<T>::Lerp(const Vector3<T>& _end, const float _t) noexcept
{
    *this = *this * (1.f - _t) + _end * _t;
    return *this;
}

template<Arithmetic T>
Vector3<T> Vector3<T>::Lerped(const Vector3<T>& _end, const float _t) const noexcept
{
    Vector3<T> ret = *this;
    ret.Lerp(_end, _t);
    return ret;
}

template<Arithmetic T>
Vector3<T>& Vector3<T>::Slerp(const Vector3<T>& _end, const float _t) noexcept
{
    const float dot = Koori::Math::Clamp(static_cast<float>(DotProduct(_end)), -1.f, 1.f);
    const float theta = Koori::Math::ACos(dot) * _t;

    const Vector3<T> relative = (_end - (*this) * dot).Normalize();
    *this = relative * Koori::Math::Sin(theta) + *this * Koori::Math::Cos(theta);
    return *this;
}

template<Arithmetic T>
Vector3<T> Vector3<T>::Slerped(const Vector3<T>& _end, const float _t) const noexcept
{
    Vector3<T> ret = *this;
    ret.Slerp(_end, _t);
    return ret;
}

template<Arithmetic T>
Vector3<T>& Vector3<T>::Normalize() noexcept
{
    *this /= Length();
    return *this;
}

template<Arithmetic T>
Vector3<T> Vector3<T>::Normalized() const noexcept
{
    Vector3<T> ret = *this;
    ret.Normalize();
    return ret;
}

template<Arithmetic T>
Vector3<T>& Vector3<T>::Translate(const Vector3<T>& _vector) noexcept
{
    *this += _vector;
    return *this;
}

template<Arithmetic T>
Vector3<T> Vector3<T>::Translated(const Vector3<T>& _vector) const noexcept
{
    Vector3<T> ret = *this;
    ret.Translate(_vector);
    return ret;
}

template<Arithmetic T>
Vector3<T>& Vector3<T>::Scale(const Vector3<T>& _anchor, const T _value) noexcept
{
    *this = _anchor + (*this - _anchor) * _value;
    return *this;
}

template<Arithmetic T>
Vector3<T> Vector3<T>::Scaled(const Vector3<T>& _anchor, const T _value) const noexcept
{
    Vector3<T> ret = *this;
    ret.Scale(_anchor, _value);
    return ret;
}

template<Arithmetic T>
Vector3<T>& Vector3<T>::Rotate(const Vector3<T>& _anchor, const float _angle) noexcept
{
    T tx = _anchor.x + (x - _anchor.x) * Koori::Math::Cos(_angle) - (y - _anchor.y) * Koori::Math::Sin(_angle);
    T ty = _anchor.y + (x - _anchor.x) * Koori::Math::Sin(_angle) + (y - _anchor.y) * Koori::Math::Cos(_angle);

    x = tx;
    y = ty;

    return *this;
}

template<Arithmetic T>
Vector3<T> Vector3<T>::Rotated(const Vector3<T>& _anchor, const float _angle) const noexcept
{
    Vector3<T> ret = *this;
    ret.Rotate(_anchor, _angle);
    return ret;
}

template<Arithmetic T>
Vector3<T>& Vector3<T>::Perpendicular() noexcept
{
    T temp = x;
    x = y;
    y = -temp;

    return *this;
}

template<Arithmetic T>
Vector3<T> Vector3<T>::GetPerpendicular() const noexcept
{
    Vector3<T> ret = *this;
    ret.Perpendicular();
    return ret;
}

template<Arithmetic T>
Vector3<T>& Vector3<T>::Reflect(const Vector3<T>& _normal) noexcept
{
    *this = *this - _normal * static_cast<T>(2) * DotProduct(_normal);
    return *this;
}

template<Arithmetic T>
Vector3<T> Vector3<T>::Reflected(const Vector3<T>& _normal) const noexcept
{
    Vector3<T> ret = *this;
    ret.Reflect(_normal);
    return ret;
}

template<Arithmetic T>
Vector3<T>& Vector3<T>::Refract(const Vector3<T>& _normal, const T _ior) noexcept
{
    const T dotNI = DotProduct(_normal);
    const T k = static_cast<T>(1) - _ior * _ior * (static_cast<T>(1) - dotNI * dotNI);
    *this = k < static_cast<T>(0) ? Vector3::Zero : (*this * _ior) - _normal * (_ior * dotNI + Koori::Math::Sqrt(k));
    return *this;
}

template<Arithmetic T>
Vector3<T> Vector3<T>::Refracted(const Vector3<T>& _normal, const T _ior) const noexcept
{
    Vector3<T> ret = *this;
    ret.Refract(_normal, _ior);
    return ret;
}

template<Arithmetic T>
Vector3<T>& Vector3<T>::Project(const Vector3<T>& _onTo) noexcept
{
    *this = _onTo * (DotProduct(_onTo) / _onTo.SqrLength());
    return *this;
}

template<Arithmetic T>
Vector3<T> Vector3<T>::Projected(const Vector3<T>& _onTo) const noexcept
{
    Vector3<T> ret = *this;
    ret.Project(_onTo);
    return ret;
}

#pragma endregion

#pragma region Vector3 Static Methods

template<Arithmetic T>
constexpr T Vector3<T>::DotProduct(const Vector3<T>& _lhs, const Vector3<T>& _rhs) noexcept
{
    return _lhs.DotProduct(_rhs);
}

template<Arithmetic T>
constexpr Vector3<T> Vector3<T>::CrossProduct(const Vector3<T>& _lhs, const Vector3<T>& _rhs) noexcept
{
    return _lhs.CrossProduct(_rhs);
}

template<Arithmetic T>
constexpr float Vector3<T>::Angle(const Vector3<T>& _lhs, const Vector3<T>& _rhs) noexcept
{
    return _lhs.Angle(_rhs);
}

template<Arithmetic T>
constexpr T Vector3<T>::SqrLength(const Vector3<T>& _vector) noexcept
{
    return _vector.SqrLength();
}

template<Arithmetic T>
constexpr T Vector3<T>::Length(const Vector3<T>& _vector) noexcept
{
    return _vector.Length();
}

template<Arithmetic T>
constexpr T Vector3<T>::SqrDistance(const Vector3<T>& _lhs, const Vector3<T>& _rhs) noexcept
{
    return _lhs.SqrDistance(_rhs);
}

template<Arithmetic T>
constexpr T Vector3<T>::Distance(const Vector3<T>& _lhs, const Vector3<T>& _rhs) noexcept
{
    return _lhs.Distance(_rhs);
}

template<Arithmetic T>
constexpr Vector3<T> Vector3<T>::Negate(const Vector3<T>& _vector) noexcept
{
    return _vector.Negated();
}

template<Arithmetic T>
Vector3<T> Vector3<T>::Inverse(const Vector3<T>& _vector) noexcept
{
    return _vector.Inversed();
}

template<Arithmetic T>
Vector3<T> Vector3<T>::Lerp(const Vector3<T>& _start, const Vector3<T>& _end, const float _t) noexcept
{
   return _start.Lerped(_end, _t);
}

template<Arithmetic T>
Vector3<T> Vector3<T>::Slerp(const Vector3<T>& _start, const Vector3<T>& _end, const float _t) noexcept
{
    return _start.Slerped(_end, _t);
}

template<Arithmetic T>
Vector3<T> Vector3<T>::Normalize(const Vector3<T>& _vector) noexcept
{
    return _vector.Normalized();
}

template<Arithmetic T>
Vector3<T> Vector3<T>::Translate(const Vector3<T>& _vector, const Vector3<T>& _value) noexcept
{
    return _vector.Translated(_value);
}

template<Arithmetic T>
Vector3<T> Vector3<T>::Scale(const Vector3<T>& _vector, const Vector3<T>& _anchor, const T _value) noexcept
{
    return _vector.Scaled(_anchor, _value);
}

template<Arithmetic T>
Vector3<T> Vector3<T>::Rotate(const Vector3<T>& _vector, const Vector3<T>& _anchor, const float _angle) noexcept
{
    return _vector.Rotated(_anchor, _angle);
}

template<Arithmetic T>
Vector3<T> Vector3<T>::Perpendicular(const Vector3<T>& _vector) noexcept
{
    return _vector.GetPerpendicular();
}

template<Arithmetic T>
Vector3<T> Vector3<T>::Reflect(const Vector3<T>& _incident, const Vector3<T>& _normal) noexcept
{
    return _incident.Reflected(_normal);
}

template<Arithmetic T>
Vector3<T> Vector3<T>::Refract(const Vector3<T>& _incident, const Vector3<T>& _normal, const T _ior) noexcept
{
    return _incident.Refracted(_normal, _ior);
}

template<Arithmetic T>
Vector3<T> Vector3<T>::Project(const Vector3<T>& _vector, const Vector3<T>& _onTo) noexcept
{
    return _vector.Projected(_onTo);
}

#pragma endregion

#pragma region Boolean Operations

template<Arithmetic T>
constexpr bool Vector3<T>::IsZero() const noexcept
{
    return Koori::Math::Equal(x, T(0)) && Koori::Math::Equal(y, T(0)) && Koori::Math::Equal(z, T(0));
}

template<Arithmetic T>
constexpr bool Vector3<T>::Equal(const Vector3<T>& _vector) const noexcept
{
    return Koori::Math::Equal(x, _vector.x) && Koori::Math::Equal(y, _vector.y) && Koori::Math::Equal(z, _vector.z);
}

template<Arithmetic T>
constexpr bool Vector3<T>::IsNormalized() const noexcept
{
    return Koori::Math::Equal(SqrLength(), T(1));
}

template<Arithmetic T>
constexpr bool Vector3<T>::IsZero(const Vector3<T>& _vector) noexcept
{
    return _vector.IsZero();
}

template<Arithmetic T>
constexpr bool Vector3<T>::Equal(const Vector3<T>& _lhs, const Vector3<T>& _rhs) noexcept
{
    return _lhs.Equal(_rhs);
}

template<Arithmetic T>
constexpr bool Vector3<T>::IsNormalized(const Vector3<T>& _vector) noexcept
{
    return _vector.IsNormalized();
}

#pragma endregion

#pragma region Vector3 Operators

template<Arithmetic T>
constexpr Vector3<T> Vector3<T>::operator+(const Vector3<T>& _vector) const noexcept
{
    return Vector3<T>(x + _vector.x, y + _vector.y, z + _vector.z);
}

template<Arithmetic T>
constexpr Vector3<T> Vector3<T>::operator+(const T _scalar) const noexcept
{
    return Vector3<T>(x + _scalar, y + _scalar, z + _scalar);
}

template<Arithmetic T>
constexpr Vector3<T> Vector3<T>::operator-(const Vector3<T>& _vector) const noexcept
{
    return Vector3<T>(x - _vector.x, y - _vector.y, z - _vector.z);
}

template<Arithmetic T>
constexpr Vector3<T> Vector3<T>::operator-(const T _scalar) const noexcept
{
    return Vector3<T>(x - _scalar, y - _scalar, z - _scalar);
}

template<Arithmetic T>
constexpr Vector3<T> Vector3<T>::operator*(const Vector3<T>& _vector) const noexcept
{
    return Vector3<T>(x * _vector.x, y * _vector.y, z * _vector.z);
}

template<Arithmetic T>
constexpr Vector3<T> Vector3<T>::operator*(const T _scalar) const noexcept
{
    return Vector3<T>(x * _scalar, y * _scalar, z * _scalar);
}

template<Arithmetic T>
Vector3<T> Vector3<T>::operator/(const Vector3<T>& _vector) const noexcept
{
    // TODO: Add verification for division by 0
    return Vector3<T>(x / _vector.x, y / _vector.y, z / _vector.z);
}

template<Arithmetic T>
Vector3<T> Vector3<T>::operator/(const T _scalar) const noexcept
{
    // TODO: Add verification for division by 0
    return Vector3<T>(x / _scalar, y / _scalar, z / _scalar);
}

template<Arithmetic T>
Vector3<T>& Vector3<T>::operator+=(const Vector3<T>& _vector) noexcept
{
    x += _vector.x;
    y += _vector.y;
    z += _vector.z;

    return *this;
}

template<Arithmetic T>
Vector3<T>& Vector3<T>::operator+=(const T _scalar) noexcept
{
    x += _scalar;
    y += _scalar;
    z += _scalar;

    return *this;
}

template<Arithmetic T>
Vector3<T>& Vector3<T>::operator-=(const Vector3<T>& _vector) noexcept
{
    x -= _vector.x;
    y -= _vector.y;
    z -= _vector.z;

    return *this;
}

template<Arithmetic T>
Vector3<T>& Vector3<T>::operator-=(const T _scalar) noexcept
{
    x -= _scalar;
    y -= _scalar;
    z -= _scalar;

    return *this;
}

template<Arithmetic T>
Vector3<T>& Vector3<T>::operator*=(const Vector3<T>& _vector) noexcept
{
    x *= _vector.x;
    y *= _vector.y;
    z *= _vector.z;

    return *this;
}

template<Arithmetic T>
Vector3<T>& Vector3<T>::operator*=(const T _scalar) noexcept
{
    x *= _scalar;
    y *= _scalar;
    z *= _scalar;

    return *this;
}

template<Arithmetic T>
Vector3<T>& Vector3<T>::operator/=(const Vector3<T>& _vector) noexcept
{
    x /= _vector.x;
    y /= _vector.y;
    z /= _vector.z;

    return *this;
}

template<Arithmetic T>
Vector3<T>& Vector3<T>::operator/=(const T _scalar) noexcept
{
    x /= _scalar;
    y /= _scalar;
    z /= _scalar;

    return *this;
}

template<Arithmetic T>
constexpr Vector3<T> Vector3<T>::operator-() noexcept
{
    return Vector3<T>(-x, -y, -z);
}

template<Arithmetic T>
Vector3<T>& Vector3<T>::operator=(const Vector3<T>& _vector) noexcept
{
    x = _vector.x;
    y = _vector.y;
    z = _vector.z;

    return *this;
}

template<Arithmetic T>
Vector3<T>& Vector3<T>::operator=(Vector3<T>&& _vector) noexcept
{
    x = _vector.x;
    y = _vector.y;
    z = _vector.z;

    _vector.x = _vector.y = _vector.z = T(0);

    return *this;
}

template<Arithmetic T>
constexpr bool Vector3<T>::operator==(const Vector3<T>& _vector) const noexcept
{
    return Equal(_vector);
}

template<Arithmetic T>
constexpr bool Vector3<T>::operator!=(const Vector3<T>& _vector) const noexcept
{
    return !Equal(_vector);
}

template<Arithmetic T>
constexpr T& Vector3<T>::operator[](const size_t _index) noexcept
{
    return Data()[_index];
}

template<Arithmetic T>
constexpr const T& Vector3<T>::operator[](const size_t _index) const noexcept
{
    return Data()[_index];
}

#pragma endregion

#pragma region String

template<Arithmetic T>
std::string Vector3<T>::ToString() const
{
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
}

#pragma endregion
