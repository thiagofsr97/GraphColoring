#include <iostream>
#include <FileReader.h>
#include "Dsatur.h"
#include "PermutationHeuristic/ColorClassHeuristic.h"


int main() {
    FileReader fileReader("input.txt");
    Graph *graph = fileReader.createGraph();
    Dsatur dsatur(graph);
    dsatur.ColorGraph();
    ColorClassHeuristic colorClassHeuristic(graph,dsatur.getColorClass(),dsatur.getNumberOfColors(),1000,ByFullColorTest);
    colorClassHeuristic.dropBucket();
    fileReader.WriteFirstResult(dsatur.getColorClass());
    fileReader.WriteOptimalResult(colorClassHeuristic.getOptimalSolution());



    return 0;
}