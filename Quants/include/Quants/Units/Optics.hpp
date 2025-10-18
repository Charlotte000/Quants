/**
 * @file Optics.hpp
 * @brief Units and type definitions for optics.
 */
#pragma once

#include "Quants/Unit.hpp"

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
static const Unit<Dimension<int>{ 0, 0, 0, 0, 0, 0, 1 }> cd;

/**
 * @brief Lumen
 */
static const Unit<Dimension<int>{ 0, 0, 0, 0, 0, 0, 1 }> lm;

/**
 * @brief Lux
 */
static const Unit<Dimension<int>{ -2, 0, 0, 0, 0, 0, 1 }> lx;

}

}
