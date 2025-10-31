#ifndef KOORI_MATH_VECTOR2_H
#define KOORI_MATH_VECTOR2_H

#include <Arithmetic/Arithmetic.h>

#include <string>

template<Arithmetic T>
struct Vector2
{
public:

    T x, y;

public:

    static Vector2<T> Zero;
    static Vector2<T> One;
    static Vector2<T> Right;
    static Vector2<T> Up;
    static Vector2<T> Left;
    static Vector2<T> Down;

#pragma region Constructors

    /**
     * @brief Default constructor, initializes all components to a default value.
     */
    Vector2() noexcept : x(T{}), y(T{}) {}

    /**
     * @brief Constructor initializing all the components to the same value.
     * @param _value Value to assign to x and y .
     */
    explicit Vector2(T _value) noexcept : x(_value), y(_value) {}

    /**
     * @brief Constructor initializing each component to a specific value.
     * @param _xValue Value to assign to x.
     * @param _yValue Value to assign to y.
     */
    Vector2(T _xValue, T _yValue) noexcept : x(_xValue), y(_yValue) {}

    /**
     * @brief Constructor copying from a reference.
     * @param _vector Reference to the Vector2 to copy.
     */
    Vector2(const Vector2<T>& _vector) noexcept : x(_vector.x), y(_vector.y) {}

    /**
     * @brief Constructor moving from a rvalue reference.
     * @param _vector Rvalue reference to the Vector2 to move.
     */
    Vector2(const Vector2<T>&& _vector) noexcept : x(_vector.x), y(_vector.y) { _vector.x = _vector.y = T{}; }

    /**
     * @brief Constructor copying from a pointer.
     * @param _vector Pointer to the Vector2 to copy.
     */
    explicit Vector2<T>(const Vector2<T>* _vector) noexcept : x(_vector->x), y(_vector->y) {}

#pragma endregion

#pragma region Getters

    /**
     * @brief Gets the value of the x component.
     * @return The value from the x component.
     */
    [[nodiscard]] inline T GetX() const { return x; };

    /**
     * @brief Gets the value of the y component.
     * @return The value from the y component.
     */
    [[nodiscard]] inline T GetY() const { return y; };

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
    [[nodiscard]] inline const T* Data() const { return &x; };

    /**
     * @brief Returns a constant iterator (pointer) to the first element of the vector.
     * @return A constant pointer to one past the last element.
     */
    [[nodiscard]] inline const T* Begin() const { return &x; };

    /**
     * @brief Returns a constant iterator (pointer) to one past the last element of the vector.
     * @return A constant pointer to one past the last element.
     */
    [[nodiscard]] inline const T* End() const { return &x + 2; };

#pragma endregion

#pragma region Vector2 Methods

    /**
     * @brief Adds two Vector2 objects component-wise.
     * @param _vector Vector to add.
     * @return A reference to the modified vector
     */
    inline Vector2<T>& AddVector(const Vector2<T>& _vector) noexcept;

    /**
     * @brief Adds two Vector2 objects component-wise.
     * @param _vector Vector to add.
     * @return A new vector
     */
    [[nodiscard]] inline Vector2<T> AddVector(const Vector2<T>& _vector) const noexcept;

    /**
     * @brief Adds a scalar value to each component of the vector.
     * @param _scalar Scalar value to add.
     */
    inline Vector2<T>& AddScalar(T _scalar) noexcept;

    [[nodiscard]] inline Vector2<T> AddScalar(T _scalar) const noexcept;

    /**
     * @brief Subtracts two Vector2 objects component-wise.
     * @param _vector Vector to subtract.
     */
    inline Vector2<T>& SubtractVector(const Vector2<T>& _vector) noexcept;

    [[nodiscard]] inline Vector2<T> SubtractVector(const Vector2<T>& _vector) const noexcept;

    /**
     * @brief Subtracts a scalar value to each component of the vector.
     * @param _scalar Scalar value to subtract.
     */
    inline Vector2<T>& SubtractScalar(T _scalar) noexcept;

    [[nodiscard]] inline Vector2<T> SubtractScalar(T _scalar) const noexcept;

    /**
     * @brief Multiplies two Vector2 objects component-wise.
     * @param _vector Vector to multiply.
     */
    inline Vector2<T>& MultiplyVector(const Vector2<T>& _vector) noexcept;

    [[nodiscard]] inline Vector2<T> MultiplyVector(const Vector2<T>& _vector) const noexcept;

    /**
     * @brief Multiplies a scalar value to each component of the vector.
     * @param _scalar Scalar value to multiply.
     */
    inline Vector2<T>& MultiplyScalar(T _scalar) noexcept;

