cmake_minimum_required(VERSION 2.8)
project( ColorReduction )
find_package( OpenCV REQUIRED )
add_executable( ColorReduction main.cpp )
target_link_libraries( ColorReduction ${OpenCV_LIBS} )