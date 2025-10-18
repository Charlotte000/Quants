/**
 * @file VectorQuantity.hpp
 */
#pragma once

#include "Quants/Quantity.hpp"

namespace Quants
{

/**
 * @brief A 3D vector quantity.
 * 
 * A vector quantity represents a physical measurement with direction.
 * 
 * @tparam E The dimensional exponents.
 */
template <Dimension<int> E>
struct VectorQuantity
{
    Quantity<E> x;
    Quantity<E> y;
    Quantity<E> z;

    /**
     * @brief Calculate the length (magnitude) of the vector.
     * @return The length of the vector.
     */
    constexpr Quantity<E> length() const
    {
        return (this->x * this->x + this->y * this->y + this->z * this->z).sqrt();
    }

    /**
     * @brief Convert the vector quantity to a different unit factor.
     * @param factor The target unit factor.
     * @return The converted vector quantity.
     */
    constexpr VectorQuantity<E> cast(const Dimension<long long>& factor) const
    {
        return { .x = this->x.cast(factor), .y = this->y.cast(factor), .z = this->z.cast(factor), };
    }
};

#pragma region Operators
#pragma region Add
template <Dimension<int> E>
constexpr VectorQuantity<E> operator+(const VectorQuantity<E>& lhs, const VectorQuantity<E>& rhs)
{
    return VectorQuantity<E>{ .x = lhs.x + rhs.x, .y = lhs.y + rhs.y, .z = lhs.z + rhs.z };
}

template <Dimension<int> E>
constexpr VectorQuantity<E>& operator+=(VectorQuantity<E>& lhs, const VectorQuantity<E>& rhs)
{
    lhs = lhs + rhs;
    return lhs;
}
#pragma endregion Add
#pragma region Sub
template <Dimension<int> E>
constexpr VectorQuantity<E> operator-(const VectorQuantity<E>& lhs)
{
    return VectorQuantity<E>{ .x = -lhs.x, .y = -lhs.y, .z = -lhs.z };
}

template <Dimension<int> E>
constexpr VectorQuantity<E> operator-(const VectorQuantity<E>& lhs, const VectorQuantity<E>& rhs)
{
    return lhs + (-rhs);
}

template <Dimension<int> E>
constexpr VectorQuantity<E>& operator-=(VectorQuantity<E>& lhs, const VectorQuantity<E>& rhs)
{
    lhs = lhs - rhs;
    return lhs;
}
#pragma endregion Sub
#pragma region Mul
template <Dimension<int> E>
constexpr VectorQuantity<E> operator*(const VectorQuantity<E>& lhs, long double rhs)
{
    return VectorQuantity<E>{ .x = lhs.x * rhs, .y = lhs.y * rhs, .z = lhs.z * rhs };
}

template <Dimension<int> E>
constexpr Quantity<E> operator*(long double lhs, const VectorQuantity<E>& rhs)
{
    return rhs * lhs;
}

template <Dimension<int> E1, Dimension<int> E2>
constexpr VectorQuantity<E1 + E2> operator*(const VectorQuantity<E1>& lhs, const Quantity<E2>& rhs)
{
    return VectorQuantity<E1 + E2>{ .x = lhs.x * rhs, .y = lhs.y * rhs, .z = lhs.z * rhs };
}

template <Dimension<int> E1, Dimension<int> E2>
constexpr Quantity<E1 + E2> operator*(const Quantity<E1>& lhs, const VectorQuantity<E2>& rhs)
{
    return rhs * lhs;
}

template <Dimension<int> E>
constexpr VectorQuantity<E>& operator*=(VectorQuantity<E>& lhs, long double rhs)
{
    lhs = lhs * rhs;
    return lhs;
}
#pragma endregion Mul
#pragma region Div
template <Dimension<int> E>
constexpr VectorQuantity<E> operator/(const VectorQuantity<E>& lhs, long double rhs)
{
    return lhs * (1 / rhs);
}

template <Dimension<int> E>
constexpr VectorQuantity<-E> operator/(long double lhs, const VectorQuantity<E>& rhs)
{
    return VectorQuantity<-E>{ .x = lhs / rhs.x, .y = lhs / rhs.y, .z = lhs / rhs.z };
}

template <Dimension<int> E1, Dimension<int> E2>
constexpr VectorQuantity<E1 - E2> operator/(const VectorQuantity<E1>& lhs, const Quantity<E2>& rhs)
{
    return lhs * (1 / rhs);
}

template <Dimension<int> E1, Dimension<int> E2>
constexpr VectorQuantity<E1 - E2> operator/(const Quantity<E1>& lhs, const VectorQuantity<E2>& rhs)
{
    return VectorQuantity<E1 - E2>{ .x = lhs / rhs.x, .y = lhs / rhs.y, .z = lhs / rhs.z };
}

template <Dimension<int> E>
constexpr VectorQuantity<E>& operator/=(VectorQuantity<E>& lhs, long double rhs)
{
    lhs = lhs / rhs;
    return lhs;
}
#pragma endregion Div
template <Dimension<int> E>
constexpr std::ostream& operator<<(std::ostream& stream, const VectorQuantity<E>& v)
{
    stream << v.x << ' ' << v.y << ' ' << v.z;
    return stream;
}
#pragma endregion Operators
}
