/**
 * @file Dimension.hpp
 */
#pragma once

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

    template <class genType2>
    constexpr operator Dimension<genType2>() const
    {
        return Dimension<genType2>
        {
            .L  = static_cast<genType2>(this->L),
            .M  = static_cast<genType2>(this->M),
            .T  = static_cast<genType2>(this->T),
            .I  = static_cast<genType2>(this->I),
            .TH = static_cast<genType2>(this->TH),
            .N  = static_cast<genType2>(this->N),
            .J  = static_cast<genType2>(this->J),
        };
    }
};

#pragma region Operators
template <class genType>
constexpr Dimension<genType> operator+(const Dimension<genType>& lhs, const Dimension<genType>& rhs)
{
    return Dimension<genType>
    {
        .L  = lhs.L  + rhs.L,
        .M  = lhs.M  + rhs.M,
        .T  = lhs.T  + rhs.T,
        .I  = lhs.I  + rhs.I,
        .TH = lhs.TH + rhs.TH,
        .N  = lhs.N  + rhs.N,
        .J  = lhs.J  + rhs.J,
    };
}

template <class genType>
constexpr Dimension<genType> operator-(const Dimension<genType>& lhs)
{
    return Dimension<genType>
    {
        .L  = -lhs.L,
        .M  = -lhs.M,
        .T  = -lhs.T,
        .I  = -lhs.I,
        .TH = -lhs.TH,
        .N  = -lhs.N,
        .J  = -lhs.J,
    };
}

template <class genType>
constexpr Dimension<genType> operator-(const Dimension<genType>& lhs, const Dimension<genType>& rhs)
{
    return lhs + (-rhs);
}

template <class genType>
constexpr Dimension<genType> operator/(const Dimension<genType>& lhs, genType rhs)
{
    return
    {
        .L  = lhs.L  / rhs,
        .M  = lhs.M  / rhs,
        .T  = lhs.T  / rhs,
        .I  = lhs.I  / rhs,
        .TH = lhs.TH / rhs,
        .N  = lhs.N  / rhs,
        .J  = lhs.J  / rhs,
    };
}

template <class genType>
constexpr Dimension<genType> max(const Dimension<genType>& lhs, const Dimension<genType>& rhs)
{
    return
    {
        .L  = std::max(lhs.L,  rhs.L),
        .M  = std::max(lhs.M,  rhs.M),
        .T  = std::max(lhs.T,  rhs.T),
        .I  = std::max(lhs.I,  rhs.I),
        .TH = std::max(lhs.TH, rhs.TH),
        .N  = std::max(lhs.N,  rhs.N),
        .J  = std::max(lhs.J,  rhs.J),
    };
}
#pragma endregion Operators
}
