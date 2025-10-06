/**
 * @file Optics.hpp
 * @brief Units and type definitions for optics.
 */
#pragma once

#include "Quants/Quantity.hpp"

namespace Quants
{

/**
 * @brief l
 * 
 * Wavelength-weighted power of emitted light per unit solid angle
 */
using LuminousIntensity = Quantity<Dimension<int>{ 0, 0, 0, 0, 0, 0, 1 }>;

/**
 * @brief E
 * 
 * Wavelength-weighted luminous flux per unit surface area
 */
using Illuminance = Quantity<Dimension<int>{ -2, 0, 0, 0, 0, 0, 1 }>;

/**
 * @brief L
 * 
 * Power of emitted electromagnetic radiation per unit solid angle per emitting source area
 */
using Radiance = Quantity<Dimension<int>{ 0, 1, -3, 0, 0, 0, 0 }>;

namespace Units
{

/**
 * @brief Candela
 */
static const LuminousIntensity cd { .value = 1 };

/**
 * @brief Lumen
 */
static const LuminousIntensity lm { .value = 1 };

/**
 * @brief Lux
 */
static const Illuminance lx { .value = 1 };

}

}
