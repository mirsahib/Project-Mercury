#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <queue>
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
    srand(time(0));
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
}

int Dijkstra::no_of_connection(){
    float percent = connect_per/100;
    int node = (vertex*(vertex-1))/2;
    return node*percent;
}


//public function
void Dijkstra::dijkstraPath(){
    priority_queue<node> nodeCost;

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
