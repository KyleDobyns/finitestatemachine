cmake_minimum_required(VERSION 3.26)
project(finitestatemachine)

set(CMAKE_CXX_STANDARD 17)

add_executable(finitestatemachine main.cpp
        statemachine.cpp)
