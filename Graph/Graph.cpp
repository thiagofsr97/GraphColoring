//
// Created by thiagofsr on 22/04/18.
//

#include <iostream>
#include "Graph.h"

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
    if(identifier > nodes.size() || identifier < 0)
    return nullptr;
    return nodes[identifier];
}





int Graph::getWeigth( int u,  int v) {
    if(u == v)
        return 0;

    //::cout << "====== index======" << GetIndex(u,v) <<std::endl;
    return array[GetIndex(u,v)];
}





Graph::Graph(int matrixSize, int arraySize) {
    this->matrixSize = matrixSize;
    this->array = new int[arraySize]();
    this->maxDegree = nullptr;
    this->arraySize = arraySize;

}

Graph::~Graph() {
    //dealing with deallocationf of memorys
    delete[] this->array;
//    for(auto node:nodes){
//        delete node;
//    }
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
        std::cout << "Neighbors of " << u->getIdentifier()+1 << " : Size " << u->getNeighbors().size() << std::endl;
        //std::cout << "Number of neighbors "<< u->getIdentifier()+1 << ": "<<u->getNeighbors().size() << std::endl;
        for(auto v:nodes.at(u->getIdentifier())->getNeighbors()){
            std::cout << v->getIdentifier()+1 << " ";

        }
        std::cout << std::endl;
    }

}

Graph *Graph::createCopy() {
    Graph* copy = new Graph(this->matrixSize,this->arraySize);
    for(auto c:nodes){
        copy->addNode(new Node(c->getIdentifier()));
    }
    for(auto c:nodes){
        for(auto neighbors:c->getNeighbors()){
            copy->getNode(c->getIdentifier())->addNeighbor(copy->getNode(neighbors->getIdentifier()));
        }
    }

    return copy;
}








