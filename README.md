# Quants

A C++ 17 library for handling physical quantities with units.

This library provides a toolkit for defining and manipulating physical quantities with associated units, ensuring dimensional correctness through compile-time checks.

Units are represented as a combination of base dimensions (length, mass, time) raised to integer powers. The library supports basic arithmetic operations, unit conversions, and vector quantities.

Every value is represented as follows: $$value * (L_s * m)^{L_p} * (M_s * kg)^{M_p} * (T_s * s)^{T_p}$$,
where `Ls`, `Ms`, and `Ts` are the base units for length, mass, and time respectively, and `Lp`, `Mp`, and `Tp` are their corresponding integer powers.

This library also includes 3 dimensional vector quantities and operations on them which can be useful in physics simulations and calculations.

## Features
- Template-based compile-time system for defining and manipulating physical quantities with units.
- Dimensional analysis to ensure correctness of operations.
- Supports basic arithmetic operations and unit conversions.
- Includes vector quantities and operations.
- Predefined physical constants and standard units.

## Installation
To use Quants in your project, include CMake file in your CMakeLists.txt:

```cmake
add_subdirectory(path/to/Quants)
target_link_libraries(your_target PRIVATE Quants)
```

## Usage
Here's a simple example of how to use the Quants library:

```cpp
#include "Quants/Units.hpp"

using namespace Quants;
using u = Quants::Units;

Length distance = 5.0 * u::m;
Time time = 2.0 * u::s;
Velocity speed = distance / time; // Results in 2.5 meters/second
```
