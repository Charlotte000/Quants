/**
 * @file Base.hpp
 * @brief Fundamental units and type definitions.
 */
#pragma once

#include "Quants/VectorQuantity.hpp"

namespace Quants
{

using Length = Quantity<Dimension<int>{ 1, 0, 0, 0, 0, 0, 0 }>;
using Mass = Quantity<Dimension<int>{ 0, 1, 0, 0, 0, 0, 0 }>;
using Time = Quantity<Dimension<int>{ 0, 0, 1, 0, 0, 0, 0 }>;
using Temperature = Quantity<Dimension<int>{ 0, 0, 0, 0, 1, 0, 0 }>;

using Area = Quantity<Dimension<int>{ 2, 0, 0, 0, 0, 0, 0 }>;
using Volume = Quantity<Dimension<int>{ 3, 0, 0, 0, 0, 0, 0 }>;

using Length3 = VectorQuantity<Dimension<int>{ 1, 0, 0, 0, 0, 0, 0 }>;

namespace Units
{

/**
 * @brief Meter
 */
static const Length m { .value = 1 };

/**
 * @brief Kilometer
 */
static const Length km { .value = 1, .factor = Dimension<long double>{ .L = 1'000, .M = 1, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Kilogram
 */
static const Mass kg { .value = 1 };

/**
 * @brief Ton
 */
static const Mass t { .value = 1, .factor = Dimension<long double>{ .L = 1, .M = 1'000, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Second
 */
static const Time s { .value = 1 };

/**
 * @brief Minute
 */
static const Time minute { .value = 1, .factor = Dimension<long double>{ .L = 1, .M = 1, .T = 60, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Hour
 */
static const Time hr { .value = 1, .factor = Dimension<long double>{ .L = 1, .M = 1, .T = 3'600, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Kelvin
 */
static const Temperature K { .value = 1 };

}

}
