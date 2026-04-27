cmake_minimum_required(VERSION 3.10)
project(QuantsProject)

option(QUANTS_BUILD_EXAMPLE "Build example" OFF)
option(QUANTS_BUILD_TESTS   "Build tests"   OFF)

add_subdirectory(Quants)

if (QUANTS_BUILD_TESTS)
    include(CTest)
    include(GoogleTest)

    enable_testing()
    add_subdirectory(tests)
endif()

if (QUANTS_BUILD_EXAMPLE)
    add_subdirectory(example)
endif()
