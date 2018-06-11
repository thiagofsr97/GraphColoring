#include <iostream>
#include <FileReader.h>
#include "Dsatur.h"
#include "PermutationHeuristic/ColorClassHeuristic.h"


int main() {
    FileReader fileReader("input.txt");
    Graph *graph = fileReader.createGraph();
    //graph->showMatrix();
    Dsatur dsatur(graph);
    dsatur.ColorGraph();
    fileReader.WriteFirstResult(dsatur.getColorClass());

    ColorClassHeuristic colorClassHeuristic(dsatur.getColorClass(),dsatur.getNumberOfColors(),500);
    colorClassHeuristic.LocalSearch();
    fileReader.WriteOptimalResult(colorClassHeuristic.getOptimalSolution());



    return 0;
}