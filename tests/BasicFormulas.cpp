#include <assert.h>

#include <Quants/Units.hpp>

#include <gtest/gtest.h>

namespace q = Quants;
namespace u = Quants::Units;

TEST(BasicFormulas, EulerMethod)
{
    const q::Length r_0 = 0 * u::m;
    const q::Velocity v_0 = 0 * u::m / u::s;
    const q::Acceleration a = 9.83 * u::m / u::s / u::s;
    const q::Time t = 1 * u::s;

    const q::Length r_formula = r_0 + v_0 * t + a * t * t / 2;

    const q::Time dT = 0.001 * u::s;

    q::Length r = r_0;
    q::Velocity v = v_0;
    for (q::Time t_0 = 0 * u::s; t_0 < t; t_0 += dT)
    {
        v += a * dT;
        r += v * dT;
    }

    EXPECT_NEAR(r.cast(u::m), r_formula.cast(u::m), 1e-1);
}

TEST(BasicFormulas, SchwarzschildRadius)
{
    const q::Length R_s = 2 * u::G * u::M_Sun / (u::c * u::c);

    EXPECT_NEAR(R_s.cast(u::km), (3 * u::km).cast(u::km), 1e-1);
}

TEST(BasicFormulas, CircularOrbit)
{
    const q::Length R_Earth = 6378 * u::km;
    const q::Velocity orbitVelocity = (u::G * u::M_Earth / R_Earth).sqrt();

    EXPECT_NEAR(orbitVelocity.cast(u::km / u::s), (7.91 * u::km / u::s).cast(u::km / u::s), 1e-1);

}

TEST(BasicFormulas, OhmsLaw)
{
    const q::Current I = 2 * u::mA;
    const q::Potential V = 5 * u::V;
    const q::Resistance R = V / I;

    EXPECT_NEAR(R.cast(u::Ohm), (2.5 * u::kOhm).cast(u::Ohm), 1e-1);
}

TEST(BasicFormulas, EulerMethod3D)
{
    const q::Length3<long double> r_0 { .x = 0 * u::m, .y = 0 * u::m, .z = 0 * u::m };
    const q::Velocity3<long double> v_0 { .x = 1 * u::m / u::s, .y = 2 * u::m / u::s, .z = 0 * u::m / u::s };
    const q::Acceleration3<long double> a { .x = 0 * u::m / u::s / u::s, .y = -9.83 * u::m / u::s / u::s, .z = 0 * u::m / u::s / u::s };
    const q::Time t = 1 * u::s;

    const q::Length3 r_formula = r_0 + v_0 * t + a * t * t / 2;

    const q::Time dT = 0.001 * u::s;

    q::Length3 r = r_0;
    q::Velocity3 v = v_0;
    for (q::Time t_0 = 0 * u::s; t_0 < t; t_0 += dT)
    {
        v += a * dT;
        r += v * dT;
    }

    EXPECT_NEAR((r - r_formula).length().cast(u::m), 0, 1e-1);
}
