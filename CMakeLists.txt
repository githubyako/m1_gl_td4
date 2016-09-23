cmake_minimum_required(VERSION 2.6)
project(gl_td3)

add_executable(gl_td3 person.cpp main.cpp)
add_definitions(-std=c++11 -O3)
install(TARGETS gl_td3 RUNTIME DESTINATION bin)
