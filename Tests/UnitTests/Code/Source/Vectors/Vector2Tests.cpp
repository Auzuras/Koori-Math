#include <gtest/gtest.h>

#include <Vector/Vector2.h>

template <typename T>
class Vector2Test : public testing::Test {};

using TestTypes = ::testing::Types<
    short, unsigned short,
    int, unsigned int,
    long, unsigned long,
    long long, unsigned long long,
    double, long double,
    float
>;

TYPED_TEST_SUITE(Vector2Test, TestTypes);

#define Vec2T Vector2<TypeParam>

TYPED_TEST(Vector2Test, Constructors)
{
    // Base constructor
    Vec2T v1;

    EXPECT_EQ(v1.x, static_cast<TypeParam>(0));
    EXPECT_EQ(v1.y, static_cast<TypeParam>(0));

    // One value constructor
    v1 = Vec2T(static_cast<TypeParam>(10));

    EXPECT_EQ(v1.x, static_cast<TypeParam>(10));
    EXPECT_EQ(v1.y, static_cast<TypeParam>(10));

    // Two values constructor
    v1 = Vec2T(static_cast<TypeParam>(20), static_cast<TypeParam>(5));

    EXPECT_EQ(v1.x, static_cast<TypeParam>(20));
    EXPECT_EQ(v1.y, static_cast<TypeParam>(5));

    // Copy constructor
    Vec2T v2 = Vec2T(static_cast<TypeParam>(3), static_cast<TypeParam>(2));
    v1 = Vec2T(v2);

    EXPECT_EQ(v1.x, v2.x);
    EXPECT_EQ(v1.y, v2.y);

    // Movement constructor
    v1 = Vec2T(10, 20);

    EXPECT_EQ(v1.x, 10);
    EXPECT_EQ(v1.y, 20);

    // Pointer constructor
    v2 = Vec2T(static_cast<TypeParam>(15), static_cast<TypeParam>(12));
    v1 = Vec2T(&v2);

    EXPECT_EQ(v1.x, v2.x);
    EXPECT_EQ(v1.y, v2.y);
}

TYPED_TEST(Vector2Test, Getters)
{
    Vec2T v1 = Vec2T(static_cast<TypeParam>(3), static_cast<TypeParam>(2));

    EXPECT_EQ(v1.GetX(), static_cast<TypeParam>(3));
    EXPECT_EQ(v1.GetY(), static_cast<TypeParam>(2));
}

TYPED_TEST(Vector2Test, Setters)
{
    Vec2T v1;

    v1.SetX(static_cast<TypeParam>(111));
    v1.SetY(static_cast<TypeParam>(101));

    EXPECT_EQ(v1.x, static_cast<TypeParam>(111));
    EXPECT_EQ(v1.y, static_cast<TypeParam>(101));
}

TYPED_TEST(Vector2Test, Addition)
{
    Vec2T v1(static_cast<TypeParam>(0), static_cast<TypeParam>(1));
    Vec2T v2(static_cast<TypeParam>(5), static_cast<TypeParam>(1));

    v1 = v1 + v2;

    EXPECT_EQ(v1.x, static_cast<TypeParam>(5));
    EXPECT_EQ(v1.y, static_cast<TypeParam>(2));

    v2 += v2;

    EXPECT_EQ(v2.x, static_cast<TypeParam>(10));
    EXPECT_EQ(v2.y, static_cast<TypeParam>(2));
}

TYPED_TEST(Vector2Test, Substraction)
{
    Vec2T v1(static_cast<TypeParam>(15), static_cast<TypeParam>(3));
    Vec2T v2(static_cast<TypeParam>(20), static_cast<TypeParam>(2));

    v1 = v1 - v2;

    EXPECT_EQ(v1.x, static_cast<TypeParam>(-5));
    EXPECT_EQ(v1.y, static_cast<TypeParam>(1));

    v2 -= v2;

    EXPECT_EQ(v2.x, static_cast<TypeParam>(0));
    EXPECT_EQ(v2.y, static_cast<TypeParam>(0));
}

