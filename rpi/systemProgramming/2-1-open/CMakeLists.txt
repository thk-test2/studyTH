cmake_minimum_required(VERSION 3.5)

project(2-1-open LANGUAGES C)

add_executable(2-1-open main.c)

set(CMAKE_INSTALL_PREFIX "/home/pi/projects/systemProgramming")
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
)
