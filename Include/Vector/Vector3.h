#ifndef KOORI_MATH_VECTOR3_H
#define KOORI_MATH_VECTOR3_H

#include <Arithmetic/Arithmetic.h>

#include <string>

template<Arithmetic T>
struct Vector3
{
public:

    T x, y, z;

public:

#pragma region Static Vectors

    /**
     * @brief Zero vector constant: (0, 0, 0)
     */
    static constexpr Vector3<T> Zero = Vector3<T>(T(0));

    /**
     * @brief One vector constant: (1, 1, 1)
     */
    static constexpr Vector3<T> One = Vector3<T>(T(1));

    /**
     * @brief Right vector constant: (1, 0, 0)
     */
    static constexpr Vector3<T> Right = Vector3<T>(T(1), T(0), T(0));

    /**
     * @brief Up vector constant: (0, 1, 0)
     */
    static constexpr Vector3<T> Up = Vector3<T>(T(0), T(1), T(0));

    /**
     * @brief Forward vector constant: (0, 0, 1)
     */
    static constexpr Vector3<T> Forward = Vector3<T>(T(0), T(0), T(1));

    /**
     * @brief Left vector constant: (-1, 0, 0)
     */
    static constexpr Vector3<T> Left = Vector3<T>(T(-1), T(0), T(0));

    /**
     * @brief Down vector constant: (0, -1, 0)
     */
    static constexpr Vector3<T> Down = Vector3<T>(T(0), T(-1), T(0));

    /**
     * @brief Forward vector constant: (0, 0, 1)
     */
    static constexpr Vector3<T> Backward = Vector3<T>(T(0), T(0), T(-1));

#pragma endregion

#pragma region Constructors

    /**
     * @brief Default constructor, initializes all components to a default value.
     */
    constexpr Vector3() noexcept;

    /**
     * @brief Constructor initializing all the components to the same value.
     * @param _value Value to assign to x and y .
     */
    explicit constexpr Vector3(T _value) noexcept;

    /**
     * @brief Constructor initializing each component to a specific value.
     * @param _xValue Value to assign to x.
     * @param _yValue Value to assign to y.
     * @param _zValue Value to assign to z.
     */
    constexpr Vector3(T _xValue, T _yValue, T _zValue) noexcept;

    /**
     * @brief Constructor copying from a reference.
     * @param _vector Reference to the Vector3 to copy.
     */
    constexpr Vector3(const Vector3<T>& _vector) noexcept;

    /**
     * @brief Constructor moving from a rvalue reference.
     * @param _vector Rvalue reference to the Vector3 to move.
     */
    constexpr Vector3(Vector3<T>&& _vector) noexcept;

    /**
     * @brief Constructor copying from a pointer.
     * @param _vector Pointer to the Vector3 to copy.
     */
    explicit constexpr Vector3(const Vector3<T>* _vector) noexcept;

#pragma endregion

#pragma region Getters

    /**
     * @brief Gets the value of the x component.
     * @return The value from the x component.
     */
    [[nodiscard]] constexpr T GetX() const { return x; };

    /**
     * @brief Gets the value of the y component.
     * @return The value from the y component.
     */
    [[nodiscard]] constexpr T GetY() const { return y; };

    /**
     * @brief Gets the value of the z component.
     * @return The value from the z component.
     */
    [[nodiscard]] constexpr T GetZ() const { return z; };

#pragma endregion

#pragma region Setters

    /**
     * @brief Sets the value of the x component.
     * @param _value New value for the x component.
     */
    constexpr void SetX(const T _value) { x = _value; };

    /**
     * @brief Sets the value of the y component.
     * @param _value New value for the y component.
     */
    constexpr void SetY(const T _value) { y = _value; };

    /**
     * @brief Sets the value of the z component.
     * @param _value New value for the z component.
     */
    constexpr void SetZ(const T _value) { z = _value; };

#pragma endregion

#pragma region Data

    /**
     * @brief Provides direct access to the underlying data.
     * @return A pointer to the first element of the vector.
     */
    [[nodiscard]] T* Data() noexcept { return &x; };

