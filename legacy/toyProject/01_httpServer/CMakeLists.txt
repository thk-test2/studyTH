
cmake_minimum_required(VERSION 3.0)

project(HttpServer)

add_executable(Server server.cpp)
add_executable(Client client.cpp)

# project(server)
# set(SOURCE server.cpp)
# add_executable(${PROJECT_NAME} ${SOURCE})