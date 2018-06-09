//
// Created by thiagofsr on 22/04/18.
//

#ifndef GREEDYALGORITHMS_FILEREADER_H
#define GREEDYALGORITHMS_FILEREADER_H


#include <fstream>
#include <iostream>
#include "../Graph/Graph.h"

class FileReader {
private:
    std::fstream *inputFile;

public:
    FileReader(const std::string& pathFile);
    ~FileReader();
    Graph* createGraph();




};


#endif //GREEDYALGORITHMS_FILEREADER_H
