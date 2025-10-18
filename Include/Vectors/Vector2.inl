#pragma region Vector Type

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
inline void Vector2<T>::AddScalar(T _value) noexcept
{
    x += _value;
    y += _value;
}

template<Arithmetic T>
inline void Vector2<T>::SubtractVector(const Vector2<T>& _vector) noexcept
{
    x -= _vector.x;
    y -= _vector.y;
}

template<Arithmetic T>
inline void Vector2<T>::SubtractScalar(T _value) noexcept
{
    x -= _value;
    y -= _value;
}

template<Arithmetic T>
inline void Vector2<T>::MultiplyVector(const Vector2<T>& _vector) noexcept
{
    x *= _vector.x;
    y *= _vector.y;
}

template<Arithmetic T>
inline void Vector2<T>::MultiplyScalar(T _value) noexcept
{
    x *= _value;
    y *= _value;
}

template<Arithmetic T>
inline void Vector2<T>::DivideVector(const Vector2<T>& _vector) noexcept
{
    x /= _vector.x;
    y /= _vector.y;
}

template<Arithmetic T>
inline void Vector2<T>::DivideScalar(T _value) noexcept
{
    x /= _value;
    y /= _value;
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
