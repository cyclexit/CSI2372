cmake_minimum_required(VERSION 3.16.3)

project("assignment4")

# file(GLOB SRCS *.cpp)

# add_definitions(-DENABLE_DEBUG)

add_executable(
    "TestGraph"
    "Graph.cpp"
    "TestGraph.cpp"
)

add_executable(
    "TestForest"
    "Graph.cpp"
    "Forest.cpp"
    "TestForest.cpp"
)

add_executable(
    "TestTree"
    "Graph.cpp"
    "Forest.cpp"
    "Tree.cpp"
    "TestTree.cpp"
)
