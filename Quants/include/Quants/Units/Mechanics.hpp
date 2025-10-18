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
using Velocity = Quantity<Dimension<int>{ 1, 0, -1, 0, 0, 0, 0 }>;

/**
 * @brief a
 * 
 * Rate of change of velocity per unit time: the second time derivative of position
 */
using Acceleration = Quantity<Dimension<int>{ 1, 0, -2, 0, 0, 0, 0 }>;

/**
 * @brief j
 * 
 * Change of acceleration per unit time: the third time derivative of position
 */
using Jerk = Quantity<Dimension<int>{ 1, 0, -3, 0, 0, 0, 0 }>;

/**
 * @brief e
 * 
 * Energy density per unit mass
 */
using SpecificEnergy = Quantity<Dimension<int>{ 2, 0, -2, 0, 0, 0, 0 }>;


/**
 * @brief p
 * 
 * Product of an object's mass and velocity
 */
using Momentum = Quantity<Dimension<int>{ 1, 1, -1, 0, 0, 0, 0 }>;

/**
 * @brief L
 * 
 * Measure of the extent and direction an object rotates about a reference point
 */
using AngularMomentum = Quantity<Dimension<int>{ 2, 1, -1, 0, 0, 0, 0 }>;

/**
 * @brief F
 * 
 * Transfer of momentum per unit time
 */
using Force = Quantity<Dimension<int>{ 1, 1, -2, 0, 0, 0, 0 }>;

/**
 * @brief T
 * 
 * Product of a force and the perpendicular distance of the force from the point about which it is exerted
 */
using Torque = Quantity<Dimension<int>{ 2, 1, -2, 0, 0, 0, 0 }>;

/**
 * @brief E
 */
using Energy = Quantity<Dimension<int>{ 2, 1, -2, 0, 0, 0, 0 }>;

/**
 * @brief P
 * 
 * Rate of transfer of energy per unit time
 */
using Power = Quantity<Dimension<int>{ 2, 1, -3, 0, 0, 0, 0 }>;

/**
 * @brief p
 * 
 * Force per unit area
 */
using Pressure = Quantity<Dimension<int>{ -1, 1, -2, 0, 0, 0, 0}>;

/**
 * @brief ρ
 * 
 * Mass per unit volume
 */
using Density = Quantity<Dimension<int>{ -3, 1, 0, 0, 0, 0, 0 }>;

/**
 * @brief S
 * 
 * Momentum of particle multiplied by distance travelled
 */
using Action = Quantity<Dimension<int>{ 2, 1, -1, 0, 0, 0, 0 }>;

/**
 * @brief f
 * 
 * Number of (periodic) occurrences per unit time
 */
using Frequency = Quantity<Dimension<int>{ 0, 0, -1, 0, 0, 0, 0 }>;

/**
 * @brief v
 * 
 * Moved distance per unit time: the first time derivative of position
 */
using Velocity3 = VectorQuantity<Dimension<int>{ 1, 0, -1, 0, 0, 0, 0 }>;

/**
 * @brief a
 * 
 * Rate of change of velocity per unit time: the second time derivative of position
 */
using Acceleration3 = VectorQuantity<Dimension<int>{ 1, 0, -2, 0, 0, 0, 0 }>;

/**
 * @brief F
 * 
 * Transfer of momentum per unit time
 */
using Force3 = VectorQuantity<Dimension<int>{ 1, 1, -2, 0, 0, 0, 0 }>;

namespace Units
{

/**
 * @brief Hertz
 */
static const Unit<Dimension<int>{ 0, 0, -1, 0, 0, 0, 0 }> Hz;

/**
 * @brief Newton
 */
static const Unit<Dimension<int>{ 1, 1, -2, 0, 0, 0, 0 }> N;

/**
 * @brief Pascal
 */
static const Unit<Dimension<int>{ -1, 1, -2, 0, 0, 0, 0}> Pa;

/**
 * @brief Joule
 */
static const Unit<Dimension<int>{ 2, 1, -2, 0, 0, 0, 0 }> J;

/**
 * @brief Watt
 */
static const Unit<Dimension<int>{ 2, 1, -3, 0, 0, 0, 0 }> W;

}

}
