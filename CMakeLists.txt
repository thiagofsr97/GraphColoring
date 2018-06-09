cmake_minimum_required(VERSION 3.10)
project(GraphColoring)

set(CMAKE_CXX_STANDARD 11)

include_directories(FileReader)
include_directories(Graph)
include_directories(Node)

add_executable(GraphColoring
        FileReader/FileReader.cpp
        FileReader/FileReader.h
        Graph/Graph.cpp
        Graph/Graph.h
        Node/Node.cpp
        Node/Node.h
        main.cpp)
