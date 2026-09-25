cmake_minimum_required(VERSION 4.1)
project(Airport)

set(CMAKE_CXX_STANDARD 20)
include_directories(/opt/homebrew/include)
add_executable(Airport main.cpp
        Airports.h
        Airports.cpp
        AirportData.h
        AirportData.cpp
        Searching.cpp
        AdvancedFeatures.cpp
        AirportDisplay.h
        AirportDisplay.cpp
)
