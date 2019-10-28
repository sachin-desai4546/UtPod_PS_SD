cmake_minimum_required(VERSION 3.14)
project(UtPod)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(UtPod
        UtPodDriver.cpp
        UtPod.cpp
        UtPod.h
        Song.h
        Song.cpp)
