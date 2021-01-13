cmake_minimum_required(VERSION 3.5)

project(openglTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(openglTest main.cpp
    ${CMAKE_SOURCE_DIR}/src/glad.c)

#list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

# To use GLAD and GLFW3, install libglfw3-dev
# and download glad from https://glad.dav1d.de/
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

target_include_directories(${PROJECT_NAME}
PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME} OpenGL glfw3)

message(STATUS ${GLFW3_INCLUDE_DIR})
