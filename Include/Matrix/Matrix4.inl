#include <Arithmetic/Equal.h>

#include <Vector/Vector3.h>

#include <Quaternion/Quaternion.h>

#pragma region Matrix Types

using Matrix4f = Matrix4<float>;
using Matrix4d = Matrix4<double>;
using Matrix4i = Matrix4<int>;
using Matrix4ui = Matrix4<unsigned int>;

#pragma endregion

#pragma region Static Matrices

template<Arithmetic T>
inline constexpr Matrix4<T> Matrix4<T>::Zero = Matrix4<T>(T(0));

template<Arithmetic T>
inline constexpr Matrix4<T> Matrix4<T>::One = Matrix4<T>(T(1));

template<Arithmetic T>
inline constexpr Matrix4<T> Matrix4<T>::Identity = Matrix4<T>(
    T(1), T(0), T(0), T(0),
    T(0), T(1), T(0), T(0), 
    T(0), T(0), T(1), T(0), 
    T(0), T(0), T(0), T(1) 
    );

#pragma endregion

#pragma region Constructors

template<Arithmetic T>
constexpr Matrix4<T>::Matrix4() noexcept
    : m00(T()), m01(T()), m02(T()), m03(T()),
    m10(T()), m11(T()), m12(T()), m13(T()),
    m20(T()), m21(T()), m22(T()), m23(T()),
    m30(T()), m31(T()), m32(T()), m33(T())
{}

template<Arithmetic T>
constexpr Matrix4<T>::Matrix4(T _value) noexcept
    : m00(_value), m01(_value), m02(_value), m03(_value),
    m10(_value), m11(_value), m12(_value), m13(_value),
    m20(_value), m21(_value), m22(_value), m23(_value),
    m30(_value), m31(_value), m32(_value), m33(_value)
{}

template<Arithmetic T>
constexpr Matrix4<T>::Matrix4(T _xValue, T _yValue, T _zValue, T _wValue) noexcept
    : m00(_xValue), m01(_yValue), m02(_zValue), m03(_wValue),
    m10(_xValue), m11(_yValue), m12(_zValue), m13(_wValue),
    m20(_xValue), m21(_yValue), m22(_zValue), m23(_wValue),
    m30(_xValue), m31(_yValue), m32(_zValue), m33(_wValue)
{}

template<Arithmetic T>
constexpr Matrix4<T>::Matrix4(T _m00, T _m01, T _m02, T _m03,
    T _m10, T _m11, T _m12, T _m13,
    T _m20, T _m21, T _m22, T _m23,
    T _m30, T _m31, T _m32, T _m33) noexcept
    : m00(_m00), m01(_m01), m02(_m02), m03(_m03),
    m10(_m10), m11(_m11), m12(_m12), m13(_m13),
    m20(_m20), m21(_m21), m22(_m22), m23(_m23),
    m30(_m30), m31(_m31), m32(_m32), m33(_m33)
{}

template<Arithmetic T>
constexpr Matrix4<T>::Matrix4(const Matrix4<T>& _matrix) noexcept
    : m00(_matrix.m00), m01(_matrix.m01), m02(_matrix.m02), m03(_matrix.m03),
    m10(_matrix.m10), m11(_matrix.m11), m12(_matrix.m12), m13(_matrix.m13),
    m20(_matrix.m20), m21(_matrix.m21), m22(_matrix.m22), m23(_matrix.m23),
    m30(_matrix.m30), m31(_matrix.m31), m32(_matrix.m32), m33(_matrix.m33)
{}

