#include <iostream>
#include <FileReader.h>
#include <AttemptHeuristic.h>
#include <ColorTestHeuristic.h>
#include "Dsatur.h"
#include "PermutationHeuristic/ColorClassHeuristic.h"

enum Heuristic {ByAttempts,ByFullColorTest};

int main() {
    FileReader fileReader("InputGood.txt");
    Graph *graph = fileReader.createGraph();
    Heuristic heuristic;
//    Heuristic heuristic = ByFullColorTest;

    Dsatur dsatur(graph);
    dsatur.ColorGraph();

    ColorClassHeuristic *colorClassHeuristic;

    switch(heuristic){
        case ByAttempts:
            colorClassHeuristic = new AttemptHeuristic(1000, graph, dsatur.getColorClass(),dsatur.getNumberOfColors());
            break;
        case ByFullColorTest:
            colorClassHeuristic = new ColorTestHeuristic(graph, dsatur.getColorClass(),dsatur.getNumberOfColors());
            break;
    }

    colorClassHeuristic->dropBucket();


    fileReader.WriteFirstResult(dsatur.getColorClass());
    fileReader.WriteOptimalResult(colorClassHeuristic->getOptimalSolution());



    return 0;
}