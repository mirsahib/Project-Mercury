#ifndef _node_h
#define _node_h

class node{
private:
    int cost;
    int id;
    int predecessor;
    bool visited;
public:
    node();
    int getCost();
    int getId();
    int getPredecessor();
    bool isVisited();
    void setCost(int c);
    void setId(int i);
    void setPredecessor(int p);
    void setVisited(bool v);
};
#endif
