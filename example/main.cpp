#include <Quants/Units.hpp>
#include <Quants/Constants.hpp>

namespace u = Quants::Units;
namespace c = Quants::Constants;

int main()
{
    Quants::Acceleration a = 1 * u::m / u::s / u::s;
    Quants::Velocity v = 0 * u::m / u::s;
    Quants::Length r = 0 * u::m;

    Quants::Time duration = 1 * u::s;
    Quants::Time step = 0.001 * u::s;
    for (Quants::Time t = 0 * u::s; t < duration; t += step)
    {
        v += a * step;
        r += v * step;
    }

    std::cout << r << std::endl;
    std::cout << a * duration * duration / 2 << std::endl;
    return 0;
}
