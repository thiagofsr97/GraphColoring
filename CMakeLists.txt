cmake_minimum_required(VERSION 3.12)
project(GraphColoring)

set(CMAKE_CXX_STANDARD 11)

include_directories("Construction Heuristic")
include_directories(FileReader)
include_directories(Graph)
include_directories(Node)
include_directories(PermutationHeuristic)

add_executable(GraphColoring
        "Construction Heuristic/Dsatur.cpp"
        "Construction Heuristic/Dsatur.h"
        FileReader/FileReader.cpp
        FileReader/FileReader.h
        Graph/Graph.cpp
        Graph/Graph.h
        Node/Node.cpp
        Node/Node.h
        PermutationHeuristic/ColorClassHeuristic.cpp
        PermutationHeuristic/ColorClassHeuristic.h
        main.cpp PermutationHeuristic/AttemptHeuristic.h PermutationHeuristic/AttemptHeuristic.cpp PermutationHeuristic/AttemptHeuristic.h PermutationHeuristic/ColorTestHeuristic.cpp PermutationHeuristic/ColorTestHeuristic.h)
