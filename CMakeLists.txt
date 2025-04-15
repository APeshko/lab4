cmake_minimum_required(VERSION 3.10)
project(Lab4)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab4
    src/main.cpp
    include/util.cpp
    include/MyArray.h
    include/MyVector.h

target_include_directories(lab4 PUBLIC include)
