#include <gtest/gtest.h>

#include <Matrix/Matrix4.h>

template <typename T>
class Matrix4Test : public testing::Test {};

using TestTypes = ::testing::Types<
    short, unsigned short,
    int, unsigned int,
    long, unsigned long,
    long long, unsigned long long,
    double, long double,
    float
>;

TYPED_TEST_SUITE(Matrix4Test, TestTypes);

#define Matrix4T Matrix4<TypeParam>