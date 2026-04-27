cmake_minimum_required(VERSION 3.10)
project(Test)

include(FetchContent)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(
    ${PROJECT_NAME}
    Math.cpp
    VectorMath.cpp
    Conversion.cpp
    BasicFormulas.cpp
)

# Quants
target_link_libraries(${PROJECT_NAME} PRIVATE Quants)

# Gtest v1.17.0
FetchContent_Declare(
    gtest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.17.0
)
FetchContent_MakeAvailable(gtest)
target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest_main)
gtest_discover_tests(${PROJECT_NAME})
