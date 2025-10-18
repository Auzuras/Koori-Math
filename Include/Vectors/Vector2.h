#ifndef KOORI_MATH_VECTOR2_H
#define KOORI_MATH_VECTOR2_H

#include <string>

#include <Arithmetic/Arithmetic.h>

template<Arithmetic T>
struct Vector2
{
    T x, y;

#pragma region Constructors

    /**
     * @brief Default constructor, initializes all components to a default value.
     */
    Vector2() : x(T{}), y(T{}) {}

    /**
     * @brief Constructor initializing all the components to the same value.
     * @param _value Value to assign to x and y .
     */
    explicit Vector2(T _value) : x(_value), y(_value) {}

    /**
     * @brief Constructor initializing each component to a specific value.
     * @param _xValue Value to assign to x.
     * @param _yValue Value to assign to y.
     */
    Vector2(T _xValue, T _yValue) : x(_xValue), y(_yValue) {}

    /**
     * @brief Constructor copying from a reference.
     * @param _vector Reference to the Vector2 to copy.
     */
    Vector2(const Vector2<T>& _vector) : x(_vector.x), y(_vector.y) {}

    /**
     * @brief Constructor copying from a pointer.
     * @param _vector Pointer to the Vector2 to copy.
     */
    explicit Vector2<T>(const Vector2<T>* _vector) : x(_vector->x), y(_vector->y) {}

#pragma endregion

#pragma region Getters

    /**
     * @brief Gets the value of the x component.
     * @return The value from the x component.
     */
    inline T GetX() const { return x; };

    /**
     * @brief Gets the value of the y component.
     * @return The value from the y component.
     */
    inline T GetY() const { return y; };

#pragma endregion

#pragma region Setters

    /**
     * @brief Sets the value of the x component.
     * @param _value New value for the x component.
     */
    inline void SetX(const T _value) { x = _value; };

    /**
     * @brief Sets the value of the y component.
     * @param _value New value for the y component.
     */
    inline void SetY(const T _value) { y = _value; };

#pragma endregion

#pragma region Data

    /**
     * @brief Provides direct access to the underlying data.
     * @return A pointer to the first element of the vector.
     */
    inline T* Data() { return &x; };

    /**
     * @brief Returns an iterator (pointer) to the first element of the vector.
     * @return A pointer to one past the last element.
     */
    inline T* Begin() { return &x; };

    /**
     * @brief Returns an iterator (pointer) to one past the last element of the vector.
     * @return A pointer to one past the last element.
     */
    inline T* End() { return &x + 2; };

    /**
     * @brief Provides direct, read-only access to the underlying data.
     * @return A constant pointer to the first element of the vector.
     */
    inline const T* Data() const { return &x; };

    /**
     * @brief Returns a constant iterator (pointer) to the first element of the vector.
     * @return A constant pointer to one past the last element.
     */
    inline const T* Begin() const { return &x; };

    /**
     * @brief Returns a constant iterator (pointer) to one past the last element of the vector.
     * @return A constant pointer to one past the last element.
     */
    inline const T* End() const { return &x + 2; };

#pragma endregion

#pragma region Vector2 Methods

    /**
     * @brief Adds each component of two vectors together.
     * @param _vector Vector to add.
     */
    inline void AddVector(const Vector2<T>& _vector) noexcept;

    /**
     * @brief Adds a scalar value to each component of the vector.
     * @param _value Scalar value to add.
     */
    inline void AddScalar(T _value) noexcept;

    /**
     * @brief Subtracts each component of two vectors together.
     * @param _vector Vector to subtract.
     */
    inline void SubtractVector(const Vector2<T>& _vector) noexcept;

    /**
     * @brief Subtracts a scalar value to each component of the vector.
     * @param _value Scalar value to subtract.
     */
    inline void SubtractScalar(T _value) noexcept;

    /**
     * @brief Multiplies each component of two vectors together.
     * @param _vector Vector to multiply.
     */
    inline void MultiplyVector(const Vector2<T>& _vector) noexcept;

    /**
     * @brief Multiplies a scalar value to each component of the vector.
     * @param _value Scalar value to multiply.
     */
    inline void MultiplyScalar(T _value) noexcept;

    /**
     * @brief Divides each component of two vectors together.
     * @param _vector Vector to divide.
     */
    inline void DivideVector(const Vector2<T>& _vector) noexcept;

    /**
     * @brief Divides a scalar value to each component of the vector.
     * @param _value Scalar value to divide.
     */
    inline void DivideScalar(T _value) noexcept;

    /**
     * @brief Computes the doct product between this vector and a second one.
     * @param _vector Vector
     * @return The result of the dot product.
     */
    [[nodiscard]] inline T DotProduct(const Vector2<T>& _vector) const noexcept;

    /**
     * @brief Computes the cross product between this vector and a second one.
     * @param _vector
     * @return The result of the 2D cross product.
     */
    [[nodiscard]] inline T CrossProduct(const Vector2<T>& _vector) const noexcept;

#pragma endregion

#pragma region String

    /**
    * @brief Converts the vector to a string representation.
    * @return A string representing the vector: "(X, Y)".
    */
    [[nodiscard]] inline std::string ToString() const;

    /**
    * @brief Converts the vector to a list of characters.
    * @return A list of characters representing the vector: "(X, Y)".
    */
    [[nodiscard]] inline const char* ToCstr() const;

#pragma endregion

};

#include "Vector2.inl"

#endif //KOORI_MATH_VECTOR2_H
