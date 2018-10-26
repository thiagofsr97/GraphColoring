//
// Created by thiagofsr on 10/06/18.
//

#ifndef GRAPHCOLORING_LARGESTFIRST_H
#define GRAPHCOLORING_LARGESTFIRST_H


#include <Dsatur.h>


class ColorClassHeuristic {

protected:
    Graph* graph;
    ColorClasses solutionSpace;
    ColorClasses optimalSolutionSpace;
    int k_value;

    virtual void MoveColorClass(ColorClasses& S,ColorClasses& T) final ;
    virtual void MoveColorClass(ColorClasses& S,ColorClasses& T, int index_to_select) final;
    virtual ColorClasses createCopy(ColorClasses& colorClasses) final;
    virtual void clearColorClass(ColorClasses &colorClasses) final;
    virtual void saveSolution(ColorClasses& optimalSolution,ColorClasses& solution) final;
    virtual void LocalSearch(ColorClasses& S, ColorClasses& T) final;

public:
    virtual ColorClasses getOptimalSolution() final;
    virtual void dropBucket() = 0;
    ColorClassHeuristic(Graph*,ColorClasses solutionSpace, int k_value);
};


#endif //GRAPHCOLORING_LARGESTFIRST_H