TYPED_TEST(Vector2Test, Multiplication)
{
    Vec2T v1(static_cast<TypeParam>(10), static_cast<TypeParam>(5));
    Vec2T v2(static_cast<TypeParam>(6), static_cast<TypeParam>(2));

    v1 = v1 * v2;

    EXPECT_EQ(v1.x, static_cast<TypeParam>(60));
    EXPECT_EQ(v1.y, static_cast<TypeParam>(10));

    v2 *= v2;

    EXPECT_EQ(v2.x, static_cast<TypeParam>(36));
    EXPECT_EQ(v2.y, static_cast<TypeParam>(4));
}

TYPED_TEST(Vector2Test, Division)
{
    Vec2T v1(static_cast<TypeParam>(10), static_cast<TypeParam>(15));
    Vec2T v2(static_cast<TypeParam>(2), static_cast<TypeParam>(3));

    v1 = v1 / v2;

    EXPECT_EQ(v1.x, static_cast<TypeParam>(5));
    EXPECT_EQ(v1.y, static_cast<TypeParam>(5));

    v2 /= v2;

    EXPECT_EQ(v2.x, static_cast<TypeParam>(1));
    EXPECT_EQ(v2.y, static_cast<TypeParam>(1));
}

TYPED_TEST(Vector2Test, Math)
{
    Vec2T v1(static_cast<TypeParam>(10), static_cast<TypeParam>(20));
    Vec2T v2(static_cast<TypeParam>(2), static_cast<TypeParam>(5));

    EXPECT_EQ(v1.DotProduct(v2), static_cast<TypeParam>(120));
    EXPECT_EQ(Vec2T::DotProduct(v1, v2), static_cast<TypeParam>(120));

    v1 = Vec2T(static_cast<TypeParam>(10), static_cast<TypeParam>(20));
    v2 = Vec2T(static_cast<TypeParam>(2), static_cast<TypeParam>(5));

    EXPECT_EQ(v1.CrossProduct(v2), static_cast<TypeParam>(10));
    EXPECT_EQ(Vec2T::CrossProduct(v1, v2), static_cast<TypeParam>(10));

    v1 = Vec2T::Up;
    v2 = Vec2T::Right;

    EXPECT_NEAR(v1.Angle(v2), static_cast<TypeParam>(90 * KM_INTERNAL_DEG_2_RAD), 0.0001);

    v2 = {1, 1};

    EXPECT_NEAR(Vec2T::Angle(v1, v2), static_cast<TypeParam>(45 * KM_INTERNAL_DEG_2_RAD), 0.0001);
}

TYPED_TEST(Vector2Test, Length)
{
    Vec2T v1(static_cast<TypeParam>(3), static_cast<TypeParam>(0));

    EXPECT_EQ(v1.SqrLength(), static_cast<TypeParam>(9));
    EXPECT_EQ(v1.Length(), static_cast<TypeParam>(3));

    EXPECT_EQ(Vec2T::SqrLength(v1), static_cast<TypeParam>(9));
    EXPECT_EQ(Vec2T::Length(v1), static_cast<TypeParam>(3));

    EXPECT_EQ(v1.SqrMagnitude(), static_cast<TypeParam>(9));
    EXPECT_EQ(v1.Magnitude(), static_cast<TypeParam>(3));

    EXPECT_EQ(Vec2T::SqrMagnitude(v1), static_cast<TypeParam>(9));
    EXPECT_EQ(Vec2T::Magnitude(v1), static_cast<TypeParam>(3));

    v1 = Vec2T(static_cast<TypeParam>(5), static_cast<TypeParam>(5));
    Vec2T v2 = Vec2T(static_cast<TypeParam>(10), static_cast<TypeParam>(5));

    EXPECT_EQ(v1.SqrDistance(v2), static_cast<TypeParam>(25));
    EXPECT_EQ(v1.Distance(v2), static_cast<TypeParam>(5));

    EXPECT_EQ(Vec2T::SqrDistance(v1, v2), static_cast<TypeParam>(25));
    EXPECT_EQ(Vec2T::Distance(v1, v2), static_cast<TypeParam>(5));
}

