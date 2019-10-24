cmake_minimum_required(VERSION 3.14)
project(UTpod)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(UTpod
        UTpod_driver.cpp
        UTpod.cpp
        UTpod.h
        Song.h)
