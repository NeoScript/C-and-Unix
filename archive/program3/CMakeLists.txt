cmake_minimum_required(VERSION 3.3)
project(program3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp PatientAccount.cpp PatientAccount.h Surgery.h Pharmacy.h Charge.h)
add_executable(program3 ${SOURCE_FILES})