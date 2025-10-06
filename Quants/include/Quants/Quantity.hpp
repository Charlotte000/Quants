/**
 * @file Quantity.hpp
 */
#pragma once

#include <math.h>
#include <ostream>
#include <stdexcept>

namespace Quants
{

/**
 * @brief Dimension of a physical quantity.
 * 
 * The dimension is represented as a vector of exponents of the base SI units:
 * Length (m), Mass (kg), Time (s), Electric current (A), Temperature (K), Amount of substance (mol), Luminous intensity (cd).
 * 
 * @tparam genType The type of the exponents, typically an integer type.
 */
template <class genType>
struct Dimension
{
    /**
     * @brief Length (m)
     */
    genType L;

    /**
     * @brief Mass (kg)
     */
    genType M;

    /**
     * @brief Time (s)
     */
    genType T;

    /**
     * @brief Electric current (A)
     */
    genType I;

    /**
     * @brief Temperature (K)
     */
    genType TH;

    /**
     * @brief Amount of substance (mol)
     */
    genType N;

    /**
     * @brief Luminous intensity (cd)
     */
    genType J;

    constexpr Dimension<genType> operator+(const Dimension<genType>& v) const
    {
        return
        {
            .L = this->L + v.L,
            .M = this->M + v.M,
            .T = this->T + v.T,
            .I = this->I + v.I,
            .TH = this->TH + v.TH,
            .N = this->N + v.N,
            .J = this->J + v.J,
        };
    }

    constexpr Dimension<genType> operator-() const
    {
        return
        {
            .L = -this->L,
            .M = -this->M,
            .T = -this->T,
            .I = -this->I,
            .TH = -this->TH,
            .N = -this->N,
            .J = -this->J,
        };
    }

    constexpr Dimension<genType> operator-(const Dimension<genType>& v) const
    {
        return *this + (-v);
    }

    constexpr Dimension<genType> operator/(genType v) const
    {
        return
        {
            .L = this->L / v,
            .M = this->M / v,
            .T = this->T / v,
            .I = this->I / v,
            .TH = this->TH / v,
            .N = this->N / v,
            .J = this->J / v,
        };
    }

    constexpr friend Dimension<genType> max(const Dimension<genType>& v1, const Dimension<genType>& v2)
    {
        return
        {
            .L = std::max(v1.L, v2.L),
            .M = std::max(v1.M, v2.M),
            .T = std::max(v1.T, v2.T),
            .I = std::max(v1.I, v2.I),
            .TH = std::max(v1.TH, v2.TH),
            .N = std::max(v1.N, v2.N),
            .J = std::max(v1.J, v2.J),
        };
    }
};

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
    Dimension<long long> factor = Dimension<long long> { .L = 1, .M = 1, .T = 1, .I = 1, .TH = 1, .N = 1, .J = 1, };

    /**
     * @brief Convert the quantity to a different unit factor.
     * @param factor The target unit factor.
     * @return The converted quantity.
     */
    Quantity<E> convert(const Dimension<long long>& factor) const
    {
        long double scale = 1;
        scale *= std::pow((long double)this->factor.L / factor.L, E.L);
        scale *= std::pow((long double)this->factor.M / factor.M, E.M);
        scale *= std::pow((long double)this->factor.T / factor.T, E.T);
        scale *= std::pow((long double)this->factor.I / factor.I, E.I);
        scale *= std::pow((long double)this->factor.TH / factor.TH, E.TH);
        scale *= std::pow((long double)this->factor.N / factor.N, E.N);
        scale *= std::pow((long double)this->factor.J / factor.J, E.J);
        return { .value = value * scale, .factor = factor };
    }

    /**
     * @brief Convert the quantity to the units of another quantity.
     * @param v The target quantity to convert to.
     * @return The conversion factor from this quantity to the target quantity.
     */
    long double convert(const Quantity<E>& v) const
    {
        return this->convert(v.factor).value / v.value;
    }

    /**
     * @brief Calculate the square root of the quantity.
     * @return The square root of the quantity.
     * @note The square root is only defined for quantities with even exponents.
     */
    Quantity<E / 2> sqrt() const
    {
        static_assert(
            E.L % 2 == 0 && E.M % 2 == 0 && E.T % 2 == 0 && E.I % 2 == 0 && E.TH % 2 == 0 && E.N % 2 == 0 && E.J % 2 == 0,
            "Square root is only defined for quantities with even exponents."
        );
        return { .value = std::sqrt(this->value), .factor = this->factor, };
    }

