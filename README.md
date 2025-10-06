# Quants

A C++ 20 library for handling physical quantities with units.

This library provides a toolkit for defining and manipulating physical quantities with associated units, ensuring dimensional correctness through compile-time checks.

Units are represented as a combination of base dimensions (length, mass, time, electric current, temperature, amount of substance and luminous intensity) raised to integer powers. The library supports basic arithmetic operations, unit conversions, and vector quantities.

Every value is represented as follows: $$value * (L_f * m)^{L_p} * (M_f * kg)^{M_p} * (T_f * s)^{T_p} * (I_f * A)^{I_p} * (TH_f * K)^{TH_p} * (N_f * mol)^{N_p} * (J_f * cd)^{J_p}$$,
where L_f, M_f, T_f, I_f, TH_f, N_f, J_f are the base unit factors for length, mass, time, electric current, temperature, amount of substance and luminous intensity respectively, and L_p, M_p, T_p, I_p, TH_p, N_p, J_p are their corresponding integer powers.

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
The project contains an `example` folder with various usage examples.

Here's a simple example of how to use the Quants library:
```cpp
#include "Quants/Units.hpp"

using namespace Quants;
using u = Quants::Units;

Length distance = 5.0 * u::m;
Time time = 2.0 * u::s;
Velocity speed = distance / time; // Results in 2.5 meters/second
```

## Documentation
The documentation is generated using Doxygen and can be found in the `docs` folder. To generate the documentation, run:
```bash
doxygen
```
