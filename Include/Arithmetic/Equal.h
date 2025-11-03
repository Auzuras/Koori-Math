#ifndef KOORI_MATH_EQUAL_H
#define KOORI_MATH_EQUAL_H

#include <Arithmetic/Arithmetic.h>

namespace Koori::Math
{
    template<class T>
    [[nodiscard]] inline bool Equal(const T& _rhs, const T& _lhs, const T& _eps = Epsilon<T>())
    {
        return (_rhs < _lhs ? _lhs - _rhs : _rhs - _lhs) <= _eps;
    }

}

#endif //KOORI_MATH_EQUAL_H