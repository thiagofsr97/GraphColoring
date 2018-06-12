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
    void addNode(Node* node);
    Node* getNode(int identifier);
    std::vector<Node*> getAllNodes();
    void setWeightMatrix( int u, int v,int weight);
    void addWeightMatrix(int i,int weight);
    int getWeigth(int u , int v);
    void showMatrix();
    void showNeighbors();
    Graph* createCopy();


};


#endif //GREEDYALGORITHMS_GRAPH_H
