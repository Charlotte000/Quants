#include <Quants/Units.hpp>

#include <gtest/gtest.h>

namespace q = Quants;
namespace u = Quants::Units;

TEST(VectorMath, Addition)
{
    const q::Length3 a { 10 * u::km, 1 * u::km, 1 * u::m };
    const q::Length3 b {   1 * u::m,  2 * u::m, 1 * u::m };
    const q::Length3 c = a + b;

    EXPECT_FLOAT_EQ(c.x.cast(u::km), 10.001);
    EXPECT_FLOAT_EQ(c.y.cast(u::km),  1.002);
    EXPECT_FLOAT_EQ(c.z.cast(u::km),  0.002);
}

TEST(VectorMath, Subtraction)
{
    const q::Length3 a { 10 * u::km, 1 * u::km, 1 * u::m };
    const q::Length3 b {   1 * u::m,  2 * u::m, 1 * u::m };
    const q::Length3 c = a - b;

    EXPECT_FLOAT_EQ(c.x.cast(u::km), 9.999);
    EXPECT_FLOAT_EQ(c.y.cast(u::km), 0.998);
    EXPECT_FLOAT_EQ(c.z.cast(u::km),     0);
}

TEST(VectorMath, Multiplication)
{
    const q::Length3 a { 10 * u::km, 1 * u::km, 1 * u::m };
    const q::Length  b = 2 * u::m;
    const auto c = a * b;

    EXPECT_FLOAT_EQ(c.x.cast(u::km * u::km),     0.02);
    EXPECT_FLOAT_EQ(c.y.cast(u::km * u::km),    0.002);
    EXPECT_FLOAT_EQ(c.z.cast(u::km * u::km), 0.000002);
}

TEST(VectorMath, Division)
{
    const q::Length3 a { 10 * u::km, 1 * u::km, 1 * u::m };
    const q::Length  b = 2 * u::m;
    const auto c = a / b;

    EXPECT_FLOAT_EQ(c.x.value, 5000);
    EXPECT_FLOAT_EQ(c.y.value,  500);
    EXPECT_FLOAT_EQ(c.z.value,  0.5);
}

TEST(VectorMath, Length)
{
    const q::Length3 a { 10 * u::km, 1 * u::km, 1 * u::m };
    const q::Length  b = a.length();

    EXPECT_FLOAT_EQ(b.cast(u::km), 10.04987567);
}