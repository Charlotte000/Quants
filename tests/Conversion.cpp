#include <assert.h>

#include <Quants/Units.hpp>

#include <gtest/gtest.h>

namespace q = Quants;
namespace u = Quants::Units;

TEST(Conversion, BasicCasting)
{
    const q::Length a = 10 * u::km;

    EXPECT_NEAR(a.cast(u::m), 10'000, 1e-1);
}

TEST(Conversion, MultidimensionalCasting)
{
    const q::Velocity a = (10 * u::km) / (100 * u::hr);

    EXPECT_NEAR(a.cast(u::m / u::s), 0.0278, 1e-3);
}

TEST(Conversion, ArithmeticConversion)
{
    {
        const q::Length a = ((10 * u::km) / (1 * u::hr)) * (10 * u::s);
        EXPECT_NEAR(a.cast(u::m), 27.78, 1e-2);
    }

    {
        const q::Time a = 10 * u::s + 1 * u::day;
        EXPECT_NEAR(a.cast(u::hr), 24.00278, 1e-3);
    }

    {
        const q::Area a = (1 * u::km) * (1 * u::m);
        EXPECT_NEAR(a.cast(u::km * u::km), 0.001, 1e-6);
    }
}
