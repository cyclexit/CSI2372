cmake_minimum_required(VERSION 3.16.3)

project("lab10")

# file(GLOB SRCS *.cpp)

# add_definitions(-DENABLE_DEBUG)

add_executable(
    "TestPoker"
    "Poker.cpp"
    "TestPoker.cpp"
)

add_executable(
    "TestTexasHoldem"
    "Poker.cpp"
    "TexasHoldem.cpp"
    "TestTexasHoldem.cpp"
)
