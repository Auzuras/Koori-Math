#ifndef KOORI_MATH_ARITHMETIC_H
#define KOORI_MATH_ARITHMETIC_H

#include <cmath>
#include <limits>

template<typename T>
concept Floating = std::is_floating_point_v<T>;

template<typename T>
concept Integral = std::is_integral_v<T>;

template<typename T>
concept Signed = Integral<T> && std::is_signed_v<T>;

template<typename T>
concept Unsigned = Integral<T> && std::is_unsigned_v<T>;

template<typename T>
concept Arithmetic = Unsigned<T> || Signed<T> || Floating<T>;

template<typename T>
concept ArithmeticSigned = Signed<T> || Floating<T>;

template<typename T>
concept ArithmeticUnsigned = Unsigned<T>;

/**
 * @brief KM_EPSILON macro, calls the Epsilon<T>() function
 */
#define KM_EPSILON Koori::Math::Epsilon<T>()

/**
 * @brief KM_PI macro, calls the PI<T>() function
 */
#define KM_PI Koori::Math::PI<T>()

/**
 * @brief KM_RAD_2_DEG macro, calls the Rad2Deg<T>() function
 */
#define KM_RAD_2_DEG Koori::Math::Rad2Deg<T>()

/**
 * @brief KM_DEG_2_RAD macro, calls the Deg2Rad<T>() function
 */
#define KM_DEG_2_RAD Koori::Math::Deg2Rad<T>()

/**
 * @brief KM_INTERNAL_PI macro, defines the internal constant value of PI used in the toolbox
 */
#define KM_INTERNAL_PI 3.14159265358979323846
#define KM_INTERNAL_RAD_2_DEG (180 / KM_INTERNAL_PI)
#define KM_INTERNAL_DEG_2_RAD (KM_INTERNAL_PI / 180)

namespace Koori::Math
{
    /**
     * @brief Returns the smallest positive value for a specified arithmetic type.
     * @tparam T Type of the value.
     * @return The smallest positive value for the specified type (epsilon).
     */
    template<Arithmetic T>
    [[nodiscard]] inline T Epsilon()
    {
        return std::numeric_limits<T>::epsilon();
    }

    /**
     * @brief Returns the value of Pi for a specified arithmetic type.
     * @tparam T Type of the value.
     * @return The value of Pi for the specified type (e.g., float, double, int).
     */
    template<Arithmetic T>
    [[nodiscard]] inline T Pi()
    {
        return static_cast<T>(KM_INTERNAL_PI);
    }

    /**
     * @brief Returns the radians-to-degrees conversion factor for a specified arithmetic type.
     * @tparam T Type of the value.
     * @return The conversion factor used to convert radians to degrees for the specified type (e.g., float, double, int).
     */
    template<Arithmetic T>
    [[nodiscard]] inline T Rad2Deg()
    {
        return static_cast<T>(KM_INTERNAL_RAD_2_DEG);
    }

    /**
     * @brief Returns the degrees-to-radians conversion factor for a specified arithmetic type.
     * @tparam T Type of the value.
     * @return The conversion factor used to convert degrees to radians for the specified type (e.g., float, double, int).
     */
    template<Arithmetic T>
    [[nodiscard]] inline T Deg2Rad()
    {
        return static_cast<T>(KM_INTERNAL_DEG_2_RAD);
    }

    /**
     * @brief Returns the square root of the given value for a specified type.
     * @tparam T Type of the value.
     * @param _value The value for which the square root is to be calculated.
     * @return The square root of the given value for the specified type.
     */
    template<Arithmetic T>
    [[nodiscard]] inline T Sqrt(T _value)
    {
        return std::sqrt(_value);
    }

    /**
     * @brief Returns the cosine of the given value for a specified type.
     * @tparam T Type of the value.
     * @param _value The value for which the cosine is to be calculated.
     * @return The cosine of the given value for the specified type.
     */
    template<Arithmetic T>
    [[nodiscard]] inline T Cos(T _value)
    {
        return std::cos(_value);
    }

