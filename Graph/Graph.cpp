//
// Created by thiagofsr on 22/04/18.
//

#include <iostream>
#include "Graph.h"

void Graph::addNode(Node *node) {
    nodes.push_back(node);
}

int Graph::GetIndex( int u, int v) {
    int offset  = 0;
    int a,b;
    if(u > v){
        a = v; b = u;
    }else{
        a = u; b = v;
    }

    for(int i = 0; i <=a;i++){
        offset+=(i+1);
    }
    return ((matrixSize*a) + b) - offset;

}

Node *Graph::getNode(int identifier) {
    for(auto v: nodes){
        if(v->getIdentifier() == identifier){
            return v;
        }
    }
    return nullptr;
}

std::vector<Node*> Graph::getAllNodes() {
    return this->nodes;
}



int Graph::getWeigth( int u,  int v) {
    if(u == v)
        return 0;

    //::cout << "====== index======" << GetIndex(u,v) <<std::endl;
    return array[GetIndex(u,v)];
}


void Graph::setWeightMatrix( int u, int v,int weight) {
    int index = GetIndex(u,v);
    array[index] = weight;
}
void Graph::addWeightMatrix(int i, int weight){
    array[i] = weight;
}

Graph::Graph(int matrixSize, int arraySize) {
    this->matrixSize = matrixSize;
    this->array = new int[arraySize]();

}

Graph::~Graph() {
    //dealing with deallocationf of memorys
    delete[] this->array;
    for(auto node:nodes){
        delete node;
    }
};



void Graph::showMatrix(){
    for(int i = 0;i<matrixSize;i++){
        for(int j = 0; j < matrixSize;j++){
            std::cout << getWeigth(i,j) << " ";

        }
        std::cout << std::endl;
    }

}

void Graph::showNeighbors() {

    for(auto u:nodes){
        std::cout << "Neighbors of " << u->getIdentifier()+1 << " :";
        for(auto v:nodes.at(u->getIdentifier())->getNeighbors()){
            std::cout << v->getIdentifier()+1 << " ";

        }
        std::cout << std::endl;
    }

}