    /**
     * @brief Provides ready-only access to the underlying data.
     * @return A const pointer to the first element of the vector.
     */
    [[nodiscard]] const T* Data() const noexcept { return &x; };

    /**
     * @brief Returns an iterator (pointer) to the first element of the vector.
     * @return A pointer to one past the last element.
     */
    [[nodiscard]] T* Begin() noexcept { return &x; };

    /**
     * @brief Returns an iterator (pointer) to one past the last element of the vector.
     * @return A pointer to one past the last element.
     */
    [[nodiscard]] T* End() noexcept { return &x + 3; };

#pragma endregion

#pragma region Vector3 Methods

    /**
     * @brief Computes the dot product between another vector and this one.
     * @param _vector The second vector required to compute the dot product.
     * @return The result of the dot product.
     */
    [[nodiscard]] constexpr T DotProduct(const Vector3<T>& _vector) const noexcept;

    /**
     * @brief Computes the cross product between another vector and this one.
     * @param _vector The second vector required to compute the cross product.
     * @return The result of the 2D cross product.
     */
    [[nodiscard]] constexpr Vector3<T> CrossProduct(const Vector3<T>& _vector) const noexcept;

    /**
     * @brief Computes the angle between another vector and this one.
     * @param _vector The second vector.
     * @return The angle (in radians) between the two vectors.
     */
    [[nodiscard]] constexpr float Angle(const Vector3<T>& _vector) const noexcept;

    /**
     * @brief Computes the squared length of this vector.
     * @return The value of the squared length.
     */
    [[nodiscard]] constexpr T SqrLength() const noexcept;

    /**
     * @brief Computes the length of this vector.
     * @return The value of the length.
     */
    [[nodiscard]] constexpr T Length() const noexcept;

    /**
     * @brief Computes the squared distance between another vector and this one.
     * @param _vector The second vector required to compute the squared distance.
     * @return The squared distance between the two vectors.
     */
    [[nodiscard]] constexpr T SqrDistance(const Vector3<T>& _vector) const noexcept;

    /**
     * @brief Computes the distance between another vector and this one.
     * @param _vector The second vector required to compute the distance.
     * @return The distance between the two vectors.
     */
    [[nodiscard]] constexpr T Distance(const Vector3<T>& _vector) const noexcept;

    /**
     * @brief Negates each component of this vector.
     * @return A reference to the modified vector.
     */
    Vector3<T>& Negate() noexcept;

    /**
     * @brief Returns the result of negating each component of this vector.
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] Vector3<T> Negated() const noexcept;

    /**
     * @brief Inverts each component of this vector.
     * @return A reference to the modified vector.
     */
    Vector3<T>& Inverse() noexcept;

    /**
     * @brief Returns the result of inverting each component of this vector.
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] Vector3<T> Inversed() const noexcept;

    /**
     * @brief Linearly interpolates this vector toward another one.
     * @param _end The second vector to interpolate toward.
     * @param _t The interpolation factor.
     * @return A reference to the modified vector.
     */
    Vector3<T>& Lerp(const Vector3<T>& _end, float _t) noexcept;

    /**
     * @brief Returns the result of linearly interpolating this vector toward another one.
     * @param _end The second vector to interpolate toward.
     * @param _t The interpolation factor.
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] Vector3<T> Lerped(const Vector3<T>& _end, float _t) const noexcept;

    /**
     * @brief Spherically interpolates this vector toward another one.
     * @param _end The second vector to interpolate toward.
     * @param _t The interpolation factor.
     * @return A reference to the modified vector.
     */
    Vector3<T>& Slerp(const Vector3<T>& _end, float _t) noexcept;

    /**
     * @brief Returns the result of spherically interpolating this vector toward another one.
     * @param _end The second vector to interpolate toward.
     * @param _t The interpolation factor.
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] Vector3<T> Slerped(const Vector3<T>& _end, float _t) const noexcept;

    /**
     * @brief Normalizes this vector to produce a unit vector (length of 1).
     * @return A reference to the modified vector.
     */
    Vector3<T>& Normalize() noexcept;

