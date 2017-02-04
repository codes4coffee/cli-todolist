cmake_minimum_required(VERSION 3.6)
project(cli_todolist)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(cli_todolist ${SOURCE_FILES})