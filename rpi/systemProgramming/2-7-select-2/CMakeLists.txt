cmake_minimum_required(VERSION 3.5)

project(2-7-select-2 LANGUAGES C)

add_executable(2-7-select-2 main.c)

set(CMAKE_INSTALL_PREFIX "/home/pi/projects/systemProgramming")
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
)
