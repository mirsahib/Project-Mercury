//============================================================================
// Name        : Dijkstra.cpp
// Author      : Mir Habib Ul Latif
// ID          : 1510175
// Copyright   :
// Description : Single source shortest path,non negative weighted graph
//============================================================================

#include <iostream>
#include <dijkstra.h>

using namespace std;

int main(){
    Dijkstra d(6,70,5,2);
    d.display_matrix();
    d.dijkstraPath();
    //d.display_node();
    d.showPath();

    return 0;
}
