cmake_minimum_required(VERSION 3.21)
project(biquad)

set(CMAKE_CXX_STANDARD 20)

add_executable(biquad main.cpp biquad.cpp biquad.h history.cpp history.h)
