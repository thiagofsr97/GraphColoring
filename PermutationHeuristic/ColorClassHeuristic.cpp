//
// Created by thiagofsr on 10/06/18.
//

#include <iostream>
#include "ColorClassHeuristic.h"

void saveSolution(ColorClasses& optimalSolution,ColorClasses& solution){
    optimalSolution.clear();
    for(auto classes:solution){
        optimalSolution.push_back(std::vector<Node*>());
        for(auto node:classes){
            Node* temp = new Node(node->getIdentifier());
            temp->setAssignedColor(node->getAssignedColor());
            optimalSolution.back().push_back(temp);

        }
    }

}


bool vectorCompare(std::vector<Node*> a,std::vector<Node*> b) {
    return a.size() > b.size();
}
ColorClassHeuristic::ColorClassHeuristic(ColorClasses solutionSpace, int k_value, int numberOfAttemps) {
    this->solutionSpace = solutionSpace;
    firstTime = true;
    this->k_value = k_value;
    this->numberOfAttemps = numberOfAttemps;
    this->result_number = INT_MAX;

}

void ColorClassHeuristic::LargestFirst() {


    if(!firstTime) {
        solutionSpace = tempSpace;
        tempSpace.clear();
    }
    std::sort(solutionSpace.begin(),solutionSpace.end(),vectorCompare);

    int numberOfColors=0;
    clearColors();
    for (auto classes:solutionSpace) {
        for (auto node:classes) {

            Dsatur::colorAssign(node, numberOfColors, tempSpace);
        }

    }
    firstTime = false;
    result_number = numberOfColors;
    if(k_value > result_number){
        k_value = result_number;
        saveSolution(optimalSolutionSpace,tempSpace);
    }
}

void ColorClassHeuristic::clearColors() {
    for (auto classes:solutionSpace) {
        for (auto node:classes) {
            node->setAssignedColor(-1);
        }
    }

}

void ColorClassHeuristic::ReverseSpace() {



    if(!firstTime) {
        solutionSpace = tempSpace;
        tempSpace.clear();
    }
    std::reverse(solutionSpace.begin(),solutionSpace.end());
    int numberOfColors=0;
    clearColors();
    for (auto classes:solutionSpace) {
        for (auto node:classes) {
            Dsatur::colorAssign(node, numberOfColors, tempSpace);
        }
    }
    result_number = numberOfColors;
    firstTime = false;
    if(k_value > result_number){
        k_value = result_number;
        saveSolution(optimalSolutionSpace,tempSpace);
    }

}

void ColorClassHeuristic::LocalSearch() {

    while(numberOfAttemps-- > 0){
        LargestFirst();
     //   std::cout << "Largest First Size " << result_number << std::endl;
        ReverseSpace();
       // std::cout << "ReverseSpace Size " << result_number << std::endl;
        RandomSpace();
        //std::cout << "RandomSpace Size " << result_number << std::endl;

    }

}

void ColorClassHeuristic::RandomSpace() {
    if(!firstTime) {
        solutionSpace = tempSpace;
        tempSpace.clear();
    }
    std::random_shuffle(solutionSpace.begin(),solutionSpace.end());
    int numberOfColors=0;
    clearColors();
    for (auto classes:solutionSpace) {
        for (auto node:classes) {
            Dsatur::colorAssign(node, numberOfColors, tempSpace);
        }
    }
    result_number = numberOfColors;
    firstTime = false;
    if(k_value > result_number){
        k_value = result_number;
        saveSolution(optimalSolutionSpace,tempSpace);
    }


}

ColorClasses ColorClassHeuristic::getOptimalSolution() {
    return this->optimalSolutionSpace;
}


