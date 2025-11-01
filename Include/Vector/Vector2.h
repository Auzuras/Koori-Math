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

#pragma region Static Vectors

    /**
     * @brief The zero static vector: (0, 0)
     */
    static Vector2<T> Zero;

    /**
     * @brief The one static vector: (1, 1)
     */
    static Vector2<T> One;

    /**
     * @brief The right static vector: (1, 0)
     */
    static Vector2<T> Right;

    /**
     * @brief The up static vector: (0, 1)
     */
    static Vector2<T> Up;

    /**
     * @brief The left static vector: (-1, 0)
     */
    static Vector2<T> Left;

    /**
     * @brief The down static vector: (0, -1)
     */
    static Vector2<T> Down;

#pragma endregion

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
     * @brief Adds another vector to this one, component-wise.
     * @param _vector The vector to add.
     * @return A reference to the modified vector.
     */
    inline Vector2<T>& AddVector(const Vector2<T>& _vector) noexcept;

    /**
     * @brief Returns the result of adding another vector to this one, component-wise.
     * @param _vector The vector to add.
     * @return A new vector representing to the result of the operation.
     */
    [[nodiscard]] inline Vector2<T> AddedVector(const Vector2<T>& _vector) const noexcept;

    /**
     * @brief Adds a scalar to this vector, component-wise.
     * @param _scalar The scalar value to add.
     * @return A reference to the modified vector.
     */
    inline Vector2<T>& AddScalar(T _scalar) noexcept;

    /**
     * @brief Returns the result of adding a scalar to this vector, component-wise.
     * @param _scalar The scalar value to add.
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] inline Vector2<T> AddedScalar(T _scalar) const noexcept;

    /**
     * @brief Subtracts another vector to this one, component-wise.
     * @param _vector The vector to subtract.
     * @return A reference to the modified vector.
     */
    inline Vector2<T>& SubtractVector(const Vector2<T>& _vector) noexcept;

    /**
     * @brief Returns the result of subtracting another vector to this one, component-wise.
     * @param _vector The vector to subtract.
     * @return A new vector representing to the result of the operation.
     */
    [[nodiscard]] inline Vector2<T> SubtractedVector(const Vector2<T>& _vector) const noexcept;

    /**
     * @brief Subtracts a scalar to this vector, component-wise.
     * @param _scalar The scalar value to subtract.
     * @return A reference to the modified vector.
     */
    inline Vector2<T>& SubtractScalar(T _scalar) noexcept;

    /**
     * @brief Returns the result of subtracting a scalar to this vector, component-wise.
     * @param _scalar The scalar value to subtract.
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] inline Vector2<T> SubtractedScalar(T _scalar) const noexcept;

    /**
     * @brief Multiplies another vector to this one, component-wise.
     * @param _vector The vector to multiply.
     * @return A reference to the modified vector.
     */
    inline Vector2<T>& MultiplyVector(const Vector2<T>& _vector) noexcept;

    /**
     * @brief Returns the result of multiplying another vector to this one, component-wise.
     * @param _vector The vector to multiply.
     * @return A new vector representing to the result of the operation.
     */
    [[nodiscard]] inline Vector2<T> MultipliedVector(const Vector2<T>& _vector) const noexcept;

    /**
     * @brief Multiplies a scalar to this vector, component-wise.
     * @param _scalar The scalar value to multiply.
     * @return A reference to the modified vector.
     */
    inline Vector2<T>& MultiplyScalar(T _scalar) noexcept;

    /**
     * @brief Returns the result of multiplying a scalar to this vector, component-wise.
     * @param _scalar The scalar value to multiply.
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] inline Vector2<T> MultipliedScalar(T _scalar) const noexcept;

    /**
     * @brief Divides another vector to this one, component-wise.
     * @param _vector The vector to divide.
     * @return A reference to the modified vector.
     */
    inline Vector2<T>& DivideVector(const Vector2<T>& _vector) noexcept;

    /**
     * @brief Returns the result of dividing another vector to this one, component-wise.
     * @param _vector The vector to divide.
     * @return A new vector representing to the result of the operation.
     */
    [[nodiscard]] inline Vector2<T> DividedVector(const Vector2<T>& _vector) const noexcept;

    /**
     * @brief Divides a scalar to this vector, component-wise.
     * @param _scalar The scalar value to divide.
     * @return A reference to the modified vector.
     */
    inline Vector2<T>& DivideScalar(T _scalar) noexcept;

    /**
     * @brief Returns the result of dividing a scalar to this vector, component-wise.
     * @param _scalar The scalar value to divide.
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] inline Vector2<T> DividedScalar(T _scalar) const noexcept;

    /**
     * @brief Computes the dot product between another vector and this one.
     * @param _vector The second vector required to compute the dot product.
     * @return The result of the dot product.
     */
    [[nodiscard]] inline T DotProduct(const Vector2<T>& _vector) const noexcept;

    /**
     * @brief Computes the cross product between another vector and this one.
     * @param _vector The second vector required to compute the cross product.
     * @return The result of the 2D cross product.
     */
    [[nodiscard]] inline T CrossProduct(const Vector2<T>& _vector) const noexcept;

    /**
     * @brief Computes the squared length of this vector.
     * @return The value of the squared length.
     */
    [[nodiscard]] inline T SqrLength() const noexcept;

    /**
     * @brief Computes the length of this vector.
     * @return The value of the length.
     */
    [[nodiscard]] inline T Length() const noexcept;

    /**
     * @brief Computes the squared magnitude of this vector (Alias for squared length).
     * @return The value of the squared magnitude.
     */
    [[nodiscard]] inline T SqrMagnitude() const noexcept;

    /**
     * @brief Computes the magnitude of this vector (Alias for length).
     * @return The value of the magnitude.
     */
    [[nodiscard]] inline T Magnitude() const noexcept;

    /**
     * @brief Computes the squared distance between another vector and this one.
     * @param _vector The second vector required to compute the squared distance.
     * @return The squared distance between the two vectors.
     */
    [[nodiscard]] inline T SqrDistance(const Vector2<T>& _vector) const noexcept;

    /**
     * @brief Computes the distance between another vector and this one.
     * @param _vector The second vector required to compute the distance.
     * @return The distance between the two vectors.
     */
    [[nodiscard]] inline T Distance(const Vector2<T>& _vector) const noexcept;

    /**
     * @brief Negates each component of this vector.
     * @return A reference to the modified vector.
     */
    inline Vector2<T>& Negate() noexcept;

    /**
     * @brief Returns the result of negating each component of this vector.
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] inline Vector2<T> Negated() const noexcept;

    /**
     * @brief Inverts each component of this vector.
     * @return A reference to the modified vector.
     */
    inline Vector2<T>& Inverse() noexcept;

    /**
     * @brief Returns the result of inverting each component of this vector.
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] inline Vector2<T> Inversed() const noexcept;

    /**
     * @brief Checks if the components of this vector are close to zero (i.e., near null).
     * @return A boolean, true if the vector's components are close to zero.
     */
    [[nodiscard]] inline bool IsNull() const noexcept;

    /**
     * @brief Checks the equality of another vector and this one.
     * @param _vector The second vector.
     * @return A boolean, true if the vectors are equal, false if not.
     */
    [[nodiscard]] inline bool Equal(const Vector2<T>& _vector) const noexcept;

    /**
     * @brief Computes the angle between another vector and this one.
     * @param _vector The second vector.
     * @return The angle (in radians) between the two vectors.
     */
    [[nodiscard]] inline float Angle(const Vector2<T>& _vector) const noexcept;

    /**
     * @brief Linearly interpolates this vector toward another one.
     * @param _end The second vector to interpolate toward.
     * @param _t The interpolation factor.
     * @return A reference to the modified vector.
     */
    inline Vector2<T>& Lerp(const Vector2<T>& _end, float _t) noexcept;

    /**
     * @brief Returns the result of linearly interpolating this vector toward another one.
     * @param _end The second vector to interpolate toward.
     * @param _t The interpolation factor.
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] inline Vector2<T> Lerped(const Vector2<T>& _end, float _t) const noexcept;

    /**
     * @brief Spherically interpolates this vector toward another one.
     * @param _end The second vector to interpolate toward.
     * @param _t The interpolation factor.
     * @return A reference to the modified vector.
     */
    inline Vector2<T>& Slerp(const Vector2<T>& _end, float _t) noexcept;

    /**
     * @brief Returns the result of spherically interpolating this vector toward another one.
     * @param _end The second vector to interpolate toward.
     * @param _t The interpolation factor.
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] inline Vector2<T> Slerped(const Vector2<T>& _end, float _t) const noexcept;

    /**
     * @brief Normalizes this vector to produce a unit vector (length of 1).
     * @return A reference to the modified vector.
     */
    inline Vector2<T>& Normalize() noexcept;

    /**
     * @brief Returns the result of normalizing this vector to produce a unit vector (length of 1).
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] inline Vector2<T> Normalized() const noexcept;

    /**
     * @brief Translates this vector with another one (adds the two vectors).
     * @param _vector Translation vector.
     * @return A reference to the modified vector.
     */
    inline Vector2<T>& Translate(const Vector2<T>& _vector) noexcept;

    /**
     * @brief Returns the result of translating this vector with another one (adds the two vectors).
     * @param _vector Translation vector.
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] inline Vector2<T> Translated(const Vector2<T>& _vector) const noexcept;

    /**
     * @brief Scales this vector around an anchor point.
     * @param _anchor The point around which to scale this vector.
     * @param _value The scaling factor.
     * @return A reference to the modified vector.
     */
    inline Vector2<T>& Scale(const Vector2<T>& _anchor, T _value) noexcept;

    /**
     * @brief Returns the result of scaling this vector around an anchor point.
     * @param _anchor The point around which to scale this vector.
     * @param _value The scaling factor.
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] inline Vector2<T> Scaled(const Vector2<T>& _anchor, T _value) const noexcept;

    /**
     * @brief Rotates this vector around an anchor point.
     * @param _anchor The pivot point around which to rotate this vector.
     * @param _angle The rotation angle in radians.
     * @return A reference to the modified vector.
     */
    inline Vector2<T>& Rotate(const Vector2<T>& _anchor, T _angle) noexcept;

    /**
     * @brief Return the result of rotating this vector around an anchor point.
     * @param _anchor The pivot point around which to rotate this vector.
     * @param _angle The rotation angle in radians.
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] inline Vector2<T> Rotated(const Vector2<T>& _anchor, T _angle) const noexcept;

    /**
     * @brief Reflects this vector about the given normal.
     * @param _normal The normal of the reflecting surface.
     * @return A reference to the modified vector.
     */
    inline Vector2<T>& Reflect(const Vector2<T>& _normal) noexcept;

    /**
     * @brief Returns the result of reflecting this vector about the given normal.
     * @param _normal The normal of the reflecting surface.
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] inline Vector2<T> Reflected(const Vector2<T>& _normal) const noexcept;

    /**
     * @brief Refracts this vector through a surface with a given normal and index of refraction.
     * @param _normal The normal of the refracting surface.
     * @param _ior The index of refraction.
     * @return A reference to the modified vector.
     */
    inline Vector2<T>& Refract(const Vector2<T>& _normal, T _ior) noexcept;

    /**
     * @brief Returns te result of refracting this vector through a surface with a given normal and index of refraction.
     * @param _normal The normal of the refracting surface.
     * @param _ior The index of refraction.
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] inline Vector2<T> Refracted(const Vector2<T>& _normal, T _ior) const noexcept;

    /**
     * @brief Projects this vector onto another vector.
     * @param _vector The vector to project onto.
     * @return A reference to the modified vector.
     */
    inline Vector2<T>& Project(const Vector2<T>& _vector) noexcept;

    /**
     * @brief Returns the result of projecting this vector onto another vector.
     * @param _vector The vector to project onto.
     * @return A new vector corresponding to the result of the operation.
     */
    [[nodiscard]] inline Vector2<T> Projected(const Vector2<T>& _vector) const noexcept;

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

    [[nodiscard]] inline static T SqrLength(const Vector2<T>& _vector) noexcept;

    [[nodiscard]] inline static T Length(const Vector2<T>& _vector) noexcept;

    [[nodiscard]] inline static T SqrMagnitude(const Vector2<T>& _vector) noexcept;

    [[nodiscard]] inline static T Magnitude(const Vector2<T>& _vector) noexcept;

    [[nodiscard]] inline static T SqrDistance(const Vector2<T>& _vector1, const Vector2<T>& _vector2) noexcept;

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
