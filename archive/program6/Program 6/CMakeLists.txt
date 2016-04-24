cmake_minimum_required(VERSION 3.4)
project(Program_6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Message.cpp
    Message.h
    Server.cpp
    Server.h
    SuperServer.cpp
    SuperServer.h
    User.cpp
    User.h)

add_executable(Program_6 ${SOURCE_FILES})