# Koori Math

Custom math library with C++ 20

Currently, vectors are templated and can be used with floating-point and integer types, including both signed and unsigned values.

Many methods are primarily designed for signed floating-point values, and there are currently no restrictions on other types. Use caution when applying certain methods (e.g., Transform, Lerp) with non-floating-point or unsigned types.

## Features:

### Vectors (2, 3, 4):

- DotProduct
- CrossProduct


- SquaredLength
- Length
- SquaredDistance
- Distance
- Inverse


- IsZero
- Equal


- Angle
- Lerp
- Slerp
- Normalize


- Translate
- Scale
- Rotate


- Reflect
- Refract
- Project