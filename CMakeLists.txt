cmake_minimum_required(VERSION 3.10)
project(QuantsProject)

option(QUANTS_BUILD_EXAMPLE "Build example" OFF)

add_subdirectory(Quants)

if (QUANTS_BUILD_EXAMPLE)
    add_subdirectory(example)
endif()
