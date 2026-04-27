#include <assert.h>

#include <Quants/Units.hpp>

#include <gtest/gtest.h>

namespace q = Quants;
namespace u = Quants::Units;

TEST(VectorMath, Addition)
{
    const q::Length3 a { 10 * u::km, 1 * u::km, 1 * u::m };
    const q::Length3 b {   1 * u::m,  2 * u::m, 1 * u::m };
    const q::Length3 c = a + b;

    EXPECT_NEAR(c.x.cast(u::km), 10.001, 1e-4);
    EXPECT_NEAR(c.y.cast(u::km),  1.002, 1e-4);
    EXPECT_NEAR(c.z.cast(u::km),  0.002, 1e-4);
}

TEST(VectorMath, Subtraction)
{
    const q::Length3 a { 10 * u::km, 1 * u::km, 1 * u::m };
    const q::Length3 b {   1 * u::m,  2 * u::m, 1 * u::m };
    const q::Length3 c = a - b;

    EXPECT_NEAR(c.x.cast(u::km), 9.999, 1e-4);
    EXPECT_NEAR(c.y.cast(u::km), 0.998, 1e-4);
    EXPECT_NEAR(c.z.cast(u::km),     0, 1e-4);
}

TEST(VectorMath, Multiplication)
{
    const q::Length3 a { 10 * u::km, 1 * u::km, 1 * u::m };
    const q::Length  b = 2 * u::m;
    const auto c = a * b;

    EXPECT_NEAR(c.x.cast(u::km * u::km), 0.02,     1e-7);
    EXPECT_NEAR(c.y.cast(u::km * u::km), 0.002,    1e-7);
    EXPECT_NEAR(c.z.cast(u::km * u::km), 0.000002, 1e-7);
}

TEST(VectorMath, Division)
{
    const q::Length3 a { 10 * u::km, 1 * u::km, 1 * u::m };
    const q::Length  b = 2 * u::m;
    const auto c = a / b;

    EXPECT_NEAR(c.x.value, 5000,     1e-7);
    EXPECT_NEAR(c.y.value, 500,    1e-7);
    EXPECT_NEAR(c.z.value, 0.5, 1e-7);
}

TEST(VectorMath, Length)
{
    const q::Length3 a { 10 * u::km, 1 * u::km, 1 * u::m };
    const q::Length  b = a.length();

    EXPECT_NEAR(b.cast(u::km), 10.049, 1e-3);
}