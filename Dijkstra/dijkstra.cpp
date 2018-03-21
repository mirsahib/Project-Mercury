#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <queue>
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
        node_array[i].setId(i);
    }
}

int Dijkstra::no_of_connection(){
    float percent = connect_per/100;
    int node = (vertex*(vertex-1))/2;
    return node*percent;
}
bool Dijkstra::isConnected(){
    queue<int>bfs;
    int counter = 0;
    int temp = source;
    //mark the source node visited and insert the source to bfs queue
    if(!node_array[temp].isVisited()){
        bfs.push(temp);
        node_array[temp].setVisited(true);
    }

    while(!bfs.empty()){
        //check if destination is connected with the source
        if(temp==destination){
            counter=1;
            break;//if destination is found break the loop
        }
        //traversing the graph
        for(int j=0;j<vertex;j++){
            if(matrix[temp][j]!=0 && matrix[temp][j]!=-1){
                if(!node_array[j].isVisited()){
                    bfs.push(j);
                    node_array[j].setVisited(true);
                }
            }
        }
        bfs.pop();//remove the parent node
        temp = bfs.front();//source changes to next child node
    }
    //reinitializing node array
    for(int i=0;i<vertex;i++){
        node_array[i].setVisited(false);
    }

    return counter;//return true if source is connected with destination
}
void Dijkstra::relax_edge(int u,int v){
    int parent_cost = node_array[u].getCost();
    int child_cost = node_array[v].getCost();
    int parent_to_child = matrix[u][v];
    if(node_array[v].getCost()==-1){
        node_array[v].setCost(parent_cost+parent_to_child);
        node_array[v].setPredecessor(u);
    }else{
        if(child_cost>parent_cost+parent_to_child){
            node_array[v].setCost(parent_cost+parent_to_child);
            node_array[v].setPredecessor(u);
        }
    }
}

//public function
void Dijkstra::dijkstraPath(){
    if(isConnected()){
        priority_queue<node,vector<node>,comparable>pq;
        int temp = source;
        node current;
        if(!node_array[temp].isVisited()){
            node_array[temp].setCost(0);
            node_array[temp].setPredecessor(temp);
            node_array[temp].setVisited(true);
            pq.push(node_array[temp]);
        }
        while(!pq.empty()){
            for(int j=0;j<vertex;j++){
                if(matrix[temp][j]!=-1 && matrix[temp][j]!=0){
                    if(!node_array[j].isVisited()){
                        relax_edge(temp,j);
                        pq.push(node_array[j]);
                    }
                }
            }
            pq.pop();
            current = pq.top();
            temp = current.getId();
            node_array[temp].setVisited(true);
        }
    }else{
        cout<<"source is not connected"<<endl;
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
        cout<<",Node predecessor "<<node_array[i].getPredecessor();
        cout<<",Node status "<<node_array[i].isVisited()<<endl;
    }

}
