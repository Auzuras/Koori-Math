#include <gtest/gtest.h>

#include <Quaternion/Quaternion.h>

template <typename T>
class QuaternionTest : public testing::Test {};

using TestTypes = ::testing::Types<
    short, unsigned short,
    int, unsigned int,
    long, unsigned long,
    long long, unsigned long long,
    double, long double,
    float
>;

TYPED_TEST_SUITE(QuaternionTest, TestTypes);

#define QuaternionT Quaternion<TypeParam>