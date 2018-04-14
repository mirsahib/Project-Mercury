
#ifndef _Edge_h
#define _Edge_h
class Edge{
private:
    int first_vertics;
    int second_vertics;
    int weight;
public:
    void setEdge(int u,int v,int w);
    void displayTree();
};


#endif
