/**
 * @file Molecular.hpp
 * @brief Units and constants commonly used in molecular physics and chemistry.
 */
#pragma once

#include "Quants/Quantity.hpp"
#include "Quants/Units/Base.hpp"
#include "Quants/Units/Mechanics.hpp"

namespace Quants
{

using AmountOfSubstance = Quantity<Dimension<int>{ 0, 0, 0, 0, 0, 1, 0 }>;

namespace Units
{

/**
 * @brief Mole
 */
static const AmountOfSubstance mol { .value = 1 };

namespace Constants
{

/**
 * @brief Planck constant
 */
static const AngularMomentum h = 6.62607015e-34l * Units::m * Units::m * Units::kg / Units::s;

/**
 * @brief Reduced Planck constant
 */
static const AngularMomentum h_bar = h * M_1_PI / 2;

/**
 * @brief Avogadro constant
 */
static const Quantity<Dimension<int>{ 0, 0, 0, 0, 0, -1, 0 }> N_a = 6.02214076e23l / Units::mol;

}

}

}
