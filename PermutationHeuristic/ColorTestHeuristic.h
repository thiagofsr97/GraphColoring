//
// Created by thiagofsr on 26/10/18.
//

#ifndef GRAPHCOLORING_COLOTESTHEURISTIC_H
#define GRAPHCOLORING_COLOTESTHEURISTIC_H


#include "ColorClassHeuristic.h"
#include <iostream>

class ColorTestHeuristic: public ColorClassHeuristic{
        public:
        ColorTestHeuristic(Graph* graph,ColorClasses solutionSpace, int k_value);
        void dropBucket() override;

};


#endif //GRAPHCOLORING_COLOTESTHEURISTIC_H
