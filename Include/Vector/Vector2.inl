#pragma region Vector Type

template<Arithmetic T>
Vector2<T> Vector2<T>::Zero = Vector2<T>(T(0));

template<Arithmetic T>
Vector2<T> Vector2<T>::One = Vector2<T>(T(1));

template<Arithmetic T>
Vector2<T> Vector2<T>::Right = Vector2<T>(T(1), T(0));

template<Arithmetic T>
Vector2<T> Vector2<T>::Up = Vector2<T>(T(0), T(1));

template<Arithmetic T>
Vector2<T> Vector2<T>::Left = Vector2<T>(T(-1), T(0));

template<Arithmetic T>
Vector2<T> Vector2<T>::Down = Vector2<T>(T(0), T(-1));

using Vector2f = Vector2<float>;
using Vector2d = Vector2<double>;
using Vector2i = Vector2<int>;

#pragma endregion

#pragma region Vector2 Methods

template<Arithmetic T>
inline void Vector2<T>::AddVector(const Vector2<T>& _vector) noexcept
{
    x += _vector.x;
    y += _vector.y;
}

template<Arithmetic T>
inline void Vector2<T>::AddScalar(const T _scalar) noexcept
{
    x += _scalar;
    y += _scalar;
}

template<Arithmetic T>
inline void Vector2<T>::SubtractVector(const Vector2<T>& _vector) noexcept
{
    x -= _vector.x;
    y -= _vector.y;
}

template<Arithmetic T>
inline void Vector2<T>::SubtractScalar(const T _scalar) noexcept
{
    x -= _scalar;
    y -= _scalar;
}

template<Arithmetic T>
inline void Vector2<T>::MultiplyVector(const Vector2<T>& _vector) noexcept
{
    x *= _vector.x;
    y *= _vector.y;
}

template<Arithmetic T>
inline void Vector2<T>::MultiplyScalar(const T _scalar) noexcept
{
    x *= _scalar;
    y *= _scalar;
}

template<Arithmetic T>
inline void Vector2<T>::DivideVector(const Vector2<T>& _vector) noexcept
{
    x /= _vector.x;
    y /= _vector.y;
}

template<Arithmetic T>
inline void Vector2<T>::DivideScalar(const T _scalar) noexcept
{
    x /= _scalar;
    y /= _scalar;
}
template<Arithmetic T>
inline T Vector2<T>::DotProduct(const Vector2<T>& _vector) const noexcept
{
    return x * _vector.x + y * _vector.y;
}

template<Arithmetic T>
inline T Vector2<T>::CrossProduct(const Vector2<T>& _vector) const noexcept
{
    return x * _vector.y - y * _vector.x;
}

template<Arithmetic T>
inline T Vector2<T>::SquaredLength() const noexcept
{
    return x * x + y * y;
}

template<Arithmetic T>
inline T Vector2<T>::Length() const noexcept
{
    return Koori::Math::Sqrt(SquaredLength());
}

template<Arithmetic T>
inline T Vector2<T>::SquaredMagnitude() const noexcept
{
    return SquaredLength();
}

template<Arithmetic T>
inline T Vector2<T>::Magnitude() const noexcept
{
    return Length();
}

template<Arithmetic T>
inline T Vector2<T>::SquaredDistance(const Vector2<T>& _vector) const noexcept
{
    return (x - _vector.x) * (x - _vector.x) + (y - _vector.y) * (y - _vector.y);
}

template<Arithmetic T>
inline T Vector2<T>::Distance(const Vector2<T>& _vector) const noexcept
{
    return Koori::Math::Sqrt(SquaredDistance(_vector));
}

template<Arithmetic T>
inline void Vector2<T>::Inverse() const noexcept
{
    const T one = static_cast<T>(1);
    x = one / x;
    y = one / y;
}

template<Arithmetic T>
inline bool Vector2<T>::IsNull() const noexcept
{
    return (Koori::Math::Abs(x) <= KM_EPSILON) && (Koori::Math::Abs(y) <= KM_EPSILON);
}

template<Arithmetic T>
inline bool Vector2<T>::Equal(const Vector2<T>& _vector) const noexcept
{
    return (Koori::Math::Abs(x - _vector.x) <= KM_EPSILON) && (Koori::Math::Abs(y - _vector.y) <= KM_EPSILON);
}

template<Arithmetic T>
inline float Vector2<T>::Angle(const Vector2<T>& _vector) const noexcept
{
    return (DotProduct(_vector)) / (Length() * _vector.Length());
}

template<Arithmetic T>
inline void Vector2<T>::Lerp(const Vector2<T>& _vector, const float _t) noexcept
{
    *this * (1.f - _t) + _vector * _t;
}

template<Arithmetic T>
inline void Vector2<T>::Slerp(const Vector2<T>& _vector, const float _t) noexcept
{
    const float dot = Koori::Math::Clamp(DotProduct(_vector), -1.f, 1.f);
    const float theta = Koori::Math::ACos(dot) * _t;

    Vector2<float> relative = (_vector - (*this) * dot).Normalize();
    *this = *this * Koori::Math::Cos(theta) + relative * Koori::Math::Sin(theta);
}

template<Arithmetic T>
inline void Vector2<T>::Normalize() noexcept
{
    const T length = Length();

    x /= length;
    y /= length;
}

template<Arithmetic T>
inline void Vector2<T>::Translate(const Vector2<T>& _vector) noexcept
{
    *this += _vector;
}

