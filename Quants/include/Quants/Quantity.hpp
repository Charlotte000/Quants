/**
 * @file Quantity.hpp
 */
#pragma once

#include <math.h>
#include <ostream>
#include <stdexcept>

#include "Quants/Dimension.hpp"
#include "Quants/VectorQuantity.hpp"

namespace Quants
{

/**
 * @brief A physical quantity with a value and a dimension.
 * 
 * A quantity represents a physical measurement, such as length, mass, time, etc.
 * It consists of a numerical value and a dimension that defines its physical nature that can be expressed in terms of the base SI units as follows:
 * value * (factor.L * m)^E.L * (factor.M * kg)^E.M * (factor.T * s)^E.T * (factor.I * A)^E.I * (factor.TH * K)^E.TH * (factor.N * mol)^E.N * (factor.J * cd)^E.J
 * 
 * @tparam E The dimensional exponents.
 */
template <Dimension<int> E>
struct Quantity
{
    /**
     * @brief Value of the quantity in the specified units.
     */
    long double value;

    /**
     * @brief Factor for each base unit to convert to the SI unit.
     */
    Dimension<long double> factor = Dimension<long double> { .L = 1, .M = 1, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1, };

    /**
     * @brief Convert the quantity to a different unit factor.
     * @param factor The target unit factor.
     * @return The converted quantity.
     */
    constexpr Quantity<E> cast(const Dimension<long double>& factor) const
    {
        long double scale = 1;
        scale *= std::pow(this->factor.L / factor.L, E.L);
        scale *= std::pow(this->factor.M / factor.M, E.M);
        scale *= std::pow(this->factor.T / factor.T, E.T);
        scale *= std::pow(this->factor.I / factor.I, E.I);
        scale *= std::pow(this->factor.TH / factor.TH, E.TH);
        scale *= std::pow(this->factor.N / factor.N, E.N);
        scale *= std::pow(this->factor.J / factor.J, E.J);
        return { .value = value * scale, .factor = factor };
    }

    /**
     * @brief Convert the quantity to the units of another quantity.
     * @param v The target quantity to convert to.
     * @return The conversion factor from this quantity to the target quantity.
     */
    constexpr long double cast(const Quantity<E>& v) const
    {
        return (*this / v).value;
    }

    /**
     * @brief Calculate the square root of the quantity.
     * @return The square root of the quantity.
     * @note The square root is only defined for quantities with even exponents.
     */
    constexpr Quantity<E / 2> sqrt() const
    {
        static_assert(
            E.L % 2 == 0 && E.M % 2 == 0 && E.T % 2 == 0 && E.I % 2 == 0 && E.TH % 2 == 0 && E.N % 2 == 0 && E.J % 2 == 0,
            "Square root is only defined for quantities with even exponents."
        );
        return { .value = std::sqrt(this->value), .factor = this->factor, };
    }
};

#pragma region Operators
template <Dimension<int> E>
struct VectorQuantity;
#pragma region Add
template <Dimension<int> E>
constexpr Quantity<E> operator+(const Quantity<E>& lhs, const Quantity<E>& rhs)
{
    Dimension<long double> newFactor = max(lhs.factor, rhs.factor);
    return Quantity<E>{ .value = lhs.cast(newFactor).value + rhs.cast(newFactor).value, .factor = newFactor };
}

template <Dimension<int> E>
constexpr Quantity<E>& operator+=(Quantity<E>& lhs, const Quantity<E>& rhs)
{
    lhs = lhs + rhs;
    return lhs;
}
#pragma endregion Add
#pragma region Sub
template <Dimension<int> E>
constexpr Quantity<E> operator-(const Quantity<E>& lhs)
{
    return Quantity<E>{ .value = -lhs.value, .factor = lhs.factor };
}

template <Dimension<int> E>
constexpr Quantity<E> operator-(const Quantity<E>& lhs, const Quantity<E>& rhs)
{
    return lhs + (-rhs);
}

template <Dimension<int> E>
constexpr Quantity<E>& operator-=(Quantity<E>& lhs, const Quantity<E>& rhs)
{
    lhs = lhs - rhs;
    return lhs;
}
#pragma endregion Sub
#pragma region Mul
template <Dimension<int> E>
constexpr Quantity<E> operator*(const Quantity<E>& lhs, long double rhs)
{
    return Quantity<E>{ .value = lhs.value * rhs, .factor = lhs.factor };
}

template <Dimension<int> E>
constexpr Quantity<E> operator*(long double lhs, const Quantity<E>& rhs)
{
    return rhs * lhs;
}

template <Dimension<int> E1, Dimension<int> E2>
constexpr Quantity<E1 + E2> operator*(const Quantity<E1>& lhs, const Quantity<E2>& rhs)
{
    Dimension<long double> newFactor = max(lhs.factor, rhs.factor);
    return Quantity<E1 + E2>{ .value = lhs.cast(newFactor).value * rhs.cast(newFactor).value, .factor = newFactor };
}

template <Dimension<int> E>
constexpr Quantity<E>& operator*=(Quantity<E>& lhs, long double rhs)
{
    lhs = lhs * rhs;
    return lhs;
}
#pragma endregion Mul
#pragma region Div
template <Dimension<int> E>
constexpr Quantity<E> operator/(const Quantity<E>& lhs, long double rhs)
{
    return lhs * (1 / rhs);
}

template <Dimension<int> E>
constexpr Quantity<-E> operator/(long double lhs, const Quantity<E>& rhs)
{
    return Quantity<-E>{ .value = lhs / rhs.value, .factor = rhs.factor };
}

template <Dimension<int> E1, Dimension<int> E2>
constexpr Quantity<E1 - E2> operator/(const Quantity<E1>& lhs, const Quantity<E2>& rhs)
{
    Dimension<long double> newFactor = max(lhs.factor, rhs.factor);
    return Quantity<E1 - E2>{ .value = lhs.cast(newFactor).value / rhs.cast(newFactor).value, .factor = newFactor };
}

template <Dimension<int> E>
constexpr Quantity<E>& operator/=(Quantity<E>& lhs, long double rhs)
{
    lhs = lhs / rhs;
    return lhs;
}
#pragma endregion Div
template <Dimension<int> E>
constexpr bool operator<(const Quantity<E>& lhs, const Quantity<E>& rhs)
{
    return (lhs - rhs).value < 0;
}

template <Dimension<int> E>
constexpr bool operator>(const Quantity<E>& lhs, const Quantity<E>& rhs)
{
    return (lhs - rhs).value > 0;
}

template <Dimension<int> E>
constexpr std::ostream& operator<<(std::ostream& stream, const Quantity<E>& v)
{
    stream << v.value;
    if (E.L) stream << " (" << v.factor.L << " m)^" << E.L;
    if (E.M) stream << " (" << v.factor.M << " kg)^" << E.M;
    if (E.T) stream << " (" << v.factor.T << " s)^" << E.T;
    if (E.I) stream << " (" << v.factor.I << " A)^" << E.I;
    if (E.TH) stream << " (" << v.factor.TH << " K)^" << E.TH;
    if (E.N) stream << " (" << v.factor.N << " mol)^" << E.N;
    if (E.J) stream << " (" << v.factor.J << " cd)^" << E.J;
    return stream;
}
#pragma endregion Operators
}
