#include <iostream>

#include <Quants/Units.hpp>

namespace q = Quants;
namespace u = Quants::Units;

int main()
{
    {
        // Euler method
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

        std::cout << "Calculated: " << r.cast(u::m) << " m" << std::endl;
        std::cout << "Formula: " << r_formula.cast(u::m) << " m" << std::endl;
        std::cout << "Error: " << (r - r_formula).cast(u::m) << " m" << std::endl;
        std::cout << std::endl;
    }

    {
        // Schwarzschild radius
        const q::Length R_s = 2 * u::G * u::M_Sun / (u::c * u::c);
        std::cout << "Schwarzschild radius of the Sun: " <<  R_s.cast(u::km) << " km" << std::endl;
        std::cout << std::endl;
    }

    {
        // Circular orbit velocity
        const q::Length R_Earth = 6378 * u::km;
        const q::Velocity orbitVelocity = (u::G * u::M_Earth / R_Earth).sqrt();
        std::cout << "Earth's circular orbit velocity: " << orbitVelocity.cast(u::m / u::s) << " m / s" << std::endl;
        std::cout << std::endl;
    }

    {
        // Ohm's Law
        const q::Current I = 2 * u::mA;
        const q::Potential V = 5 * u::V;
        const q::Resistance R = V / I;
        std::cout << "R = V / I" << std::endl;
        std::cout << "R = " << V.cast(u::V) << " V / " << I.cast(u::mA) << " mA" << std::endl;
        std::cout << "R = " << R.cast(u::kOhm) << " kOhm" << std::endl;
        std::cout << std::endl;
    }

    {
        // Euler method 3D
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

        std::cout << "Calculated: " << r << std::endl;
        std::cout << "Formula: " << r_formula << std::endl;
        std::cout << "Error: " << (r - r_formula).length() << std::endl;
    }

    return 0;
}
