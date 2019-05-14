cmake_minimum_required(VERSION 2.8.11)
project(LongestSubstring)

set(CMAKE_CXX_STANDARD 11)

add_executable(test_app main.cpp)

# add_custom_command(TARGET test_app
#                     COMMAND ${CMAKE_COMMAND} POST_BUILD -E cp $<TARGET_FILE: test_app> ${PROJECT_SOURCE_DIR}/tt_app)