    Quantity<E> operator+(const Quantity<E>& v) const
    {
        Dimension<long long> newFactor = max(this->factor, v.factor);
        return { .value = this->convert(newFactor).value + v.convert(newFactor).value, .factor = newFactor, };
    }

    Quantity<E>& operator+=(const Quantity<E>& v)
    {
        *this = *this + v;
        return *this;
    }

    Quantity<E> operator-() const
    {
        return { .value = -this->value, .factor = this->factor, };
    }

    Quantity<E> operator-(const Quantity<E>& v) const
    {
        return *this + (-v);
    }

    Quantity<E>& operator-=(const Quantity<E>& v)
    {
        *this = *this - v;
        return *this;
    }

    Quantity<E> operator*(long double v) const
    {
        return { .value = this->value * v, .factor = this->factor, };
    }

    template <Dimension<int> E2>
    Quantity<E + E2> operator*(const Quantity<E2>& v) const
    {
        Dimension<long long> newFactor = max(this->factor, v.factor);
        return { .value = this->convert(newFactor).value * v.convert(newFactor).value, .factor = newFactor, };
    }

    Quantity<E>& operator*=(long double v)
    {
        *this = *this * v;
        return *this;
    }

    friend Quantity<E> operator*(long double v1, const Quantity<E>& v2)
    {
        return v2 * v1;
    }

    Quantity<E> operator/(long double v) const
    {
        return *this * (1 / v);
    }

    template <Dimension<int> E2>
    Quantity<E - E2> operator/(const Quantity<E2>& v) const
    {
        Dimension<long long> newFactor = max(this->factor, v.factor);
        return { .value = this->convert(newFactor).value / v.convert(newFactor).value, .factor = newFactor, };
    }

    Quantity<E>& operator/=(long double v)
    {
        *this = *this / v;
        return *this;
    }

    friend Quantity<-E> operator/(long double v1, const Quantity<E>& v2)
    {
        return { .value = v1 / v2.value, .factor = v2.factor, };
    }

    bool operator<(const Quantity<E>& v) const
    {
        return (*this - v).value < 0;
    }

    bool operator>(const Quantity<E>& v) const
    {
        return (*this - v).value > 0;
    }

    friend std::ostream& operator<<(std::ostream& stream, const Quantity<E>& v)
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
};

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
    Quantity<E> length() const
    {
        return (this->x * this->x + this->y * this->y + this->z * this->z).sqrt();
    }

    /**
     * @brief Convert the vector quantity to a different unit factor.
     * @param factor The target unit factor.
     * @return The converted vector quantity.
     */
    VectorQuantity<E> convert(const Dimension<long long>& factor) const
    {
        return { .x = this->x.convert(factor), .y = this->y.convert(factor), .z = this->z.convert(factor), };
    }

    VectorQuantity<E> operator+(const VectorQuantity<E>& v) const
    {
        return { .x = this->x + v.x, .y = this->y + v.y, .z = this->z + v.z, };
    }

    VectorQuantity<E>& operator+=(const VectorQuantity<E>& v)
    {
        *this = *this + v;
        return *this;
    }

    VectorQuantity<E> operator-() const
    {
        return { .x = -this->x, .y = -this->y, .z = -this->z, };
    }

    VectorQuantity<E> operator-(const VectorQuantity<E>& v) const
    {
        return *this + (-v);
    }

    VectorQuantity<E>& operator-=(const VectorQuantity<E>& v)
    {
        *this = *this - v;
        return *this;
    }

    VectorQuantity<E> operator*(long double v) const
    {
        return { .x = this->x * v, .y = this->y * v, .z = this->z * v, };
    }

    friend Quantity<E> operator*(long double v1, const VectorQuantity<E>& v2)
    {
        return v2 * v1;
    }

    VectorQuantity<E>& operator*=(long double v)
    {
        *this = *this * v;
        return *this;
    }

    VectorQuantity<E> operator/(long double v) const
    {
        return *this * (1 / v);
    }

    friend VectorQuantity<-E> operator/(long double v1, const VectorQuantity<E>& v2)
    {
        return { .x = v1 / v2.x, .y = v1 / v2.y, .z = v1 / v2.z, };
    }

    VectorQuantity<E>& operator/=(long double v)
    {
        *this = *this / v;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& stream, const VectorQuantity<E>& v)
    {
        stream << v.x << ' ' << v.y << ' ' << v.z;
        return stream;
    }
};

}
