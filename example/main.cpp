#include <iostream>

#include <Quants/Units.hpp>

namespace q = Quants;
namespace u = Quants::Units;
namespace c = Quants::Constants;

int main()
{
    {
        // Euler method
        const q::Length r_0 = 0 * u::m;
        const q::Velocity v_0 = 0 * u::m / u::s;
        const q::Acceleration a = 9.83 * u::m / u::s / u::s;
        const q::Time t = 1 * u::s;

        const q::Length r_formula = r_0 + v_0 * t + a * t * t / 2;

        const q::Time step = 0.001 * u::s;

        q::Length r = r_0;
        q::Velocity v = v_0;
        for (q::Time t_0 = 0 * u::s; t_0 < t; t_0 += step)
        {
            v += a * step;
            r += v * step;
        }

        std::cout << "Calculated: " << r.convert(u::m) << " m" << std::endl;
        std::cout << "Formula: " << r_formula.convert(u::m) << " m" << std::endl;
        std::cout << "Error: " << (r - r_formula).convert(u::m) << " m" << std::endl;
        std::cout << std::endl;
    }

    {
        // Schwarzschild radius
        const q::Mass M_Sun = 1.98892e30l * u::kg;
        const q::Length R_s = 2 * c::G * M_Sun / (c::c * c::c);
        std::cout << "Schwarzschild radius of the Sun: " <<  R_s.convert(u::km) << " km" << std::endl;
        std::cout << std::endl;
    }

    {
        // Circular orbit velocity
        const q::Mass M_Earth = 5.972e24l * u::kg;
        const q::Length R_Earth = 6378 * u::km;
        const q::Velocity orbitVelocity = (c::G * M_Earth / R_Earth).sqrt();
        std::cout << "Earth's circular orbit velocity: " << orbitVelocity.convert(u::m / u::s) << " m / s" << std::endl;
        std::cout << std::endl;
    }

    {
        // Ohm's Law
        const q::Current I = 20 * u::A / 1000;
        const q::Potential V = 5 * u::V;
        const q::Resistance R = V / I;
        std::cout << "R = V / I" << std::endl;
        std::cout << "R = " << V.convert(u::V) << " V / " << I.convert(u::A / 1000) << " mA" << std::endl;
        std::cout << "R = " << R.convert(u::Ohm) << " Ohm" << std::endl;
    }

    return 0;
}
