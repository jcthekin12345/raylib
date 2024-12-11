cmake_minimum_required(VERSION 3.30)
project(LanguageBook)
set(CMAKE_CXX_STANDARD 20)

add_executable(LanguageBook main.cpp
        l.cpp
        l.h)
find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(main PRIVATE nlohmann_json::nlohmann_json)
