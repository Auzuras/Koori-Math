#pragma region Vector Types

#include "Arithmetic/Equal.h"

using Vector4f = Vector4<float>;
using Vector4d = Vector4<double>;
using Vector4i = Vector4<int>;
using Vector4ui = Vector4<unsigned int>;

#pragma endregion

#pragma region Static Vectors

template<Arithmetic T>
inline constexpr Vector4<T> Vector4<T>::Zero = Vector4<T>(T(0));

template<Arithmetic T>
inline constexpr Vector4<T> Vector4<T>::One = Vector4<T>(T(1));

template<Arithmetic T>
inline constexpr Vector4<T> Vector4<T>::Right = Vector4<T>(T(1), T(0), T(0), T(0));

template<Arithmetic T>
inline constexpr Vector4<T> Vector4<T>::Up = Vector4<T>(T(0), T(1), T(0), T(0));

template<Arithmetic T>
inline constexpr Vector4<T> Vector4<T>::Forward = Vector4<T>(T(0), T(0), T(1), T(0));

template<Arithmetic T>
inline constexpr Vector4<T> Vector4<T>::Left = Vector4<T>(T(-1), T(0), T(0), T(0));

template<Arithmetic T>
inline constexpr Vector4<T> Vector4<T>::Down = Vector4<T>(T(0), T(-1), T(0), T(0));

template<Arithmetic T>
inline constexpr Vector4<T> Vector4<T>::Backward = Vector4<T>(T(0), T(0), T(-1), T(0));

#pragma endregion

#pragma region Constructors

template<Arithmetic T>
constexpr Vector4<T>::Vector4() noexcept
    : x(T()), y(T()), z(T()), w(T())
{}

template<Arithmetic T>
constexpr Vector4<T>::Vector4(T _value) noexcept
    : x(_value), y(_value), z(_value), w(_value)
{}

template<Arithmetic T>
constexpr Vector4<T>::Vector4(T _xValue, T _yValue, T _zValue, T _wValue) noexcept
    : x(_xValue), y(_yValue), z(_zValue), w(_wValue)
{}

template<Arithmetic T>
constexpr Vector4<T>::Vector4(const Vector4<T>& _vector) noexcept
    : x(_vector.x), y(_vector.y), z(_vector.z), w(_vector.w)
{}

template<Arithmetic T>
constexpr Vector4<T>::Vector4(Vector4<T>&& _vector) noexcept
    : x(_vector.x), y(_vector.y), z(_vector.z), w(_vector.w)
{
    _vector.x = _vector.y = _vector.z = _vector.w = T();
}

template<Arithmetic T>
constexpr Vector4<T>::Vector4(const Vector4<T>* _vector) noexcept
    : x(_vector->x), y(_vector->y), z(_vector->z), w(_vector->w)
{}

#pragma endregion

#pragma region Vector4 Methods

template<Arithmetic T>
constexpr T Vector4<T>::DotProduct(const Vector4<T>& _vector) const noexcept
{
    return x * _vector.x + y * _vector.y + z * _vector.z + w * _vector.w;
}

template<Arithmetic T>
constexpr float Vector4<T>::Angle(const Vector4<T>& _vector) const noexcept
{
    return Koori::Math::ACos(DotProduct(_vector) / (Length() * _vector.Length()));
}

template<Arithmetic T>
constexpr T Vector4<T>::SqrLength() const noexcept
{
    return x * x + y * y + z * z + w * w;
}

template<Arithmetic T>
constexpr T Vector4<T>::Length() const noexcept
{
    return Koori::Math::Sqrt(SqrLength());
}

template<Arithmetic T>
constexpr T Vector4<T>::SqrDistance(const Vector4<T>& _vector) const noexcept
{
    return (x - _vector.x) * (x - _vector.x) + (y - _vector.y) * (y - _vector.y) + (z - _vector.z) * (z - _vector.z) + (w - _vector.w) * (w - _vector.w);
}

template<Arithmetic T>
constexpr T Vector4<T>::Distance(const Vector4<T>& _vector) const noexcept
{
    return Koori::Math::Sqrt(SqrDistance(_vector));
}