template<Arithmetic T>
constexpr Matrix4<T>::Matrix4(Matrix4<T>&& _matrix) noexcept
    : m00(_matrix.m00), m01(_matrix.m01), m02(_matrix.m02), m03(_matrix.m03),
    m10(_matrix.m10), m11(_matrix.m11), m12(_matrix.m12), m13(_matrix.m13),
    m20(_matrix.m20), m21(_matrix.m21), m22(_matrix.m22), m23(_matrix.m23),
    m30(_matrix.m30), m31(_matrix.m31), m32(_matrix.m32), m33(_matrix.m33)
{
    _matrix.m00 = _matrix.m01 = _matrix.m02 = _matrix.m03
        = _matrix.m10 = _matrix.m11 = _matrix.m12 = _matrix.m13
        = _matrix.m20 = _matrix.m21 = _matrix.m22 = _matrix.m23
        = _matrix.m30 = _matrix.m31 = _matrix.m32 = _matrix.m33 = T();
}

template<Arithmetic T>
constexpr Matrix4<T>::Matrix4(const Matrix4<T>* _matrix) noexcept
    : m00(_matrix->m00), m01(_matrix->m01), m02(_matrix->m02), m03(_matrix->m03),
    m10(_matrix->m10), m11(_matrix->m11), m12(_matrix->m12), m13(_matrix->m13),
    m20(_matrix->m20), m21(_matrix->m21), m22(_matrix->m22), m23(_matrix->m23),
    m30(_matrix->m30), m31(_matrix->m31), m32(_matrix->m32), m33(_matrix->m33)
{}

#pragma endregion

#pragma region Matrix4 Methods

template<Arithmetic T>
constexpr T Matrix4<T>::Trace() const noexcept
{
    return m00 + m11 + m22 + m33;
}

template<Arithmetic T>
constexpr T Matrix4<T>::Determinant() const noexcept
{
    return T(0);
}

template<Arithmetic T>
Matrix4<T> Matrix4<T>::Transpose() const noexcept
{
    return Matrix4<T>(
        m00, m10, m20, m30,
        m01, m11, m21, m31,
        m02, m12, m22, m32,
        m03, m13, m23, m33
    );
}

template<Arithmetic T>
Matrix4<T> Matrix4<T>::Inverse() const noexcept
{
    return Matrix4<T>();
}

template<Arithmetic T>
Matrix4<T> Matrix4<T>::Translation(const T _x, const T _y, const T _z) const noexcept
{
    return Matrix4<T>(
        T(1), T(0), T(0), T(_x),
        T(0), T(1), T(0), T(_y),
        T(0), T(0), T(1), T(_z),
        T(0), T(0), T(0), T(1)
    );
}

template<Arithmetic T>
Matrix4<T> Matrix4<T>::Translation(const Vector3<T>& _translation) const noexcept
{
    return Translation(_translation.x, _translation.y, _translation.z);
}

template<Arithmetic T>
Matrix4<T> Matrix4<T>::XRotation(const T _angle) const noexcept
{
    const T c = Koori::Math::Cos(_angle);
    const T s = Koori::Math::Sin(_angle);

    return Matrix4<T>(
        T(1), T(0), T(0), T(0),
        T(0), T(c), T(s), T(0),
        T(0), T(-s), T(c), T(0),
        T(0), T(0), T(0), T(1)
    );
}

template<Arithmetic T>
Matrix4<T> Matrix4<T>::YRotation(const T _angle) const noexcept
{
    const T c = Koori::Math::Cos(_angle);
    const T s = Koori::Math::Sin(_angle);

    return Matrix4<T>(
        T(c), T(0), T(-s), T(0),
        T(0), T(1), T(0), T(0),
        T(s), T(0), T(c), T(0),
        T(0), T(0), T(0), T(1)
    );
}

template<Arithmetic T>
Matrix4<T> Matrix4<T>::ZRotation(const T _angle) const noexcept
{
    const T c = Koori::Math::Cos(_angle);
    const T s = Koori::Math::Sin(_angle);

    return Matrix4<T>(
        T(c), T(s), T(0), T(0),
        T(-s), T(c), T(0), T(0),
        T(0), T(0), T(1), T(0),
        T(0), T(0), T(0), T(1)
    );
}

