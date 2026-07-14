#pragma region Vector Types

#include "Arithmetic/Equal.h"

using Vector2f = Vector2<float>;
using Vector2d = Vector2<double>;
using Vector2i = Vector2<int>;
using Vector2ui = Vector2<unsigned int>;

#pragma endregion

#pragma region Static Vectors

template<Arithmetic T>
inline constexpr Vector2<T> Vector2<T>::Zero = Vector2<T>(T(0));

template<Arithmetic T>
inline constexpr Vector2<T> Vector2<T>::One = Vector2<T>(T(1));

template<Arithmetic T>
inline constexpr Vector2<T> Vector2<T>::Right = Vector2<T>(T(1), T(0));

template<Arithmetic T>
inline constexpr Vector2<T> Vector2<T>::Up = Vector2<T>(T(0), T(1));

template<Arithmetic T>
inline constexpr Vector2<T> Vector2<T>::Left = Vector2<T>(T(-1), T(0));

template<Arithmetic T>
inline constexpr Vector2<T> Vector2<T>::Down = Vector2<T>(T(0), T(-1));

#pragma endregion

#pragma region Constructors

template<Arithmetic T>
constexpr Vector2<T>::Vector2() noexcept
    : x(T()), y(T())
{}

template<Arithmetic T>
constexpr Vector2<T>::Vector2(T _value) noexcept
    : x(_value), y(_value)
{}

template<Arithmetic T>
constexpr Vector2<T>::Vector2(T _xValue, T _yValue) noexcept
    : x(_xValue), y(_yValue)
{}

template<Arithmetic T>
constexpr Vector2<T>::Vector2(const Vector2<T>& _vector) noexcept
    : x(_vector.x), y(_vector.y)
{}

template<Arithmetic T>
constexpr Vector2<T>::Vector2(Vector2<T>&& _vector) noexcept
    : x(_vector.x), y(_vector.y)
{
    _vector.x = _vector.y = T();
}

template<Arithmetic T>
constexpr Vector2<T>::Vector2(const Vector2<T>* _vector) noexcept
    : x(_vector->x), y(_vector->y)
{}

#pragma endregion

#pragma region Vector2 Methods

template<Arithmetic T>
constexpr T Vector2<T>::DotProduct(const Vector2<T>& _vector) const noexcept
{
    return x * _vector.x + y * _vector.y;
}

template<Arithmetic T>
constexpr T Vector2<T>::CrossProduct(const Vector2<T>& _vector) const noexcept
{
    return x * _vector.y - y * _vector.x;
}

template<Arithmetic T>
constexpr float Vector2<T>::Angle(const Vector2<T>& _vector) const noexcept
{
    return Koori::Math::ACos(DotProduct(_vector) / (Length() * _vector.Length()));
}

template<Arithmetic T>
constexpr T Vector2<T>::SqrLength() const noexcept
{
    return x * x + y * y;
}

template<Arithmetic T>
constexpr T Vector2<T>::Length() const noexcept
{
    return Koori::Math::Sqrt(SqrLength());
}

template<Arithmetic T>
constexpr T Vector2<T>::SqrDistance(const Vector2<T>& _vector) const noexcept
{
    return (x - _vector.x) * (x - _vector.x) + (y - _vector.y) * (y - _vector.y);
}

template<Arithmetic T>
constexpr T Vector2<T>::Distance(const Vector2<T>& _vector) const noexcept
{
    return Koori::Math::Sqrt(SqrDistance(_vector));
}

template<Arithmetic T>
Vector2<T>& Vector2<T>::Negate() noexcept
{
    *this *= static_cast<T>(-1);
    return *this;
}

template<Arithmetic T>
Vector2<T> Vector2<T>::Negated() const noexcept
{
    Vector2<T> ret = *this;
    ret.Negate();
    return ret;
}

template<Arithmetic T>
Vector2<T>& Vector2<T>::Inverse() noexcept
{
    // TODO: Add verification for division by 0
    const T one = static_cast<T>(1);
    x = one / x;
    y = one / y;
    return *this;
}

template<Arithmetic T>
Vector2<T> Vector2<T>::Inversed() const noexcept
{
    Vector2<T> ret = *this;
    ret.Inverse();
    return ret;
}

template<Arithmetic T>
Vector2<T>& Vector2<T>::Lerp(const Vector2<T>& _end, const float _t) noexcept
{
    *this = *this * (1.f - _t) + _end * _t;
    return *this;
}

template<Arithmetic T>
Vector2<T> Vector2<T>::Lerped(const Vector2<T>& _end, const float _t) const noexcept
{
    Vector2<T> ret = *this;
    ret.Lerp(_end, _t);
    return ret;
}

