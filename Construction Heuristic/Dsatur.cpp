//
// Created by thiagofsr on 10/06/18.
//

#include <iostream>
#include "Dsatur.h"
class Compare
{
public:
    bool operator() (Node* a, Node* b)
    {
        if(a->getDegreeSat() == b->getDegreeSat()){
            return a->getNeighbors().size() > b->getNeighbors().size();
        }

        return a->getDegreeSat() > b->getDegreeSat();
    }
};

void Dsatur::ColorGraph() {
    Node* current;
    std::priority_queue<Node*,std::vector<Node*>,Compare> nodes;
    nodes.push(graph->sortByMaxDegreeNode());

    while(!nodes.empty()){
        current = nodes.top();
        nodes.pop();
        if(!current->beenVisited()) {
            assignColor(current);
            current->switchState();
            for (auto neighbor:current->getNeighbors()) {
                if(!neighbor->beenVisited()) {
                    neighbor->incrementDegreeSat();
                    nodes.push(neighbor);
                }
            }
        }

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