    /**
     * @brief Returns the result of normalizing this vector to produce a unit vector (length of 1).
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] Vector3<T> Normalized() const noexcept;

    /**
     * @brief Translates this vector with another one (adds the two vectors).
     * @param _vector The translation vector.
     * @return A reference to the modified vector.
     */
    Vector3<T>& Translate(const Vector3<T>& _vector) noexcept;

    /**
     * @brief Returns the result of translating this vector with another one (adds the two vectors).
     * @param _vector The translation vector.
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] Vector3<T> Translated(const Vector3<T>& _vector) const noexcept;

    /**
     * @brief Scales this vector around an anchor point.
     * @param _anchor The point around which to scale this vector.
     * @param _value The scaling factor.
     * @return A reference to the modified vector.
     */
    Vector3<T>& Scale(const Vector3<T>& _anchor, T _value) noexcept;

    /**
     * @brief Returns the result of scaling this vector around an anchor point.
     * @param _anchor The point around which to scale this vector.
     * @param _value The scaling factor.
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] Vector3<T> Scaled(const Vector3<T>& _anchor, T _value) const noexcept;

    /**
     * @brief Rotates this vector around an anchor point.
     * @param _anchor The pivot point around which to rotate this vector.
     * @param _angle The rotation angle in radians.
     * @return A reference to the modified vector.
     */
    Vector3<T>& Rotate(const Vector3<T>& _anchor, float _angle) noexcept;

    /**
     * @brief Return the result of rotating this vector around an anchor point.
     * @param _anchor The pivot point around which to rotate this vector.
     * @param _angle The rotation angle in radians.
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] Vector3<T> Rotated(const Vector3<T>& _anchor, float _angle) const noexcept;

    /**
     * @brief Reflects this vector about the given normal.
     * @param _normal The normal of the reflecting surface.
     * @return A reference to the modified vector.
     */
    Vector3<T>& Reflect(const Vector3<T>& _normal) noexcept;

    /**
     * @brief Returns the result of reflecting this vector about the given normal.
     * @param _normal The normal of the reflecting surface.
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] Vector3<T> Reflected(const Vector3<T>& _normal) const noexcept;

    /**
     * @brief Refracts this vector through a surface with a given normal and index of refraction.
     * @param _normal The normal of the refracting surface.
     * @param _ior The index of refraction.
     * @return A reference to the modified vector.
     */
    Vector3<T>& Refract(const Vector3<T>& _normal, T _ior) noexcept;

    /**
     * @brief Returns te result of refracting this vector through a surface with a given normal and index of refraction.
     * @param _normal The normal of the refracting surface.
     * @param _ior The index of refraction.
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] Vector3<T> Refracted(const Vector3<T>& _normal, T _ior) const noexcept;

    /**
     * @brief Projects this vector onto another vector.
     * @param _onTo The vector to project onto.
     * @return A reference to the modified vector.
     */
    Vector3<T>& Project(const Vector3<T>& _onTo) noexcept;

    /**
     * @brief Returns the result of projecting this vector onto another vector.
     * @param _onTo The vector to project onto.
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] Vector3<T> Projected(const Vector3<T>& _onTo) const noexcept;

#pragma endregion

#pragma region Vector3 Static Methods

    /**
     * @brief Computes the dot product between two vectors.
     * @param _lhs The left-hand side vector.
     * @param _rhs The right-hand side vector.
     * @return The result of the dot product.
     */
    [[nodiscard]] constexpr static T DotProduct(const Vector3<T>& _lhs, const Vector3<T>& _rhs) noexcept;

    /**
     * @brief Computes the cross product between two vectors.
     * @param _lhs The left-hand side vector.
     * @param _rhs The right-hand side vector.
     * @return The result of the 2D cross product.
     */
    [[nodiscard]] constexpr static Vector3<T> CrossProduct(const Vector3<T>& _lhs, const Vector3<T>& _rhs) noexcept;

