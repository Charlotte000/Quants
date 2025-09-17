cmake_minimum_required(VERSION 3.10)
project(Example)

set(CMAKE_CXX_STANDARD 20)

add_executable(
    ${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

# Quants
target_link_libraries(${PROJECT_NAME} PRIVATE Quants)
