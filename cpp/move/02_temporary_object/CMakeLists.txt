cmake_minimum_required(VERSION 3.5)

project(02_temporary_object LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(02_temporary_object main.cpp Point.h)
