/**
 * @file Astronomy.hpp
 * @brief Units and constants commonly used in astronomy.
 */
#pragma once

#include "Quants/Units/Mechanics.hpp"

namespace Quants
{

namespace Units
{

/**
 * @brief Julian day
 */
static const Time day { .value = 1, .factor = Dimension<long long>{ .L = 1, .M = 1, .T = 86400, .I = 1, .TH = 1, .N = 1, .J = 1, } };

/**
 * @brief Julian year
 */
static const Time year { .value = 1, .factor = Dimension<long long>{ .L = 1, .M = 1, .T = 31'557'600, .I = 1, .TH = 1, .N = 1, .J = 1, } };

/**
 * @brief Astronomical unit
 */
static const Length au { .value = 1, .factor = Dimension<long long>{ .L = 149'597'870'700, .M = 1, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1, } };

/**
 * @brief Light year
 */
static const Length ly { .value = 1, .factor = Dimension<long long>{ .L = 9'460'730'472'580'800, .M = 1, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1, } };

/**
 * @brief Parsec
 */
static const Length pc { .value = 1, .factor = Dimension<long long>{ .L = 30'856'775'812'800'000, .M = 1, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1, } };

}

namespace Constants
{

/**
 * @brief Gravitational constant
 */
static const Quantity<Dimension<int>{ 3, -1, -2, 0, 0, 0, 0 }> G = 6.6743e-11l * (Units::m * Units::m * Units::m / (Units::kg * Units::s * Units::s));

/**
 * @brief Speed of light in vacuum
 */
static const Velocity c = 299'792'458.l * (Units::m / Units::s);

}

}
