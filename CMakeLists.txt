cmake_minimum_required(VERSION 3.5)
project(layoutbts)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


include_directories(/usr/local/include matplotlib-cpp)

set(SOURCE_FILES main.cpp helper.cpp helper.h matplotlib-cpp/matplotlibcpp.h)
add_executable(layoutbts ${SOURCE_FILES})

target_link_libraries(layoutbts python2.7 lept tesseract opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs pthread)
