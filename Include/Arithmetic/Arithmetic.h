#ifndef KOORI_MATH_ARITHMETIC_H
#define KOORI_MATH_ARITHMETIC_H

#include <concepts>

template<typename T>
concept Arithmetic =
    std::is_arithmetic_v<T> &&
    !std::is_same_v<T, char> &&
    !std::is_same_v<T, signed char> &&
    !std::is_same_v<T, unsigned char> &&
    !std::is_same_v<T, bool>;

#endif //KOORI_MATH_ARITHMETIC_H