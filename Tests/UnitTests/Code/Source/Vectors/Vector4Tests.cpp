#include <gtest/gtest.h>

#include <Vector/Vector4.h>

template <typename T>
class Vector4Test : public testing::Test {};

using TestTypes = ::testing::Types<
    short, unsigned short,
    int, unsigned int,
    long, unsigned long,
    long long, unsigned long long,
    double, long double,
    float
>;

TYPED_TEST_SUITE(Vector4Test, TestTypes);

#define Vec4T Vector4<TypeParam>

TYPED_TEST(Vector4Test, Constructors)
{
    // Base constructor
    Vec4T v1;

    EXPECT_EQ(v1.x, TypeParam(0));
    EXPECT_EQ(v1.y, TypeParam(0));
    EXPECT_EQ(v1.z, TypeParam(0));
    EXPECT_EQ(v1.w, TypeParam(0));

    // One value constructor
    v1 = Vec4T(TypeParam(10));

    EXPECT_EQ(v1.x, TypeParam(10));
    EXPECT_EQ(v1.y, TypeParam(10));
    EXPECT_EQ(v1.z, TypeParam(10));
    EXPECT_EQ(v1.w, TypeParam(10));

    // Four values constructor
    v1 = Vec4T(TypeParam(20), TypeParam(5), TypeParam(2), TypeParam(0));

    EXPECT_EQ(v1.x, TypeParam(20));
    EXPECT_EQ(v1.y, TypeParam(5));
    EXPECT_EQ(v1.z, TypeParam(2));
    EXPECT_EQ(v1.w, TypeParam(0));

    // Copy constructor
    Vec4T v2 = Vec4T(TypeParam(3), TypeParam(2), TypeParam(10), TypeParam(25));
    v1 = Vec4T(v2);

    EXPECT_EQ(v1.x, v2.x);
    EXPECT_EQ(v1.y, v2.y);
    EXPECT_EQ(v1.z, v2.z);
    EXPECT_EQ(v1.w, v2.w);

    // Movement constructor
    v1 = Vec4T(10, 20, 30, 40);

    EXPECT_EQ(v1.x, 10);
    EXPECT_EQ(v1.y, 20);
    EXPECT_EQ(v1.z, 30);
    EXPECT_EQ(v1.w, 40);

    // Pointer constructor
    v2 = Vec4T(TypeParam(15), TypeParam(12), TypeParam(2), TypeParam(5));
    v1 = Vec4T(&v2);

    EXPECT_EQ(v1.x, v2.x);
    EXPECT_EQ(v1.y, v2.y);
    EXPECT_EQ(v1.z, v2.z);
    EXPECT_EQ(v1.w, v2.w);
}

TYPED_TEST(Vector4Test, Getters)
{
    Vec4T v1 = Vec4T(TypeParam(3), TypeParam(2), TypeParam(1), TypeParam(0));

    EXPECT_EQ(v1.GetX(), TypeParam(3));
    EXPECT_EQ(v1.GetY(), TypeParam(2));
    EXPECT_EQ(v1.GetZ(), TypeParam(1));
    EXPECT_EQ(v1.GetW(), TypeParam(0));
}

TYPED_TEST(Vector4Test, Setters)
{
    Vec4T v1;

    v1.SetX(TypeParam(111));
    v1.SetY(TypeParam(101));
    v1.SetZ(TypeParam(169));
    v1.SetW(TypeParam(167));

    EXPECT_EQ(v1.x, TypeParam(111));
    EXPECT_EQ(v1.y, TypeParam(101));
    EXPECT_EQ(v1.z, TypeParam(169));
    EXPECT_EQ(v1.w, TypeParam(167));
}

