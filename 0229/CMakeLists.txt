cmake_minimum_required(VERSION 2.8.3)
project(0229)

set(CMAKE_CXX_STANDARD 11)
include(ExternalProject)
ExternalProject_Add(aaa
        URL https://github.com/Itseez/opencv/archive/3.2.0.zip
        URL_MD5 bfc6a261eb069b709bcfe7e363ef5899
        SOURCE_DIR ${PROJECT_SOURCE_DIR}/src
        UPDATE_COMMAND ""
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND ""
)

add_executable(0229 main.cpp)