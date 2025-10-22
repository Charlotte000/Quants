/**
 * @file Mechanics.hpp
 * @brief Units and type definitions for mechanics.
 */
#pragma once

#include "Quants/Units/Base.hpp"

namespace Quants
{

/**
 * @brief v
 * 
 * Moved distance per unit time: the first time derivative of position
 */
template <class T = long double>
using Velocity = Quantity<T, Dimension<int>{ 1, 0, -1, 0, 0, 0, 0 }>;

/**
 * @brief a
 * 
 * Rate of change of velocity per unit time: the second time derivative of position
 */
template <class T = long double>
using Acceleration = Quantity<T, Dimension<int>{ 1, 0, -2, 0, 0, 0, 0 }>;

/**
 * @brief j
 * 
 * Change of acceleration per unit time: the third time derivative of position
 */
template <class T = long double>
using Jerk = Quantity<T, Dimension<int>{ 1, 0, -3, 0, 0, 0, 0 }>;

/**
 * @brief e
 * 
 * Energy density per unit mass
 */
template <class T = long double>
using SpecificEnergy = Quantity<T, Dimension<int>{ 2, 0, -2, 0, 0, 0, 0 }>;


/**
 * @brief p
 * 
 * Product of an object's mass and velocity
 */
template <class T = long double>
using Momentum = Quantity<T, Dimension<int>{ 1, 1, -1, 0, 0, 0, 0 }>;

/**
 * @brief L
 * 
 * Measure of the extent and direction an object rotates about a reference point
 */
template <class T = long double>
using AngularMomentum = Quantity<T, Dimension<int>{ 2, 1, -1, 0, 0, 0, 0 }>;

/**
 * @brief F
 * 
 * Transfer of momentum per unit time
 */
template <class T = long double>
using Force = Quantity<T, Dimension<int>{ 1, 1, -2, 0, 0, 0, 0 }>;

/**
 * @brief T
 * 
 * Product of a force and the perpendicular distance of the force from the point about which it is exerted
 */
template <class T = long double>
using Torque = Quantity<T, Dimension<int>{ 2, 1, -2, 0, 0, 0, 0 }>;

/**
 * @brief E
 */
template <class T = long double>
using Energy = Quantity<T, Dimension<int>{ 2, 1, -2, 0, 0, 0, 0 }>;

/**
 * @brief P
 * 
 * Rate of transfer of energy per unit time
 */
template <class T = long double>
using Power = Quantity<T, Dimension<int>{ 2, 1, -3, 0, 0, 0, 0 }>;

/**
 * @brief p
 * 
 * Force per unit area
 */
template <class T = long double>
using Pressure = Quantity<T, Dimension<int>{ -1, 1, -2, 0, 0, 0, 0}>;

/**
 * @brief ρ
 * 
 * Mass per unit volume
 */
template <class T = long double>
using Density = Quantity<T, Dimension<int>{ -3, 1, 0, 0, 0, 0, 0 }>;

/**
 * @brief S
 * 
 * Momentum of particle multiplied by distance travelled
 */
template <class T = long double>
using Action = Quantity<T, Dimension<int>{ 2, 1, -1, 0, 0, 0, 0 }>;

/**
 * @brief f
 * 
 * Number of (periodic) occurrences per unit time
 */
template <class T = long double>
using Frequency = Quantity<T, Dimension<int>{ 0, 0, -1, 0, 0, 0, 0 }>;

/**
 * @brief v
 * 
 * Moved distance per unit time: the first time derivative of position
 */
template <class T = long double>
using Velocity3 = VectorQuantity<T, Dimension<int>{ 1, 0, -1, 0, 0, 0, 0 }>;

/**
 * @brief a
 * 
 * Rate of change of velocity per unit time: the second time derivative of position
 */
template <class T = long double>
using Acceleration3 = VectorQuantity<T, Dimension<int>{ 1, 0, -2, 0, 0, 0, 0 }>;

/**
 * @brief F
 * 
 * Transfer of momentum per unit time
 */
template <class T = long double>
using Force3 = VectorQuantity<T, Dimension<int>{ 1, 1, -2, 0, 0, 0, 0 }>;

namespace Units
{

/**
 * @brief Hertz
 */
static const Frequency<long double> Hz { .value = 1 };

/**
 * @brief Kilo-hertz
 */
static const Frequency<long double> kHz { .value = 1, .factor = Dimension<long double>{ .L = 1, .M = 1, .T = 0.001, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Newton
 */
static const Force<long double> N { .value = 1 };

/**
 * @brief Kilo-newton
 */
static const Force<long double> kN { .value = 1, .factor = Dimension<long double>{ .L = 1000, .M = 1, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Pascal
 */
static const Pressure<long double> Pa { .value = 1 };

/**
 * @brief Kilo-pascal
 */
static const Pressure<long double> kPa { .value = 1, .factor = Dimension<long double>{ .L = 1, .M = 1000, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Joule
 */
static const Energy<long double> J { .value = 1 };

/**
 * @brief Kilo-joule
 */
static const Energy<long double> kJ { .value = 1, .factor = Dimension<long double>{ .L = 1, .M = 1000, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Mega-joule
 */
static const Energy<long double> MJ { .value = 1, .factor = Dimension<long double>{ .L = 1, .M = 1e6, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Watt
 */
static const Power<long double> W { .value = 1 };

/**
 * @brief Kilo-watt
 */
static const Power<long double> kW { .value = 1, .factor = Dimension<long double>{ .L = 1, .M = 1000, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Mega-watt
 */
static const Power<long double> MW { .value = 1, .factor = Dimension<long double>{ .L = 1, .M = 1e6, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1 } };

}

}
