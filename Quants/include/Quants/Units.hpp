#pragma once

#include "Quants/Quantity.hpp"

namespace Quants::Units
{

/**
 * @brief Meter
 */
static const Length m { .value = 1, .Ls = 1 };

/**
 * @brief Kilometer
 */
static const Length km { .value = 1, .Ls = 1'000 };

/**
 * @brief Astronomical unit
 */
static const Length au { .value = 1, .Ls = 149'597'870'700 };

/**
 * @brief Light year
 */
static const Length ly { .value = 1, .Ls = 9'460'730'472'580'800 };

/**
 * @brief Parsec
 */
static const Length pc { .value = 1, .Ls = 30'856'775'812'800'000 };

/**
 * @brief Kilogram
 */
static const Mass kg { .value = 1, .Ms = 1 };

/**
 * @brief Ton
 */
static const Mass t { .value = 1, .Ms = 1'000 };

/**
 * @brief Second
 */
static const Time s { .value = 1, .Ts = 1 };

/**
 * @brief Minute
 */
static const Time minute { .value = 1, .Ts = 60 };

/**
 * @brief Hour
 */
static const Time hr { .value = 1, .Ts = 3600 };

/**
 * @brief Day
 */
static const Time day { .value = 1, .Ts = 86400 };

/**
 * @brief Year
 */
static const Time year { .value = 1, .Ts = 31'557'600 };

/**
 * @brief Newton. The measure of force
 */
static const Quantity<1, 1, -2> N = m * kg / (s * s);

/**
 * @brief Degree. 360 degrees = 1 turn. Denoted by °
 */
static const long double deg = M_PI / 180;

/**
 * @brief Arc minute. 60 arc minutes = 1 degree. Denoted by '
 */
static const long double arcMin = deg / 60;

/**
 * @brief Arc second. 60 arc seconds = 1 arc minute. Denoted by "
 * 
 */
static const long double arcSec = arcMin / 60;

/**
 * @brief Hour angle. 12 hours = 1 turn. Denoted by h
 */
static const long double hourAngle = M_PI / 12;

/**
 * @brief Minute angle. 60 minutes = 1 hour angle. Denoted by m
 */
static const long double minuteAngle = hourAngle / 60;

/**
 * @brief Second angle. 60 seconds = 1 minute angle. Denoted by s
 */
static const long double secondAngle = minuteAngle / 60;

}
