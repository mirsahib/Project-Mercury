#include <iostream>
#include "Graph.h"
#include "Edge.h"

using namespace std;

int main()
{
    Graph g(6,70);
    g.display_matrix();
    g.makeMst();
    g.displayMST();

    return 0;
}
