//
// Created by thiagofsr on 26/10/18.
//

#ifndef GRAPHCOLORING_ATTEMPTHEURISTIC_H
#define GRAPHCOLORING_ATTEMPTHEURISTIC_H


#include "ColorClassHeuristic.h"
#include <iostream>

class AttemptHeuristic: public ColorClassHeuristic{

private:
    int number_of_attemps;

public:
    AttemptHeuristic(int number_of_attemps, Graph* graph,ColorClasses solutionSpace, int k_value);
    void dropBucket() override;

};


#endif //GRAPHCOLORING_ATTEMPTHEURISTIC_H
