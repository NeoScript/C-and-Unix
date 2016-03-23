cmake_minimum_required(VERSION 3.3)
project(testing)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(testing ${SOURCE_FILES})

#These were added in order to make OpenCV work out
FIND_PACKAGE(OpenCV REQUIRED core highgui imgproc)
target_link_libraries(testing ${OpenCV_LIBS})