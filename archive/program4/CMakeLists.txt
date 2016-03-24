cmake_minimum_required(VERSION 3.3)
project(program4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp FuelGauge.cpp FuelGauge.h Odometer.cpp Odometer.h)
add_executable(program4 ${SOURCE_FILES})