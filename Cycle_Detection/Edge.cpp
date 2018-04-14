#include <iostream>
#include "Edge.h"

using namespace std;
void Edge::setEdge(int u,int v,int w){
    first_vertics = u;
    second_vertics = v;
    weight = w;
}
void Edge::displayTree(){
    cout<<first_vertics<<"->"<<second_vertics<<"   "<<weight<<endl;
}
