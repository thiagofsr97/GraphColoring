#include <iostream>
#include <FileReader.h>
#include "Dsatur.h"


int main() {
    FileReader fileReader("input.txt");
    Graph *graph = fileReader.createGraph();
    //graph->showNeighbors();
    Dsatur dsatur(graph);
    dsatur.ColorGraph();


    for(auto node:graph->getAllNodes()){
        std::cout << "Node " << node->getIdentifier()+1 << " Colored with: " << node->getAssignedColor() << std::endl;
    }

    return 0;
}