template<Arithmetic T>
Matrix4<T> Matrix4<T>::Rotation(const T _angle, const Vector3<T>& _axis) const noexcept
{
    return Matrix4<T>();
}

template<Arithmetic T>
Matrix4<T> Matrix4<T>::Rotation(const Quaternion<T>& _rotation) const noexcept
{
    return Matrix4<T>();
}

template<Arithmetic T>
Matrix4<T> Matrix4<T>::Scaling(const T _x, const T _y, const T _z) const noexcept
{
    return Matrix4<T>(
        T(_x), T(0), T(0), T(0),
        T(0), T(_y), T(0), T(0),
        T(0), T(0), T(_z), T(0),
        T(0), T(0), T(0), T(1)
    );
}

template<Arithmetic T>
Matrix4<T> Matrix4<T>::Scaling(const Vector3<T>& _scaling) const noexcept
{
    return Scaling(_scaling.x, _scaling.y, _scaling.z);
}

template<Arithmetic T>
Matrix4<T> Matrix4<T>::TRS(const Matrix4<T>& _translation, const Matrix4<T>& _rotation, const Matrix4<T>& _scaling) const noexcept
{
    return _translation * _rotation * _scaling;
}

template<Arithmetic T>
Matrix4<T> Matrix4<T>::TRS(const Vector3<T>& _translation, const Quaternion<T>& _rotation, const Vector3<T>& _scaling) const noexcept
{
    return Matrix4<T>();
}

template<Arithmetic T>
Matrix4<T> Matrix4<T>::PerspectiveProjection(const T _near, const T _far, const T _aspect, const T _fov) const noexcept
{
    // Perspective RH matrix with | 0 - 1
    const T tanHalfFov = Koori::Math::Tan(_fov * T(0.5));
    const T s = T(1) / (_aspect * tanHalfFov);
    const T s2 = T(1) / tanHalfFov;

    return Matrix4<T>(
        T(s), T(0), T(0), T(0),
        T(0), T(s2), T(0), T(0),
        T(0), T(0), T(_far / (_near - _far)), T(-1),
        T(0), T(0), T(-(_far * _near) / (_far - _near)), T(0)
    );
}

template<Arithmetic T>
Matrix4<T> Matrix4<T>::OrthographicProjection(const T _near, const T _far, const T _top, const T _bottom, const T _right, const T _left) const noexcept
{
    // Orthographic RH matrix with | 0 - 1
    return Matrix4<T>(
        T(T(2) / (_right - _left)), T(0), T(0), T(0),
        T(0), T(T(2) / (_top - _bottom)), T(0), T(0),
        T(0), T(0), T(T(-1) / (_far - _near)), T(0),
        T(-(_right + _left) / (_right - _left)), T(-(_top + _bottom) / (_top - _bottom)), T((-_near) / (_far - _near)), T(1)
    );
}

template<Arithmetic T>
Matrix4<T> Matrix4<T>::ViewMatrix(const Vector3<T>& _eye, const Vector3<T>& _lookAt, const Vector3<T>& _up) const noexcept
{
    Vector3<T> zAxis = (_lookAt - _eye);
    zAxis = zAxis.Normalize();
    Vector3<T> xAxis = zAxis.CrossProduct(_up);
    zAxis = zAxis.Normalize();
    Vector3<T> yAxis = xAxis.CrossProduct(zAxis);
    yAxis = yAxis.Normalize();

    return Matrix4<T>(
        xAxis.x, yAxis.x, zAxis.x, T(0),
        xAxis.y, yAxis.y, zAxis.y, T(0),
        xAxis.z, yAxis.z, zAxis.z, T(0),
        -_eye.x, -_eye.y, -_eye.x, T(1)
    );
}

#pragma endregion

#pragma region Boolean Operations

