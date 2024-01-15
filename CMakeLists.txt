cmake_minimum_required(VERSION 3.26)
project(pile_generique)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(pile_generique
        main.cpp
        pile.h)
