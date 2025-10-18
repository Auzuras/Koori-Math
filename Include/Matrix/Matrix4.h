#ifndef KOORI_MATH_MATRIX4_H
#define KOORI_MATH_MATRIX4_H

#include <Arithmetic/Arithmetic.h>

template<Arithmetic T>
struct Matrix4
{
public:

    T m00, m01, m02, m03,
      m10, m11, m12, m13,
      m20, m21, m22, m23,
      m30, m31, m32, m33;

};

#include "Matrix4.inl"

#endif //KOORI_MATH_MATRIX4_H