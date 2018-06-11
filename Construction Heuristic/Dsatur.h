//
// Created by thiagofsr on 10/06/18.
//

#ifndef GRAPHCOLORING_DSATUR_H
#define GRAPHCOLORING_DSATUR_H

#include <stack>


#include <Node.h>
#include <queue>
#include <Graph.h>

typedef std::vector<std::vector<Node*>> ColorClasses;
class Dsatur {
private:
    int number_of_colors_used;
    Graph *graph;
    ColorClasses classes;
public:

    void assignColor(Node* node);
    static void colorAssign(Node* node,int &number_of_colors_used,ColorClasses &alternativeSpace);
    Dsatur(Graph *graph);
    ColorClasses getColorClass();
    int getNumberOfColors();
    void ColorGraph();

};


#endif //GRAPHCOLORING_DSATUR_H
