cmake_minimum_required(VERSION 3.10)
project(Lab4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab4
    src/main.cpp
    src/utils.cpp
)

target_include_directories(lab4 PUBLIC include)