template<Arithmetic T>
constexpr bool Matrix4<T>::IsZero() const noexcept
{
    return
        Koori::Math::Equal(m00, T(0)) && Koori::Math::Equal(m01, T(0)) && Koori::Math::Equal(m02, T(0)) && Koori::Math::Equal(m03, T(0)) &&
        Koori::Math::Equal(m10, T(0)) && Koori::Math::Equal(m11, T(0)) && Koori::Math::Equal(m12, T(0)) && Koori::Math::Equal(m13, T(0)) &&
        Koori::Math::Equal(m20, T(0)) && Koori::Math::Equal(m21, T(0)) && Koori::Math::Equal(m22, T(0)) && Koori::Math::Equal(m23, T(0)) &&
        Koori::Math::Equal(m30, T(0)) && Koori::Math::Equal(m31, T(0)) && Koori::Math::Equal(m32, T(0)) && Koori::Math::Equal(m33, T(0));
}

template<Arithmetic T>
constexpr bool Matrix4<T>::Equal(const Matrix4<T>& _matrix) const noexcept
{
    return
        Koori::Math::Equal(m00, _matrix.m00) && Koori::Math::Equal(m01, _matrix.m01) && Koori::Math::Equal(m02, _matrix.m02) && Koori::Math::Equal(m03, _matrix.m03) &&
        Koori::Math::Equal(m10, _matrix.m10) && Koori::Math::Equal(m11, _matrix.m11) && Koori::Math::Equal(m12, _matrix.m12) && Koori::Math::Equal(m13, _matrix.m13) &&
        Koori::Math::Equal(m20, _matrix.m20) && Koori::Math::Equal(m21, _matrix.m21) && Koori::Math::Equal(m22, _matrix.m22) && Koori::Math::Equal(m23, _matrix.m23) &&
        Koori::Math::Equal(m30, _matrix.m30) && Koori::Math::Equal(m31, _matrix.m31) && Koori::Math::Equal(m32, _matrix.m32) && Koori::Math::Equal(m33, _matrix.m33);
}

template<Arithmetic T>
constexpr bool Matrix4<T>::IsZero(const Matrix4<T>& _vector) noexcept
{
    return _vector.IsZero();
}

template<Arithmetic T>
constexpr bool Matrix4<T>::Equal(const Matrix4<T>& _lhs, const Matrix4<T>& _rhs) noexcept
{
    return _lhs.Equal(_rhs);
}

#pragma endregion

#pragma region Matrix4 Operators

template<Arithmetic T>
constexpr Matrix4<T> Matrix4<T>::operator+(const Matrix4<T>& _matrix) const noexcept
{
    return Matrix4<T>(
        m00 + _matrix.m00, m01 + _matrix.m01, m02 + _matrix.m02, m03 + _matrix.m03,
        m10 + _matrix.m10, m11 + _matrix.m11, m12 + _matrix.m12, m13 + _matrix.m13,
        m20 + _matrix.m20, m21 + _matrix.m21, m22 + _matrix.m22, m23 + _matrix.m23,
        m30 + _matrix.m30, m31 + _matrix.m31, m32 + _matrix.m32, m33 + _matrix.m33
    );
}

template<Arithmetic T>
constexpr Matrix4<T> Matrix4<T>::operator+(const T _scalar) const noexcept
{
    return Matrix4<T>(
        m00 + _scalar, m01 + _scalar, m02 + _scalar, m03 + _scalar,
        m10 + _scalar, m11 + _scalar, m12 + _scalar, m13 + _scalar,
        m20 + _scalar, m21 + _scalar, m22 + _scalar, m23 + _scalar,
        m30 + _scalar, m31 + _scalar, m32 + _scalar, m33 + _scalar
    );
}

template<Arithmetic T>
constexpr Matrix4<T> Matrix4<T>::operator-(const Matrix4<T>& _matrix) const noexcept
{
    return Matrix4<T>(
        m00 - _matrix.m00, m01 - _matrix.m01, m02 - _matrix.m02, m03 - _matrix.m03,
        m10 - _matrix.m10, m11 - _matrix.m11, m12 - _matrix.m12, m13 - _matrix.m13,
        m20 - _matrix.m20, m21 - _matrix.m21, m22 - _matrix.m22, m23 - _matrix.m23,
        m30 - _matrix.m30, m31 - _matrix.m31, m32 - _matrix.m32, m33 - _matrix.m33
    );
}

