//
// Created by thiagofsr on 10/06/18.
//

#include <iostream>
#include "Dsatur.h"

    bool compare (Node* a, Node* b)
    {
        if(a->getDegreeSat() == b->getDegreeSat()){
//            if(a->getNeighbors().size() == b->getNeighbors().size()){
//                return a->getIdentifier() > b->getIdentifier();
//            }
            return a->getNeighbors().size() <= b->getNeighbors().size();
        }

        return a->getDegreeSat() < b->getDegreeSat();
    }


void Dsatur::ColorGraph() {
    Node* current;
    std::vector<Node*> nodes = graph->getAllNodes();
    //std::priority_queue<Node*,std::vector<Node*>,Compare> nodes;
    std::sort(nodes.begin(),nodes.end(),compare);

    while(!nodes.empty()){
        current = nodes.back();
        nodes.erase(nodes.end()-1);
        if(!current->beenVisited()) {
            assignColor(current);
            current->switchState();
            for (auto neighbor:current->getNeighbors()) {
                if(!neighbor->beenVisited()) {
                    neighbor->incrementDegreeSat();
                }
            }
        }
        std::sort(nodes.begin(),nodes.end(),compare);

    }

}

Dsatur::Dsatur(Graph *graph) {
    this->graph = graph;
    this->number_of_colors_used = 0;

}

void Dsatur::assignColor(Node *node) {
    int color = 1;
    for(;color<=number_of_colors_used;color++){
        bool assignIt = true;
        for(auto neighbor:node->getNeighbors()){
            if(neighbor->getAssignedColor()!=-1 && neighbor->getAssignedColor() == color){
                assignIt = false;
                break;
            }
        }
        if(assignIt)
            break;
    }

    node->setAssignedColor(color);
    if(color > number_of_colors_used)
        number_of_colors_used = color;

}

int Dsatur::getNumberOfColors() {
    return this->number_of_colors_used;
}
