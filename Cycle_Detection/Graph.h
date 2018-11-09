#ifndef _Graph_h
#define _Graph_h
#include <vector>
#include "PriorityQueue.h"
#include "Edge.h"
#include "node.h"

using namespace std;

class Graph{
private:
    int vertex;
    float connect_per;
    int** matrix;
    int no_of_edge;
    int cycleCounter;
    vector<node>visitedList;
    int pivot_id;
    Edge* edge;//mst edge array
    node* node_array;//label array

    //private function
    void initialize_matrix();
    void initialize_node();
    int no_of_connection();


public:
    Graph();
    Graph(int v,float per_of_con);
    bool is_id_visited(int id);
    void detectCycle();
    void display_matrix();
    void display();
};


#endif // _Graph_h
