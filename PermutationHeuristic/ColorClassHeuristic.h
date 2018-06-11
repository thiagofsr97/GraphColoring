//
// Created by thiagofsr on 10/06/18.
//

#ifndef GRAPHCOLORING_LARGESTFIRST_H
#define GRAPHCOLORING_LARGESTFIRST_H


#include <Dsatur.h>

class ColorClassHeuristic {


private:
    ColorClasses solutionSpace;
    ColorClasses tempSpace;
    ColorClasses optimalSolutionSpace;
    int k_value;
    int result_number;
    int numberOfAttemps;
    void clearColors();
    bool firstTime;
    void LargestFirst();
    void ReverseSpace();
    void RandomSpace();

public:
    ColorClassHeuristic(ColorClasses solutionSpace,int k_value,int numberOfAttemps);
    ColorClasses getOptimalSolution();

    void LocalSearch();


};


#endif //GRAPHCOLORING_LARGESTFIRST_H
