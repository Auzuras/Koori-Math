#include <gtest/gtest.h>

#include <Vectors/Vector2.h>

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

TYPED_TEST(Vector2Test, IDK)
{
    Vector2<TypeParam> v1;

    EXPECT_EQ(v1.x, static_cast<TypeParam>(0));
    EXPECT_EQ(v1.y, static_cast<TypeParam>(0));
}