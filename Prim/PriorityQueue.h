
#ifndef _PriorityQueue_h
#define _PriorityQueue_h
#include "node.h"

class PriorityQueue{
private:
    int cap;
    int noOfNode;
    node* arr;
    void initialize(node& e);
    void initialize(int from);
    void expand();
    bool compare(int i,int j);
    void sink(int index);
    void swim(int index);
public:
    PriorityQueue();
    ~PriorityQueue();
    void push(node e);
    void pop();
    node peek();
    int popCost();
    bool isEmpty();
    void removeElement(node e);
    void display();

};


#endif // _PriorityQueue_h
