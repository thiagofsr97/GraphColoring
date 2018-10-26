//
// Created by thiagofsr on 26/10/18.
//


#include "ColorTestHeuristic.h"

ColorTestHeuristic::ColorTestHeuristic(Graph *graph, ColorClasses solutionSpace, int k_value) : ColorClassHeuristic(
        graph, solutionSpace, k_value) {}

void ColorTestHeuristic::dropBucket() {
    ColorClasses S = createCopy(solutionSpace);
    int number_of_collors_tested = 0;
    ColorClasses backup;

    while(number_of_collors_tested< S.size()){
        clearColorClass(backup);
        backup = createCopy(S);
        ColorClasses T = S;
        MoveColorClass(S, T,number_of_collors_tested);
        LocalSearch(S, T);
        if (S.size() < k_value) {
            std::cout << "Improvement has happened. Now using " << k_value << " colors.\n";
            k_value = S.size();
            number_of_collors_tested = 0;
            saveSolution(optimalSolutionSpace, S);
        }
        else{
            clearColorClass(S);
            S = createCopy(backup);
            number_of_collors_tested++;
        }
    }

}
