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
     * @brief Normalize the vector quantity.
     * @return Normalized direction vector.
     */
    constexpr glm::vec<3, long double> normalize() const
    {
        return glm::normalize(this->cast(Unit<E>{ .factor = max(max(this->x.factor, this->y.factor), this->z.factor) }));
    }

    /**
     * @brief Convert the vector quantity to a different unit factor.
     * @param factor The target unit factor.
     * @return The converted vector quantity.
     */
    constexpr glm::vec<3, long double> cast(const Unit<E>& v) const
    {
        return glm::vec<3, long double>(this->x.cast(v).value, this->y.cast(v).value, this->z.cast(v).value);
    }
};

#pragma region Operators
#pragma region +
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
#pragma endregion +
#pragma region -
template <Dimension<int> E>
constexpr VectorQuantity<E> operator-(const VectorQuantity<E>& val)
{
    return VectorQuantity<E>{ .x = -val.x, .y = -val.y, .z = -val.z };
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
#pragma endregion -
#pragma region *
template <Dimension<int> E>
constexpr VectorQuantity<E> operator*(long double lhs, const VectorQuantity<E>& rhs)
{
    return VectorQuantity<E>{ .x = lhs * rhs.x, .y = lhs * rhs.y, .z = lhs * rhs.z };
}

template <Dimension<int> E>
constexpr VectorQuantity<E> operator*(const VectorQuantity<E>& lhs, long double rhs)
{
    return rhs * lhs;
}

template <Dimension<int> E1, Dimension<int> E2>
constexpr VectorQuantity<E1 + E2> operator*(const Quantity<E1>& lhs, const VectorQuantity<E2>& rhs)
{
    return VectorQuantity<E1 + E2>{ .x = lhs * rhs.x, .y = lhs * rhs.y, .z = lhs * rhs.z };
}

template <Dimension<int> E1, Dimension<int> E2>
constexpr VectorQuantity<E1 + E2> operator*(const VectorQuantity<E1>& lhs, const Quantity<E2>& rhs)
{
    return rhs * lhs;
}

template <Dimension<int> E>
constexpr VectorQuantity<E>& operator*=(VectorQuantity<E>& lhs, long double rhs)
{
    lhs = lhs * rhs;
    return lhs;
}
#pragma endregion *
#pragma region /
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
constexpr VectorQuantity<E1 - E2> operator/(const Quantity<E1>& lhs, const VectorQuantity<E2>& rhs)
{
    return VectorQuantity<E1 - E2>{ .x = lhs / rhs.x, .y = lhs / rhs.y, .z = lhs / rhs.z };
}

template <Dimension<int> E1, Dimension<int> E2>
constexpr VectorQuantity<E1 - E2> operator/(const VectorQuantity<E1>& lhs, const Quantity<E2>& rhs)
{
    return VectorQuantity<E1 - E2>{ .x = lhs.x / rhs, .y = lhs.y / rhs, .z = lhs.z / rhs };
}

template <Dimension<int> E>
constexpr VectorQuantity<E>& operator/=(VectorQuantity<E>& lhs, long double rhs)
{
    lhs = lhs / rhs;
    return lhs;
}
#pragma endregion /
template <Dimension<int> E>
constexpr std::ostream& operator<<(std::ostream& stream, const VectorQuantity<E>& v)
{
    stream << "x=" << v.x << " y=" << v.y << " z=" << v.z;
    return stream;
}
#pragma endregion Operators


}
