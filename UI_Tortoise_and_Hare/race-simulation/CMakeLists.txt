cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)

project(race-simulation)

set(PROJECT_NAME "race-simulation")

find_package(GTest REQUIRED)

include(GoogleTest)

enable_testing()

include_directories(mocks)

add_subdirectory(common)
add_subdirectory(race)
add_subdirectory(track)

add_executable(${PROJECT_NAME} main.cpp RaceSimulation.cpp)

target_link_libraries(${PROJECT_NAME} rs::race rs::track)
