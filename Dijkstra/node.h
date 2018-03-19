
#ifndef _Node_h
#define _Node_h

class node{
private:
    int cost;
    int predecessor;
    bool visited;

public:
    node();
    int getCost();
    int getPredecessor();
    bool isVisited();
    void setVisited(bool v);
    void setCost(int c);
    void setPredecessor(int p);
};

#endif
