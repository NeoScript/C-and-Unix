cmake_minimum_required(VERSION 3.3)
project(testing)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(testing ${SOURCE_FILES})

#These were added in order to make OpenCV work out
FIND_PACKAGE(OpenCV REQUIRED opencv_core opencv_highgui opencv_imgproc opencv_videoio)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(testing ${OpenCV_LIBS})