//
// Created by thiagofsr on 10/06/18.
//

#include <iostream>
#include "Dsatur.h"


/*
 * Compare function to sort list of nodes.
 *
 * The comparison firstly checks if both nodes have the same
 * saturation degree. If so, so it will compare the number of neighbors
 * of each node.
 *
 * In case they are not equal in saturation degree, the comparison is done
 * by the saturation degree.
 *
 */
bool compare (Node* a, Node* b)
    {
        if(a->getDegreeSat() == b->getDegreeSat()){
//            if(a->getNeighbors().size() == b->getNeighbors().size()){
//                return a->getIdentifier() > b->getIdentifier();
//            }
            return a->getNeighbors().size() <= b->getNeighbors().size();
        }

        return a->getDegreeSat() < b->getDegreeSat();
    }


/*
 *  Dsatur algorithm used in this method in order to
 *  color the graphs.
 *  The strategy is to get the node with highest
 *  saturation degree and assign a color to it.
 *  Once the color is assigned to a node, its neighbors will
 *  have their saturation degree incremented.
 *  After it, this node gets erased from the list.
 *  The left nodes are then re-sorted by saturation degree and
 *  the process is repeated.
 */
void Dsatur::ColorGraph() {
    Node *current;
    std::vector<Node *> nodes = graph->getAllNodes();
    std::sort(nodes.begin(), nodes.end(), compare);

    while (!nodes.empty()) {
        current = nodes.back();
        nodes.erase(nodes.end() - 1);
        if (!current->beenVisited()) {
            assignColor(current);
            current->switchState();
            for (auto neighbor:current->getNeighbors()) {
                if (!neighbor->beenVisited()) {
                    neighbor->incrementDegreeSat();
                }
            }
        }
        std::sort(nodes.begin(), nodes.end(), compare);

    }
}


/*
 * Dsatur Class Constructor
 */

Dsatur::Dsatur(Graph *graph):graph(graph), number_of_colors_used(0){}


/*
 * Method that assigns color to a node.
 *  The colors are represented by integer numbers.
 *  The first attempt when assigning a color to a node is to
 *  try to assign the number 1 to it. If a neighbor of this node
 *  has already been colored with 1, then the algorithm will increment
 *  the color and try to assign again to the current node.
 *
 */

void Dsatur::assignColor(Node *node) {

    int color = 1;
    for(;color<=number_of_colors_used;color++){
        bool assignIt = true;
        for(auto neighbor:node->getNeighbors()){
            if(neighbor->getAssignedColor()!=-1 && neighbor->getAssignedColor() == color){
                assignIt = false;
                break;
            }
        }

        if(assignIt)
            break;
    }

    node->setAssignedColor(color);

    if(color > number_of_colors_used) {
        number_of_colors_used = color;
        classes.push_back(std::vector<Node*>(1,node));
    }else{
        classes[color-1].push_back(node);
    }

}





/*
 * This function is defined as static.
 * Designed to be used by other classes.
 * The goal of this method is to try to reassign a
 * color to a node that already has a defined color.
 * In other words, change the color class (bucket) of this node.
 *
 * Its parameters are a reference to the Node and a reference to
 * a solution space (buckets of nodes).
 *
 * As each color class represents a color, the method
 * will look into each class, checking the color of a node in there
 * and seeing if the color of the node (that wants to change color)
 * is equal any of those. By finding the first bucket that differs in
 * color, the node will get its color assign to this bucket.
 */

bool Dsatur::colorAssign(Node *node, ColorClasses &colorClasses) {

    using Iter = ColorClasses::const_iterator;
    for (auto it = colorClasses.begin()+1; it!=colorClasses.end(); ++it) {
        int color = (*it)[0]->getAssignedColor();
        bool assignIt = true;
        for(auto neighbor:node->getNeighbors()){
            if(neighbor->getAssignedColor()!=-1 && neighbor->getAssignedColor() == color){
                assignIt = false;
                break;
            }
        }
        if(assignIt) {
            node->setAssignedColor(color);
            return true;
        }
    }

    return false;
}

