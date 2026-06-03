cmake_minimum_required(VERSION 3.15)

project(PEParser)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(PeParser main.cpp
                        parse.cpp)
