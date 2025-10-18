/**
 * @file Quantity.hpp
 */
#pragma once

#include "Quants/Unit.hpp"

namespace Quants
{

/**
 * @brief A physical quantity with dimensions.
 * 
 * A quantity represents a measurable physical property, defined by its value and unit.
 * 
 * Each quantity can be represented as follows:
 * value * (unit.factor.L * m)^(E.L) * (unit.factor.M * kg)^(E.M) * (unit.factor.T * s)^(E.T) * (unit.factor.I * A)^(E.I) * (unit.factor.TH * K)^(E.TH) * (unit.factor.N * mol)^(E.N) * (unit.factor.J * cd)^(E.J)
 * 
 * @tparam E The dimensional exponents.
 */
template <Dimension<int> E>
struct Quantity
{
    /**
     * @brief The numerical value of the quantity.
     */
    long double value;

    /**
     * @brief The unit of the quantity.
     * 
     * The unit defines the scaling factor and exponents for each dimension.
     */
    Unit<E> unit;

    /**
     * @brief Convert the quantity to a different unit.
     * @param unit The target unit.
     * @return The converted quantity.
     */
    constexpr Quantity<E> cast(const Unit<E>& unit) const
    {
        return Quantity<E>{ .value = this->value * this->unit.cast(unit), .unit = unit };
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
        return Quantity<E / 2>{ .value = std::sqrt(this->value), .unit = Unit<E / 2>{ .factor = this->unit.factor } };
    }
};

#pragma region Operators
#pragma region +
template <Dimension<int> E>
constexpr Quantity<E> operator+(const Quantity<E>& lhs, const Quantity<E>& rhs)
{
    Unit<E> newUnit{ .factor = max(lhs.unit.factor, rhs.unit.factor) };
    return Quantity<E>{ .value = lhs.cast(newUnit).value + rhs.cast(newUnit).value, .unit = newUnit };
}

template <Dimension<int> E>
constexpr Quantity<E>& operator+=(Quantity<E>& lhs, const Quantity<E>& rhs)
{
    lhs = lhs + rhs;
    return lhs;
}
#pragma endregion +
#pragma region -
template <Dimension<int> E>
constexpr Quantity<E> operator-(const Quantity<E>& v)
{
    return Quantity<E>{ .value = -v.value, .unit = v.unit };
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
#pragma endregion -
template <Dimension<int> E>
constexpr Quantity<E> operator*(long double lhs, const Quantity<E>& rhs)
{
    return Quantity<E>{ .value = rhs.value * lhs, .unit = rhs.unit };
}

template <Dimension<int> E>
constexpr Quantity<E> operator*(const Quantity<E>& lhs, long double rhs)
{
    return rhs * lhs;
}

template <Dimension<int> E1, Dimension<int> E2>
constexpr Quantity<E1 + E2> operator*(const Quantity<E1>& lhs, const Quantity<E2>& rhs)
{
    Dimension<long long> newFactor = max(lhs.unit.factor, rhs.unit.factor);
    return Quantity<E1 + E2>
    {
        .value = lhs.cast(Unit<E1>{ .factor = newFactor }).value * rhs.cast(Unit<E2>{ .factor = newFactor }).value,
        .unit = Unit<E1 + E2>{ .factor = newFactor }
    };
}

template <Dimension<int> E>
constexpr Quantity<E>& operator*=(Quantity<E>& lhs, long double rhs)
{
    lhs = lhs * rhs;
    return lhs;
}

template <Dimension<int> E>
constexpr Quantity<E> operator/(const Quantity<E>& lhs, long double rhs)
{
    return lhs * (1 / rhs);
}

template <Dimension<int> E1, Dimension<int> E2>
constexpr Quantity<E1 - E2> operator/(const Quantity<E1>& lhs, const Quantity<E2>& rhs)
{
    Dimension<long long> newFactor = max(lhs.unit.factor, rhs.unit.factor);
    return Quantity<E1 - E2>
    {
        .value = lhs.cast(Unit<E1>{ .factor = newFactor }).value / rhs.cast(Unit<E2>{ .factor = newFactor }).value,
        .unit = Unit<E1 - E2>{ .factor = newFactor }
    };
}

template <Dimension<int> E>
constexpr Quantity<E>& operator/=(const Quantity<E>& lhs, long double rhs)
{
    lhs = lhs / rhs;
    return lhs;
}

template <Dimension<int> E>
constexpr Quantity<-E> operator/(long double lhs, const Quantity<E>& rhs)
{
    return Quantity<-E>{ .value = lhs / rhs.value, .unit = rhs.unit };
}

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
    stream << v.value << ' ' << v.unit;
    return stream;
}
#pragma endregion Operators

}
