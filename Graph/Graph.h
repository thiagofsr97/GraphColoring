//
// Created by thiagofsr on 22/04/18.
//

#ifndef GREEDYALGORITHMS_GRAPH_H
#define GREEDYALGORITHMS_GRAPH_H


#include <vector>
#include <array>
#include "../Node/Node.h"
#include <algorithm>
class Graph {
private:
    std::vector<Node*> nodes;
    int *array;
    int matrixSize;
    Node* maxDegree;
    int GetIndex(int u, int v);
    int arraySize;

public:
    Graph(int matrixSize,int arraySize);
    ~Graph();
    void addNode(Node *node) {
        nodes.push_back(node);
    }
    Node* getNode(int identifier);
    std::vector<Node*> getAllNodes() {
        return this->nodes;
    }
    void setWeightMatrix( int u, int v,int weight) {
        int index = GetIndex(u,v);
        array[index] = weight;
    }
    void addWeightMatrix(int i, int weight){
        array[i] = weight;
    }
    int getWeigth(int u , int v);
    void showMatrix();
    void showNeighbors();
    Graph* createCopy();


};


#endif //GREEDYALGORITHMS_GRAPH_H
