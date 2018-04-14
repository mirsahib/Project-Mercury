#ifndef _Graph_h
#define _Graph_h
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
    int mstSetCounter;
    int* mstSet;
    Edge* edge;//mst edge array
    node* node_array;//label array

    //private function
    void setConnected(int c);
    void initialize_matrix();
    void initialize_node();
    int no_of_connection();
    void relaxEdge(int u,int v,PriorityQueue &pq);

public:
    Graph();
    Graph(int v,float per_of_con);
    void makeMst();
    bool inMstSet(int index);
    void display_matrix();
    void displayMST();
};


#endif // _Graph_h
