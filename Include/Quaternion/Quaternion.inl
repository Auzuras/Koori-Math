#pragma region Quaternion Types

#include "Arithmetic/Equal.h"

using Quaternionf = Quaternion<float>;
using Quaterniond = Quaternion<double>;
using Quaternioni = Quaternion<int>;
using Quaternionui = Quaternion<unsigned int>;

#pragma endregion

#pragma region Constructors

template<Arithmetic T>
constexpr Quaternion<T>::Quaternion() noexcept
    : w(T()), x(T()), y(T()), z(T())
{}

#pragma endregion