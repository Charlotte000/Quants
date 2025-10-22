/**
 * @file Base.hpp
 * @brief Fundamental units and type definitions.
 */
#pragma once

#include "Quants/VectorQuantity.hpp"

namespace Quants
{

template <class T = long double>
using Length = Quantity<T, Dimension<int>{ 1, 0, 0, 0, 0, 0, 0 }>;

template <class T = long double>
using Mass = Quantity<T, Dimension<int>{ 0, 1, 0, 0, 0, 0, 0 }>;

template <class T = long double>
using Time = Quantity<T, Dimension<int>{ 0, 0, 1, 0, 0, 0, 0 }>;

template <class T = long double>
using Temperature = Quantity<T, Dimension<int>{ 0, 0, 0, 0, 1, 0, 0 }>;

template <class T = long double>
using Area = Quantity<T, Dimension<int>{ 2, 0, 0, 0, 0, 0, 0 }>;

template <class T = long double>
using Volume = Quantity<T, Dimension<int>{ 3, 0, 0, 0, 0, 0, 0 }>;

template <class T = long double>
using Length3 = VectorQuantity<T, Dimension<int>{ 1, 0, 0, 0, 0, 0, 0 }>;

namespace Units
{

/**
 * @brief Nanometer
 */
static const Length<long double> nm { .value = 1, .factor = Dimension<long double>{ .L = 0.000'000'001, .M = 1, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1 } };


/**
 * @brief Millimeter
 */
static const Length<long double> mm { .value = 1, .factor = Dimension<long double>{ .L = 0.001, .M = 1, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Meter
 */
static const Length<long double> m { .value = 1 };

/**
 * @brief Kilometer
 */
static const Length<long double> km { .value = 1, .factor = Dimension<long double>{ .L = 1'000, .M = 1, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Kilogram
 */
static const Mass<long double> kg { .value = 1 };

/**
 * @brief Ton
 */
static const Mass<long double> t { .value = 1, .factor = Dimension<long double>{ .L = 1, .M = 1'000, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Millisecond
 */
static const Time<long double> ms { .value = 1, .factor = Dimension<long double>{ .L = 1, .M = 1, .T = 0.001, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Second
 */
static const Time<long double> s { .value = 1 };

/**
 * @brief Minute
 */
static const Time<long double> minute { .value = 1, .factor = Dimension<long double>{ .L = 1, .M = 1, .T = 60, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Hour
 */
static const Time<long double> hr { .value = 1, .factor = Dimension<long double>{ .L = 1, .M = 1, .T = 3'600, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Kelvin
 */
static const Temperature<long double> K { .value = 1 };

}

}
