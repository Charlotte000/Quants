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
static const Time day { .value = 1, .factor = Dimension<long double>{ .L = 1, .M = 1, .T = 86'400, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Julian year
 */
static const Time year { .value = 1, .factor = Dimension<long double>{ .L = 1, .M = 1, .T = 31'557'600, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Astronomical unit
 */
static const Length au { .value = 1, .factor = Dimension<long double>{ .L = 149'597'870'700, .M = 1, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Light year
 */
static const Length ly { .value = 1, .factor = Dimension<long double>{ .L = 9'460'730'472'580'800, .M = 1, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Parsec
 */
static const Length pc { .value = 1, .factor = Dimension<long double>{ .L = 30'856'775'812'800'000, .M = 1, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Gravitational constant
 */
static const Quantity<Dimension<int>{ 3, -1, -2, 0, 0, 0, 0 }> G = 6.6743e-11l * (Units::m * Units::m * Units::m / (Units::kg * Units::s * Units::s));

/**
 * @brief Speed of light in vacuum
 */
static const Velocity c { .value = 1, .factor = Dimension<long double>{ .L = 299'792'458, .M = 1, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Mass of the Sun
 */
static const Mass M_Sun { .value = 1, .factor = Dimension<long double>{ .L = 1, .M = 1988400e24l, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Mass of the Mercury
 */
static const Mass M_Mercury { .value = 1, .factor = Dimension<long double>{ .L = 1, .M = 0.3301e24l, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Mass of the Venus
 */
static const Mass M_Venus { .value = 1, .factor = Dimension<long double>{ .L = 1, .M = 4.8673e24l, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Mass of the Earth
 */
static const Mass M_Earth { .value = 1, .factor = Dimension<long double>{ .L = 1, .M = 5.9722e24l, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Mass of the Mars
 */
static const Mass M_Mars { .value = 1, .factor = Dimension<long double>{ .L = 1, .M = 0.64169e24l, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Mass of the Jupiter
 */
static const Mass M_Jupiter { .value = 1, .factor = Dimension<long double>{ .L = 1, .M = 1898.13e24l, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Mass of the Saturn
 */
static const Mass M_Saturn { .value = 1, .factor = Dimension<long double>{ .L = 1, .M = 568.32e24l, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Mass of the Uranus
 */
static const Mass M_Uranus { .value = 1, .factor = Dimension<long double>{ .L = 1, .M = 86.811e24l, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Mass of the Neptune
 */
static const Mass M_Neptune { .value = 1, .factor = Dimension<long double>{ .L = 1, .M = 102.409e24l, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1 } };

}

}
