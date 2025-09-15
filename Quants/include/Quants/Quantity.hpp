/**
 * @file Quantity.hpp
 * @brief Defines a template-based system for handling physical quantities with units in C++.
 * 
 * This file provides a `Quantity` template that allows for the representation and manipulation
 * of physical quantities with dimensional analysis. It supports basic arithmetic operations,
 * unit conversions, and vector quantities.
 */
#pragma once

#include <math.h>
#include <ostream>
#include <stdexcept>

namespace Quants
{

/**
 * @brief Represents a physical quantity with dimensional analysis.
 * 
 * Each quantity is defined by its exponents in length (L), mass (M), and time (T).
 * Every value is represented as follows: value * (Ls * m)^Lp * (Ms * kg)^Mp * (Ts * s)^Tp
 * 
 * @tparam Lp The Length exponent.
 * @tparam Mp The Mass exponent.
 * @tparam Tp The Time exponent.
 */
template <int Lp, int Mp, int Tp>
struct Quantity
{
    /**
     * @brief The numerical value of the quantity.
     */
    long double value;

    /**
     * @brief The length scale in meters.
     */
    long long Ls = 1;

    /**
     * @brief The mass scale in kilograms.
     */
    long long Ms = 1;

    /**
     * @brief The time scale in seconds.
     */
    long long Ts = 1;

    /**
     * @brief Covert the quantity to different scales.
     * @param Ls Length scale in meters.
     * @param Ms Mass scale in kilograms.
     * @param Ts Time scale in seconds.
     * @return A new Quantity object converted to the specified scales.
     */
    Quantity<Lp, Mp, Tp> convert(long long Ls, long long Ms, long long Ts) const
    {
        long double factor = 1;
        factor *= std::pow((long double)this->Ls / Ls, Lp);
        factor *= std::pow((long double)this->Ms / Ms, Mp);
        factor *= std::pow((long double)this->Ts / Ts, Tp);

        return { value * factor, Ls, Ms, Ts };
    }

    /**
     * @brief Convert the quantity to a given quantity's scale.
     * @param v The quantity whose scale to convert to.
     * @return The numerical value of this quantity in the scale of v.
     */
    long double convert(const Quantity<Lp, Mp, Tp>& v) const
    {
        return this->convert(v.Ls, v.Ms, v.Ts).value / v.value;
    }

    /**
     * @brief Calculate the square root of the quantity.
     * @return A new Quantity object representing the square root.
     * @note This function is only valid if Lp, Mp, and Tp are even numbers.
     */
    Quantity<Lp / 2, Mp / 2, Tp / 2> sqrt() const
    {
        static_assert(Lp % 2 == 0 && Mp % 2 == 0 && Tp % 2 == 0, "Square root is only defined for quantities with even exponents.");
        return { std::sqrt(this->value), this->Ls, this->Ms, this->Ts };
    }

    Quantity<Lp, Mp, Tp> operator+(const Quantity<Lp, Mp, Tp>& v) const
    {
        long long lS = std::max(this->Ls, v.Ls);
        long long mS = std::max(this->Ms, v.Ms);
        long long tS = std::max(this->Ts, v.Ts);

        return { this->convert(lS, mS, tS).value + v.convert(lS, mS, tS).value, lS, mS, tS };
    }

    Quantity<Lp, Mp, Tp>& operator+=(const Quantity<Lp, Mp, Tp>& v)
    {
        *this = *this + v;
        return *this;
    }

    Quantity<Lp, Mp, Tp> operator-(const Quantity<Lp, Mp, Tp>& v) const
    {
        long long lS = std::max(this->Ls, v.Ls);
        long long mS = std::max(this->Ms, v.Ms);
        long long tS = std::max(this->Ts, v.Ts);

        return { this->convert(lS, mS, tS).value - v.convert(lS, mS, tS).value, lS, mS, tS };
    }

    Quantity<Lp, Mp, Tp> operator-() const
    {
        return { -this->value, this->Ls, this->Ms, this->Ts };
    }

    Quantity<Lp, Mp, Tp>& operator-=(const Quantity<Lp, Mp, Tp>& v)
    {
        *this = *this - v;
        return *this;
    }

    Quantity<Lp, Mp, Tp> operator*(long double v) const
    {
        return { this->value * v, this->Ls, this->Ms, this->Ts };
    }

    template <int Lp2, int Mp2, int Tp2>
    Quantity<Lp + Lp2, Mp + Mp2, Tp + Tp2> operator*(const Quantity<Lp2, Mp2, Tp2>& v) const
    {
        long long lS = std::max(this->Ls, v.Ls);
        long long mS = std::max(this->Ms, v.Ms);
        long long tS = std::max(this->Ts, v.Ts);

        return { this->convert(lS, mS, tS).value * v.convert(lS, mS, tS).value, lS, mS, tS };
    }

    Quantity<Lp, Mp, Tp>& operator*=(long double v)
    {
        *this = *this * v;
        return *this;
    }

    friend Quantity<Lp, Mp, Tp> operator*(long double v1, const Quantity<Lp, Mp, Tp>& v2)
    {
        return { v1 * v2.value, v2.Ls, v2.Ms, v2.Ts };
    }

