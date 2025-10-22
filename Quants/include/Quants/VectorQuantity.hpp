/**
 * @file VectorQuantity.hpp
 */
#pragma once

#include "Quants/Quantity.hpp"

namespace Quants
{

template <class T, Dimension<int> E>
struct Quantity;

/**
 * @brief A 3D vector quantity.
 * 
 * A vector quantity represents a physical measurement with direction.
 * 
 * @tparam E The dimensional exponents.
 */
template <class T, Dimension<int> E>
struct VectorQuantity
{
    Quantity<T, E> x;
    Quantity<T, E> y;
    Quantity<T, E> z;

    /**
     * @brief Calculate the length (magnitude) of the vector.
     * @return The length of the vector.
     */
    constexpr Quantity<T, E> length() const
    {
        return (this->x * this->x + this->y * this->y + this->z * this->z).sqrt();
    }

    /**
     * @brief Convert the vector quantity to a different unit factor.
     * @param factor The target unit factor.
     * @return The converted vector quantity.
     */
    constexpr VectorQuantity<T, E> cast(const Dimension<T>& factor) const
    {
        return VectorQuantity<T, E>{ .x = this->x.cast(factor), .y = this->y.cast(factor), .z = this->z.cast(factor) };
    }

    template <class T2>
    constexpr operator VectorQuantity<T2, E>() const
    {
        return VectorQuantity<T2, E> { .x = static_cast<T2>(this->x), .y = static_cast<T2>(this->y), .z = static_cast<T2>(this->z) };
    }
};

#pragma region Operators
#pragma region Add
template <class T, Dimension<int> E>
constexpr VectorQuantity<T, E> operator+(const VectorQuantity<T, E>& lhs, const VectorQuantity<T, E>& rhs)
{
    return VectorQuantity<T, E>{ .x = lhs.x + rhs.x, .y = lhs.y + rhs.y, .z = lhs.z + rhs.z };
}

template <class T, Dimension<int> E>
constexpr VectorQuantity<T, E>& operator+=(VectorQuantity<T, E>& lhs, const VectorQuantity<T, E>& rhs)
{
    lhs = lhs + rhs;
    return lhs;
}
#pragma endregion Add
#pragma region Sub
template <class T, Dimension<int> E>
constexpr VectorQuantity<T, E> operator-(const VectorQuantity<T, E>& lhs)
{
    return VectorQuantity<T, E>{ .x = -lhs.x, .y = -lhs.y, .z = -lhs.z };
}

template <class T, Dimension<int> E>
constexpr VectorQuantity<T, E> operator-(const VectorQuantity<T, E>& lhs, const VectorQuantity<T, E>& rhs)
{
    return lhs + (-rhs);
}

template <class T, Dimension<int> E>
constexpr VectorQuantity<T, E>& operator-=(VectorQuantity<T, E>& lhs, const VectorQuantity<T, E>& rhs)
{
    lhs = lhs - rhs;
    return lhs;
}
#pragma endregion Sub
#pragma region Mul
template <class T1, class T2, Dimension<int> E>
constexpr VectorQuantity<T1, E> operator*(const VectorQuantity<T1, E>& lhs, T2 rhs)
{
    return VectorQuantity<T1, E>{ .x = lhs.x * rhs, .y = lhs.y * rhs, .z = lhs.z * rhs };
}

template <class T1, class T2, Dimension<int> E>
constexpr Quantity<T2, E> operator*(T1 lhs, const VectorQuantity<T2, E>& rhs)
{
    return rhs * lhs;
}

template <class T, Dimension<int> E1, Dimension<int> E2>
constexpr VectorQuantity<T, E1 + E2> operator*(const VectorQuantity<T, E1>& lhs, const Quantity<T, E2>& rhs)
{
    return VectorQuantity<T, E1 + E2>{ .x = lhs.x * rhs, .y = lhs.y * rhs, .z = lhs.z * rhs };
}

template <class T, Dimension<int> E1, Dimension<int> E2>
constexpr Quantity<T, E1 + E2> operator*(const Quantity<T, E1>& lhs, const VectorQuantity<T, E2>& rhs)
{
    return rhs * lhs;
}

template <class T1, class T2, Dimension<int> E>
constexpr VectorQuantity<T1, E>& operator*=(VectorQuantity<T1, E>& lhs, T2 rhs)
{
    lhs = lhs * rhs;
    return lhs;
}
#pragma endregion Mul
#pragma region Div
template <class T1, class T2, Dimension<int> E>
constexpr VectorQuantity<T1, E> operator/(const VectorQuantity<T1, E>& lhs, T2 rhs)
{
    return lhs * (static_cast<T1>(1) / rhs);
}

template <class T1, class T2, Dimension<int> E>
constexpr VectorQuantity<T2, -E> operator/(T1 lhs, const VectorQuantity<T2, E>& rhs)
{
    return VectorQuantity<T2, -E>{ .x = lhs / rhs.x, .y = lhs / rhs.y, .z = lhs / rhs.z };
}

template <class T, Dimension<int> E1, Dimension<int> E2>
constexpr VectorQuantity<T, E1 - E2> operator/(const VectorQuantity<T, E1>& lhs, const Quantity<T, E2>& rhs)
{
    return lhs * (1 / rhs);
}

template <class T, Dimension<int> E1, Dimension<int> E2>
constexpr VectorQuantity<T, E1 - E2> operator/(const Quantity<T, E1>& lhs, const VectorQuantity<T, E2>& rhs)
{
    return VectorQuantity<T, E1 - E2>{ .x = lhs / rhs.x, .y = lhs / rhs.y, .z = lhs / rhs.z };
}

template <class T1, class T2, Dimension<int> E>
constexpr VectorQuantity<T1, E>& operator/=(VectorQuantity<T1, E>& lhs, T2 rhs)
{
    lhs = lhs / rhs;
    return lhs;
}
#pragma endregion Div
template <class T, Dimension<int> E>
constexpr std::ostream& operator<<(std::ostream& stream, const VectorQuantity<T, E>& v)
{
    stream << v.x << ' ' << v.y << ' ' << v.z;
    return stream;
}
#pragma endregion Operators
}
