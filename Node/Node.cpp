#include <iostream>
#include "Node.h"

Node::Node( int const &id) {
    this->identifier  = id;
    this->visited = false;
    this->assignedColor = -1;
    this->degreeSaturation = 0;

}

void Node::addNeighbor(Node *node) {
    this->neighbors.push_back(node);

}

std::vector<Node*> Node::getNeighbors() {
    return this->neighbors;
}

int Node::getIdentifier() {
    return this->identifier;
}

bool Node::beenVisited() {
    return this->visited;
}

void Node::switchState(){
    this->visited?this->visited=false:this->visited=true;
}

int Node::getAssignedColor(){
       return this->assignedColor;
}

void Node::setAssignedColor(int color) {
    this->assignedColor = color;

}


void Node::clearSettings() {

    this->visited = false;
}

void Node::incrementDegreeSat() {
    this->degreeSaturation +=1;

}

int Node::getDegreeSat() {
    return this->degreeSaturation;
}