template<Arithmetic T>
inline void Vector2<T>::Scale(const Vector2<T>& _anchor, const T _value) noexcept
{
    *this = _anchor + (*this - _anchor) * _value;
}

template<Arithmetic T>
inline void Vector2<T>::Rotate(const Vector2<T>& _anchor, const T _angle) noexcept
{
    x = _anchor.x + (x - _anchor.x) * Koori::Math::Cos(_angle) - (y - _anchor.y) * Koori::Math::Sin(_angle);
    x = _anchor.y + (x - _anchor.x) * Koori::Math::Sin(_angle) + (y - _anchor.y) * Koori::Math::Cos(_angle);
}

template<Arithmetic T>
inline void Vector2<T>::Reflect(const Vector2<T>& _normal) noexcept
{
    *this = *this - static_cast<T>(2) * (DotProduct(_normal)) * _normal;
}

template<Arithmetic T>
inline void Vector2<T>::Refract(const Vector2<T>& _normal, const T _ior) noexcept
{
    const T k = static_cast<T>(1) - _ior * _ior * (static_cast<T>(1) - Dot(_normal) * Dot(_normal));
    *this = k < static_cast<T>(0) ? Vector2<T>(0) : _ior * *this - (_ior * DotProduct(_normal) + Koori::Math::Sqrt(k)) * _normal;
}

template<Arithmetic T>
inline void Vector2<T>::Project(const Vector2<T>& _vector) noexcept
{
    *this = Dotproduct(_vector) / _vector.DotProduct(_vector) * _vector;
}

#pragma endregion

#pragma region Vector2 Static Functions
#pragma endregion

#pragma region String

template<Arithmetic T>
inline std::string Vector2<T>::ToString() const
{
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

template<Arithmetic T>
inline const char* Vector2<T>::ToCstr() const
{
    return ToString().c_str();
}

#pragma endregion

#pragma region Vector2 Operators

template<Arithmetic T>
inline Vector2<T> Vector2<T>::operator+(const Vector2<T>& _vector) noexcept
{
    return Vector2<T>(x + _vector.x, y + _vector.y);
}

template<Arithmetic T>
inline Vector2<T> Vector2<T>::operator+(const T _scalar) noexcept
{
    return Vector2<T>(x + _scalar, y + _scalar);
}

template<Arithmetic T>
inline Vector2<T> Vector2<T>::operator-(const Vector2<T>& _vector) noexcept
{
    return Vector2<T>(x - _vector.x, y - _vector.y);
}

template<Arithmetic T>
inline Vector2<T> Vector2<T>::operator-(const T _scalar) noexcept
{
    return Vector2<T>(x - _scalar, y - _scalar);
}

template<Arithmetic T>
inline Vector2<T> Vector2<T>::operator*(const Vector2<T>& _vector) noexcept
{
    return Vector2<T>(x * _vector.x, y * _vector.y);
}

template<Arithmetic T>
inline Vector2<T> Vector2<T>::operator*(const T _scalar) noexcept
{
    return Vector2<T>(x * _scalar, y * _scalar);
}

template<Arithmetic T>
inline Vector2<T> Vector2<T>::operator/(const Vector2<T>& _vector) noexcept
{
    return Vector2<T>(x / _vector.x, y / _vector.y);
}

template<Arithmetic T>
inline Vector2<T> Vector2<T>::operator/(const T _scalar) noexcept
{
    return Vector2<T>(x / _scalar, y / _scalar);
}

template<Arithmetic T>
inline void Vector2<T>::operator+=(const Vector2<T>& _vector) noexcept
{
    AddVector(_vector);
}

template<Arithmetic T>
inline void Vector2<T>::operator+=(const T _scalar) noexcept
{
    AddScalar(_scalar);
}

template<Arithmetic T>
inline void Vector2<T>::operator-=(const Vector2<T>& _vector) noexcept
{
    SubtractVector(_vector);
}

template<Arithmetic T>
inline void Vector2<T>::operator-=(const T _scalar) noexcept
{
    SubtractScalar(_scalar);
}

template<Arithmetic T>
inline void Vector2<T>::operator*=(const Vector2<T>& _vector) noexcept
{
    MultiplyVector(_vector);
}

template<Arithmetic T>
inline void Vector2<T>::operator*=(const T _scalar) noexcept
{
    MultiplyScalar(_scalar);
}

template<Arithmetic T>
inline void Vector2<T>::operator/=(const Vector2<T>& _vector) noexcept
{
    DivideVector(_vector);
}

template<Arithmetic T>
inline void Vector2<T>::operator/=(const T _scalar) noexcept
{
    DivideScalar(_scalar);
}

template<Arithmetic T>
inline Vector2<T>& Vector2<T>::operator=(const Vector2<T>& _vector) noexcept
{
    x = _vector.x;
    y = _vector.y;

    return *this;
}

template<Arithmetic T>
inline Vector2<T>& Vector2<T>::operator=(const Vector2<T>&& _vector) noexcept
{
    x = _vector.x;
    y = _vector.y;

    return *this;
}

template<Arithmetic T>
inline bool Vector2<T>::operator==(const Vector2<T>& _vector) const noexcept
{
    return Equal(_vector);
}

template<Arithmetic T>
inline T Vector2<T>::operator[](const size_t _index) const noexcept
{
    switch (_index)
    {
        case 0:
            return x;
        case 1:
            return y;
        default:
            return NAN;
    }
}

#pragma endregion