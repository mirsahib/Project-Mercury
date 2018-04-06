#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <queue>
#include <stack>
#include <vector>
#include "node.h"
#include "dijkstra.h"

using namespace std;

//constructor
Dijkstra::Dijkstra(int v,float per_of_con,int s,int d){
    this->vertex = v;//no. of node initialize
    this->connect_per = per_of_con;//connection percentage
    this->source = s;//source initialize
    this->destination = d;//destination initialize
    this->matrix = new int*[vertex];// create 1d matrix
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
    this->node_array = new node[vertex];//creating node array
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

void Dijkstra::relax_edge(int u,int v,priority_queue<node,vector<node>,comparable>& pq){
    int parent_cost = node_array[u].getCost();
    int child_cost = node_array[v].getCost();
    int parent_to_child = matrix[u][v];
    if(node_array[v].getCost()==-1){//check if child node has any cost
        node_array[v].setCost(parent_cost+parent_to_child);
        node_array[v].setPredecessor(u);//replace child node cost to new cost
        pq.push(node_array[v]);
    }else{
        if(child_cost>parent_cost+parent_to_child){//if child node cost is more than parent node cost + parent to child node cost
            node_array[v].setCost(parent_cost+parent_to_child);
            node_array[v].setPredecessor(u);//update child node cost
            pq.push(node_array[v]);//duplicate should be deleted otherwise there will be a redundant node
        }
    }
}
void Dijkstra::setConnected(int c){
    connected = c;
}
bool Dijkstra::isConnected(){
    return connected;
}


//public function
void Dijkstra::dijkstraPath(){
        int temp = source;
        priority_queue<node,vector<node>,comparable>pq;
        node current;
        if(!node_array[temp].isVisited()){
            node_array[temp].setCost(0);
            node_array[temp].setPredecessor(temp);
            node_array[temp].setVisited(true);
            pq.push(node_array[temp]);//load initial source to the priority queue
        }
        while(!pq.empty()){
            if(temp==destination){
                setConnected(1);
            }

            for(int j=0;j<vertex;j++){
                if(matrix[temp][j]!=-1 && matrix[temp][j]!=0){//check if node is self connected or disconnected
                    if(!node_array[j].isVisited()){//check whether the node is visited
                        relax_edge(temp,j,pq);//check if minimum weighted edge is found
                    }
                }
            }
            pq.pop();//remove the explored node
            current = pq.top();//load new node which has minimum cost
            temp = current.getId();//get new node id
            node_array[temp].setVisited(true);//mark the new explore node as visited
        }
    if(!isConnected()){
        cout<<"graph is not connected"<<endl;
    }
}
void Dijkstra::showPath(){
    if(isConnected()){
        int temp = destination;
        stack <int> path;
        cout<<"Path distance: "<<node_array[temp].getCost()<<endl;
        while(temp!=source){
            path.push(temp);//store path info into a stack
            temp=node_array[temp].getPredecessor();
        }
        path.push(temp);//
        while(!path.empty()){
            if(path.top()==destination){
                cout<<path.top();
            }else{
                cout<<path.top()<<"->";
            }
            path.pop();
        }
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