    [[nodiscard]] inline Vector2<T> MultiplyScalar(T _scalar) const noexcept;

    /**
     * @brief Divides two Vector2 objects component-wise.
     * @param _vector Vector to divide.
     */
    inline Vector2<T>& DivideVector(const Vector2<T>& _vector) noexcept;

    [[nodiscard]] inline Vector2<T> DivideVector(const Vector2<T>& _vector) const noexcept;

    /**
     * @brief Divides a scalar value to each component of the vector.
     * @param _scalar Scalar value to divide.
     */
    inline Vector2<T>& DivideScalar(T _scalar) noexcept;

    [[nodiscard]] inline Vector2<T> DivideScalar(T _scalar) const noexcept;

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

    /**
     * @brief Computes the squared length of the vector.
     * @return The value of the squared length.
     */
    [[nodiscard]] inline T SquaredLength() const noexcept;

    /**
     * @brief Computes the length of the vector.
     * @return The value of the length.
     */
    [[nodiscard]] inline T Length() const noexcept;

    /**
     * @brief Computes the squared length of the vector.
     * @return The value of the squared length.
     */
    [[nodiscard]] inline T SquaredMagnitude() const noexcept;

    /**
     * @brief Computes the length of the vector.
     * @return The value of the length.
     */
    [[nodiscard]] inline T Magnitude() const noexcept;

    /**
     * @brief Computes the squared distance between the current vector and another vector.
     * @param _vector The second vector.
     * @return The squared distance between the two vectors.
     */
    [[nodiscard]] inline T SquaredDistance(const Vector2<T>& _vector) const noexcept;

    /**
     * @brief Computes the distance between the current vector and another vector.
     * @param _vector The second vector.
     * @return The distance between the two vectors.
     */
    [[nodiscard]] inline T Distance(const Vector2<T>& _vector) const noexcept;

    inline Vector2<T>& Opposite() noexcept;

    [[nodiscard]] inline Vector2<T> Opposite() const noexcept;

    /**
     *
     */
    inline Vector2<T>& Inverse() noexcept;

    [[nodiscard]] inline Vector2<T> Inverse() const noexcept;

    /**
     * @brief Checks if the components of the vector are close to zero (i.e., near null).
     * @return A boolean, true if the vector's components are close to zero.
     */
    [[nodiscard]] inline bool IsNull() const noexcept;

    /**
     * @brief Checks the equality of two vectors
     * @param _vector The second vector.
     * @return A boolean, true if the vectors are equal, false if not.
     */
    [[nodiscard]] inline bool Equal(const Vector2<T>& _vector) const noexcept;

    /**
     * @brief
     * @param _vector
     * @return
     */
    [[nodiscard]] inline float Angle(const Vector2<T>& _vector) const noexcept;

    /**
     * @brief
     * @param _vector
     * @param _t
     */
    inline Vector2<T>& Lerp(const Vector2<T>& _vector, float _t) noexcept;

    [[nodiscard]] inline Vector2<T> Lerp(const Vector2<T>& _vector, float _t) const noexcept;

    /**
     * @brief
     * @param _vector
     * @param _t
     */
    inline Vector2<T>& Slerp(const Vector2<T>& _vector, float _t) noexcept;

    [[nodiscard]] inline Vector2<T> Slerp(const Vector2<T>& _vector, float _t) const noexcept;

    /**
     * @brief Normalizes the vector to produce a unit vector (length of 1).
     */
    inline Vector2<T>& Normalize() noexcept;

    [[nodiscard]] inline Vector2<T> Normalize() const noexcept;

    /**
     *
     * @param _vector
     */
    inline Vector2<T>& Translate(const Vector2<T>& _vector) noexcept;

    [[nodiscard]] inline Vector2<T> Translate(const Vector2<T>& _vector) const noexcept;

    /**
     *
     * @param _anchor
     * @param _value
     */
    inline Vector2<T>& Scale(const Vector2<T>& _anchor, T _value) noexcept;

    [[nodiscard]] inline Vector2<T> Scale(const Vector2<T>& _anchor, T _value) const noexcept;

    /**
     *
     * @param _anchor
     * @param _angle
     */
    inline Vector2<T>& Rotate(const Vector2<T>& _anchor, T _angle) noexcept;

    [[nodiscard]] inline Vector2<T> Rotate(const Vector2<T>& _anchor, T _angle) const noexcept;

    /**
     * @brief
     * @param _normal
     */
    inline Vector2<T>& Reflect(const Vector2<T>& _normal) noexcept;

