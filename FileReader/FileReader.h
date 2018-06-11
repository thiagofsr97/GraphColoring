//
// Created by thiagofsr on 22/04/18.
//

#ifndef GREEDYALGORITHMS_FILEREADER_H
#define GREEDYALGORITHMS_FILEREADER_H


#include <fstream>
#include <iostream>
#include <Dsatur.h>
#include "../Graph/Graph.h"
#include <sstream>

class FileReader {
private:
    std::fstream *inputFile;
    std::fstream *outputFile;

public:
    FileReader(const std::string& pathFile);
    ~FileReader();
    Graph* createGraph();
    void WriteFirstResult(ColorClasses firstSolution);
    void WriteOptimalResult(ColorClasses optimalSolution);




};


#endif //GREEDYALGORITHMS_FILEREADER_H