TYPED_TEST(Vector4Test, Addition)
{
    Vec4T v1(TypeParam(0), TypeParam(1), TypeParam(10), TypeParam(20));
    Vec4T v2(TypeParam(5), TypeParam(1), TypeParam(5), TypeParam(0));

    v1 = v1 + v2;

    EXPECT_EQ(v1.x, TypeParam(5));
    EXPECT_EQ(v1.y, TypeParam(2));
    EXPECT_EQ(v1.z, TypeParam(15));
    EXPECT_EQ(v1.w, TypeParam(20));

    v2 += v2;

    EXPECT_EQ(v2.x, TypeParam(10));
    EXPECT_EQ(v2.y, TypeParam(4));
    EXPECT_EQ(v2.z, TypeParam(30));
    EXPECT_EQ(v2.w, TypeParam(40));
}

TYPED_TEST(Vector4Test, Subtraction)
{
    Vec4T v1(TypeParam(15), TypeParam(3), TypeParam(5), TypeParam(4));
    Vec4T v2(TypeParam(20), TypeParam(2), TypeParam(3), TypeParam(1));

    v1 = v1 - v2;

    EXPECT_EQ(v1.x, TypeParam(-5));
    EXPECT_EQ(v1.y, TypeParam(1));
    EXPECT_EQ(v1.z, TypeParam(2));
    EXPECT_EQ(v1.w, TypeParam(3));

    v2 -= v2;

    EXPECT_EQ(v2.x, TypeParam(0));
    EXPECT_EQ(v2.y, TypeParam(0));
    EXPECT_EQ(v2.w, TypeParam(0));
    EXPECT_EQ(v2.z, TypeParam(0));
}

TYPED_TEST(Vector4Test, Multiplication)
{
    Vec4T v1(TypeParam(10), TypeParam(5), TypeParam(3), TypeParam(15));
    Vec4T v2(TypeParam(6), TypeParam(2), TypeParam(1), TypeParam(2));

    v1 = v1 * v2;

    EXPECT_EQ(v1.x, TypeParam(60));
    EXPECT_EQ(v1.y, TypeParam(10));
    EXPECT_EQ(v1.z, TypeParam(3));
    EXPECT_EQ(v1.w, TypeParam(30));

    v2 *= v2;

    EXPECT_EQ(v2.x, TypeParam(36));
    EXPECT_EQ(v2.y, TypeParam(100));
    EXPECT_EQ(v2.z, TypeParam(9));
    EXPECT_EQ(v2.w, TypeParam(900));
}

TYPED_TEST(Vector4Test, Division)
{
    Vec4T v1(TypeParam(10), TypeParam(15), TypeParam(10), TypeParam(64));
    Vec4T v2(TypeParam(2), TypeParam(3), TypeParam(5), TypeParam(8));

    v1 = v1 / v2;

    EXPECT_EQ(v1.x, TypeParam(5));
    EXPECT_EQ(v1.y, TypeParam(5));
    EXPECT_EQ(v1.w, TypeParam(2));
    EXPECT_EQ(v1.z, TypeParam(8));

    v2 /= v2;

    EXPECT_EQ(v2.x, TypeParam(1));
    EXPECT_EQ(v2.y, TypeParam(1));
    EXPECT_EQ(v2.w, TypeParam(1));
    EXPECT_EQ(v2.z, TypeParam(1));
}

TYPED_TEST(Vector4Test, Math)
{
    Vec4T v1(TypeParam(10), TypeParam(20), TypeParam(5), TypeParam(2));
    Vec4T v2(TypeParam(2), TypeParam(5), TypeParam(100), TypeParam(5));

    EXPECT_EQ(v1.DotProduct(v2), TypeParam(630));
    EXPECT_EQ(Vec4T::DotProduct(v1, v2), TypeParam(630));

    v1 = Vec4T::Up;
    v2 = Vec4T::Right;

    EXPECT_NEAR(v1.Angle(v2), TypeParam(90 * KM_INTERNAL_DEG_2_RAD), 0.0001);

    v2 = {1, 1, 0, 0};

    EXPECT_NEAR(Vec4T::Angle(v1, v2), TypeParam(45 * KM_INTERNAL_DEG_2_RAD), 0.0001);
}

