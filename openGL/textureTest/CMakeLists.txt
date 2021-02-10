cmake_minimum_required(VERSION 3.5)

project(textureTest LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# To use GLAD and GLFW3, install libglfw3-dev
# and download glad from https://glad.dav1d.de/

set(OPENGL_LIB ${CMAKE_SOURCE_DIR}/../lib)

FILE(COPY
    ${OPENGL_LIB}/awesomeface.png
    ${OPENGL_LIB}/container.jpg
    ${OPENGL_LIB}/wall.jpg
    ${CMAKE_SOURCE_DIR}/shader.vs
    ${CMAKE_SOURCE_DIR}/shader.fs
    DESTINATION ${CMAKE_BINARY_DIR})

add_executable(${PROJECT_NAME}
    ${OPENGL_LIB}/glad/src/glad.c main.cpp
    ${OPENGL_LIB}/Shader.h
    ${OPENGL_LIB}/stb_image.h)

target_include_directories(${PROJECT_NAME}
PUBLIC
    ${OPENGL_LIB}/
    ${OPENGL_LIB}/glad/include
    ${OPENGL_LIB}/glm
)

target_link_libraries(${PROJECT_NAME} OpenGL glfw dl)