    /**
     * @brief Returns the angle between two vectors.
     * @param _lhs The left-hand side vector.
     * @param _rhs The right-hand side vector.
     * @return The angle (in radians) between the two vectors.
     */
    [[nodiscard]] constexpr static float Angle(const Vector3<T>& _lhs, const Vector3<T>& _rhs) noexcept;

    /**
     * @brief Computes the squared length of a vector.
     * @param _vector The input vector.
     * @return The value of the squared length.
     */
    [[nodiscard]] constexpr static T SqrLength(const Vector3<T>& _vector) noexcept;

    /**
     * @brief Computes the length of a vector.
     * @param _vector The input vector.
     * @return The value of the length.
     */
    [[nodiscard]] constexpr static T Length(const Vector3<T>& _vector) noexcept;

    /**
     * @brief Computes the squared distance between two vectors.
     * @param _lhs The left-hand side vector.
     * @param _rhs The right-hand side vector.
     * @return The squared distance between the two vectors.
     */
    [[nodiscard]] constexpr static T SqrDistance(const Vector3<T>& _lhs, const Vector3<T>& _rhs) noexcept;

    /**
     * @brief Computes the distance between two vectors.
     * @param _lhs The left-hand side vector.
     * @param _rhs The right-hand side vector.
     * @return The distance between the two vectors.
     */
    [[nodiscard]] constexpr static T Distance(const Vector3<T>& _lhs, const Vector3<T>& _rhs) noexcept;

    /**
     * @brief Returns the result of negating each component of a vector.
     * @param _vector The vector to negate.
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] constexpr static Vector3<T> Negate(const Vector3<T>& _vector) noexcept;

    /**
     * @brief Returns the result of inverting each component of this vector.
     * @param _vector Vector to invert.
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] static Vector3<T> Inverse(const Vector3<T>& _vector) noexcept;

    /**
     * @brief Returns the result of linearly interpolating a vector toward another one.
     * @param _start The vector to interpolate.
     * @param _end The second vector to interpolate toward.
     * @param _t The interpolation factor.
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] static Vector3<T> Lerp(const Vector3<T>& _start, const Vector3<T>& _end, float _t) noexcept;

    /**
     * @brief Returns the result of spherically interpolating a vector toward another one.
     * @param _start The vector to interpolate.
     * @param _end The second vector to interpolate toward.
     * @param _t The interpolation factor.
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] static Vector3<T> Slerp(const Vector3<T>& _start, const Vector3<T>& _end, float _t) noexcept;

    /**
     * @brief Returns the result of normalizing a vector to produce a unit vector (length of 1).
     * @param _vector The vector to normalize.
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] static Vector3<T> Normalize(const Vector3<T>& _vector) noexcept;

    /**
     * @brief Returns the result of translating a vector with another one (adds the two vectors).
     * @param _vector The vector to translate.
     * @param _value The translation vector.
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] static Vector3<T> Translate(const Vector3<T>& _vector, const Vector3<T>& _value) noexcept;

    /**
     * @brief Returns the result of scaling a vector around an anchor point.
     * @param _vector The vector to scale.
     * @param _anchor The point around which to scale this vector.
     * @param _value The scaling factor.
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] static Vector3<T> Scale(const Vector3<T>& _vector, const Vector3<T>& _anchor, T _value) noexcept;

    /**
     * @brief Return the result of rotating a vector around an anchor point.
     * @param _vector The vector to rotate.
     * @param _anchor The pivot point around which to rotate this vector.
     * @param _angle The rotation angle in radians.
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] static Vector3<T> Rotate(const Vector3<T>& _vector, const Vector3<T>& _anchor, float _angle) noexcept;

    /**
     * @brief Returns the result of reflecting the incident vector about the given normal.
     * @param _incident The incident vector.
     * @param _normal The normal of the reflecting surface.
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] static Vector3<T> Reflect(const Vector3<T>& _incident, const Vector3<T>& _normal) noexcept;

    /**
     * @brief Returns te result of refracting the incident vector through a surface with a given normal and index of refraction.
     * @param _incident The incident vector.
     * @param _normal The normal of the refracting surface.
     * @param _ior The index of refraction.
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] static Vector3<T> Refract(const Vector3<T>& _incident, const Vector3<T>& _normal, T _ior) noexcept;

    /**
     * @brief Returns the result of projecting a vector onto another.
     * @param _vector The vector to project.
     * @param _onTo The vector to project onto.
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] static Vector3<T> Project(const Vector3<T>& _vector, const Vector3<T>& _onTo) noexcept;

#pragma endregion

#pragma region Boolean Operations

    /**
     * @brief Checks if the components of this vector are close to zero.
     * @return A boolean, true if the vector's components are close to zero.
     */
    [[nodiscard]] constexpr bool IsZero() const noexcept;

