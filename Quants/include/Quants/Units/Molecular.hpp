/**
 * @file Molecular.hpp
 * @brief Units and constants commonly used in molecular physics and chemistry.
 */
#pragma once

#include "Quants/Units/Mechanics.hpp"

namespace Quants
{

template <class T = long double>
using AmountOfSubstance = Quantity<T, Dimension<int>{ 0, 0, 0, 0, 0, 1, 0 }>;

namespace Units
{

/**
 * @brief Mole
 */
static const AmountOfSubstance<long double> mol { .value = 1 };

/**
 * @brief Planck constant
 */
static const AngularMomentum<long double> h = 6.62607015e-34l * Units::m * Units::m * Units::kg / Units::s;

/**
 * @brief Reduced Planck constant
 */
static const AngularMomentum<long double> h_bar = h * M_1_PI / 2;

/**
 * @brief Avogadro constant
 */
static const Quantity<long double, Dimension<int>{ 0, 0, 0, 0, 0, -1, 0 }> N_a = 6.02214076e23l / Units::mol;

}

}