    Quantity<Lp, Mp, Tp> operator/(long double v) const
    {
        return { this->value / v, this->Ls, this->Ms, this->Ts };
    }

    template <int Lp2, int Mp2, int Tp2>
    Quantity<Lp - Lp2, Mp - Mp2, Tp - Tp2> operator/(const Quantity<Lp2, Mp2, Tp2>& v) const
    {
        long long lS = std::max(this->Ls, v.Ls);
        long long mS = std::max(this->Ms, v.Ms);
        long long tS = std::max(this->Ts, v.Ts);

        return { this->convert(lS, mS, tS).value / v.convert(lS, mS, tS).value, lS, mS, tS };
    }

    Quantity<Lp, Mp, Tp>& operator/=(long double v)
    {
        *this = *this / v;
        return *this;
    }

    friend Quantity<-Lp, -Mp, -Tp> operator/(long double v1, const Quantity<Lp, Mp, Tp>& v2)
    {
        return { v1 / v2.value, v2.Ls, v2.Ms, v2.Ts };
    }

    bool operator<(const Quantity<Lp, Mp, Tp>& v) const
    {
        return (*this - v).value < 0;
    }

    bool operator>(const Quantity<Lp, Mp, Tp>& v) const
    {
        return (*this - v).value > 0;
    }

    friend std::ostream& operator<<(std::ostream& stream, const Quantity<Lp, Mp, Tp>& v)
    {
        stream << v.value;
        if (Lp) stream << " (" << v.Ls << " m)^" << Lp;
        if (Mp) stream << " (" << v.Ms << " kg)^" << Mp;
        if (Tp) stream << " (" << v.Ts << " s)^" << Tp;

        return stream;
    }
};

/**
 * @brief Represents a 3D vector of physical quantities.
 * @tparam Lp The Length exponent.
 * @tparam Mp The Mass exponent.
 * @tparam Tp The Time exponent.
 */
template <int Lp, int Mp, int Tp>
struct VectorQuantity
{
    Quantity<Lp, Mp, Tp> x;

    Quantity<Lp, Mp, Tp> y;

    Quantity<Lp, Mp, Tp> z;

    Quantity<Lp, Mp, Tp> length() const
    {
        return (this->x * this->x + this->y * this->y + this->z * this->z).sqrt();
    }

    VectorQuantity<Lp, Mp, Tp> convert(long long Ls, long long Ms, long long Ts) const
    {
        return { this->x.convert(Ls, Ms, Ts), this->y.convert(Ls, Ms, Ts), this->z.convert(Ls, Ms, Ts) };
    }

    VectorQuantity<Lp, Mp, Tp> operator+(const VectorQuantity<Lp, Mp, Tp>& v) const
    {
        return { this->x + v.x, this->y + v.y, this->z + v.z };
    }

    VectorQuantity<Lp, Mp, Tp>& operator+=(const VectorQuantity<Lp, Mp, Tp>& v)
    {
        this->x += v.x;
        this->y += v.y;
        this->z += v.z;
        return *this;
    }

    VectorQuantity<Lp, Mp, Tp> operator-(const VectorQuantity<Lp, Mp, Tp>& v) const
    {
        return { this->x - v.x, this->y - v.y, this->z - v.z };
    }

    VectorQuantity<Lp, Mp, Tp> operator-() const
    {
        return { -this->x, -this->y, -this->z };
    }

    VectorQuantity<Lp, Mp, Tp>& operator-=(const VectorQuantity<Lp, Mp, Tp>& v)
    {
        this->x -= v.x;
        this->y -= v.y;
        this->z -= v.z;
        return *this;
    }

    VectorQuantity<Lp, Mp, Tp> operator*(long double v) const
    {
        return { this->x * v, this->y * v, this->z * v };
    }

    friend Quantity<Lp, Mp, Tp> operator*(long double v1, const VectorQuantity<Lp, Mp, Tp>& v2)
    {
        return { v1 * v2.x, v1 * v2.y, v1 * v2.z };
    }

    VectorQuantity<Lp, Mp, Tp>& operator*=(long double v)
    {
        this->x *= v;
        this->y *= v;
        this->z *= v;
        return *this;
    }

    VectorQuantity<Lp, Mp, Tp> operator/(long double v) const
    {
        return { this->x / v, this->y / v, this->z / v };
    }

    friend VectorQuantity<-Lp, -Mp, -Tp> operator/(long double v1, const VectorQuantity<Lp, Mp, Tp>& v2)
    {
        return { v1 / v2.x, v1 / v2.y, v1 / v2.z };
    }

    VectorQuantity<Lp, Mp, Tp>& operator/=(long double v)
    {
        this->x /= v;
        this->y /= v;
        this->z /= v;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& stream, const VectorQuantity<Lp, Mp, Tp>& v)
    {
        stream << v.x << ' ' << v.y << ' ' << v.z;
        return stream;
    }
};

using Length = Quantity<1, 0, 0>;
using Mass = Quantity<0, 1, 0>;
using Time = Quantity<0, 0, 1>;
using Velocity = Quantity<1, 0, -1>;

using Acceleration = Quantity<1, 0, -2>;

using Length3 = VectorQuantity<1, 0, 0>;
using Velocity3 = VectorQuantity<1, 0, -1>;

};