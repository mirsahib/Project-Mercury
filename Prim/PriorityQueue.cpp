#include <iostream>
#include "PriorityQueue.h"
#include "node.h"

using namespace std;

void PriorityQueue::sink(int k){
    while(true){
        int left = 2*k+1;
        int right = 2*k+2;
        int smallest = left;

        if(right<noOfNode && compare(right,left)){
            smallest = right;
        }
        if(left>=noOfNode || compare(k,smallest)){
            break;
        }
        swap(arr[smallest],arr[k]);
        k=smallest;
    }
}
void PriorityQueue::swim(int k){
    int parent = (k-1)/2;
    while(k>0 && compare(k,parent)){
        swap(arr[parent],arr[k]);
        k=parent;
        parent=(k-1)/2;

    }
}
bool PriorityQueue::compare(int i,int j){
    int cost_i = arr[i].getCost();
    int cost_j = arr[j].getCost();
    return cost_i<cost_j;
}

PriorityQueue::PriorityQueue(){
    this->cap=10;
    this->noOfNode=0;
    arr = new node[10];
}
PriorityQueue::~PriorityQueue(){
    delete[]arr;
}
void PriorityQueue::expand(){
    this->cap *=2;
    node* temp = new node[cap];

    for(int i=0;i<noOfNode;i++){
        temp[i] = arr[i];
    }

    delete arr;
    arr = temp;
    //initialize(noOfNode);
}
void PriorityQueue::initialize(int from){
    for(int i=from;i<cap;i++){
        initialize(arr[i]);
    }
}
void PriorityQueue::initialize(node& e){
    e.setCost(-1);
    e.setPredecessor(-1);
    e.setVisited(false);
}
void PriorityQueue::push(node e){
    if(noOfNode>=cap){
        expand();
    }
    int i = noOfNode;
    arr[noOfNode++] = e;
    swim(i);
}
void PriorityQueue::pop(){
    if(noOfNode==1){
        initialize(arr[0]);
        noOfNode=0;
        return;
    }
    swap(arr[noOfNode-1],arr[0]);
    initialize(arr[noOfNode-1]);
    noOfNode--;
    //int i=0;
    sink(0);
}
node PriorityQueue::peek(){
    return arr[0];
}
int PriorityQueue::popCost(){
    swap(arr[noOfNode-1],arr[0]);
    initialize(arr[noOfNode-1]);
    noOfNode--;
    //int i=0;
    sink(0);
    return arr[0].getCost();
}
void PriorityQueue::removeElement(node e){
    int id = e.getId();
    int index;
    //int counter=0;
    int nodeId;
    for(int i=0;i<noOfNode;i++){
        nodeId = arr[i].getId();
        if(nodeId==id){
            swap(arr[i],arr[noOfNode-1]);
            initialize(arr[noOfNode-1]);
            noOfNode--;
            //display();
            if(noOfNode<=1)return;
            index = i;
            break;
        }
    }
    sink(index);
    swim(index);
}
bool PriorityQueue::isEmpty(){
    if(noOfNode==0){
        return true;
    }
    return false;
}


void PriorityQueue::display(){
    for(int i=0;i<noOfNode;i++){
        cout<<"cost: "<<arr[i].getCost()<<" ID: "<<arr[i].getId()<<" predecessor: "<<arr[i].getPredecessor()<<" status: "<<arr[i].isVisited()<<endl;
    }
    cout<<endl;
}

