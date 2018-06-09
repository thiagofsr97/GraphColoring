//
// Created by thiagofsr on 22/04/18.
//

#ifndef GREEDYALGORITHMS_GRAPH_H
#define GREEDYALGORITHMS_GRAPH_H


#include <vector>
#include <array>
#include "../Node/Node.h"
class Graph {
private:
    std::vector<Node*> nodes;
    int *array;
    int matrixSize;
    int GetIndex(int u, int v);
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


};


#endif //GREEDYALGORITHMS_GRAPH_H