TYPED_TEST(Vector4Test, Length)
{
    Vec4T v1(TypeParam(3), TypeParam(0), TypeParam(5), TypeParam(10));

    EXPECT_EQ(v1.SqrLength(), TypeParam(9));
    EXPECT_EQ(v1.Length(), TypeParam(3));

    EXPECT_EQ(Vec4T::SqrLength(v1), TypeParam(9));
    EXPECT_EQ(Vec4T::Length(v1), TypeParam(3));

    v1 = Vec4T(TypeParam(5), TypeParam(5), TypeParam(5), TypeParam(5));
    Vec4T v2 = Vec4T(TypeParam(10), TypeParam(5), TypeParam(20), TypeParam(25));

    EXPECT_EQ(v1.SqrDistance(v2), TypeParam(25));
    EXPECT_EQ(v1.Distance(v2), TypeParam(5));

    EXPECT_EQ(Vec4T::SqrDistance(v1, v2), TypeParam(25));
    EXPECT_EQ(Vec4T::Distance(v1, v2), TypeParam(5));
}

TYPED_TEST(Vector4Test, Negate)
{
    Vec4T v1(TypeParam(10), TypeParam(10), TypeParam(-5), TypeParam(3));
    v1 = v1.Negated();

    EXPECT_EQ(v1.x, TypeParam(-10));
    EXPECT_EQ(v1.y, TypeParam(-10));
    EXPECT_EQ(v1.z, TypeParam(5));
    EXPECT_EQ(v1.w, TypeParam(-3));

    v1 = { TypeParam(5), TypeParam(5), TypeParam(5), TypeParam(5) };
    v1.Negate();

    EXPECT_EQ(v1.x, TypeParam(-5));
    EXPECT_EQ(v1.y, TypeParam(-5));
    EXPECT_EQ(v1.w, TypeParam(-5));
    EXPECT_EQ(v1.z, TypeParam(-5));

    EXPECT_EQ(Vec4T::Negate(v1).x, TypeParam(5));
    EXPECT_EQ(Vec4T::Negate(v1).y, TypeParam(5));
    EXPECT_EQ(Vec4T::Negate(v1).z, TypeParam(5));
    EXPECT_EQ(Vec4T::Negate(v1).w, TypeParam(5));
}

TYPED_TEST(Vector4Test, Inverse)
{
    Vec4T v1(TypeParam(2));

    EXPECT_NEAR(Vec4T::Inverse(v1).x, TypeParam(0.5), 0.001);
    EXPECT_NEAR(Vec4T::Inverse(v1).y, TypeParam(0.5), 0.001);
    EXPECT_NEAR(Vec4T::Inverse(v1).z, TypeParam(0.5), 0.001);
    EXPECT_NEAR(Vec4T::Inverse(v1).w, TypeParam(0.5), 0.001);

    v1 = v1.Inversed();

    EXPECT_NEAR(v1.x, TypeParam(0.5), 0.001);
    EXPECT_NEAR(v1.y, TypeParam(0.5), 0.001);
    EXPECT_NEAR(v1.z, TypeParam(0.5), 0.001);
    EXPECT_NEAR(v1.w, TypeParam(0.5), 0.001);

    v1 = { TypeParam(5), TypeParam(0), TypeParam(0), TypeParam(0) };
    v1.Inverse();

    EXPECT_NEAR(v1.x, TypeParam(0.2), 0.001);
    EXPECT_NEAR(v1.y, TypeParam(0.2), 0.001);
    EXPECT_NEAR(v1.z, TypeParam(0.2), 0.001);
    EXPECT_NEAR(v1.w, TypeParam(0.2), 0.001);
}

