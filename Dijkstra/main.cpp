#include <iostream>
#include <dijkstra.h>

using namespace std;

int main(){
    Dijkstra d(6,50,0,4);
    d.display_matrix();
    d.dijkstraPath();
    d.display_node();

    return 0;
}