    /**
     * @brief Returns the arc cosine (inverse cosine) of the given value.
     * @tparam T Type of the value.
     * @param _value The value for which the arc cosine is to be calculated.
     * @return The arc cosine (inverse cosine) of the given value for the specified type.
     */
    template<Arithmetic T>
    [[nodiscard]] inline T ACos(T _value)
    {
        return std::acos(_value);
    }

    /**
     * @brief Returns the sine of the given value for a specified type.
     * @tparam T Type of the value.
     * @param _value The value for which the sine is to be calculated.
     * @return The sine of the given value for the specified type.
     */
    template<Arithmetic T>
    [[nodiscard]] inline T Sin(T _value)
    {
        return std::sin(_value);
    }

    /**
     * @brief Returns the arc sine (inverse sine) of the given value.
     * @tparam T Type of the value.
     * @param _value The value for which the arc sine is to be calculated.
     * @return The arc sine (inverse sine) of the given value for the specified type.
     */
    template<Arithmetic T>
    [[nodiscard]] inline T ASin(T _value)
    {
        return std::asin(_value);
    }

    /**
     * @brief Returns the tangent of the given value for a specified type.
     * @tparam T Type of the value.
     * @param _value The value for which the tangent is to be calculated.
     * @return The tangent of the given value for the specified type.
     */
    template<Arithmetic T>
    [[nodiscard]] inline T Tan(T _value)
    {
        return std::tan(_value);
    }

    /**
     * @brief Returns the arc tangent (inverse tangent) of the given value.
     * @tparam T Type of the value.
     * @param _value The value for which the arc tangent is to be calculated.
     * @return The arc tangent (inverse tangent) of the given value for the specified type.
     */
    template<Arithmetic T>
    [[nodiscard]] inline T ATan(T _value)
    {
        return std::atan(_value);
    }

    /**
     * @brief Returns the absolute value of a signed value for a specified type.
     * @tparam T Type of the value (signed types only).
     * @param _value The signed value for which the absolute value is to be calculated.
     * @return The absolute value of the given signed value for the specified type.
     */
    template<ArithmeticSigned T>
    [[nodiscard]] inline T Abs(T _value)
    {
        return std::abs(_value);
    }

    /**
     * @brief Returns the same value for an unsigned value, since unsigned types are always positive.
     * @tparam T Type of the value (unsigned types only).
     * @param _value The unsigned value.
     * @return The same value, since unsigned types cannot be negative.
     */
    template<ArithmeticUnsigned T>
    [[nodiscard]] inline T Abs(T _value)
    {
        return _value;
    }

    /**
     * @brief Returns the exponential (e^x) of the given value for a specified type.
     * @tparam T Type of the value.
     * @param _value The value for which the exponential is to be calculated.
     * @return The exponential (e^x) of the given value for the specified type.
     */
    template<Arithmetic T>
    [[nodiscard]] inline T Exp(T _value)
    {
        return std::exp(_value);
    }

    /**
     * @brief Returns the natural logarithm (base e) of the given value for a specified type.
     * @tparam T Type of the value.
     * @param _value The value for which the logarithm is to be calculated.
     * @return The natural logarithm (log_e) of the given value for the specified type.
     */
    template<Arithmetic T>
    [[nodiscard]] inline T Log(T _value)
    {
        return std::log(_value);
    }

    template<Arithmetic T>
    [[nodiscard]] inline T Clamp(T _value, T _min, T _max)
    {
        return (_value < _min) ? _min : (_value > _max) ? _max : _value;
    }

    template<Arithmetic T>
    [[nodiscard]] inline T Min(T _firstValue, T _secondValue)
    {
        return (_firstValue < _secondValue) ? _firstValue : _secondValue;
    }

    template<Arithmetic T>
    [[nodiscard]] inline T Max(T _firstValue, T _secondValue)
    {
        return (_firstValue > _secondValue) ? _firstValue : _secondValue;
    }

}

#endif //KOORI_MATH_ARITHMETIC_H