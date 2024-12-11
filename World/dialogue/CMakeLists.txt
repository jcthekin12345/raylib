cmake_minimum_required(VERSION 3.30)
project(dialogue)

set(CMAKE_CXX_STANDARD 23)

add_executable(dialogue main.cpp
        Dialogue.h
        JLifeEngine.h
)