TYPED_TEST(Vector2Test, BooleanOperations)
{
    Vec2T v1(static_cast<TypeParam>(3), static_cast<TypeParam>(0));

    EXPECT_EQ(v1.IsNull(), false);
    EXPECT_EQ(Vec2T::IsNull(v1), false);

    v1 = Vec2T(static_cast<TypeParam>(0), static_cast<TypeParam>(0));

    EXPECT_EQ(v1.IsNull(), true);
    EXPECT_EQ(Vec2T::IsNull(v1), true);

    Vec2T v2(static_cast<TypeParam>(5), static_cast<TypeParam>(10));

    EXPECT_EQ(v1.Equal(v2), false);
    EXPECT_EQ(Vec2T::Equal(v1, v2), false);

    v1 = Vec2T(static_cast<TypeParam>(5), static_cast<TypeParam>(10));

    EXPECT_EQ(v1.Equal(v2), true);
    EXPECT_EQ(Vec2T::Equal(v1, v2), true);
}

TYPED_TEST(Vector2Test, Negate)
{
    Vec2T v1(static_cast<TypeParam>(10), static_cast<TypeParam>(10));
    v1 = v1.Negated();

    EXPECT_EQ(v1.x, static_cast<TypeParam>(-10));
    EXPECT_EQ(v1.y, static_cast<TypeParam>(-10));

    v1 = { static_cast<TypeParam>(5), static_cast<TypeParam>(5) };
    v1.Negate();

    EXPECT_EQ(v1.x, static_cast<TypeParam>(-5));
    EXPECT_EQ(v1.y, static_cast<TypeParam>(-5));

    EXPECT_EQ(Vec2T::Negate(v1).x, static_cast<TypeParam>(5));
    EXPECT_EQ(Vec2T::Negate(v1).y, static_cast<TypeParam>(5));
}

TYPED_TEST(Vector2Test, Inverse)
{
    TypeParam eps = Koori::Math::Epsilon<TypeParam>();

    Vec2T v1(static_cast<TypeParam>(2), static_cast<TypeParam>(2));
    v1 = v1.Inversed();

    EXPECT_NEAR(v1.x, static_cast<TypeParam>(0.5), eps);
    EXPECT_NEAR(v1.y, static_cast<TypeParam>(0.5), eps);

    v1 = { static_cast<TypeParam>(5), static_cast<TypeParam>(5) };
    v1.Inverse();

    EXPECT_NEAR(v1.x, static_cast<TypeParam>(0.2), eps);
    EXPECT_NEAR(v1.y, static_cast<TypeParam>(0.2), eps);

    v1 = { static_cast<TypeParam>(10), static_cast<TypeParam>(10) };

    EXPECT_NEAR(Vec2T::Inverse(v1).x, static_cast<TypeParam>(0.1), eps);
    EXPECT_NEAR(Vec2T::Inverse(v1).y, static_cast<TypeParam>(0.1), eps);
}

TYPED_TEST(Vector2Test, Transform)
{
    // Translation
    {
        Vec2T v1(static_cast<TypeParam>(2), static_cast<TypeParam>(2));
        Vec2T v2(static_cast<TypeParam>(3), static_cast<TypeParam>(3));

        EXPECT_EQ(Vec2T::Translate(v1, v2).x, static_cast<TypeParam>(5));
        EXPECT_EQ(Vec2T::Translate(v1, v2).y, static_cast<TypeParam>(5));

        v1 = v1.Translated(v2);

        EXPECT_EQ(v1.x, static_cast<TypeParam>(5));
        EXPECT_EQ(v1.y, static_cast<TypeParam>(5));

        v1.Translate(v2);

        EXPECT_EQ(v1.x, static_cast<TypeParam>(8));
        EXPECT_EQ(v1.y, static_cast<TypeParam>(8));
    }

    // Scale
    {
        Vec2T v1(static_cast<TypeParam>(3), static_cast<TypeParam>(3));
        Vec2T v2(static_cast<TypeParam>(0), static_cast<TypeParam>(0));

        EXPECT_EQ(Vec2T::Scale(v1, v2, 5).x, static_cast<TypeParam>(15));
        EXPECT_EQ(Vec2T::Scale(v1, v2, 5).y, static_cast<TypeParam>(15));

        v1 = v1.Scaled(v2, 5);

        EXPECT_EQ(v1.x, static_cast<TypeParam>(15));
        EXPECT_EQ(v1.y, static_cast<TypeParam>(15));

        v1.Scale(v2, 2);

        EXPECT_EQ(v1.x, static_cast<TypeParam>(30));
        EXPECT_EQ(v1.y, static_cast<TypeParam>(30));
    }

    // Rotation
    {
        Vec2T v1(static_cast<TypeParam>(0), static_cast<TypeParam>(1));
        Vec2T v2(static_cast<TypeParam>(0), static_cast<TypeParam>(0));

        EXPECT_NEAR(Vec2T::Rotate(v1, v2, -90 * KM_INTERNAL_DEG_2_RAD).x, static_cast<TypeParam>(1), 0.001);
        EXPECT_NEAR(Vec2T::Rotate(v1, v2, -90 * KM_INTERNAL_DEG_2_RAD).y, static_cast<TypeParam>(0), 0.001);

        v1 = v1.Rotated(v2, -90 * KM_INTERNAL_DEG_2_RAD);

        EXPECT_NEAR(v1.x, static_cast<TypeParam>(1), 0.001);
        EXPECT_NEAR(v1.y, static_cast<TypeParam>(0), 0.001);

        v1.Rotate(v2, 90 * KM_INTERNAL_DEG_2_RAD);

        EXPECT_NEAR(v1.x, static_cast<TypeParam>(0), 0.001);
        EXPECT_NEAR(v1.y, static_cast<TypeParam>(1), 0.001);
    }
}

