#pragma once

#include "Quants/Units.hpp"

namespace Quants::Constants
{

/**
 * @brief Gravitational constant
 */
static const Quantity<3, -1, -2> G = 6.6743e-11l * (Units::m * Units::m * Units::m / (Units::kg * Units::s * Units::s));

/**
 * @brief Speed of light in vacuum
 */
static const Velocity c = 299'792'458.l * (Units::m / Units::s);

/**
 * @brief Planck constant
 */
static const Quantity<2, 1, -1> h = 6.62607015e-34l * Units::m * Units::m * Units::kg / Units::s;

/**
 * @brief Reduced Planck constant
 */
static const Quantity<2, 1, -1> h_bar = h * M_1_PI / 2;

}