template<Arithmetic T>
Vector4<T>& Vector4<T>::Negate() noexcept
{
    *this *= static_cast<T>(-1);
    return *this;
}

template<Arithmetic T>
Vector4<T> Vector4<T>::Negated() const noexcept
{
    Vector4<T> ret = *this;
    ret.Negate();
    return ret;
}

template<Arithmetic T>
Vector4<T>& Vector4<T>::Inverse() noexcept
{
    // TODO: Add verification for division by 0
    const T one = static_cast<T>(1);
    x = one / x;
    y = one / y;
    z = one / z;
    w = one / w;
    return *this;
}

template<Arithmetic T>
Vector4<T> Vector4<T>::Inversed() const noexcept
{
    Vector4<T> ret = *this;
    ret.Inverse();
    return ret;
}

template<Arithmetic T>
Vector4<T>& Vector4<T>::Lerp(const Vector4<T>& _end, const float _t) noexcept
{
    *this = *this * (1.f - _t) + _end * _t;
    return *this;
}

template<Arithmetic T>
Vector4<T> Vector4<T>::Lerped(const Vector4<T>& _end, const float _t) const noexcept
{
    Vector4<T> ret = *this;
    ret.Lerp(_end, _t);
    return ret;
}

template<Arithmetic T>
Vector4<T>& Vector4<T>::Slerp(const Vector4<T>& _end, const float _t) noexcept
{
    const float dot = Koori::Math::Clamp(static_cast<float>(DotProduct(_end)), -1.f, 1.f);
    const float theta = Koori::Math::ACos(dot) * _t;

    const Vector4<T> relative = (_end - (*this) * dot).Normalize();
    *this = relative * Koori::Math::Sin(theta) + *this * Koori::Math::Cos(theta);
    return *this;
}

template<Arithmetic T>
Vector4<T> Vector4<T>::Slerped(const Vector4<T>& _end, const float _t) const noexcept
{
    Vector4<T> ret = *this;
    ret.Slerp(_end, _t);
    return ret;
}

template<Arithmetic T>
Vector4<T>& Vector4<T>::Normalize() noexcept
{
    *this /= Length();
    return *this;
}

template<Arithmetic T>
Vector4<T> Vector4<T>::Normalized() const noexcept
{
    Vector4<T> ret = *this;
    ret.Normalize();
    return ret;
}

template<Arithmetic T>
Vector4<T>& Vector4<T>::Translate(const Vector4<T>& _vector) noexcept
{
    *this += _vector;
    return *this;
}

template<Arithmetic T>
Vector4<T> Vector4<T>::Translated(const Vector4<T>& _vector) const noexcept
{
    Vector4<T> ret = *this;
    ret.Translate(_vector);
    return ret;
}

template<Arithmetic T>
Vector4<T>& Vector4<T>::Scale(const Vector4<T>& _anchor, const T _value) noexcept
{
    *this = _anchor + (*this - _anchor) * _value;
    return *this;
}

template<Arithmetic T>
Vector4<T> Vector4<T>::Scaled(const Vector4<T>& _anchor, const T _value) const noexcept
{
    Vector4<T> ret = *this;
    ret.Scale(_anchor, _value);
    return ret;
}

template<Arithmetic T>
Vector4<T>& Vector4<T>::Rotate(const Vector4<T>& _anchor, const float _angle) noexcept
{
    T tx = _anchor.x + (x - _anchor.x) * Koori::Math::Cos(_angle) - (y - _anchor.y) * Koori::Math::Sin(_angle);
    T ty = _anchor.y + (x - _anchor.x) * Koori::Math::Sin(_angle) + (y - _anchor.y) * Koori::Math::Cos(_angle);

    x = tx;
    y = ty;

    return *this;
}

template<Arithmetic T>
Vector4<T> Vector4<T>::Rotated(const Vector4<T>& _anchor, const float _angle) const noexcept
{
    Vector4<T> ret = *this;
    ret.Rotate(_anchor, _angle);
    return ret;
}

