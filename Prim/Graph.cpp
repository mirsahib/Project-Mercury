#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Edge.h"
#include "PriorityQueue.h"
#include "node.h"
#include "Graph.h"

using namespace std;

//constructor
Graph::Graph(int v,float per_of_con){
    this->vertex = v;//no. of node initialize
    this->connect_per = per_of_con;//connection percentage
    node_array = new node[vertex];//create label array

    this->matrix = new int*[vertex];
    edge = new Edge[100];
    no_of_edge=0;

    for(int i=0;i<vertex;i++){
        this->matrix[i] = new int[vertex];//create 2d matrix
    }
    initialize_matrix();
    initialize_node();
}
//private function
void Graph::initialize_matrix(){
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
void Graph::initialize_node(){
    for(int i=0;i<vertex;i++){
        node_array[i].setId(i);
    }
}

//calculate the number of connection for the given percentage
int Graph::no_of_connection(){
    float percent = connect_per/100;
    int node = (vertex*(vertex-1))/2;// n(n-1)/2 formula for fully connected graph
    return node*percent;
}
void Graph::relaxEdge(int u,int v,PriorityQueue &pq){
    int parent_cost = node_array[u].getCost();
    int child_cost = node_array[v].getCost();
    int parent_to_child_cost = matrix[u][v];

    if(node_array[v].getCost()==-1){
        node_array[v].setCost(parent_to_child_cost);
        node_array[v].setPredecessor(u);
        pq.push(node_array[v]);
    }else{
        if(child_cost>parent_cost+parent_to_child_cost){
            pq.removeElement(node_array[v]);
            node_array[v].setCost(parent_to_child_cost);
            node_array[v].setPredecessor(u);
            pq.push(node_array[v]);
            //pq.display();

        }
    }

}
void Graph::makeMst(){
    int temp=0;
    PriorityQueue pq;
    int u,v,weight;
    node_array[temp].setCost(0);
    node_array[temp].setPredecessor(0);
    node_array[temp].setId(0);
    node_array[temp].setVisited(true);
    pq.push(node_array[temp]);
    while(!pq.isEmpty()){
        for(int j=0;j<vertex;j++){
            if(matrix[temp][j]!=-1 && matrix[temp][j]!=0){
                if(!node_array[j].isVisited()){
                    relaxEdge(temp,j,pq);
                }
            }
        }
        //pq.display();
        u = pq.peek().getPredecessor();
        v = pq.peek().getId();
        weight = pq.peek().getCost();
        edge[no_of_edge].setEdge(u,v,weight);
        no_of_edge++;
        pq.pop();
        //pq.display();
        temp = pq.peek().getId();
        node_array[temp].setVisited(true);
    }
}
bool Graph::inMstSet(int index){
    for(int i=0;i<vertex;i++){
        if(mstSet[i]==index){
            return true;
        }
    }
    return false;
}

void Graph::display_matrix(){
    cout<<"Sample Graph"<<endl;
    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            cout<<setw(3)<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void Graph::displayMST(){
    cout<<"Minimum spanning tree"<<endl;
    cout<<"Edge"<<"  "<<"weight"<<endl;
    for(int i=1;i<no_of_edge;i++){
        edge[i].displayTree();
    }
}
