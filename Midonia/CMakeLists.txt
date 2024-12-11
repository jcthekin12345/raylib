cmake_minimum_required(VERSION 3.30)
project(Midonia)

set(CMAKE_CXX_STANDARD 20)

add_executable(Midonia main.cpp
        lib/character.h
        lib/lifeEngine.h
        lib/time.h
)
