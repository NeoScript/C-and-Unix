cmake_minimum_required(VERSION 3.3)
project(program5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Card.h Deck.h Hand.h Deck.cpp Hand.cpp)
add_executable(program5 ${SOURCE_FILES})