cmake_minimum_required(VERSION 2.8)
project(hw07)
add_definitions(-std=c++03)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
aux_source_directory(. DIR_SRCS)
add_executable(hw07 ${DIR_SRCS} )
target_link_libraries(hw07 ${OpenCV_LIBS})