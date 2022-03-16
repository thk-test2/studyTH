cmake_minimum_required(VERSION 3.5)

project(2-2-write LANGUAGES C)

add_executable(2-2-write main.c)

set(CMAKE_INSTALL_PREFIX "/home/pi/projects/systemProgramming")
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
)
