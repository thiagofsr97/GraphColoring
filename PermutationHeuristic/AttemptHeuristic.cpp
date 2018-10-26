//
// Created by thiagofsr on 26/10/18.
//


#include "AttemptHeuristic.h"

AttemptHeuristic::AttemptHeuristic(int number_of_attemps, Graph *graph, ColorClasses solutionSpace, int k_value):ColorClassHeuristic(graph, solutionSpace,k_value), number_of_attemps(number_of_attemps) {}

void AttemptHeuristic::dropBucket(){
    ColorClasses S = createCopy(solutionSpace);
    while(number_of_attemps--) {
        ColorClasses T = S;
        MoveColorClass(S, T);
        LocalSearch(S, T);
        if (S.size() < k_value) {
            std::cout << "Improvement has happened. Now using " << k_value << " colors.\n";
            k_value = S.size();
            saveSolution(optimalSolutionSpace, S);
        }
    }
}