template<Arithmetic T>
Vector2<T>& Vector2<T>::Slerp(const Vector2<T>& _end, const float _t) noexcept
{
    const float dot = Koori::Math::Clamp(static_cast<float>(DotProduct(_end)), -1.f, 1.f);
    const float theta = Koori::Math::ACos(dot) * _t;

    const Vector2<T> relative = (_end - (*this) * dot).Normalize();
    *this = relative * Koori::Math::Sin(theta) + *this * Koori::Math::Cos(theta);
    return *this;
}

template<Arithmetic T>
Vector2<T> Vector2<T>::Slerped(const Vector2<T>& _end, const float _t) const noexcept
{
    Vector2<T> ret = *this;
    ret.Slerp(_end, _t);
    return ret;
}

template<Arithmetic T>
Vector2<T>& Vector2<T>::Normalize() noexcept
{
    *this /= Length();
    return *this;
}

template<Arithmetic T>
Vector2<T> Vector2<T>::Normalized() const noexcept
{
    Vector2<T> ret = *this;
    ret.Normalize();
    return ret;
}

template<Arithmetic T>
Vector2<T>& Vector2<T>::Translate(const Vector2<T>& _vector) noexcept
{
    *this += _vector;
    return *this;
}

template<Arithmetic T>
Vector2<T> Vector2<T>::Translated(const Vector2<T>& _vector) const noexcept
{
    Vector2<T> ret = *this;
    ret.Translate(_vector);
    return ret;
}

template<Arithmetic T>
Vector2<T>& Vector2<T>::Scale(const Vector2<T>& _anchor, const T _value) noexcept
{
    *this = _anchor + (*this - _anchor) * _value;
    return *this;
}

template<Arithmetic T>
Vector2<T> Vector2<T>::Scaled(const Vector2<T>& _anchor, const T _value) const noexcept
{
    Vector2<T> ret = *this;
    ret.Scale(_anchor, _value);
    return ret;
}

template<Arithmetic T>
Vector2<T>& Vector2<T>::Rotate(const Vector2<T>& _anchor, const float _angle) noexcept
{
    T tx = _anchor.x + (x - _anchor.x) * Koori::Math::Cos(_angle) - (y - _anchor.y) * Koori::Math::Sin(_angle);
    T ty = _anchor.y + (x - _anchor.x) * Koori::Math::Sin(_angle) + (y - _anchor.y) * Koori::Math::Cos(_angle);

    x = tx;
    y = ty;

    return *this;
}

template<Arithmetic T>
Vector2<T> Vector2<T>::Rotated(const Vector2<T>& _anchor, const float _angle) const noexcept
{
    Vector2<T> ret = *this;
    ret.Rotate(_anchor, _angle);
    return ret;
}

template<Arithmetic T>
Vector2<T>& Vector2<T>::Perpendicular() noexcept
{
    T temp = x;
    x = y;
    y = -temp;

    return *this;
}

template<Arithmetic T>
Vector2<T> Vector2<T>::GetPerpendicular() const noexcept
{
    Vector2<T> ret = *this;
    ret.Perpendicular();
    return ret;
}

template<Arithmetic T>
Vector2<T>& Vector2<T>::Reflect(const Vector2<T>& _normal) noexcept
{
    *this = *this - _normal * static_cast<T>(2) * DotProduct(_normal);
    return *this;
}

template<Arithmetic T>
Vector2<T> Vector2<T>::Reflected(const Vector2<T>& _normal) const noexcept
{
    Vector2<T> ret = *this;
    ret.Reflect(_normal);
    return ret;
}

template<Arithmetic T>
Vector2<T>& Vector2<T>::Refract(const Vector2<T>& _normal, const T _ior) noexcept
{
    const T dotNI = DotProduct(_normal);
    const T k = static_cast<T>(1) - _ior * _ior * (static_cast<T>(1) - dotNI * dotNI);
    *this = k < static_cast<T>(0) ? Vector2::Zero : (*this * _ior) - _normal * (_ior * dotNI + Koori::Math::Sqrt(k));
    return *this;
}

template<Arithmetic T>
Vector2<T> Vector2<T>::Refracted(const Vector2<T>& _normal, const T _ior) const noexcept
{
    Vector2<T> ret = *this;
    ret.Refract(_normal, _ior);
    return ret;
}

template<Arithmetic T>
Vector2<T>& Vector2<T>::Project(const Vector2<T>& _onTo) noexcept
{
    *this = _onTo * (DotProduct(_onTo) / _onTo.SqrLength());
    return *this;
}

template<Arithmetic T>
Vector2<T> Vector2<T>::Projected(const Vector2<T>& _onTo) const noexcept
{
    Vector2<T> ret = *this;
    ret.Project(_onTo);
    return ret;
}

#pragma endregion

#pragma region Vector2 Static Methods

