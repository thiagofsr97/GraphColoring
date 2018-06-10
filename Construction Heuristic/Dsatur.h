//
// Created by thiagofsr on 10/06/18.
//

#ifndef GRAPHCOLORING_DSATUR_H
#define GRAPHCOLORING_DSATUR_H

#include <Node.h>
#include <queue>
#include <Graph.h>


class Dsatur {
private:
    int number_of_colors_used;
    Graph *graph;
    void assignColor(Node* node);

public:
    Dsatur(Graph *graph);
    void ColorGraph();

};


#endif //GRAPHCOLORING_DSATUR_H
