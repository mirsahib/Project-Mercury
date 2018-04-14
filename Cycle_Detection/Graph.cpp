#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Edge.h"
#include "node.h"
#include "Graph.h"
#include <stack>

using namespace std;

//constructor
Graph::Graph(int v,float per_of_con){
    this->vertex = v;//no. of node initialize
    this->connect_per = per_of_con;//connection percentage
    node_array = new node[vertex];//create label array
    int cycleCounter=0;
    this->matrix = new int*[vertex];
    pivot_id=0;
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
        if(matrix[x][y]==-1){
            matrix[x][y] = 1;
            matrix[y][x] = 1;
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
void Graph::detectCycle(){
    int temp = 0;
    stack<node>node_list;
    //vector<node>visitedList;
    node_array[temp].setPredecessor(0);
    node_array[temp].setVisited(true);
    node_list.push(node_array[temp]);
    //visitedList.push_back(node_array[temp]);

    while(!node_list.empty()){

        for(int i=0;i<vertex;i++){
            if(matrix[temp][i]!=0 && matrix[temp][i]!=-1){
                if(!node_array[i].isVisited()){
                    node_array[i].setPredecessor(temp);
                    node_list.push(node_array[i]);
                }
            }
        }
        temp = node_list.top().getId();
        if(is_id_visited(temp)){
            cycleCounter=1;
            pivot_id=temp;
            visitedList.push_back(node_list.top());
        }else{
            visitedList.push_back(node_list.top());
        }
        node_array[temp].setVisited(true);
        node_list.pop();
    }

}
bool Graph::is_id_visited(int id){
    for(int i=0;i<visitedList.size();i++){
        int visitedId = visitedList[i].getId();
        if(visitedId==id){
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
void Graph::display(){
    if(cycleCounter==1){
        for(int i=0;i<visitedList.size();i++){
            int id = visitedList[i].getId();
            if(visitedList[i].getId()==pivot_id){
                cout<<visitedList[i].getPredecessor()<<"->";
            }
        }
        cout<<pivot_id;
    }else{
        cout<<"there is no cycle"<<endl;
    }
}
