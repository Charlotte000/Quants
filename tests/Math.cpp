#include <Quants/Units.hpp>

#include <gtest/gtest.h>

namespace q = Quants;
namespace u = Quants::Units;

TEST(Math, Addition)
{
    const q::Length a = 10 * u::km;
    const q::Length b = 1 * u::m;
    const q::Length c = a + b;

    EXPECT_FLOAT_EQ(c.cast(u::m), 10'001);
}

TEST(Math, Subtraction)
{
    const q::Mass a = 10 * u::t;
    const q::Mass b = 1 * u::kg;
    const q::Mass c = a - b;

    EXPECT_FLOAT_EQ(c.cast(u::kg), 9'999);
}

TEST(Math, Multiplication)
{
    const q::Time    a = 10 * u::ms;
    const q::Current b = 2 * u::A;
    const auto c = a * b;

    EXPECT_FLOAT_EQ(c.cast(u::s * u::A), 0.02);
}

TEST(Math, Division)
{
    const q::Temperature       a = 100 * u::K;
    const q::AmountOfSubstance b = 1e3 * u::mol;
    const auto c = a / b;

    EXPECT_FLOAT_EQ(c.cast(u::K / u::mol), 0.1);
}

TEST(Math, Sqrt)
{
    const q::Area   a = 10 * u::km * u::km;
    const q::Length b = a.sqrt();

    EXPECT_FLOAT_EQ(b.cast(u::m), 3162.2776);
}