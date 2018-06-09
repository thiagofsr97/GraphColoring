#include <iostream>
#include <FileReader.h>

int main() {
    FileReader fileReader("input.txt");
    Graph *graph = fileReader.createGraph();
    graph->showNeighbors();
    return 0;
}