    [[nodiscard]] inline Vector2<T> Reflect(const Vector2<T>& _normal) const noexcept;

    /**
     * @brief
     * @param _normal
     * @param _ior
     */
    inline Vector2<T>& Refract(const Vector2<T>& _normal, T _ior) noexcept;

    [[nodiscard]] inline Vector2<T> Refract(const Vector2<T>& _normal, T _ior) const noexcept;

    /**
     * @brief
     * @param _vector
     */
    inline Vector2<T>& Project(const Vector2<T>& _vector) noexcept;

    [[nodiscard]] inline Vector2<T> Project(const Vector2<T>& _vector) const noexcept;

#pragma endregion

#pragma region Vector2 Static Methods

    [[nodiscard]] inline static Vector2<T> AddVector(const Vector2<T>& _vector1, const Vector2<T>& _vector2) noexcept;

    [[nodiscard]] inline static Vector2<T> AddScalar(const Vector2<T>& _vector, T _scalar) noexcept;

    [[nodiscard]] inline static Vector2<T> SubtractVector(const Vector2<T>& _vector1, const Vector2<T>& _vector2) noexcept;

    [[nodiscard]] inline static Vector2<T> SubtractScalar(const Vector2<T>& _vector, T _scalar) noexcept;

    [[nodiscard]] inline static Vector2<T> MultiplyVector(const Vector2<T>& _vector1, const Vector2<T>& _vector2) noexcept;

    [[nodiscard]] inline static Vector2<T> MultiplyScalar(const Vector2<T>& _vector, T _scalar) noexcept;

    [[nodiscard]] inline static Vector2<T> DivideVector(const Vector2<T>& _vector1, const Vector2<T>& _vector2) noexcept;

    [[nodiscard]] inline static Vector2<T> DivideScalar(const Vector2<T>& _vector, T _scalar) noexcept;

    [[nodiscard]] inline static T DotProduct(const Vector2<T>& _vector1, const Vector2<T>& _vector2) noexcept;

    [[nodiscard]] inline static T CrossProduct(const Vector2<T>& _vector1, const Vector2<T>& _vector2) noexcept;

    [[nodiscard]] inline static T SquaredLength(const Vector2<T>& _vector) noexcept;

    [[nodiscard]] inline static T Length(const Vector2<T>& _vector) noexcept;

    [[nodiscard]] inline static T SquaredMagnitude(const Vector2<T>& _vector) noexcept;

    [[nodiscard]] inline static T Magnitude(const Vector2<T>& _vector) noexcept;

    [[nodiscard]] inline static T SquaredDistance(const Vector2<T>& _vector1, const Vector2<T>& _vector2) noexcept;

    [[nodiscard]] inline static T Distance(const Vector2<T>& _vector1, const Vector2<T>& _vector2) noexcept;

    [[nodiscard]] inline static Vector2<T> Opposite(const Vector2<T>& _vector) noexcept;

    [[nodiscard]] inline static Vector2<T> Inverse(const Vector2<T>& _vector) noexcept;

    [[nodiscard]] inline static bool IsNull(const Vector2<T>& _vector) noexcept;

    [[nodiscard]] inline static bool Equal(const Vector2<T>& _vector1, const Vector2<T>& _vector2) noexcept;

    [[nodiscard]] inline static float Angle(const Vector2<T>& _vector1, const Vector2<T>& _vector2) noexcept;

    [[nodiscard]] inline static Vector2<T> Lerp(const Vector2<T>& _vector1, const Vector2<T>& _vector2, float _t) noexcept;

    [[nodiscard]] inline static Vector2<T> Slerp(const Vector2<T>& _vector1, const Vector2<T>& _vector2, float _t) noexcept;

    [[nodiscard]] inline static Vector2<T> Normalize(const Vector2<T>& _vector) noexcept;

    [[nodiscard]] inline static Vector2<T> Translate(const Vector2<T>& _vector, const Vector2<T>& _value) noexcept;

    [[nodiscard]] inline static Vector2<T> Scale(const Vector2<T>& _vector, const Vector2<T>& _anchor, T _value) noexcept;

    [[nodiscard]] inline static Vector2<T> Rotate(const Vector2<T>& _vector, const Vector2<T>& _anchor, T _angle) noexcept;

    [[nodiscard]] inline static Vector2<T> Reflect(const Vector2<T>& _vector,const Vector2<T>& _normal) noexcept;

    [[nodiscard]] inline static Vector2<T> Refract(const Vector2<T>& _vector, const Vector2<T>& _normal, T _ior) noexcept;

