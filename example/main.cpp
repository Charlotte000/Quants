#include <iostream>

#include <Quants/Units.hpp>
#include <Quants/Constants.hpp>

namespace u = Quants::Units;
namespace c = Quants::Constants;

int main()
{
    Quants::Acceleration a = 9.83 * u::m / u::s / u::s;
    Quants::Velocity v = 0 * u::m / u::s;
    Quants::Length r = 0 * u::m;

    Quants::Time duration = 1 * u::s;
    Quants::Time step = 0.001 * u::s;
    for (Quants::Time t = 0 * u::s; t < duration; t += step)
    {
        v += a * step;
        r += v * step;
    }

    Quants::Length r0 = a * duration * duration / 2;

    std::cout << "Calculated: " << r << std::endl;
    std::cout << "Formula: " << a * duration * duration / 2 << std::endl;
    std::cout << "Error: " << r - r0 << std::endl;
    std::cout << std::endl;

    Quants::Mass M = 1.98892e30l * u::kg;
    Quants::Length R_s = 2 * c::G * M / (c::c * c::c);
    std::cout << "Schwarzschild radius of the Sun: " <<  R_s << std::endl;
    return 0;
}