template<Arithmetic T>
Vector4<T>& Vector4<T>::Reflect(const Vector4<T>& _normal) noexcept
{
    *this = *this - _normal * static_cast<T>(2) * DotProduct(_normal);
    return *this;
}

template<Arithmetic T>
Vector4<T> Vector4<T>::Reflected(const Vector4<T>& _normal) const noexcept
{
    Vector4<T> ret = *this;
    ret.Reflect(_normal);
    return ret;
}

template<Arithmetic T>
Vector4<T>& Vector4<T>::Refract(const Vector4<T>& _normal, const T _ior) noexcept
{
    const T dotNI = DotProduct(_normal);
    const T k = static_cast<T>(1) - _ior * _ior * (static_cast<T>(1) - dotNI * dotNI);
    *this = k < static_cast<T>(0) ? Vector4::Zero : (*this * _ior) - _normal * (_ior * dotNI + Koori::Math::Sqrt(k));
    return *this;
}

template<Arithmetic T>
Vector4<T> Vector4<T>::Refracted(const Vector4<T>& _normal, const T _ior) const noexcept
{
    Vector4<T> ret = *this;
    ret.Refract(_normal, _ior);
    return ret;
}

template<Arithmetic T>
Vector4<T>& Vector4<T>::Project(const Vector4<T>& _onTo) noexcept
{
    *this = _onTo * (DotProduct(_onTo) / _onTo.SqrLength());
    return *this;
}

template<Arithmetic T>
Vector4<T> Vector4<T>::Projected(const Vector4<T>& _onTo) const noexcept
{
    Vector4<T> ret = *this;
    ret.Project(_onTo);
    return ret;
}

#pragma endregion

#pragma region Vector4 Static Methods

template<Arithmetic T>
constexpr T Vector4<T>::DotProduct(const Vector4<T>& _lhs, const Vector4<T>& _rhs) noexcept
{
    return _lhs.DotProduct(_rhs);
}

template<Arithmetic T>
constexpr float Vector4<T>::Angle(const Vector4<T>& _lhs, const Vector4<T>& _rhs) noexcept
{
    return _lhs.Angle(_rhs);
}

template<Arithmetic T>
constexpr T Vector4<T>::SqrLength(const Vector4<T>& _vector) noexcept
{
    return _vector.SqrLength();
}

template<Arithmetic T>
constexpr T Vector4<T>::Length(const Vector4<T>& _vector) noexcept
{
    return _vector.Length();
}

template<Arithmetic T>
constexpr T Vector4<T>::SqrDistance(const Vector4<T>& _lhs, const Vector4<T>& _rhs) noexcept
{
    return _lhs.SqrDistance(_rhs);
}

template<Arithmetic T>
constexpr T Vector4<T>::Distance(const Vector4<T>& _lhs, const Vector4<T>& _rhs) noexcept
{
    return _lhs.Distance(_rhs);
}

template<Arithmetic T>
constexpr Vector4<T> Vector4<T>::Negate(const Vector4<T>& _vector) noexcept
{
    return _vector.Negated();
}

template<Arithmetic T>
Vector4<T> Vector4<T>::Inverse(const Vector4<T>& _vector) noexcept
{
    return _vector.Inversed();
}

template<Arithmetic T>
Vector4<T> Vector4<T>::Lerp(const Vector4<T>& _start, const Vector4<T>& _end, const float _t) noexcept
{
   return _start.Lerped(_end, _t);
}

template<Arithmetic T>
Vector4<T> Vector4<T>::Slerp(const Vector4<T>& _start, const Vector4<T>& _end, const float _t) noexcept
{
    return _start.Slerped(_end, _t);
}

template<Arithmetic T>
Vector4<T> Vector4<T>::Normalize(const Vector4<T>& _vector) noexcept
{
    return _vector.Normalized();
}

template<Arithmetic T>
Vector4<T> Vector4<T>::Translate(const Vector4<T>& _vector, const Vector4<T>& _value) noexcept
{
    return _vector.Translated(_value);
}