    [[nodiscard]] inline static Vector2<T> Project(const Vector2<T>& _vector1, const Vector2<T>& _vector2) noexcept;

#pragma endregion

#pragma region Operators

    /**
     * @brief Adds two Vector2 objects component-wise.
     * @param _vector Vector to add.
     * @return A new Vector2 representing the sum of both vectors.
     */
    inline Vector2<T> operator+(const Vector2<T>& _vector) noexcept;

    /**
     * @brief Adds a scalar value to each component of the vector.
     * @param _scalar Scalar value to add.
     * @return A new Vector2 with the scalar added to both x and y.
     */
    inline Vector2<T> operator+(T _scalar) noexcept;

    /**
     * @brief Subtracts two Vector2 objects component-wise.
     * @param _vector Vector to subtract.
     * @return A new Vector2 representing the subtraction of both vectors.
     */
    inline Vector2<T> operator-(const Vector2<T>& _vector) noexcept;

    /**
     * @brief Subtracts a scalar value to each component of the vector.
     * @param _scalar Scalar value to subtract.
     * @return A new Vector2 with the scalar subtracted to both x and y.
     */
    inline Vector2<T> operator-(T _scalar) noexcept;

    /**
     * @brief Multiplies two Vector2 objects component-wise.
     * @param _vector Vector to multiply.
     * @return A new Vector2 representing the multiplication of both vectors.
     */
    inline Vector2<T> operator*(const Vector2<T>& _vector) noexcept;

    /**
     * @brief Multiplies a scalar value to each component of the vector.
     * @param _scalar Scalar value to multiply.
     * @return A new Vector2 with the scalar multiplied to both x and y.
     */
    inline Vector2<T> operator*(T _scalar) noexcept;

    /**
     * @brief Divides two Vector2 objects component-wise.
     * @param _vector Vector to divide.
     * @return A new Vector2 representing the division of both vectors.
     */
    inline Vector2<T> operator/(const Vector2<T>& _vector) noexcept;

    /**
     * @brief Divides a scalar value to each component of the vector.
     * @param _scalar Scalar value to divide.
     * @return A new Vector2 with the scalar divided to both x and y.
     */
    inline Vector2<T> operator/(T _scalar) noexcept;

    /**
     * @brief Adds another Vector2 to this one, component-wise.
     * @param _vector Vector to add.
     */
    inline void operator+=(const Vector2<T>& _vector) noexcept;

    /**
     * @brief Adds a scalar value to each component of this vector.
     * @param _scalar Scalar value to add.
     */
    inline void operator+=(T _scalar) noexcept;

    /**
     * @brief Subtracts another Vector2 to this one, component-wise.
     * @param _vector Vector to subtract.
     */
    inline void operator-=(const Vector2<T>& _vector) noexcept;

    /**
     * @brief Subtracts a scalar value to each component of this vector.
     * @param _scalar Scalar value to subtract.
     */
    inline void operator-=(T _scalar) noexcept;

    /**
     * @brief Multiplies another Vector2 to this one, component-wise.
     * @param _vector Vector to multiply.
     */
    inline void operator*=(const Vector2<T>& _vector) noexcept;

    /**
     * @brief Multiplies a scalar value to each component of this vector.
     * @param _scalar Scalar value to multiply.
     */
    inline void operator*=(T _scalar) noexcept;

    /**
     * @brief Divides another Vector2 to this one, component-wise.
     * @param _vector Vector to divide.
     */
    inline void operator/=(const Vector2<T>& _vector) noexcept;

    /**
     * @brief Divides a scalar value to each component of this vector.
     * @param _scalar Scalar value to divide.
     */
    inline void operator/=(T _scalar) noexcept;

    /**
     * @brief Assigns the values of another Vector2 to this one.
     * @param _vector Vector to assign from.
     * @return Reference to this vector.
     */
    inline Vector2<T>& operator=(const Vector2<T>& _vector) noexcept;

    /**
     * @brief Moves the values of another Vector2 to this one.
     * @param _vector Rvalue reference to vector to assign from.
     * @return Reference to this vector.
     */
    inline Vector2<T>& operator=(Vector2<T>&& _vector) noexcept;

    /**
     * @brief
     * @param _vector
     * @return
     */
    inline bool operator==(const Vector2<T>& _vector) const noexcept;

    inline T operator[](size_t _index) const noexcept;

    friend inline std::ostream& operator<< (std::ostream& _stream, const Vector2<T>& _vector)
    {
        _stream << _vector.ToString();
        return _stream;
    }

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
