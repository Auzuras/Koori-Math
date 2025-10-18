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

TYPED_TEST(Vector2Test, Constructors)
{
    Vector2<TypeParam> v1;

    EXPECT_EQ(v1.x, static_cast<TypeParam>(0));
    EXPECT_EQ(v1.y, static_cast<TypeParam>(0));

    v1 = Vector2<TypeParam>(static_cast<TypeParam>(10));

    EXPECT_EQ(v1.x, static_cast<TypeParam>(10));
    EXPECT_EQ(v1.y, static_cast<TypeParam>(10));

    v1 = Vector2<TypeParam>(static_cast<TypeParam>(20), static_cast<TypeParam>(5));

    EXPECT_EQ(v1.x, static_cast<TypeParam>(20));
    EXPECT_EQ(v1.y, static_cast<TypeParam>(5));

    Vector2<TypeParam> v2 = Vector2<TypeParam>(static_cast<TypeParam>(3), static_cast<TypeParam>(2));
    v1 = Vector2<TypeParam>(v2);

    EXPECT_EQ(v1.x, v2.x);
    EXPECT_EQ(v1.y, v2.y);

    v2 = Vector2<TypeParam>(static_cast<TypeParam>(15), static_cast<TypeParam>(12));
    v1 = Vector2<TypeParam>(&v2);

    EXPECT_EQ(v1.x, v2.x);
    EXPECT_EQ(v1.y, v2.y);
}

TYPED_TEST(Vector2Test, Getters)
{
    Vector2<TypeParam> v1 = Vector2<TypeParam>(static_cast<TypeParam>(3), static_cast<TypeParam>(2));

    EXPECT_EQ(v1.GetX(), static_cast<TypeParam>(3));
    EXPECT_EQ(v1.GetY(), static_cast<TypeParam>(2));
}

TYPED_TEST(Vector2Test, Setters)
{
    Vector2<TypeParam> v1;

    v1.SetX(static_cast<TypeParam>(111));
    v1.SetY(static_cast<TypeParam>(101));

    EXPECT_EQ(v1.x, static_cast<TypeParam>(111));
    EXPECT_EQ(v1.y, static_cast<TypeParam>(101));
}

TYPED_TEST(Vector2Test, Addition)
{
    Vector2<TypeParam> v1(static_cast<TypeParam>(0), static_cast<TypeParam>(1));
    Vector2<TypeParam> v2(static_cast<TypeParam>(5), static_cast<TypeParam>(1));

    v1 = v1 + v2;

    EXPECT_EQ(v1.x, static_cast<TypeParam>(5));
    EXPECT_EQ(v1.y, static_cast<TypeParam>(2));

    v2 += v2;

    EXPECT_EQ(v2.x, static_cast<TypeParam>(10));
    EXPECT_EQ(v2.y, static_cast<TypeParam>(2));
}

TYPED_TEST(Vector2Test, Substraction)
{
    Vector2<TypeParam> v1(static_cast<TypeParam>(15), static_cast<TypeParam>(3));
    Vector2<TypeParam> v2(static_cast<TypeParam>(20), static_cast<TypeParam>(2));

    v1 = v1 - v2;

    EXPECT_EQ(v1.x, static_cast<TypeParam>(-5));
    EXPECT_EQ(v1.y, static_cast<TypeParam>(1));

    v2 -= v2;

    EXPECT_EQ(v2.x, static_cast<TypeParam>(0));
    EXPECT_EQ(v2.y, static_cast<TypeParam>(0));
}

TYPED_TEST(Vector2Test, Multiplication)
{
    Vector2<TypeParam> v1(static_cast<TypeParam>(10), static_cast<TypeParam>(5));
    Vector2<TypeParam> v2(static_cast<TypeParam>(6), static_cast<TypeParam>(2));

    v1 = v1 * v2;

    EXPECT_EQ(v1.x, static_cast<TypeParam>(60));
    EXPECT_EQ(v1.y, static_cast<TypeParam>(10));

    v2 *= v2;

    EXPECT_EQ(v2.x, static_cast<TypeParam>(36));
    EXPECT_EQ(v2.y, static_cast<TypeParam>(4));
}

TYPED_TEST(Vector2Test, Division)
{
    Vector2<TypeParam> v1(static_cast<TypeParam>(10), static_cast<TypeParam>(15));
    Vector2<TypeParam> v2(static_cast<TypeParam>(2), static_cast<TypeParam>(3));

    v1 = v1 / v2;

    EXPECT_EQ(v1.x, static_cast<TypeParam>(5));
    EXPECT_EQ(v1.y, static_cast<TypeParam>(5));

    v2 /= v2;

    EXPECT_EQ(v2.x, static_cast<TypeParam>(1));
    EXPECT_EQ(v2.y, static_cast<TypeParam>(1));
}

TYPED_TEST(Vector2Test, DotProduct)
{
    Vector2<TypeParam> v1(static_cast<TypeParam>(10), static_cast<TypeParam>(20));
    Vector2<TypeParam> v2(static_cast<TypeParam>(2), static_cast<TypeParam>(5));

    EXPECT_EQ(v1.DotProduct(v2), static_cast<TypeParam>(120));
}

TYPED_TEST(Vector2Test, CrossProduct)
{
    Vector2<TypeParam> v1(static_cast<TypeParam>(10), static_cast<TypeParam>(20));
    Vector2<TypeParam> v2(static_cast<TypeParam>(2), static_cast<TypeParam>(5));

    EXPECT_EQ(v1.CrossProduct(v2), static_cast<TypeParam>(10));
}