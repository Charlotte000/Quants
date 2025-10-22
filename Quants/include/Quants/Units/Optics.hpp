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
template <class T = long double>
using LuminousIntensity = Quantity<T, Dimension<int>{ 0, 0, 0, 0, 0, 0, 1 }>;

/**
 * @brief E
 * 
 * Wavelength-weighted luminous flux per unit surface area
 */
template <class T = long double>
using Illuminance = Quantity<T, Dimension<int>{ -2, 0, 0, 0, 0, 0, 1 }>;

/**
 * @brief L
 * 
 * Power of emitted electromagnetic radiation per unit solid angle per emitting source area
 */
template <class T = long double>
using Radiance = Quantity<T, Dimension<int>{ 0, 1, -3, 0, 0, 0, 0 }>;

namespace Units
{

/**
 * @brief Candela
 */
static const LuminousIntensity<long double> cd { .value = 1 };

/**
 * @brief Lumen
 */
static const LuminousIntensity<long double> lm { .value = 1 };

/**
 * @brief Lux
 */
static const Illuminance<long double> lx { .value = 1 };

}

}
