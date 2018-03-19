#include <iostream>
#include "node.h"

using namespace std;

node::node(){
    this->cost = 0;
    this->predecessor =-1;
    this->visited = false;
}
int node::getCost(){
    return this->cost;
}
int node::getPredecessor(){
    return this->predecessor;
}
bool node::isVisited(){
    return this->visited;
}
void node::setCost(int c){
    this->cost = c;
}
void node::setPredecessor(int p){
    this->predecessor = p;
}
void node::setVisited(bool v){
    this->visited = v;
}