template<Arithmetic T>
Vector4<T> Vector4<T>::Scale(const Vector4<T>& _vector, const Vector4<T>& _anchor, const T _value) noexcept
{
    return _vector.Scaled(_anchor, _value);
}

template<Arithmetic T>
Vector4<T> Vector4<T>::Rotate(const Vector4<T>& _vector, const Vector4<T>& _anchor, const float _angle) noexcept
{
    return _vector.Rotated(_anchor, _angle);
}

template<Arithmetic T>
Vector4<T> Vector4<T>::Reflect(const Vector4<T>& _incident, const Vector4<T>& _normal) noexcept
{
    return _incident.Reflected(_normal);
}

template<Arithmetic T>
Vector4<T> Vector4<T>::Refract(const Vector4<T>& _incident, const Vector4<T>& _normal, const T _ior) noexcept
{
    return _incident.Refracted(_normal, _ior);
}

template<Arithmetic T>
Vector4<T> Vector4<T>::Project(const Vector4<T>& _vector, const Vector4<T>& _onTo) noexcept
{
    return _vector.Projected(_onTo);
}

#pragma endregion

#pragma region Boolean Operations

template<Arithmetic T>
constexpr bool Vector4<T>::IsZero() const noexcept
{
    return Koori::Math::Equal(x, T(0)) && Koori::Math::Equal(y, T(0)) && Koori::Math::Equal(z, T(0)) && Koori::Math::Equal(w, T(0));
}

template<Arithmetic T>
constexpr bool Vector4<T>::Equal(const Vector4<T>& _vector) const noexcept
{
    return Koori::Math::Equal(x, _vector.x) && Koori::Math::Equal(y, _vector.y) && Koori::Math::Equal(z, _vector.z) && Koori::Math::Equal(w, _vector.w);
}

template<Arithmetic T>
constexpr bool Vector4<T>::IsNormalized() const noexcept
{
    return Koori::Math::Equal(SqrLength(), T(1));
}

template<Arithmetic T>
constexpr bool Vector4<T>::IsZero(const Vector4<T>& _vector) noexcept
{
    return _vector.IsZero();
}

template<Arithmetic T>
constexpr bool Vector4<T>::Equal(const Vector4<T>& _lhs, const Vector4<T>& _rhs) noexcept
{
    return _lhs.Equal(_rhs);
}

template<Arithmetic T>
constexpr bool Vector4<T>::IsNormalized(const Vector4<T>& _vector) noexcept
{
    return _vector.IsNormalized();
}

#pragma endregion

#pragma region Vector4 Operators

template<Arithmetic T>
constexpr Vector4<T> Vector4<T>::operator+(const Vector4<T>& _vector) const noexcept
{
    return Vector4<T>(x + _vector.x, y + _vector.y, z + _vector.z, w + _vector.w);
}

template<Arithmetic T>
constexpr Vector4<T> Vector4<T>::operator+(const T _scalar) const noexcept
{
    return Vector4<T>(x + _scalar, y + _scalar, z + _scalar, w + _scalar);
}

template<Arithmetic T>
constexpr Vector4<T> Vector4<T>::operator-(const Vector4<T>& _vector) const noexcept
{
    return Vector4<T>(x - _vector.x, y - _vector.y, z - _vector.z, w - _vector.w);
}

template<Arithmetic T>
constexpr Vector4<T> Vector4<T>::operator-(const T _scalar) const noexcept
{
    return Vector4<T>(x - _scalar, y - _scalar, z - _scalar, w - _scalar);
}

template<Arithmetic T>
constexpr Vector4<T> Vector4<T>::operator*(const Vector4<T>& _vector) const noexcept
{
    return Vector4<T>(x * _vector.x, y * _vector.y, z * _vector.z, w * _vector.w);
}

template<Arithmetic T>
constexpr Vector4<T> Vector4<T>::operator*(const T _scalar) const noexcept
{
    return Vector4<T>(x * _scalar, y * _scalar, z * _scalar, w * _scalar);
}

