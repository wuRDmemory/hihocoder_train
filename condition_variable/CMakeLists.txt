cmake_minimum_required(VERSION 3.10)
project(condition_variable)

set(CMAKE_CXX_STANDARD 11)

add_executable(condition_variable main.cpp)
target_link_libraries(condition_variable pthread)