/**
 * @file Electromagnetism.hpp
 * @brief Units and type definitions for electromagnetism.
 */
#pragma once

#include "Quants/Quantity.hpp"

namespace Quants
{

/**
 * @brief Q
 * 
 * The force per unit electric field strength
 */
template <class T = long double>
using Charge = Quantity<T, Dimension<int>{ 0, 0, 1, 1, 0, 0, 0 }>;

/**
 * @brief I
 * 
 * Rate of flow of electrical charge per unit time
 */
template <class T = long double>
using Current = Quantity<T, Dimension<int>{ 0, 0, 0, 1, 0, 0, 0 }>;

/**
 * @brief J
 * 
 * Electric current per unit cross-section area
 */
template <class T = long double>
using CurrentDensity = Quantity<T, Dimension<int>{ -2, 0, 0, 1, 0, 0, 0 }>;

/**
 * @brief φ
 * 
 * Energy required to move a unit charge through an electric field from a reference point
 */
template <class T = long double>
using Potential = Quantity<T, Dimension<int>{ 2, 1, -3, -1, 0, 0, 0 }>;

/**
 * @brief R
 * 
 * Electric potential per unit electric current
 */
template <class T = long double>
using Resistance = Quantity<T, Dimension<int>{ 2, 1, -3, -2, 0, 0, 0 }>;

/**
 * @brief Z
 * 
 * Resistance to an alternating current of a given frequency, including effect on phase
 */
template <class T = long double>
using Impedance = Quantity<T, Dimension<int>{ 2, 1, -3, -2, 0, 0, 0 }>;

/**
 * @brief ρ
 * 
 * Bulk property equivalent of electrical resistance
 */
template <class T = long double>
using Resistivity = Quantity<T, Dimension<int>{ 3, 1, -3, -2, 0, 0, 0 }>;

/**
 * @brief C
 * 
 * Stored charge per unit electric potential
 */
template <class T = long double>
using Capacitance = Quantity<T, Dimension<int>{ -2, -1, 4, 2, 0, 0, 0 }>;

/**
 * @brief Φ_E
 * 
 * The total electric field that crosses a given surface
 */
template <class T = long double>
using ElectricFlux = Quantity<T, Dimension<int>{ 3, 1, -3, -1, 0, 0, 0 }>;

/**
 * @brief E
 * 
 * Strength of the electric field
 */
template <class T = long double>
using ElectricFieldStrength = Quantity<T, Dimension<int>{ 1, 1, -3, -1, 0, 0, 0 }>;

/**
 * @brief D
 * 
 * Strength of the electric displacement
 */
template <class T = long double>
using ElectricDisplacementField = Quantity<T, Dimension<int>{ -2, 0, 1, 1, 0, 0, 0 }>;

/**
 * @brief ε
 * 
 * Measure for how the polarization of a material is affected by the application of an external electric field
 */
template <class T = long double>
using Permittivity = Quantity<T, Dimension<int>{ -3, -1, 4, 2, 0, 0, 0 }>;

/**
 * @brief p
 * 
 * Measure of the separation of equal and opposite electric charges
 */
template <class T = long double>
using ElectricDipoleMoment = Quantity<T, Dimension<int>{ 1, 0, 1, 1, 0, 0, 0 }>;

/**
 * @brief G
 * 
 * Measure for how easily current flows through a material
 */
template <class T = long double>
using Conductance = Quantity<T, Dimension<int>{ -2, -1, 3, 2, 0, 0, 0 }>;

/**
 * @brief σ
 * 
 * Measure of a material's ability to conduct an electric current
 */
template <class T = long double>
using Conductivity = Quantity<T, Dimension<int>{ -3, -1, 3, 2, 0, 0, 0 }>;

/**
 * @brief B
 * 
 * Measure for the strength of the magnetic field
 */
template <class T = long double>
using MagneticFluxDensity = Quantity<T, Dimension<int>{ 0, 1, -2, -1, 0, 0, 0 }>;

/**
 * @brief Φ
 * 
 * Measure of magnetism, taking account of the strength and the extent of a magnetic field
 */
template <class T = long double>
using MagneticFlux = Quantity<T, Dimension<int>{ 2, 1, -2, -1, 0, 0, 0 }>;

/**
 * @brief H
 * 
 * Strength of a magnetic field
 */
template <class T = long double>
using MagneticFieldStrength = Quantity<T, Dimension<int>{ -1, 0, 0, 1, 0, 0, 0 }>;

/**
 * @brief R
 * 
 * Resistance to the flow of magnetic flux
 */
template <class T = long double>
using Reluctance = Quantity<T, Dimension<int>{ -2, -1, 2, 2, 0, 0, 0 }>;

/**
 * @brief P
 * 
 * The inverse of reluctance
 */
template <class T = long double>
using Permeance = Quantity<T, Dimension<int>{ 2, 1, -2, -2, 0, 0, 0 }>;

/**
 * @brief L
 * 
 * Magnetic flux generated per unit current through a circuit
 */
template <class T = long double>
using Inductance = Quantity<T, Dimension<int>{ 2, 1, -2, -2, 0, 0, 0 }>;

/**
 * @brief μ
 * 
 * Measure for how the magnetization of material is affected by the application of an external magnetic field
 */
template <class T = long double>
using Permeability = Quantity<T, Dimension<int>{ 1, 1, -2, -2, 0, 0, 0 }>;

/**
 * @brief m
 * 
 * The component of magnetic strength and orientation that can be represented by an equivalent magnetic dipole
 */
template <class T = long double>
using MagneticDipoleMoment = Quantity<T, Dimension<int>{ 2, 0, 0, 1, 0, 0, 0 }>;

/**
 * @brief M
 * 
 * Amount of magnetic moment per unit volume
 */
template <class T = long double>
using Magnetization = Quantity<T, Dimension<int>{ -1, 0, 0, 1, 0, 0, 0 }>;

namespace Units
{

/**
 * @brief Milliampere
 */
static const Current<long double> mA { .value = 1, .factor = Dimension<long double>{ .L = 1, .M = 1, .T = 1, .I = 0.001, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Ampere
 */
static const Current<long double> A { .value = 1 };

/**
 * @brief Coulomb
 */
static const Charge<long double> C { .value = 1 };

/**
 * @brief Pico-farad
 */
static const Capacitance<long double> pF { .value = 1, .factor = Dimension<long double>{ .L = 1, .M = 1e12, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Nano-farad
 */
static const Capacitance<long double> nF { .value = 1, .factor = Dimension<long double>{ .L = 1, .M = 1e9, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Micro-farad
 */
static const Capacitance<long double> uF { .value = 1, .factor = Dimension<long double>{ .L = 1, .M = 1e6, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Milli-farad
 */
static const Capacitance<long double> mF { .value = 1, .factor = Dimension<long double>{ .L = 1, .M = 1'000, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Farad
 */
static const Capacitance<long double> F { .value = 1 };

/**
 * @brief Henry
 */
static const Inductance<long double> H { .value = 1 };

/**
 * @brief Ohm
 */
static const Resistance<long double> Ohm { .value = 1 };

/**
 * @brief Kilo-ohm
 */
static const Resistance<long double> kOhm { .value = 1, .factor = Dimension<long double>{ .L = 1, .M = 1000, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Siemens
 */
static const Conductance<long double> S { .value = 1 };

/**
 * @brief Tesla
 */
static const MagneticFluxDensity<long double> T { .value = 1 };

/**
 * @brief Milli-volt
 */
static const Potential<long double> mV { .value = 1, .factor = Dimension<long double>{ .L = 1, .M = 0.001, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Volt
 */
static const Potential<long double> V { .value = 1 };

/**
 * @brief Kilo-volt
 */
static const Potential<long double> kV { .value = 1, .factor = Dimension<long double>{ .L = 1, .M = 1000, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Weber
 */
static const MagneticFlux<long double> Wb { .value = 1 };

}

}