template<Arithmetic T>
Vector4<T> Vector4<T>::operator/(const Vector4<T>& _vector) const noexcept
{
    // TODO: Add verification for division by 0
    return Vector4<T>(x / _vector.x, y / _vector.y, z / _vector.z, w / _vector.w);
}

template<Arithmetic T>
Vector4<T> Vector4<T>::operator/(const T _scalar) const noexcept
{
    // TODO: Add verification for division by 0
    return Vector4<T>(x / _scalar, y / _scalar, z / _scalar, w / _scalar);
}

template<Arithmetic T>
Vector4<T>& Vector4<T>::operator+=(const Vector4<T>& _vector) noexcept
{
    x += _vector.x;
    y += _vector.y;
    z += _vector.z;
    w += _vector.w;

    return *this;
}

template<Arithmetic T>
Vector4<T>& Vector4<T>::operator+=(const T _scalar) noexcept
{
    x += _scalar;
    y += _scalar;
    z += _scalar;
    w += _scalar;

    return *this;
}

template<Arithmetic T>
Vector4<T>& Vector4<T>::operator-=(const Vector4<T>& _vector) noexcept
{
    x -= _vector.x;
    y -= _vector.y;
    z -= _vector.z;
    w -= _vector.w;

    return *this;
}

template<Arithmetic T>
Vector4<T>& Vector4<T>::operator-=(const T _scalar) noexcept
{
    x -= _scalar;
    y -= _scalar;
    z -= _scalar;
    w -= _scalar;

    return *this;
}

template<Arithmetic T>
Vector4<T>& Vector4<T>::operator*=(const Vector4<T>& _vector) noexcept
{
    x *= _vector.x;
    y *= _vector.y;
    z *= _vector.z;
    w *= _vector.w;

    return *this;
}

template<Arithmetic T>
Vector4<T>& Vector4<T>::operator*=(const T _scalar) noexcept
{
    x *= _scalar;
    y *= _scalar;
    z *= _scalar;
    w *= _scalar;

    return *this;
}

template<Arithmetic T>
Vector4<T>& Vector4<T>::operator/=(const Vector4<T>& _vector) noexcept
{
    x /= _vector.x;
    y /= _vector.y;
    z /= _vector.z;
    w /= _vector.w;

    return *this;
}

template<Arithmetic T>
Vector4<T>& Vector4<T>::operator/=(const T _scalar) noexcept
{
    x /= _scalar;
    y /= _scalar;
    z /= _scalar;
    w /= _scalar;

    return *this;
}

template<Arithmetic T>
constexpr Vector4<T> Vector4<T>::operator-() noexcept
{
    return Vector4<T>(-x, -y, -z, -w);
}

template<Arithmetic T>
Vector4<T>& Vector4<T>::operator=(const Vector4<T>& _vector) noexcept
{
    x = _vector.x;
    y = _vector.y;
    z = _vector.z;
    w = _vector.w;

    return *this;
}

template<Arithmetic T>
Vector4<T>& Vector4<T>::operator=(Vector4<T>&& _vector) noexcept
{
    x = _vector.x;
    y = _vector.y;
    z = _vector.z;
    w = _vector.w;

    _vector.x = _vector.y = _vector.z = _vector.w = T(0);

    return *this;
}

template<Arithmetic T>
constexpr bool Vector4<T>::operator==(const Vector4<T>& _vector) const noexcept
{
    return Equal(_vector);
}

template<Arithmetic T>
constexpr bool Vector4<T>::operator!=(const Vector4<T>& _vector) const noexcept
{
    return !Equal(_vector);
}

template<Arithmetic T>
constexpr T& Vector4<T>::operator[](const size_t _index) noexcept
{
    return Data()[_index];
}

template<Arithmetic T>
constexpr const T& Vector4<T>::operator[](const size_t _index) const noexcept
{
    return Data()[_index];
}

#pragma endregion

#pragma region String

template<Arithmetic T>
std::string Vector4<T>::ToString() const
{
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + std::to_string(w) + ")";
}

#pragma endregion
