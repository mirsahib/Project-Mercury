#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <stack>
#include "PriorityQueue.h"
#include "node.h"
#include "dijkstra.h"

using namespace std;

//constructor
Dijkstra::Dijkstra(int v,float per_of_con,int s,int d){
    this->vertex = v;//no. of node initialize
    this->connect_per = per_of_con;//connection percentage
    this->source = s;//source initialize
    this->destination = d;//destination initialize
    this->matrix = new int*[vertex];
    this->connected = 0;

    for(int i=0;i<vertex;i++){
        this->matrix[i] = new int[vertex];//create 2d matrix
    }
    initialize_matrix();
    initialize_node();
}
//private function
void Dijkstra::initialize_matrix(){
    //srand(time(0));
    int x,y;
    int node = no_of_connection();//number of node connected
    int num;
    //creating unweighted graph
    for(int i=0;i<vertex;i++){
        for(int j=i;j<vertex;j++){
            if(i==j){
                matrix[i][j]=0;
            }else{
                matrix[i][j] = -1;
                matrix[j][i] = -1;
            }
        }
    }

    //creating weighted graph with random value in random postion
    while(node){
        x = rand()%vertex;
        y = rand()%vertex;
        num = rand()%100;
        if(matrix[x][y]==-1){
            matrix[x][y] = num;
            matrix[y][x] = num;
            node--;
        }
    }
}
void Dijkstra::initialize_node(){
    this->node_array = new node[vertex];//creating label array
    for(int i=0;i<vertex;i++){
        node_array[i].setId(i);//setting an id for the node
    }
}
//calculate the number of connection for the given percentage
int Dijkstra::no_of_connection(){
    float percent = connect_per/100;
    int node = (vertex*(vertex-1))/2;// n(n-1)/2 formula for fully connected graph
    return node*percent;
}


void Dijkstra::setConnected(int c){
    connected = c;
}
bool Dijkstra::isConnected(){
    return connected;
}
void Dijkstra::relaxEdge(int u,int v,PriorityQueue &pq){
    int parent_cost = node_array[u].getCost();
    int child_cost = node_array[v].getCost();
    int parent_to_child_cost = matrix[u][v];

    if(node_array[v].getCost()==-1){
        node_array[v].setCost(parent_cost+parent_to_child_cost);
        node_array[v].setPredecessor(u);
        pq.push(node_array[v]);
    }else{
        if(child_cost>parent_cost+parent_to_child_cost){
            pq.removeElement(node_array[v]);
            node_array[v].setCost(parent_cost+parent_to_child_cost);
            node_array[v].setPredecessor(u);
            pq.push(node_array[v]);
            //pq.display();

        }
    }

}

//public function
void Dijkstra::dijkstraPath(){
    int temp = source;
    PriorityQueue pq;
    node_array[temp].setCost(0);
    node_array[temp].setPredecessor(0);
    node_array[temp].setId(0);
    node_array[temp].setVisited(true);
    pq.push(node_array[temp]);

    while(!pq.isEmpty()){
        if(temp==destination){
            setConnected(1);
        }
        for(int j=0;j<vertex;j++){
            if(matrix[temp][j]!=-1 && matrix[temp][j]!=0){
                if(!node_array[j].isVisited()){
                    relaxEdge(temp,j,pq);
                }
            }
        }
        //pq.display();
        pq.pop();
        temp = pq.peek().getId();
        //pq.display();
        node_array[temp].setVisited(true);
    }
}
void Dijkstra::showPath(){
    if(isConnected()){
        stack<int>path;
        int temp = destination;
        cout<<"Path cost: "<<node_array[temp].getCost()<<endl;
        while(temp!=source){
            path.push(temp);
            temp = node_array[temp].getPredecessor();
        }
        cout<<"Path display: ";
        path.push(temp);
        while(!path.empty()){
            if(path.top()==destination){
                cout<<path.top();
            }else{
                cout<<path.top()<<"->";
            }
            path.pop();
        }
        cout<<endl;
    }else{
        cout<<"There is no path from source to destination"<<endl;
    }
}
void Dijkstra::display_matrix(){
    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            cout<<setw(3)<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void Dijkstra::display_node(){
    for(int i=0;i<vertex;i++){
        cout<<"Node cost "<<node_array[i].getCost();
        cout<<",Node ID "<<node_array[i].getId();
        cout<<",Node predecessor "<<node_array[i].getPredecessor();
        cout<<",Node status "<<node_array[i].isVisited()<<endl;
    }

}
