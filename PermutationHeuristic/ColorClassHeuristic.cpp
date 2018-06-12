//
// Created by thiagofsr on 10/06/18.
//

#include <iostream>
#include "ColorClassHeuristic.h"


bool vectorCompare(std::vector<Node*> a,std::vector<Node*> b) {
    return a.size() < b.size();
}
ColorClassHeuristic::ColorClassHeuristic(Graph* graph,ColorClasses solutionSpace, int k_value, int numberOfAttemps,Heuristic heuristic) {
    this->graph = graph;
    this->solutionSpace = createCopy(solutionSpace);
    this->k_value = k_value;
    this->numberOfAttemps = numberOfAttemps;
    this->heuristic = heuristic;
}



ColorClasses ColorClassHeuristic::getOptimalSolution() {
    return this->optimalSolutionSpace;
}

ColorClasses ColorClassHeuristic::createCopy(ColorClasses &colorClasses) {
    Graph *copy = this->graph->createCopy();
    ColorClasses copyClass;
    for (auto classes:colorClasses) {
        copyClass.push_back(std::vector<Node *>());
        for (auto node:classes) {
            copy->getNode(node->getIdentifier())->setAssignedColor(node->getAssignedColor());//with same assigned color
            copyClass.back().push_back(copy->getNode(node->getIdentifier()));
        }
    }
    delete copy;
    return copyClass;
}

void ColorClassHeuristic::clearColorClass(ColorClasses &colorClasses) {
    for(auto classes:colorClasses){
        for(auto node:classes){
            delete node;
        }

    }
    colorClasses.clear();

}

void ColorClassHeuristic::saveSolution(ColorClasses &optimalSolution, ColorClasses &solution) {
    clearColorClass(optimalSolution);
    optimalSolution = createCopy(solution);

}

//gets bucket with lesser number of vertices and randomly chooses a
//vertice from it trying to color it with a different color

void ColorClassHeuristic::LocalSearch(ColorClasses& S, ColorClasses& T) {
    std::random_shuffle(T[0].begin(),T[0].end());
    for(int node_color_T = 0; node_color_T < T[0].size();node_color_T++){
        Node* node = T[0][node_color_T];
        if(Dsatur::colorAssign(node,S)){
            for(int j = 0; j < S.size(); j++){
                if(S[j][0]->getAssignedColor() == node->getAssignedColor()) {
                    S[j].push_back(node);
                    int last_index = T[0].size()-1;
                    T[0].erase(T[0].begin() + node_color_T);
                    if(node_color_T !=last_index)
                        node_color_T--;
                    break;
                }
            }
        }
    }


    if(!T[0].empty()){
        S.push_back(T[0]);
    }
}

void ColorClassHeuristic::dropBucket() {
    ColorClasses S = createCopy(solutionSpace);

    switch (heuristic){
        case ByAttempts:
            while(numberOfAttemps--) {
                ColorClasses T = S;
                MoveColorClass(S, T);
                LocalSearch(S, T);
                if (S.size() < k_value) {
                    std::cout << "Improvement has happened. \n";
                    k_value = S.size();
                    saveSolution(optimalSolutionSpace, S);
                }
            }
            break;
        case ByFullColorTest:
            int number_of_collors_tested = 0;
            ColorClasses backup;

            while(number_of_collors_tested< S.size()){
                clearColorClass(backup);
                backup = createCopy(S);
                ColorClasses T = S;
                MoveColorClass(S, T,number_of_collors_tested);
                LocalSearch(S, T);
                if (S.size() < k_value) {
                    std::cout << "Improvement has happened. \n";
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
            break;

    }




}
void ColorClassHeuristic::MoveColorClass(ColorClasses &S, ColorClasses& T) {
    std::random_shuffle(T.begin(),T.end());
    while(T.size() > 1){
        T.erase(T.begin());
    }
    for(int i = 0; i < S.size(); i ++){
        if(T[0][0]->getIdentifier() == S[i][0]->getIdentifier()){
            S.erase(S.begin()+i);

            break;
        }
    }




}

void ColorClassHeuristic::MoveColorClass(ColorClasses &S, ColorClasses &T, int index_to_select) {
    ColorClasses n;
    n.push_back(T[index_to_select]);
    T = n;
    for(int i = 0; i < S.size(); i ++){
        if(T[0][0]->getIdentifier() == S[i][0]->getIdentifier()){
            S.erase(S.begin()+i);
            break;
        }
    }

}


