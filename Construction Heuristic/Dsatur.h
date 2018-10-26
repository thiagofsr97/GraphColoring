//
// Created by thiagofsr on 10/06/18.
//

#ifndef GRAPHCOLORING_DSATUR_H
#define GRAPHCOLORING_DSATUR_H

#include <stack>


#include <Node.h>
#include <queue>
#include <Graph.h>

/*
 * ColorClasses represents a bi-dimensional vector of Nodes.
 * It is used to represent the solution space.
 * The so called Buckets.
 */
typedef std::vector<std::vector<Node*>> ColorClasses;
class Dsatur {
private:
    int number_of_colors_used;
    Graph *graph;
    ColorClasses classes;
public:

    Dsatur(Graph *graph);
    void assignColor(Node* node);
    static bool colorAssign(Node *node, ColorClasses& colorClasses);
    ColorClasses getColorClass();
    int getNumberOfColors();
    void ColorGraph();

};


#endif //GRAPHCOLORING_DSATUR_H
