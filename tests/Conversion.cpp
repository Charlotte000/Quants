#include <Quants/Units.hpp>

#include <gtest/gtest.h>

namespace q = Quants;
namespace u = Quants::Units;

TEST(Conversion, BasicCasting)
{
    const q::Length a = 10 * u::km;

    EXPECT_FLOAT_EQ(a.cast(u::m), 10'000);
}

TEST(Conversion, MultidimensionalCasting)
{
    const q::Velocity a = (10 * u::km) / (100 * u::hr);

    EXPECT_FLOAT_EQ(a.cast(u::m / u::s), 0.02777777778);
}

TEST(Conversion, ArithmeticConversion)
{
    {
        const q::Length a = ((10 * u::km) / (1 * u::hr)) * (10 * u::s);
        EXPECT_FLOAT_EQ(a.cast(u::m), 27.777777778);
    }

    {
        const q::Time a = 10 * u::s + 1 * u::day;
        EXPECT_FLOAT_EQ(a.cast(u::hr), 24.00278);
    }

    {
        const q::Area a = (1 * u::km) * (1 * u::m);
        EXPECT_FLOAT_EQ(a.cast(u::km * u::km), 0.001);
    }
}