TYPED_TEST(Vector4Test, BooleanOperations)
{
    // Is Null
    {
        Vec4T v1(TypeParam(3), TypeParam(0), TypeParam(2), TypeParam(10));

        EXPECT_EQ(v1.IsZero(), false);
        EXPECT_EQ(Vec4T::IsZero(v1), false);

        v1 = Vec4T(TypeParam(0), TypeParam(0), TypeParam(0), TypeParam(0));

        EXPECT_EQ(v1.IsZero(), true);
        EXPECT_EQ(Vec4T::IsZero(v1), true);
    }

    // Equal
    {
        Vec4T v1(TypeParam(3), TypeParam(0), TypeParam(2), TypeParam(10));
        Vec4T v2(TypeParam(5), TypeParam(10), TypeParam(20), TypeParam(1));

        EXPECT_EQ(v1.Equal(v2), false);
        EXPECT_EQ(Vec4T::Equal(v1, v2), false);

        v1 = Vec4T(TypeParam(5), TypeParam(10), TypeParam(20), TypeParam(1));

        EXPECT_EQ(v1.Equal(v2), true);
        EXPECT_EQ(Vec4T::Equal(v1, v2), true);
    }

    // Is Normalized
    {
        Vec4T v1(TypeParam(5), TypeParam(0), TypeParam(5), TypeParam(10));

        EXPECT_EQ(v1.IsNormalized(), false);
        EXPECT_EQ(Vec4T::IsNormalized(v1), false);

        v1.Normalize();

        EXPECT_EQ(v1.IsNormalized(), true);
        EXPECT_EQ(Vec4T::IsNormalized(v1), true);
    }
}

TYPED_TEST(Vector4Test, Lerp)
{
    // Lerp
    {
        Vec4T v1(TypeParam(0));
        Vec4T v2(TypeParam(1));

        EXPECT_NEAR(Vec4T::Lerp(v1, v2, 0.5).x, TypeParam(0.5), 0.001);
        EXPECT_NEAR(Vec4T::Lerp(v1, v2, 0.5).y, TypeParam(0.5), 0.001);
        EXPECT_NEAR(Vec4T::Lerp(v1, v2, 0.5).z, TypeParam(0.5), 0.001);
        EXPECT_NEAR(Vec4T::Lerp(v1, v2, 0.5).w, TypeParam(0.5), 0.001);

        v1 = v1.Lerped(v2, 1);

        EXPECT_NEAR(v1.x, TypeParam(1), 0.001);
        EXPECT_NEAR(v1.y, TypeParam(1), 0.001);
        EXPECT_NEAR(v1.z, TypeParam(1), 0.001);
        EXPECT_NEAR(v1.w, TypeParam(1), 0.001);

        v1 =  { TypeParam(0), TypeParam(0), TypeParam(0), TypeParam(0) };
        v1.Lerp(v2, 2);

        EXPECT_NEAR(v1.x, TypeParam(2), 0.001);
        EXPECT_NEAR(v1.y, TypeParam(2), 0.001);
        EXPECT_NEAR(v1.z, TypeParam(2), 0.001);
        EXPECT_NEAR(v1.w, TypeParam(2), 0.001);
    }

    // Slerp
    {
        Vec4T v1(TypeParam(1), TypeParam(0), TypeParam(0), TypeParam(0));
        Vec4T v2(TypeParam(0), TypeParam(1), TypeParam(0), TypeParam(0));

        EXPECT_NEAR(Vec4T::Slerp(v1, v2, 0.5).x, TypeParam(0.70710676908493042), 0.001);
        EXPECT_NEAR(Vec4T::Slerp(v1, v2, 0.5).y, TypeParam(0.70710676908493042), 0.001);
        EXPECT_NEAR(Vec4T::Slerp(v1, v2, 0.5).z, TypeParam(0.70710676908493042), 0.001);
        EXPECT_NEAR(Vec4T::Slerp(v1, v2, 0.5).w, TypeParam(0.70710676908493042), 0.001);

        v1 = v1.Slerped(v2, 1);

        EXPECT_NEAR(v1.x, TypeParam(0), 0.001);
        EXPECT_NEAR(v1.y, TypeParam(1), 0.001);
        EXPECT_NEAR(v1.z, TypeParam(1), 0.001);
        EXPECT_NEAR(v1.w, TypeParam(1), 0.001);

        v1 =  { TypeParam(1), TypeParam(0), TypeParam(0), TypeParam(0) };
        v1.Slerp(v2, 2);

        EXPECT_NEAR(v1.x, TypeParam(-1), 0.001);
        EXPECT_NEAR(v1.y, TypeParam(0), 0.001);
        EXPECT_NEAR(v1.z, TypeParam(0), 0.001);
        EXPECT_NEAR(v1.w, TypeParam(0), 0.001);
    }
}

