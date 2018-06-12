//
// Created by thiagofsr on 22/04/18.
//



#include "FileReader.h"

bool vectorCompareByColor(std::vector<Node*> a, std::vector<Node*> b) {
    return a[0]->getAssignedColor() < b[0]->getAssignedColor();
}
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
    int greatest_number_of_neighbors = 1;
    std::string line,numbers;
    int current = 1;

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
    inputFile->close();

    return graph;
}

void FileReader::WriteFirstResult(ColorClasses firstSolution) {
    outputFile = new std::fstream("Results_First_Solution.txt",std::ios::out);
    *outputFile << "Number of colors used: " << firstSolution.size() << " colors.\n\n";
    for(auto classes:firstSolution){
        *outputFile << "Nodes colored with Color " + std::to_string (classes[0]->getAssignedColor()) + "\n";
        for(auto node:classes){
            *outputFile << "\tId: " +std::to_string(node->getIdentifier()+1) + "\n";
        }
    }
    outputFile->close();
    delete outputFile;
}

void FileReader::WriteOptimalResult(ColorClasses optimalSolution) {

    std::sort(optimalSolution.begin(),optimalSolution.end(),vectorCompareByColor);
    outputFile = new std::fstream("Results_Optimal_Solution.txt",std::ios::out);
    *outputFile << "Number of colors used " << optimalSolution.size() << " colors.\n\n";
    for(auto classes:optimalSolution){
        *outputFile << "Nodes colored with Color " + std::to_string (classes[0]->getAssignedColor()) + "\n";
        for(auto node:classes){
            *outputFile << "\tId: " +std::to_string(node->getIdentifier()+1) + "\n";
        }
    }
    outputFile->close();
    delete outputFile;

}