template<Arithmetic T>
constexpr Matrix4<T> Matrix4<T>::operator-(const T _scalar) const noexcept
{
    return Matrix4<T>(
        m00 - _scalar, m01 - _scalar, m02 - _scalar, m03 - _scalar,
        m10 - _scalar, m11 - _scalar, m12 - _scalar, m13 - _scalar,
        m20 - _scalar, m21 - _scalar, m22 - _scalar, m23 - _scalar,
        m30 - _scalar, m31 - _scalar, m32 - _scalar, m33 - _scalar
    );
}

template<Arithmetic T>
constexpr Matrix4<T> Matrix4<T>::operator*(const Matrix4<T>& _matrix) const noexcept
{
    return Matrix4<T>(
        m00 * _matrix.m00 + m01 * _matrix.m10 + m02 * _matrix.m20 + m03 * _matrix.m30,
        m00 * _matrix.m01 + m01 * _matrix.m11 + m02 * _matrix.m21 + m03 * _matrix.m31,
        m00 * _matrix.m02 + m01 * _matrix.m12 + m02 * _matrix.m22 + m03 * _matrix.m32,
        m00 * _matrix.m03 + m01 * _matrix.m13 + m02 * _matrix.m23 + m03 * _matrix.m33,

        m10 * _matrix.m00 + m11 * _matrix.m10 + m12 * _matrix.m20 + m13 * _matrix.m30,
        m10 * _matrix.m01 + m11 * _matrix.m11 + m12 * _matrix.m21 + m13 * _matrix.m31,
        m10 * _matrix.m02 + m11 * _matrix.m12 + m12 * _matrix.m22 + m13 * _matrix.m32,
        m10 * _matrix.m03 + m11 * _matrix.m13 + m12 * _matrix.m23 + m13 * _matrix.m33,

        m20 * _matrix.m00 + m21 * _matrix.m10 + m22 * _matrix.m20 + m23 * _matrix.m30,
        m20 * _matrix.m01 + m21 * _matrix.m11 + m22 * _matrix.m21 + m23 * _matrix.m31,
        m20 * _matrix.m02 + m21 * _matrix.m12 + m22 * _matrix.m22 + m23 * _matrix.m32,
        m20 * _matrix.m03 + m21 * _matrix.m13 + m22 * _matrix.m23 + m23 * _matrix.m33,

        m30 * _matrix.m00 + m31 * _matrix.m10 + m32 * _matrix.m20 + m33 * _matrix.m30,
        m30 * _matrix.m01 + m31 * _matrix.m11 + m32 * _matrix.m21 + m33 * _matrix.m31,
        m30 * _matrix.m02 + m31 * _matrix.m12 + m32 * _matrix.m22 + m33 * _matrix.m32,
        m30 * _matrix.m03 + m31 * _matrix.m13 + m32 * _matrix.m23 + m33 * _matrix.m33
    );
}

template<Arithmetic T>
constexpr Matrix4<T> Matrix4<T>::operator*(const T _scalar) const noexcept
{
    return Matrix4<T>(
        m00 * _scalar, m01 * _scalar, m02 * _scalar, m03 * _scalar,
        m10 * _scalar, m11 * _scalar, m12 * _scalar, m13 * _scalar,
        m20 * _scalar, m21 * _scalar, m22 * _scalar, m23 * _scalar,
        m30 * _scalar, m31 * _scalar, m32 * _scalar, m33 * _scalar
    );
}

