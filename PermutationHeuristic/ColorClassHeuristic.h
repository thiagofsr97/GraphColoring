//
// Created by thiagofsr on 10/06/18.
//

#ifndef GRAPHCOLORING_LARGESTFIRST_H
#define GRAPHCOLORING_LARGESTFIRST_H


#include <Dsatur.h>
enum Heuristic {ByAttempts,ByFullColorTest};

class ColorClassHeuristic {


private:
    Graph* graph;
    ColorClasses solutionSpace;
    ColorClasses optimalSolutionSpace;
    int k_value;

    int numberOfAttemps;

    Heuristic  heuristic;
    void MoveColorClass(ColorClasses& S,ColorClasses& T);
    void MoveColorClass(ColorClasses& S,ColorClasses& T,int index_to_select);
    ColorClasses createCopy(ColorClasses& colorClasses);
    void clearColorClass(ColorClasses &colorClasses);
    void saveSolution(ColorClasses& optimalSolution,ColorClasses& solution);
    void LocalSearch(ColorClasses& S, ColorClasses& T);
public:
    ColorClasses getOptimalSolution();
    void dropBucket();
    ColorClassHeuristic(Graph*,ColorClasses solutionSpace,int k_value,int numberOfAttemps,Heuristic heuristic);



};


#endif //GRAPHCOLORING_LARGESTFIRST_H