template<Arithmetic T>
constexpr T Vector2<T>::DotProduct(const Vector2<T>& _lhs, const Vector2<T>& _rhs) noexcept
{
    return _lhs.DotProduct(_rhs);
}

template<Arithmetic T>
constexpr T Vector2<T>::CrossProduct(const Vector2<T>& _lhs, const Vector2<T>& _rhs) noexcept
{
    return _lhs.CrossProduct(_rhs);
}

template<Arithmetic T>
constexpr float Vector2<T>::Angle(const Vector2<T>& _lhs, const Vector2<T>& _rhs) noexcept
{
    return _lhs.Angle(_rhs);
}

template<Arithmetic T>
constexpr T Vector2<T>::SqrLength(const Vector2<T>& _vector) noexcept
{
    return _vector.SqrLength();
}

template<Arithmetic T>
constexpr T Vector2<T>::Length(const Vector2<T>& _vector) noexcept
{
    return _vector.Length();
}

template<Arithmetic T>
constexpr T Vector2<T>::SqrDistance(const Vector2<T>& _lhs, const Vector2<T>& _rhs) noexcept
{
    return _lhs.SqrDistance(_rhs);
}

template<Arithmetic T>
constexpr T Vector2<T>::Distance(const Vector2<T>& _lhs, const Vector2<T>& _rhs) noexcept
{
    return _lhs.Distance(_rhs);
}

template<Arithmetic T>
constexpr Vector2<T> Vector2<T>::Negate(const Vector2<T>& _vector) noexcept
{
    return _vector.Negated();
}

template<Arithmetic T>
Vector2<T> Vector2<T>::Inverse(const Vector2<T>& _vector) noexcept
{
    return _vector.Inversed();
}

template<Arithmetic T>
Vector2<T> Vector2<T>::Lerp(const Vector2<T>& _start, const Vector2<T>& _end, const float _t) noexcept
{
   return _start.Lerped(_end, _t);
}

template<Arithmetic T>
Vector2<T> Vector2<T>::Slerp(const Vector2<T>& _start, const Vector2<T>& _end, const float _t) noexcept
{
    return _start.Slerped(_end, _t);
}

template<Arithmetic T>
Vector2<T> Vector2<T>::Normalize(const Vector2<T>& _vector) noexcept
{
    return _vector.Normalized();
}

template<Arithmetic T>
Vector2<T> Vector2<T>::Translate(const Vector2<T>& _vector, const Vector2<T>& _value) noexcept
{
    return _vector.Translated(_value);
}

template<Arithmetic T>
Vector2<T> Vector2<T>::Scale(const Vector2<T>& _vector, const Vector2<T>& _anchor, const T _value) noexcept
{
    return _vector.Scaled(_anchor, _value);
}

template<Arithmetic T>
Vector2<T> Vector2<T>::Rotate(const Vector2<T>& _vector, const Vector2<T>& _anchor, const float _angle) noexcept
{
    return _vector.Rotated(_anchor, _angle);
}

template<Arithmetic T>
Vector2<T> Vector2<T>::Perpendicular(const Vector2<T>& _vector) noexcept
{
    return _vector.GetPerpendicular();
}

template<Arithmetic T>
Vector2<T> Vector2<T>::Reflect(const Vector2<T>& _incident, const Vector2<T>& _normal) noexcept
{
    return _incident.Reflected(_normal);
}

template<Arithmetic T>
Vector2<T> Vector2<T>::Refract(const Vector2<T>& _incident, const Vector2<T>& _normal, const T _ior) noexcept
{
    return _incident.Refracted(_normal, _ior);
}

template<Arithmetic T>
Vector2<T> Vector2<T>::Project(const Vector2<T>& _vector, const Vector2<T>& _onTo) noexcept
{
    return _vector.Projected(_onTo);
}

#pragma endregion

#pragma region Boolean Operations

template<Arithmetic T>
constexpr bool Vector2<T>::IsZero() const noexcept
{
    return Koori::Math::Equal(x, T(0)) && Koori::Math::Equal(y, T(0));
}

template<Arithmetic T>
constexpr bool Vector2<T>::Equal(const Vector2<T>& _vector) const noexcept
{
    return Koori::Math::Equal(x, _vector.x) && Koori::Math::Equal(y, _vector.y);
}

template<Arithmetic T>
constexpr bool Vector2<T>::IsNormalized() const noexcept
{
    return Koori::Math::Equal(SqrLength(), T(1));
}

template<Arithmetic T>
constexpr bool Vector2<T>::IsZero(const Vector2<T>& _vector) noexcept
{
    return _vector.IsZero();
}

template<Arithmetic T>
constexpr bool Vector2<T>::Equal(const Vector2<T>& _lhs, const Vector2<T>& _rhs) noexcept
{
    return _lhs.Equal(_rhs);
}