TYPED_TEST(Vector4Test, Normalize)
{
    Vec4T v1(TypeParam(5), TypeParam(0), TypeParam(0), TypeParam(0));

    EXPECT_EQ(Vec4T::Normalize(v1).x, 1);
    EXPECT_EQ(Vec4T::Normalize(v1).y, 0);
    EXPECT_EQ(Vec4T::Normalize(v1).z, 0);
    EXPECT_EQ(Vec4T::Normalize(v1).w, 0);

    v1 = v1.Normalized();

    EXPECT_EQ(Vec4T::Normalize(v1).x, 1);
    EXPECT_EQ(Vec4T::Normalize(v1).y, 0);
    EXPECT_EQ(Vec4T::Normalize(v1).z, 0);
    EXPECT_EQ(Vec4T::Normalize(v1).w, 0);

    v1 =  { TypeParam(5), TypeParam(0), TypeParam(0), TypeParam(10) };
    v1.Normalize();

    EXPECT_EQ(Vec4T::Normalize(v1).x, 1);
    EXPECT_EQ(Vec4T::Normalize(v1).y, 0);
    EXPECT_EQ(Vec4T::Normalize(v1).z, 0);
    EXPECT_EQ(Vec4T::Normalize(v1).w, 0);
}

TYPED_TEST(Vector4Test, Transform)
{
    // Translation
    {
        Vec4T v1(TypeParam(2));
        Vec4T v2(TypeParam(3));

        EXPECT_EQ(Vec4T::Translate(v1, v2).x, TypeParam(5));
        EXPECT_EQ(Vec4T::Translate(v1, v2).y, TypeParam(5));
        EXPECT_EQ(Vec4T::Translate(v1, v2).z, TypeParam(5));
        EXPECT_EQ(Vec4T::Translate(v1, v2).w, TypeParam(5));

        v1 = v1.Translated(v2);

        EXPECT_EQ(v1.x, TypeParam(5));
        EXPECT_EQ(v1.y, TypeParam(5));
        EXPECT_EQ(v1.z, TypeParam(5));
        EXPECT_EQ(v1.w, TypeParam(5));

        v1.Translate(v2);

        EXPECT_EQ(v1.x, TypeParam(8));
        EXPECT_EQ(v1.y, TypeParam(8));
        EXPECT_EQ(v1.z, TypeParam(8));
        EXPECT_EQ(v1.w, TypeParam(8));
    }

    // Scale
    {
        Vec4T v1(TypeParam(3));
        Vec4T v2(TypeParam(0));

        EXPECT_EQ(Vec4T::Scale(v1, v2, 5).x, TypeParam(15));
        EXPECT_EQ(Vec4T::Scale(v1, v2, 5).y, TypeParam(15));
        EXPECT_EQ(Vec4T::Scale(v1, v2, 5).z, TypeParam(15));
        EXPECT_EQ(Vec4T::Scale(v1, v2, 5).w, TypeParam(15));

        v1 = v1.Scaled(v2, 5);

        EXPECT_EQ(v1.x, TypeParam(15));
        EXPECT_EQ(v1.y, TypeParam(15));
        EXPECT_EQ(v1.z, TypeParam(15));
        EXPECT_EQ(v1.w, TypeParam(15));

        v1.Scale(v2, 2);

        EXPECT_EQ(v1.x, TypeParam(30));
        EXPECT_EQ(v1.y, TypeParam(30));
        EXPECT_EQ(v1.z, TypeParam(30));
        EXPECT_EQ(v1.w, TypeParam(30));
    }

    // Rotation
    {
        Vec4T v1(TypeParam(0), TypeParam(1), TypeParam(0), TypeParam(0));
        Vec4T v2(TypeParam(0), TypeParam(0), TypeParam(0), TypeParam(0));

        EXPECT_NEAR(Vec4T::Rotate(v1, v2, -90 * KM_INTERNAL_DEG_2_RAD).x, TypeParam(1), 0.001);
        EXPECT_NEAR(Vec4T::Rotate(v1, v2, -90 * KM_INTERNAL_DEG_2_RAD).y, TypeParam(0), 0.001);
        EXPECT_NEAR(Vec4T::Rotate(v1, v2, -90 * KM_INTERNAL_DEG_2_RAD).z, TypeParam(0), 0.001);
        EXPECT_NEAR(Vec4T::Rotate(v1, v2, -90 * KM_INTERNAL_DEG_2_RAD).w, TypeParam(0), 0.001);

        v1 = v1.Rotated(v2, -90 * KM_INTERNAL_DEG_2_RAD);

        EXPECT_NEAR(v1.x, TypeParam(1), 0.001);
        EXPECT_NEAR(v1.y, TypeParam(0), 0.001);
        EXPECT_NEAR(v1.z, TypeParam(0), 0.001);
        EXPECT_NEAR(v1.w, TypeParam(0), 0.001);

        v1.Rotate(v2, 90 * KM_INTERNAL_DEG_2_RAD);

        EXPECT_NEAR(v1.x, TypeParam(0), 0.001);
        EXPECT_NEAR(v1.y, TypeParam(1), 0.001);
        EXPECT_NEAR(v1.z, TypeParam(1), 0.001);
        EXPECT_NEAR(v1.w, TypeParam(1), 0.001);
    }
}