TYPED_TEST(Vector2Test, Physics)
{
    // Reflection
    {
        Vec2T v1(static_cast<TypeParam>(1), static_cast<TypeParam>(-1));
        Vec2T v2(static_cast<TypeParam>(0), static_cast<TypeParam>(1));

        EXPECT_EQ(Vec2T::Reflect(v1, v2).x, static_cast<TypeParam>(1));
        EXPECT_EQ(Vec2T::Reflect(v1, v2).y, static_cast<TypeParam>(1));

        v1 = v1.Reflected(v2);

        EXPECT_EQ(v1.x, static_cast<TypeParam>(1));
        EXPECT_EQ(v1.y, static_cast<TypeParam>(1));

        v1.Reflect(v2);

        EXPECT_EQ(v1.x, static_cast<TypeParam>(1));
        EXPECT_EQ(v1.y, static_cast<TypeParam>(-1));
    }

    // Refraction
    {
        Vec2T v1(static_cast<TypeParam>(1), static_cast<TypeParam>(-1));
        Vec2T v2(static_cast<TypeParam>(0), static_cast<TypeParam>(1));

        EXPECT_NEAR(Vec2T::Refract(v1, v2, 1).x, static_cast<TypeParam>(1), 0.001);
        EXPECT_NEAR(Vec2T::Refract(v1, v2, 1).y, static_cast<TypeParam>(-1), 0.001);

        v1 = v1.Refracted(v2, 1);

        EXPECT_NEAR(v1.x, static_cast<TypeParam>(1), 0.001);
        EXPECT_NEAR(v1.y, static_cast<TypeParam>(-1), 0.001);

        v1.Refract(v2, 1);

        EXPECT_NEAR(v1.x, static_cast<TypeParam>(1), 0.001);
        EXPECT_NEAR(v1.y, static_cast<TypeParam>(-1), 0.001);
    }
}

TYPED_TEST(Vector2Test, StaticValues)
{
    Vec2T v = Vec2T::Zero;

    EXPECT_EQ(v.x, static_cast<TypeParam>(0));
    EXPECT_EQ(v.y, static_cast<TypeParam>(0));

    v = Vec2T::One;

    EXPECT_EQ(v.x, static_cast<TypeParam>(1));
    EXPECT_EQ(v.y, static_cast<TypeParam>(1));

    v = Vec2T::Right;

    EXPECT_EQ(v.x, static_cast<TypeParam>(1));
    EXPECT_EQ(v.y, static_cast<TypeParam>(0));

    v = Vec2T::Up;

    EXPECT_EQ(v.x, static_cast<TypeParam>(0));
    EXPECT_EQ(v.y, static_cast<TypeParam>(1));

    v = Vec2T::Left;

    EXPECT_EQ(v.x, static_cast<TypeParam>(-1));
    EXPECT_EQ(v.y, static_cast<TypeParam>(0));

    v = Vec2T::Down;

    EXPECT_EQ(v.x, static_cast<TypeParam>(0));
    EXPECT_EQ(v.y, static_cast<TypeParam>(-1));
}