    /**
     * @brief Checks the equality of another vector and this one.
     * @param _vector The second vector.
     * @return A boolean, true if the vectors are equal, false if not.
     */
    [[nodiscard]] constexpr bool Equal(const Vector3<T>& _vector) const noexcept;

    /**
     * @brief Checks if the length
     * of the vector is equal to one.
     * @return A boolean, true if the vectors is normalized, false if not.
     */
    [[nodiscard]] constexpr bool IsNormalized() const noexcept;

    /**
     * @brief Checks if the components of a vector are close to zero.
     * @param _vector Vector to check.
     * @return A boolean, true if the vector's components are close to zero.
     */
    [[nodiscard]] constexpr static bool IsZero(const Vector3<T>& _vector) noexcept;

    /**
     * @brief Returns the equality of two vectors.
     * @param _lhs The left-hand side vector.
     * @param _rhs The right-hand side vector.
     * @return A boolean, true if the vectors are equal, false if not.
     */
    [[nodiscard]] constexpr static bool Equal(const Vector3<T>& _lhs, const Vector3<T>& _rhs) noexcept;

    /**
     * @brief Checks if the length of the vector is equal to one.
     * @param _vector Vector to check.
     * @return A boolean, true if the vectors is normalized, false if not.
     */
    [[nodiscard]] constexpr static bool IsNormalized(const Vector3<T>& _vector) noexcept;

#pragma endregion

#pragma region String

    /**
     * @brief Converts the vector to a string representation.
     * @return A string representing the vector: "(X, Y)".
     */
    [[nodiscard]] std::string ToString() const;

#pragma endregion

#pragma region Operators

    /**
     * @brief Adds two Vector3 objects component-wise.
     * @param _vector Vector to add.
     * @return A new Vector3 representing the sum of both vectors.
     */
    constexpr Vector3<T> operator+(const Vector3<T>& _vector) const noexcept;

    /**
     * @brief Adds a scalar value to each component of the vector.
     * @param _scalar Scalar value to add.
     * @return A new Vector3 with the scalar added to both x and y.
     */
    constexpr Vector3<T> operator+(T _scalar) const noexcept;

    /**
     * @brief Subtracts two Vector3 objects component-wise.
     * @param _vector Vector to subtract.
     * @return A new Vector3 representing the subtraction of both vectors.
     */
    constexpr Vector3<T> operator-(const Vector3<T>& _vector) const noexcept;

    /**
     * @brief Subtracts a scalar value to each component of the vector.
     * @param _scalar Scalar value to subtract.
     * @return A new Vector3 with the scalar subtracted to both x and y.
     */
    constexpr Vector3<T> operator-(T _scalar) const noexcept;

    /**
     * @brief Multiplies two Vector3 objects component-wise.
     * @param _vector Vector to multiply by.
     * @return A new Vector3 representing the multiplication of both vectors.
     */
    constexpr Vector3<T> operator*(const Vector3<T>& _vector) const noexcept;

    /**
     * @brief Multiplies a scalar value to each component of the vector.
     * @param _scalar Scalar value to multiply by.
     * @return A new Vector3 with the scalar multiplied to both x and y.
     */
    constexpr Vector3<T> operator*(T _scalar) const noexcept;
    /**
     * @brief Divides two Vector3 objects component-wise.
     * @param _vector Vector to divide by.
     * @return A new Vector3 representing the division of both vectors.
     */
    Vector3<T> operator/(const Vector3<T>& _vector) const noexcept;

