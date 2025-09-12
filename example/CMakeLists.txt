cmake_minimum_required(VERSION 3.10)
project(App)

set(CMAKE_CXX_STANDARD 17)

add_executable(
    ${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

# Quants
target_link_libraries(${PROJECT_NAME} PRIVATE Quants)
