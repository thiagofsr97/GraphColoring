#include <iostream>
#include <FileReader.h>
#include "Dsatur.h"


int main() {
    FileReader fileReader("input.txt");
    Graph *graph = fileReader.createGraph();
    //graph->showNeighbors();
    Dsatur dsatur(graph);
    dsatur.ColorGraph();
    std::cout << "Node greatest degree " << graph->sortByMaxDegreeNode()->getIdentifier()+1 << std::endl;


    for(auto node:graph->getAllNodes()){
        std::cout << "Node " << node->getIdentifier()+1 << " Colored with: " << node->getAssignedColor()-1 << std::endl;
    }
    std::cout << "Number of colors used " << dsatur.getNumberOfColors() << std::endl;

    return 0;
}