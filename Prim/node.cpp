#include <iostream>
#include "node.h"
using namespace std;

node::node(){
    this->cost = -1;
    this->predecessor = -1;
    this->visited = false;
}
int node::getCost(){
    return this->cost;
}
int node::getId(){
    return id;
}
int node::getPredecessor(){
    return predecessor;
}
bool node::isVisited(){
    return visited;
}
void node::setCost(int c){
    cost = c;
}
void node::setId(int i){
    id = i;
}
void node::setPredecessor(int p){
    predecessor = p;
}
void node::setVisited(bool v){
    visited = v;
}