template<Arithmetic T>
constexpr bool Vector2<T>::IsNormalized(const Vector2<T>& _vector) noexcept
{
    return _vector.IsNormalized();
}

#pragma endregion

#pragma region Vector2 Operators

template<Arithmetic T>
constexpr Vector2<T> Vector2<T>::operator+(const Vector2<T>& _vector) const noexcept
{
    return Vector2<T>(x + _vector.x, y + _vector.y);
}

template<Arithmetic T>
constexpr Vector2<T> Vector2<T>::operator+(const T _scalar) const noexcept
{
    return Vector2<T>(x + _scalar, y + _scalar);
}

template<Arithmetic T>
constexpr Vector2<T> Vector2<T>::operator-(const Vector2<T>& _vector) const noexcept
{
    return Vector2<T>(x - _vector.x, y - _vector.y);
}

template<Arithmetic T>
constexpr Vector2<T> Vector2<T>::operator-(const T _scalar) const noexcept
{
    return Vector2<T>(x - _scalar, y - _scalar);
}

template<Arithmetic T>
constexpr Vector2<T> Vector2<T>::operator*(const Vector2<T>& _vector) const noexcept
{
    return Vector2<T>(x * _vector.x, y * _vector.y);
}

template<Arithmetic T>
constexpr Vector2<T> Vector2<T>::operator*(const T _scalar) const noexcept
{
    return Vector2<T>(x * _scalar, y * _scalar);
}

template<Arithmetic T>
Vector2<T> Vector2<T>::operator/(const Vector2<T>& _vector) const noexcept
{
    // TODO: Add verification for division by 0
    return Vector2<T>(x / _vector.x, y / _vector.y);
}

template<Arithmetic T>
Vector2<T> Vector2<T>::operator/(const T _scalar) const noexcept
{
    // TODO: Add verification for division by 0
    return Vector2<T>(x / _scalar, y / _scalar);
}

template<Arithmetic T>
Vector2<T>& Vector2<T>::operator+=(const Vector2<T>& _vector) noexcept
{
    x += _vector.x;
    y += _vector.y;

    return *this;
}

template<Arithmetic T>
Vector2<T>& Vector2<T>::operator+=(const T _scalar) noexcept
{
    x += _scalar;
    y += _scalar;

    return *this;
}

template<Arithmetic T>
Vector2<T>& Vector2<T>::operator-=(const Vector2<T>& _vector) noexcept
{
    x -= _vector.x;
    y -= _vector.y;

    return *this;
}

template<Arithmetic T>
Vector2<T>& Vector2<T>::operator-=(const T _scalar) noexcept
{
    x -= _scalar;
    y -= _scalar;

    return *this;
}

template<Arithmetic T>
Vector2<T>& Vector2<T>::operator*=(const Vector2<T>& _vector) noexcept
{
    x *= _vector.x;
    y *= _vector.y;

    return *this;
}

template<Arithmetic T>
Vector2<T>& Vector2<T>::operator*=(const T _scalar) noexcept
{
    x *= _scalar;
    y *= _scalar;

    return *this;
}

template<Arithmetic T>
Vector2<T>& Vector2<T>::operator/=(const Vector2<T>& _vector) noexcept
{
    x /= _vector.x;
    y /= _vector.y;

    return *this;
}

template<Arithmetic T>
Vector2<T>& Vector2<T>::operator/=(const T _scalar) noexcept
{
    x /= _scalar;
    y /= _scalar;

    return *this;
}

template<Arithmetic T>
constexpr Vector2<T> Vector2<T>::operator-() noexcept
{
    return Vector2<T>(-x, -y);
}

template<Arithmetic T>
Vector2<T>& Vector2<T>::operator=(const Vector2<T>& _vector) noexcept
{
    x = _vector.x;
    y = _vector.y;

    return *this;
}

template<Arithmetic T>
Vector2<T>& Vector2<T>::operator=(Vector2<T>&& _vector) noexcept
{
    x = _vector.x;
    y = _vector.y;

    _vector.x = _vector.y = T(0);

    return *this;
}

template<Arithmetic T>
constexpr bool Vector2<T>::operator==(const Vector2<T>& _vector) const noexcept
{
    return Equal(_vector);
}

template<Arithmetic T>
constexpr bool Vector2<T>::operator!=(const Vector2<T>& _vector) const noexcept
{
    return !Equal(_vector);
}

template<Arithmetic T>
constexpr T& Vector2<T>::operator[](const size_t _index) noexcept
{
    return Data()[_index];
}

template<Arithmetic T>
constexpr const T& Vector2<T>::operator[](const size_t _index) const noexcept
{
    return Data()[_index];
}

#pragma endregion

#pragma region String

template<Arithmetic T>
std::string Vector2<T>::ToString() const
{
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

#pragma endregion