    /**
     * @brief Divides a scalar value to each component of the vector.
     * @param _scalar Scalar value to divide by.
     * @return A new Vector3 with the scalar divided to both x and y.
     */
    Vector3<T> operator/(T _scalar) const noexcept;

    /**
     * @brief Adds another Vector3 to this one, component-wise.
     * @param _vector Vector to add.
     * @return A reference to this vector.
     */
    Vector3<T>& operator+=(const Vector3<T>& _vector) noexcept;

    /**
     * @brief Adds a scalar value to each component of this vector.
     * @param _scalar Scalar value to add.
     * @return A reference to this vector.
     */
    Vector3<T>& operator+=(T _scalar) noexcept;

    /**
     * @brief Subtracts another Vector3 to this one, component-wise.
     * @param _vector Vector to subtract.
     * @return A reference to this vector.
     */
    Vector3<T>& operator-=(const Vector3<T>& _vector) noexcept;

    /**
     * @brief Subtracts a scalar value to each component of this vector.
     * @param _scalar Scalar value to subtract.
     * @return A reference to this vector.
     */
    Vector3<T>& operator-=(T _scalar) noexcept;

    /**
     * @brief Multiplies another Vector3 to this one, component-wise.
     * @param _vector Vector to multiply by.
     * @return A reference to this vector.
     */
    Vector3<T>& operator*=(const Vector3<T>& _vector) noexcept;

    /**
     * @brief Multiplies a scalar value to each component of this vector.
     * @param _scalar Scalar value to multiply by.
     * @return A reference to this vector.
     */
    Vector3<T>& operator*=(T _scalar) noexcept;

    /**
     * @brief Divides another Vector3 to this one, component-wise.
     * @param _vector Vector to divide by.
     * @return A reference to this vector.
     */
    Vector3<T>& operator/=(const Vector3<T>& _vector) noexcept;

    /**
     * @brief Divides a scalar value to each component of this vector.
     * @param _scalar Scalar value to divide by.
     * @return A reference to this vector.
     */
    Vector3<T>& operator/=(T _scalar) noexcept;

    /**
     * @brief Negates the vector
     * @return A new Vector3 with the x and y components negated
     */
    constexpr Vector3<T> operator-() noexcept;

    /**
     * @brief Assigns the values of another Vector3 to this one.
     * @param _vector Vector to assign from.
     * @return A reference to this vector.
     */
    Vector3<T>& operator=(const Vector3<T>& _vector) noexcept;

    /**
     * @brief Moves the values of another Vector3 to this one.
     * @param _vector Rvalue reference to vector to assign from.
     * @return A reference to this vector.
     */
    Vector3<T>& operator=(Vector3<T>&& _vector) noexcept;

    /**
     * @brief Checks the equality of another vector and this one.
     * @param _vector The second vector.
     * @return A boolean, true if the vectors are equal, false if not.
     */
    constexpr bool operator==(const Vector3<T>& _vector) const noexcept;

    /**
     * @brief Checks the inequality of another vector and this one.
     * @param _vector The second vector.
     * @return A boolean, true if the vectors are inequal, false if not.
     */
    constexpr bool operator!=(const Vector3<T>& _vector) const noexcept;

    /**
     * @brief Returns a reference to the x or y component of the vector.
     * @param _index The index of the component (0 for x, 1 for y).
     * @return A reference to the specified component.
     */
    constexpr T& operator[](size_t _index) noexcept;

    /**
     * @brief Returns a const reference to the x or y component of the vector.
     * @param _index The index of the component (0 for x, 1 for y).
     * @return A const reference to the specified component.
     */
    constexpr const T& operator[](size_t _index) const noexcept;

    /**
     * @brief Outputs the vector to a stream in a readable format.
     * @param _stream The output stream.
     * @param _vector The vector to output.
     * @return A reference to the output stream.
     */
    friend std::ostream& operator<<(std::ostream& _stream, const Vector3<T>& _vector)
    {
        _stream << _vector.ToString();
        return _stream;
    }

#pragma endregion
};

#include "Vector3.inl"

#endif //KOORI_MATH_VECTOR3_H