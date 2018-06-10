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

    void addNeighbor(Node* node);
    std::vector<Node*> getNeighbors();
    int getIdentifier();
    bool beenVisited();
    void switchState();
    int getAssignedColor();
    int getDegreeSat();
    void incrementDegreeSat();
    void setAssignedColor(int color);
    void clearSettings();
};

#endif //GREEDYALGORITHMS_NODE_H