template<Arithmetic T>
Matrix4<T> Matrix4<T>::operator/(const Matrix4<T>& _matrix) const noexcept
{
    // TODO: Add verification for division by 0
    return Matrix4<T>(
        m00 / _matrix.m00, m01 / _matrix.m01, m02 / _matrix.m02, m03 / _matrix.m03,
        m10 / _matrix.m10, m11 / _matrix.m11, m12 / _matrix.m12, m13 / _matrix.m13,
        m20 / _matrix.m20, m21 / _matrix.m21, m22 / _matrix.m22, m23 / _matrix.m23,
        m30 / _matrix.m30, m31 / _matrix.m31, m32 / _matrix.m32, m33 / _matrix.m33
    );
}

template<Arithmetic T>
Matrix4<T> Matrix4<T>::operator/(const T _scalar) const noexcept
{
    // TODO: Add verification for division by 0
    return Matrix4<T>(
        m00 / _scalar, m01 / _scalar, m02 / _scalar, m03 / _scalar,
        m10 / _scalar, m11 / _scalar, m12 / _scalar, m13 / _scalar,
        m20 / _scalar, m21 / _scalar, m22 / _scalar, m23 / _scalar,
        m30 / _scalar, m31 / _scalar, m32 / _scalar, m33 / _scalar
    );
}

template<Arithmetic T>
Matrix4<T>& Matrix4<T>::operator+=(const Matrix4<T>& _matrix) noexcept
{
    m00 += _matrix.m00; m01 += _matrix.m01; m02 += _matrix.m02; m03 += _matrix.m03;
    m10 += _matrix.m10; m11 += _matrix.m11; m12 += _matrix.m12; m13 += _matrix.m13;
    m20 += _matrix.m20; m21 += _matrix.m21; m22 += _matrix.m22; m23 += _matrix.m23;
    m30 += _matrix.m30; m31 += _matrix.m31; m32 += _matrix.m32; m33 += _matrix.m33;

    return *this;
}

template<Arithmetic T>
Matrix4<T>& Matrix4<T>::operator+=(const T _scalar) noexcept
{
    m00 += _scalar; m01 += _scalar; m02 += _scalar; m03 += _scalar;
    m10 += _scalar; m11 += _scalar; m12 += _scalar; m13 += _scalar;
    m20 += _scalar; m21 += _scalar; m22 += _scalar; m23 += _scalar;
    m30 += _scalar; m31 += _scalar; m32 += _scalar; m33 += _scalar;

    return *this;
}

template<Arithmetic T>
Matrix4<T>& Matrix4<T>::operator-=(const Matrix4<T>& _matrix) noexcept
{
    m00 -= _matrix.m00; m01 -= _matrix.m01; m02 -= _matrix.m02; m03 -= _matrix.m03;
    m10 -= _matrix.m10; m11 -= _matrix.m11; m12 -= _matrix.m12; m13 -= _matrix.m13;
    m20 -= _matrix.m20; m21 -= _matrix.m21; m22 -= _matrix.m22; m23 -= _matrix.m23;
    m30 -= _matrix.m30; m31 -= _matrix.m31; m32 -= _matrix.m32; m33 -= _matrix.m33;

    return *this;
}

template<Arithmetic T>
Matrix4<T>& Matrix4<T>::operator-=(const T _scalar) noexcept
{
    m00 -= _scalar; m01 -= _scalar; m02 -= _scalar; m03 -= _scalar;
    m10 -= _scalar; m11 -= _scalar; m12 -= _scalar; m13 -= _scalar;
    m20 -= _scalar; m21 -= _scalar; m22 -= _scalar; m23 -= _scalar;
    m30 -= _scalar; m31 -= _scalar; m32 -= _scalar; m33 -= _scalar;

    return *this;
}

