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
template <class T, Dimension<int> E>
struct Quantity
{
    /**
     * @brief Value of the quantity in the specified units.
     */
    T value;

    /**
     * @brief Factor for each base unit to convert to the SI unit.
     */
    Dimension<T> factor = Dimension<T> { .L = 1, .M = 1, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1 };

    /**
     * @brief Convert the quantity to a different unit factor.
     * @param factor The target unit factor.
     * @return The converted quantity.
     */
    constexpr Quantity<T, E> cast(const Dimension<T>& factor) const
    {
        T scale = 1;
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
    constexpr T cast(const Quantity<T, E>& v) const
    {
        return (*this / v).value;
    }

    /**
     * @brief Calculate the square root of the quantity.
     * @return The square root of the quantity.
     * @note The square root is only defined for quantities with even exponents.
     */
    constexpr Quantity<T, E / 2> sqrt() const
    {
        static_assert(
            E.L % 2 == 0 && E.M % 2 == 0 && E.T % 2 == 0 && E.I % 2 == 0 && E.TH % 2 == 0 && E.N % 2 == 0 && E.J % 2 == 0,
            "Square root is only defined for quantities with even exponents."
        );
        return { .value = std::sqrt(this->value), .factor = this->factor };
    }

    template <class T2>
    constexpr operator Quantity<T2, E>() const
    {
        return Quantity<T2, E>{ .value = static_cast<T2>(this->value), .factor = static_cast<Dimension<T2>>(this->factor) };
    }
};

#pragma region Operators
template <class T, Dimension<int> E>
struct VectorQuantity;
#pragma region Add
template <class T, Dimension<int> E>
constexpr Quantity<T, E> operator+(const Quantity<T, E>& lhs, const Quantity<T, E>& rhs)
{
    Dimension<T> newFactor = max(lhs.factor, rhs.factor);
    return Quantity<T, E>{ .value = lhs.cast(newFactor).value + rhs.cast(newFactor).value, .factor = newFactor };
}

template <class T, Dimension<int> E>
constexpr Quantity<T, E>& operator+=(Quantity<T, E>& lhs, const Quantity<T, E>& rhs)
{
    lhs = lhs + rhs;
    return lhs;
}
#pragma endregion Add
#pragma region Sub
template <class T, Dimension<int> E>
constexpr Quantity<T, E> operator-(const Quantity<T, E>& lhs)
{
    return Quantity<T, E>{ .value = -lhs.value, .factor = lhs.factor };
}

template <class T, Dimension<int> E>
constexpr Quantity<T, E> operator-(const Quantity<T, E>& lhs, const Quantity<T, E>& rhs)
{
    return lhs + (-rhs);
}

template <class T, Dimension<int> E>
constexpr Quantity<T, E>& operator-=(Quantity<T, E>& lhs, const Quantity<T, E>& rhs)
{
    lhs = lhs - rhs;
    return lhs;
}
#pragma endregion Sub
#pragma region Mul
template <class T1, class T2, Dimension<int> E>
constexpr Quantity<T1, E> operator*(const Quantity<T1, E>& lhs, T2 rhs)
{
    return Quantity<T1, E>{ .value = lhs.value * rhs, .factor = lhs.factor };
}

template <class T1, class T2, Dimension<int> E>
constexpr Quantity<T2, E> operator*(T1 lhs, const Quantity<T2, E>& rhs)
{
    return rhs * lhs;
}

template <class T, Dimension<int> E1, Dimension<int> E2>
constexpr Quantity<T, E1 + E2> operator*(const Quantity<T, E1>& lhs, const Quantity<T, E2>& rhs)
{
    Dimension<T> newFactor = max(lhs.factor, rhs.factor);
    return Quantity<T, E1 + E2>{ .value = lhs.cast(newFactor).value * rhs.cast(newFactor).value, .factor = newFactor };
}

template <class T1, class T2, Dimension<int> E>
constexpr Quantity<T1, E>& operator*=(Quantity<T1, E>& lhs, T2 rhs)
{
    lhs = lhs * rhs;
    return lhs;
}
#pragma endregion Mul
#pragma region Div
template <class T1, class T2, Dimension<int> E>
constexpr Quantity<T1, E> operator/(const Quantity<T1, E>& lhs, T2 rhs)
{
    return lhs * (static_cast<T1>(1) / rhs);
}

template <class T1, class T2, Dimension<int> E>
constexpr Quantity<T2, -E> operator/(T1 lhs, const Quantity<T2, E>& rhs)
{
    return Quantity<T2, -E>{ .value = lhs / rhs.value, .factor = rhs.factor };
}

template <class T, Dimension<int> E1, Dimension<int> E2>
constexpr Quantity<T, E1 - E2> operator/(const Quantity<T, E1>& lhs, const Quantity<T, E2>& rhs)
{
    Dimension<T> newFactor = max(lhs.factor, rhs.factor);
    return Quantity<T, E1 - E2>{ .value = lhs.cast(newFactor).value / rhs.cast(newFactor).value, .factor = newFactor };
}

template <class T1, class T2, Dimension<int> E>
constexpr Quantity<T1, E>& operator/=(Quantity<T1, E>& lhs, T2 rhs)
{
    lhs = lhs / rhs;
    return lhs;
}
#pragma endregion Div
template <class T, Dimension<int> E>
constexpr bool operator<(const Quantity<T, E>& lhs, const Quantity<T, E>& rhs)
{
    return (lhs - rhs).value < 0;
}

template <class T, Dimension<int> E>
constexpr bool operator>(const Quantity<T, E>& lhs, const Quantity<T, E>& rhs)
{
    return (lhs - rhs).value > 0;
}

template <class T, Dimension<int> E>
constexpr std::ostream& operator<<(std::ostream& stream, const Quantity<T, E>& v)
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
