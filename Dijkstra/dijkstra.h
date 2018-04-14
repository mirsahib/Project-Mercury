#ifndef _Dijkstra_H
#define _Dijkstra
#include <vector>
#include "PriorityQueue.h"
#include "node.h"

using namespace std;

class Dijkstra{
private:
    int vertex;
    float connect_per;
    int source;
    int destination;
    int** matrix;
    node* node_array;
    int connected;

    void setConnected(int c);
    void initialize_matrix();
    void initialize_node();
    void relaxEdge(int u,int v,PriorityQueue &pq);
    int no_of_connection();
    bool isConnected();

public:
    Dijkstra();
    Dijkstra(int v,float per_of_con,int s,int d);//dijkstra(no of vertices,percentage of connection,source,destination)
    void dijkstraPath();
    void showPath();
    void display_matrix();
    void display_node();
};

#endif