template<Arithmetic T>
Matrix4<T>& Matrix4<T>::operator*=(const Matrix4<T>& _matrix) noexcept
{
    const Matrix4<T> lhs(*this);

    m00 = lhs.m00 * rhs.m00 + lhs.m01 * rhs.m10 + lhs.m02 * rhs.m20 + lhs.m03 * rhs.m30;
    m01 = lhs.m00 * rhs.m01 + lhs.m01 * rhs.m11 + lhs.m02 * rhs.m21 + lhs.m03 * rhs.m31;
    m02 = lhs.m00 * rhs.m02 + lhs.m01 * rhs.m12 + lhs.m02 * rhs.m22 + lhs.m03 * rhs.m32;
    m03 = lhs.m00 * rhs.m03 + lhs.m01 * rhs.m13 + lhs.m02 * rhs.m23 + lhs.m03 * rhs.m33;

    m10 = lhs.m10 * rhs.m00 + lhs.m11 * rhs.m10 + lhs.m12 * rhs.m20 + lhs.m13 * rhs.m30;
    m11 = lhs.m10 * rhs.m01 + lhs.m11 * rhs.m11 + lhs.m12 * rhs.m21 + lhs.m13 * rhs.m31;
    m12 = lhs.m10 * rhs.m02 + lhs.m11 * rhs.m12 + lhs.m12 * rhs.m22 + lhs.m13 * rhs.m32;
    m13 = lhs.m10 * rhs.m03 + lhs.m11 * rhs.m13 + lhs.m12 * rhs.m23 + lhs.m13 * rhs.m33;

    m20 = lhs.m20 * rhs.m00 + lhs.m21 * rhs.m10 + lhs.m22 * rhs.m20 + lhs.m23 * rhs.m30;
    m21 = lhs.m20 * rhs.m01 + lhs.m21 * rhs.m11 + lhs.m22 * rhs.m21 + lhs.m23 * rhs.m31;
    m22 = lhs.m20 * rhs.m02 + lhs.m21 * rhs.m12 + lhs.m22 * rhs.m22 + lhs.m23 * rhs.m32;
    m23 = lhs.m20 * rhs.m03 + lhs.m21 * rhs.m13 + lhs.m22 * rhs.m23 + lhs.m23 * rhs.m33;

    m30 = lhs.m30 * rhs.m00 + lhs.m31 * rhs.m10 + lhs.m32 * rhs.m20 + lhs.m33 * rhs.m30;
    m31 = lhs.m30 * rhs.m01 + lhs.m31 * rhs.m11 + lhs.m32 * rhs.m21 + lhs.m33 * rhs.m31;
    m32 = lhs.m30 * rhs.m02 + lhs.m31 * rhs.m12 + lhs.m32 * rhs.m22 + lhs.m33 * rhs.m32;
    m33 = lhs.m30 * rhs.m03 + lhs.m31 * rhs.m13 + lhs.m32 * rhs.m23 + lhs.m33 * rhs.m33;

    return *this;
}

template<Arithmetic T>
Matrix4<T>& Matrix4<T>::operator*=(const T _scalar) noexcept
{
    m00 *= _scalar; m01 *= _scalar; m02 *= _scalar; m03 *= _scalar;
    m10 *= _scalar; m11 *= _scalar; m12 *= _scalar; m13 *= _scalar;
    m20 *= _scalar; m21 *= _scalar; m22 *= _scalar; m23 *= _scalar;
    m30 *= _scalar; m31 *= _scalar; m32 *= _scalar; m33 *= _scalar;

    return *this;
}

template<Arithmetic T>
Matrix4<T>& Matrix4<T>::operator/=(const Matrix4<T>& _matrix) noexcept
{
    m00 /= _matrix.m00; m01 /= _matrix.m01; m02 /= _matrix.m02; m03 /= _matrix.m03;
    m10 /= _matrix.m10; m11 /= _matrix.m11; m12 /= _matrix.m12; m13 /= _matrix.m13;
    m20 /= _matrix.m20; m21 /= _matrix.m21; m22 /= _matrix.m22; m23 /= _matrix.m23;
    m30 /= _matrix.m30; m31 /= _matrix.m31; m32 /= _matrix.m32; m33 /= _matrix.m33;

    return *this;
}

