cmake_minimum_required(VERSION 3.27)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(src
        BinaryTree.cpp
        BinaryTree.h
        GenerateData.cpp
        main.cpp
        printStar.cpp
        Star.cpp
        Star.h)
