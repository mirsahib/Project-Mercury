#include <iostream>
#include "Graph.h"


using namespace std;

int main()
{
    Graph g(6,50);
    g.display_matrix();
    g.detectCycle();
    g.display();
    return 0;
}
