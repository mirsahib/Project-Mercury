
#ifndef _Node_h
#define _Node_h

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
    void setVisited(bool v);
    void setCost(int c);
    void setId(int i);
    void setPredecessor(int p);
};

class comparable{
public:
    int operator() (node &a,node &b);
};


#endif
