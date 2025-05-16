cmake_minimum_required(VERSION 3.10)
project(ChatProject)

set(CMAKE_CXX_STANDARD 20)
include_directories(include)

add_executable(server src/server.cpp)
add_executable(client src/client.cpp)