template<Arithmetic T>
Matrix4<T>& Matrix4<T>::operator/=(const T _scalar) noexcept
{
    m00 /= _scalar; m01 /= _scalar; m02 /= _scalar; m03 /= _scalar;
    m10 /= _scalar; m11 /= _scalar; m12 /= _scalar; m13 /= _scalar;
    m20 /= _scalar; m21 /= _scalar; m22 /= _scalar; m23 /= _scalar;
    m30 /= _scalar; m31 /= _scalar; m32 /= _scalar; m33 /= _scalar;

    return *this;
}

template<Arithmetic T>
constexpr Matrix4<T> Matrix4<T>::operator-() noexcept
{
    return Matrix4<T>(
        -m00, -m01, -m02, -m03,
        -m10, -m11, -m12, -m13,
        -m20, -m21, -m22, -m23,
        -m30, -m31, -m32, -m33
    );
}

template<Arithmetic T>
Matrix4<T>& Matrix4<T>::operator=(const Matrix4<T>& _matrix) noexcept
{
    m00 = _matrix.m00; m01 = _matrix.m01; m02 = _matrix.m02; m03 = _matrix.m03;
    m10 = _matrix.m10; m11 = _matrix.m11; m12 = _matrix.m12; m13 = _matrix.m13;
    m20 = _matrix.m20; m21 = _matrix.m21; m22 = _matrix.m22; m23 = _matrix.m23;
    m30 = _matrix.m30; m31 = _matrix.m31; m32 = _matrix.m32; m33 = _matrix.m33;

    return *this;
}

template<Arithmetic T>
Matrix4<T>& Matrix4<T>::operator=(Matrix4<T>&& _matrix) noexcept
{
    m00 = _matrix.m00; m01 = _matrix.m01; m02 = _matrix.m02; m03 = _matrix.m03;
    m10 = _matrix.m10; m11 = _matrix.m11; m12 = _matrix.m12; m13 = _matrix.m13;
    m20 = _matrix.m20; m21 = _matrix.m21; m22 = _matrix.m22; m23 = _matrix.m23;
    m30 = _matrix.m30; m31 = _matrix.m31; m32 = _matrix.m32; m33 = _matrix.m33;

    _matrix.m00 = _matrix.m01 = _matrix.m02 = _matrix.m03
    = _matrix.m10 = _matrix.m11 = _matrix.m12 = _matrix.m13
    = _matrix.m20 = _matrix.m21 = _matrix.m22 = _matrix.m23
    = _matrix.m30 = _matrix.m31 = _matrix.m32 = _matrix.m33 = T();

    return *this;
}

template<Arithmetic T>
constexpr bool Matrix4<T>::operator==(const Matrix4<T>& _matrix) const noexcept
{
    return Equal(_matrix);
}

template<Arithmetic T>
constexpr bool Matrix4<T>::operator!=(const Matrix4<T>& _matrix) const noexcept
{
    return !Equal(_matrix);
}

template<Arithmetic T>
constexpr T& Matrix4<T>::operator[](const size_t _index) noexcept
{
    return Data()[_index];
}

template<Arithmetic T>
constexpr const T& Matrix4<T>::operator[](const size_t _index) const noexcept
{
    return Data()[_index];
}

#pragma endregion

#pragma region String

template<Arithmetic T>
std::string Matrix4<T>::ToString() const
{
    return
        "(" + std::to_string(m00) + ", " + std::to_string(m01) + ", " + std::to_string(m02) + ", " + std::to_string(m03) + ")\n" +
        "(" + std::to_string(m10) + ", " + std::to_string(m11) + ", " + std::to_string(m12) + ", " + std::to_string(m13) + ")\n" +
        "(" + std::to_string(m20) + ", " + std::to_string(m21) + ", " + std::to_string(m22) + ", " + std::to_string(m23) + ")\n" +
        "(" + std::to_string(m30) + ", " + std::to_string(m31) + ", " + std::to_string(m32) + ", " + std::to_string(m33) + ")";
}

#pragma endregion