TYPED_TEST(Vector4Test, Projection)
{
    // Reflection
    {
        Vec4T v1(TypeParam(1), TypeParam(-1), TypeParam(0), TypeParam(0));
        Vec4T v2(TypeParam(0), TypeParam(1), TypeParam(0), TypeParam(0));

        EXPECT_EQ(Vec4T::Reflect(v1, v2).x, TypeParam(1));
        EXPECT_EQ(Vec4T::Reflect(v1, v2).y, TypeParam(1));
        EXPECT_EQ(Vec4T::Reflect(v1, v2).z, TypeParam(1));
        EXPECT_EQ(Vec4T::Reflect(v1, v2).w, TypeParam(1));

        v1 = v1.Reflected(v2);

        EXPECT_EQ(v1.x, TypeParam(1));
        EXPECT_EQ(v1.y, TypeParam(1));
        EXPECT_EQ(v1.z, TypeParam(1));
        EXPECT_EQ(v1.w, TypeParam(1));

        v1.Reflect(v2);

        EXPECT_EQ(v1.x, TypeParam(1));
        EXPECT_EQ(v1.y, TypeParam(-1));
        EXPECT_EQ(v1.z, TypeParam(-1));
        EXPECT_EQ(v1.w, TypeParam(-1));
    }

    // Refraction
    {
        Vec4T v1(TypeParam(1), TypeParam(-1), TypeParam(0), TypeParam(0));
        Vec4T v2(TypeParam(0), TypeParam(1), TypeParam(0), TypeParam(0));

        EXPECT_NEAR(Vec4T::Refract(v1, v2, 1).x, TypeParam(1), 0.001);
        EXPECT_NEAR(Vec4T::Refract(v1, v2, 1).y, TypeParam(-1), 0.001);
        EXPECT_NEAR(Vec4T::Refract(v1, v2, 1).z, TypeParam(-1), 0.001);
        EXPECT_NEAR(Vec4T::Refract(v1, v2, 1).w, TypeParam(-1), 0.001);

        v1 = v1.Refracted(v2, 1);

        EXPECT_NEAR(v1.x, TypeParam(1), 0.001);
        EXPECT_NEAR(v1.y, TypeParam(-1), 0.001);
        EXPECT_NEAR(v1.z, TypeParam(-1), 0.001);
        EXPECT_NEAR(v1.w, TypeParam(-1), 0.001);

        v1.Refract(v2, 1);

        EXPECT_NEAR(v1.x, TypeParam(1), 0.001);
        EXPECT_NEAR(v1.y, TypeParam(-1), 0.001);
        EXPECT_NEAR(v1.z, TypeParam(-1), 0.001);
        EXPECT_NEAR(v1.w, TypeParam(-1), 0.001);
    }

    // Projection
    {
        Vec4T v1(TypeParam(2), TypeParam(2), TypeParam(0), TypeParam(0));
        Vec4T v2(TypeParam(2), TypeParam(0), TypeParam(0), TypeParam(0));

        EXPECT_NEAR(Vec4T::Project(v1,v2).x, TypeParam(2), 0.001);
        EXPECT_NEAR(Vec4T::Project(v1,v2).y, TypeParam(0), 0.001);
        EXPECT_NEAR(Vec4T::Project(v1,v2).z, TypeParam(0), 0.001);
        EXPECT_NEAR(Vec4T::Project(v1,v2).w, TypeParam(0), 0.001);

        v1 = v1.Projected(v2);

        EXPECT_NEAR(v1.x, TypeParam(2), 0.001);
        EXPECT_NEAR(v1.y, TypeParam(0), 0.001);
        EXPECT_NEAR(v1.z, TypeParam(0), 0.001);
        EXPECT_NEAR(v1.w, TypeParam(0), 0.001);

        v2 = { 1, 1, 0, 0 };
        v1.Project(v2);

        EXPECT_NEAR(v1.x, TypeParam(1), 0.001);
        EXPECT_NEAR(v1.y, TypeParam(1), 0.001);
        EXPECT_NEAR(v1.z, TypeParam(1), 0.001);
        EXPECT_NEAR(v1.w, TypeParam(1), 0.001);
    }
}

