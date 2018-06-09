//
// Created by thiagofsr on 22/04/18.
//


#include <sstream>
#include "FileReader.h"

FileReader::FileReader(const std::string &pathFile) {
    this->inputFile = new std::fstream(pathFile,std::ios::in);
    if(!inputFile->is_open()){
        std::cout << "Error opening file, check path.\n";
        exit(1);
    }

}

FileReader::~FileReader() {
    delete this->inputFile;

}

Graph *FileReader::createGraph() {
    std::string mark, edge;
    int offset = 0;
    int count = 0;
    int currentLine = 0;
    int j = 0;
    int matrixSize = 0;
    int node_1,node_2;
    std::string line,numbers;

    getline(*inputFile,line);
    std::stringstream ss(line);
    ss >> mark >> edge >> matrixSize;

    std::vector<std::string> weights;

    for(int i = 0; i < matrixSize;i++){
        offset+=(i+1);
    }
    Graph *graph = new Graph(matrixSize,(matrixSize*matrixSize)-offset);

    for(int i = 0; i < matrixSize;i++)
        graph->addNode(new Node(i));



    while(!inputFile->eof()){
      getline(*inputFile,line);
      if(!line.empty()){
          std::stringstream ss{line};

          while(ss >> mark >> node_1 >> node_2 );
          graph->setWeightMatrix(node_1-1,node_2-1,1);
          graph->getNode((unsigned int)node_1-1)->addNeighbor(graph->getNode((unsigned int)node_2-1));
          graph->getNode((unsigned int)node_2-1)->addNeighbor(graph->getNode((unsigned int)node_1-1));

      }
    }

    return graph;
}


