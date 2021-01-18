cmake_minimum_required(VERSION 3.5)

project(modelTest LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# To use GLAD and GLFW3, install libglfw3-dev
# and download glad from https://glad.dav1d.de/

add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/glad/src/glad.c main.cpp)

target_include_directories(${PROJECT_NAME}
PUBLIC
    ${CMAKE_SOURCE_DIR}/glad/include
)

target_link_libraries(${PROJECT_NAME} OpenGL glfw dl)

