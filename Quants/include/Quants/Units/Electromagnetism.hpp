/**
 * @file Electromagnetism.hpp
 * @brief Units and type definitions for electromagnetism.
 */
#pragma once

#include "Quants/Unit.hpp"

namespace Quants
{

/**
 * @brief Q
 * 
 * The force per unit electric field strength
 */
using Charge = Quantity<Dimension<int>{ 0, 0, 1, 1, 0, 0, 0 }>;

/**
 * @brief I
 * 
 * Rate of flow of electrical charge per unit time
 */
using Current = Quantity<Dimension<int>{ 0, 0, 0, 1, 0, 0, 0 }>;

/**
 * @brief J
 * 
 * Electric current per unit cross-section area
 */
using CurrentDensity = Quantity<Dimension<int>{ -2, 0, 0, 1, 0, 0, 0 }>;

/**
 * @brief φ
 * 
 * Energy required to move a unit charge through an electric field from a reference point
 */
using Potential = Quantity<Dimension<int>{ 2, 1, -3, -1, 0, 0, 0 }>;

/**
 * @brief R
 * 
 * Electric potential per unit electric current
 */
using Resistance = Quantity<Dimension<int>{ 2, 1, -3, -2, 0, 0, 0 }>;

/**
 * @brief Z
 * 
 * Resistance to an alternating current of a given frequency, including effect on phase
 */
using Impedance = Quantity<Dimension<int>{ 2, 1, -3, -2, 0, 0, 0 }>;

/**
 * @brief ρ
 * 
 * Bulk property equivalent of electrical resistance
 */
using Resistivity = Quantity<Dimension<int>{ 3, 1, -3, -2, 0, 0, 0 }>;

/**
 * @brief C
 * 
 * Stored charge per unit electric potential
 */
using Capacitance = Quantity<Dimension<int>{ -2, -1, 4, 2, 0, 0, 0 }>;

/**
 * @brief Φ_E
 * 
 * The total electric field that crosses a given surface
 */
using ElectricFlux = Quantity<Dimension<int>{ 3, 1, -3, -1, 0, 0, 0 }>;

/**
 * @brief E
 * 
 * Strength of the electric field
 */
using ElectricFieldStrength = Quantity<Dimension<int>{ 1, 1, -3, -1, 0, 0, 0 }>;

/**
 * @brief D
 * 
 * Strength of the electric displacement
 */
using ElectricDisplacementField = Quantity<Dimension<int>{ -2, 0, 1, 1, 0, 0, 0 }>;

/**
 * @brief ε
 * 
 * Measure for how the polarization of a material is affected by the application of an external electric field
 */
using Permittivity = Quantity<Dimension<int>{ -3, -1, 4, 2, 0, 0, 0 }>;

/**
 * @brief p
 * 
 * Measure of the separation of equal and opposite electric charges
 */
using ElectricDipoleMoment = Quantity<Dimension<int>{ 1, 0, 1, 1, 0, 0, 0 }>;

/**
 * @brief G
 * 
 * Measure for how easily current flows through a material
 */
using Conductance = Quantity<Dimension<int>{ -2, -1, 3, 2, 0, 0, 0 }>;

/**
 * @brief σ
 * 
 * Measure of a material's ability to conduct an electric current
 */
using Conductivity = Quantity<Dimension<int>{ -3, -1, 3, 2, 0, 0, 0 }>;

/**
 * @brief B
 * 
 * Measure for the strength of the magnetic field
 */
using MagneticFluxDensity = Quantity<Dimension<int>{ 0, 1, -2, -1, 0, 0, 0 }>;

/**
 * @brief Φ
 * 
 * Measure of magnetism, taking account of the strength and the extent of a magnetic field
 */
using MagneticFlux = Quantity<Dimension<int>{ 2, 1, -2, -1, 0, 0, 0 }>;

/**
 * @brief H
 * 
 * Strength of a magnetic field
 */
using MagneticFieldStrength = Quantity<Dimension<int>{ -1, 0, 0, 1, 0, 0, 0 }>;

/**
 * @brief R
 * 
 * Resistance to the flow of magnetic flux
 */
using Reluctance = Quantity<Dimension<int>{ -2, -1, 2, 2, 0, 0, 0 }>;

/**
 * @brief P
 * 
 * The inverse of reluctance
 */
using Permeance = Quantity<Dimension<int>{ 2, 1, -2, -2, 0, 0, 0 }>;

/**
 * @brief L
 * 
 * Magnetic flux generated per unit current through a circuit
 */
using Inductance = Quantity<Dimension<int>{ 2, 1, -2, -2, 0, 0, 0 }>;

/**
 * @brief μ
 * 
 * Measure for how the magnetization of material is affected by the application of an external magnetic field
 */
using Permeability = Quantity<Dimension<int>{ 1, 1, -2, -2, 0, 0, 0 }>;

/**
 * @brief m
 * 
 * The component of magnetic strength and orientation that can be represented by an equivalent magnetic dipole
 */
using MagneticDipoleMoment = Quantity<Dimension<int>{ 2, 0, 0, 1, 0, 0, 0 }>;

/**
 * @brief M
 * 
 * Amount of magnetic moment per unit volume
 */
using Magnetization = Quantity<Dimension<int>{ -1, 0, 0, 1, 0, 0, 0 }>;

namespace Units
{

/**
 * @brief Ampere
 */
static const Unit<Dimension<int>{ 0, 0, 0, 1, 0, 0, 0 }> A;

/**
 * @brief Coulomb
 */
static const Unit<Dimension<int>{ 0, 0, 1, 1, 0, 0, 0 }> C;

/**
 * @brief Farad
 */
static const Unit<Dimension<int>{ -2, -1, 4, 2, 0, 0, 0 }> F;

/**
 * @brief Henry
 */
static const Unit<Dimension<int>{ 2, 1, -2, -2, 0, 0, 0 }> H;

/**
 * @brief Ohm
 * 
 */
static const Unit<Dimension<int>{ 2, 1, -3, -2, 0, 0, 0 }> Ohm;

/**
 * @brief Siemens
 */
static const Unit<Dimension<int>{ -2, -1, 3, 2, 0, 0, 0 }> S;

/**
 * @brief Tesla
 */
static const Unit<Dimension<int>{ 0, 1, -2, -1, 0, 0, 0 }> T;

/**
 * @brief Volt
 */
static const Unit<Dimension<int>{ 2, 1, -3, -1, 0, 0, 0 }> V;

/**
 * @brief Weber
 */
static const Unit<Dimension<int>{ 2, 1, -2, -1, 0, 0, 0 }> Wb;

}

}
