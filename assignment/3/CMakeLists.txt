cmake_minimum_required(VERSION 3.16.3)

project("assignment3")

file(GLOB SRCS *.cpp)

# add_definitions(-DENABLE_DEBUG)

add_executable("TestGraph" ${SRCS})
