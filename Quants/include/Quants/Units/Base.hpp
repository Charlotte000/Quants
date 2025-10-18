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
static const Unit<Dimension<int>{ 1, 0, 0, 0, 0, 0, 0 }> m;

/**
 * @brief Kilometer
 */
static const Unit<Dimension<int>{ 1, 0, 0, 0, 0, 0, 0 }> km { .factor = Dimension<long long>{ .L = 1'000, .M = 1, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Kilogram
 */
static const Unit<Dimension<int>{ 0, 1, 0, 0, 0, 0, 0 }> kg;

/**
 * @brief Ton
 */
static const Unit<Dimension<int>{ 0, 1, 0, 0, 0, 0, 0 }> t { .factor = Dimension<long long>{ .L = 1, .M = 1'000, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Second
 */
static const Unit<Dimension<int>{ 0, 0, 1, 0, 0, 0, 0 }> s;

/**
 * @brief Minute
 */
static const Unit<Dimension<int>{ 0, 0, 1, 0, 0, 0, 0 }> minute { .factor = Dimension<long long>{ .L = 1, .M = 1, .T = 60, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Hour
 */
static const Unit<Dimension<int>{ 0, 0, 1, 0, 0, 0, 0 }> hr { .factor = Dimension<long long>{ .L = 1, .M = 1, .T = 3600, .I = 1, .TH = 1, .N = 1, .J = 1 } };

/**
 * @brief Kelvin
 */
static const Unit<Dimension<int>{ 0, 0, 0, 0, 1, 0, 0 }> K;

}

}
