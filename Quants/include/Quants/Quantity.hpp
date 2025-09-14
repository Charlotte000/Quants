#pragma once

#include <math.h>
#include <ostream>
#include <stdexcept>

namespace Quants
{

template <int Lp, int Mp, int Tp>
struct Quantity
{
    long double value;
    long long Ls = 1, Ms = 1, Ts = 1;

    Quantity<Lp, Mp, Tp> convert(long long Ls, long long Ms, long long Ts) const
    {
        long double factor = 1;
        factor *= std::pow((long double)this->Ls / Ls, Lp);
        factor *= std::pow((long double)this->Ms / Ms, Mp);
        factor *= std::pow((long double)this->Ts / Ts, Tp);

        return { value * factor, Ls, Ms, Ts };
    }

    long double convert(const Quantity<Lp, Mp, Tp>& v) const
    {
        return this->convert(v.Ls, v.Ms, v.Ts).value / v.value;
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

    Quantity<Lp / 2, Mp / 2, Tp / 2> sqrt() const
    {
        static_assert(Lp % 2 == 0);
        return { std::sqrt(this->value), this->Ls, this->Ms, this->Ts };
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

template <int Lp = 0, int Mp = 0, int Tp = 0>
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

    VectorQuantity<Lp, Mp, Tp> operator-(const VectorQuantity<Lp, Mp, Tp>& v) const
    {
        return { this->x - v.x, this->y - v.y, this->z - v.z };
    }

    VectorQuantity<Lp, Mp, Tp> operator-() const
    {
        return { -this->x, -this->y, -this->z };
    }

    VectorQuantity<Lp, Mp, Tp> operator*(double v) const
    {
        return { this->x * v, this->y * v, this->z * v };
    }

    friend Quantity<Lp, Mp, Tp> operator*(long double v1, const VectorQuantity<Lp, Mp, Tp>& v2)
    {
        return { v1 * v2.x, v1 * v2.y, v1 * v2.z };
    }

    friend VectorQuantity<-Lp, -Mp, -Tp> operator/(long double v1, const VectorQuantity<Lp, Mp, Tp>& v2)
    {
        return { v1 / v2.x, v1 / v2.y, v1 / v2.z };
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