TYPED_TEST(Vector4Test, StaticValues)
{
    Vec4T v = Vec4T::Zero;

    EXPECT_EQ(v.x, TypeParam(0));
    EXPECT_EQ(v.y, TypeParam(0));
    EXPECT_EQ(v.z, TypeParam(0));
    EXPECT_EQ(v.w, TypeParam(0));

    v = Vec4T::One;

    EXPECT_EQ(v.x, TypeParam(1));
    EXPECT_EQ(v.y, TypeParam(1));
    EXPECT_EQ(v.z, TypeParam(1));
    EXPECT_EQ(v.w, TypeParam(1));

    v = Vec4T::Right;

    EXPECT_EQ(v.x, TypeParam(1));
    EXPECT_EQ(v.y, TypeParam(0));
    EXPECT_EQ(v.z, TypeParam(0));
    EXPECT_EQ(v.w, TypeParam(0));

    v = Vec4T::Up;

    EXPECT_EQ(v.x, TypeParam(0));
    EXPECT_EQ(v.y, TypeParam(1));
    EXPECT_EQ(v.z, TypeParam(1));
    EXPECT_EQ(v.w, TypeParam(1));

    v = Vec4T::Forward;

    EXPECT_EQ(v.x, TypeParam(0));
    EXPECT_EQ(v.y, TypeParam(0));
    EXPECT_EQ(v.z, TypeParam(1));
    EXPECT_EQ(v.w, TypeParam(0));

    v = Vec4T::Left;

    EXPECT_EQ(v.x, TypeParam(-1));
    EXPECT_EQ(v.y, TypeParam(0));
    EXPECT_EQ(v.z, TypeParam(0));
    EXPECT_EQ(v.w, TypeParam(0));

    v = Vec4T::Down;

    EXPECT_EQ(v.x, TypeParam(0));
    EXPECT_EQ(v.y, TypeParam(-1));
    EXPECT_EQ(v.z, TypeParam(0));
    EXPECT_EQ(v.w, TypeParam(0));

    v = Vec4T::Backward;

    EXPECT_EQ(v.x, TypeParam(0));
    EXPECT_EQ(v.y, TypeParam(0));
    EXPECT_EQ(v.z, TypeParam(-1));
    EXPECT_EQ(v.w, TypeParam(0));
}