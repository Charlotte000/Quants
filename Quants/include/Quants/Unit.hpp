/**
 * @file Unit.hpp
 */
#pragma once

#include <math.h>
#include <ostream>
#include <stdexcept>

#include <glm/glm.hpp>

#include "Quants/Quantity.hpp"
#include "Quants/Dimension.hpp"
#include "Quants/VectorQuantity.hpp"

namespace Quants
{

/**
 * @brief A physical unit.
 * 
 * A unit defines the scaling factors and exponents for each dimension of a physical quantity.
 * 
 * @tparam E The dimensional exponents.
 */
template <Dimension<int> E>
struct Unit
{
    /**
     * @brief The scaling factors for each dimension.
     * 
     * The factor defines how the unit scales for each base dimension from the SI system.
     */
    Dimension<long long> factor = Dimension<long long> { .L = 1, .M = 1, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1, };

    /**
     * @brief Convert the unit to a different unit.
     * @param unit The target unit.
     * @return The scaling factor to convert to the target unit.
     */
    constexpr long double cast(const Unit<E>& unit) const
    {
        long double scale = 1;
        scale *= std::pow((long double)this->factor.L / unit.factor.L, E.L);
        scale *= std::pow((long double)this->factor.M / unit.factor.M, E.M);
        scale *= std::pow((long double)this->factor.T / unit.factor.T, E.T);
        scale *= std::pow((long double)this->factor.I / unit.factor.I, E.I);
        scale *= std::pow((long double)this->factor.TH / unit.factor.TH, E.TH);
        scale *= std::pow((long double)this->factor.N / unit.factor.N, E.N);
        scale *= std::pow((long double)this->factor.J / unit.factor.J, E.J);
        return scale;
    }
};

#pragma region Operators
template <Dimension<int> E>
struct Quantity;

template <Dimension<int> E>
struct VectorQuantity;

#pragma region *
template <Dimension<int> E>
constexpr Quantity<E> operator*(long double lhs, const Unit<E>& rhs)
{
    return Quantity<E>{ .value = lhs, .unit = rhs };
}

template <Dimension<int> E>
constexpr Quantity<E> operator*(const Unit<E>& lhs, long double rhs)
{
    return rhs * lhs;
}

template <Dimension<int> E1, Dimension<int> E2>
constexpr Unit<E1 + E2> operator*(const Unit<E1>& lhs, const Unit<E2>& rhs)
{
    return Unit<E1 + E2>{ .factor = max(lhs.factor, rhs.factor) };
}

template <Dimension<int> E>
constexpr VectorQuantity<E> operator*(const glm::vec<3, long double>& lhs, const Unit<E>& rhs)
{
    return VectorQuantity<E>{ lhs.x * rhs, lhs.y * rhs, lhs.z * rhs };
}

template <Dimension<int> E>
constexpr VectorQuantity<E> operator*(const Unit<E>& lhs, const glm::vec<3, long double>& rhs)
{
    return rhs * lhs;
}
#pragma endregion *
#pragma region /
template <Dimension<int> E>
constexpr Quantity<-E> operator/(long double lhs, const Unit<E>& rhs)
{
    return Quantity<-E>{ .value = lhs, .unit = Unit<-E>{ .factor = rhs.factor } };
}

template <Dimension<int> E>
constexpr Quantity<E> operator/(const Unit<E>& lhs, long double rhs)
{
    return lhs * (1 / rhs);
}

template <Dimension<int> E1, Dimension<int> E2>
constexpr Unit<E1 - E2> operator/(const Unit<E1>& lhs, const Unit<E2>& rhs)
{
    return Unit<E1 - E2>{ .factor = max(lhs.factor, rhs.factor) };
}
#pragma endregion
template <Dimension<int> E>
constexpr std::ostream& operator<<(std::ostream& stream, const Unit<E>& v)
{
    if (E.L != 0)
    {
        stream << "(" << v.factor.L << " m)";
        if (E.L != 1) stream << "^" << E.L;
    }

    if (E.M != 0)
    {
        stream << " (" << v.factor.M << " kg)";
        if (E.M != 1) stream << "^" << E.M;
    }

    if (E.T != 0)
    {
        stream << " (" << v.factor.T << " s)";
        if (E.T != 1) stream << "^" << E.T;
    }

    if (E.I != 0)
    {
        stream << " (" << v.factor.I << " A)";
        if (E.I != 1) stream << "^" << E.I;
    }

    if (E.TH != 0)
    {
        stream << " (" << v.factor.TH << " K)";
        if (E.TH != 1) stream << "^" << E.TH;
    }

    if (E.N != 0)
    {
        stream << " (" << v.factor.N << " mol)";
        if (E.N != 1) stream << "^" << E.N;
    }

    if (E.J != 0)
    {
        stream << " (" << v.factor.J << " cd)";
        if (E.J != 1) stream << "^" << E.J;
    }

    return stream;
}
#pragma endregion Operators

}
