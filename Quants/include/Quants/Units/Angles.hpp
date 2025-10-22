/**
 * @file Angles.hpp
 * @brief Common angle units. Although angles are dimensionless, these units are provided for convenience.
 */
#pragma once

#include <math.h>

namespace Quants::Units
{

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