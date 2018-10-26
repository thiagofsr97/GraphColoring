//
// Created by thiagofsr on 22/04/18.
//

#ifndef GREEDYALGORITHMS_NODE_H
#define GREEDYALGORITHMS_NODE_H

#include <string>
#include <map>
#include <climits>
#include <vector>

class Node {
private:
    int identifier;
    bool visited;
    int assignedColor;
    std::vector<Node*> neighbors;
    int degreeSaturation;
public:
    Node(const int& id);

    void addNeighbor(Node *node) {
        this->neighbors.push_back(node);

    }

    std::vector<Node*> getNeighbors() {
        return this->neighbors;
    }
    int getIdentifier() {
        return this->identifier;
    }
    bool beenVisited() {
        return this->visited;
    }
    void switchState(){
        this->visited?this->visited=false:this->visited=true;
    }

    int getAssignedColor(){
        return this->assignedColor;
    }


    int getDegreeSat() {
        return this->degreeSaturation;
    }


    void incrementDegreeSat() {
        this->degreeSaturation +=1;

    }
    void setAssignedColor(int color) {
        this->assignedColor = color;

    }
    void clearSettings() {

        this->visited = false;
    }
};

#endif //GREEDYALGORITHMS_NODE_H
