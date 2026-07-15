#ifndef KOORI_MATH_QUATERNION_H
#define KOORI_MATH_QUATERNION_H

#include <Arithmetic/Arithmetic.h>

template<Arithmetic T>
struct Quaternion
{
public:

    T w, x, y, z;

public:

    constexpr Quaternion() noexcept;

};

#include "Quaternion.inl"

#endif //KOORI_MATH_QUATERNION_H