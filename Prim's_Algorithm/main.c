#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main()
{
    printf("Hello world!\n");
    //int **t;
    graph g, g1;
    init_graph(&g, 5);
    init_graph(&g1, 5);

    add_edge(&g, 1, 2,1);

    add_edge(&g, 1, 3, 2);
    add_edge(&g, 1, 4, 3);
    add_edge(&g, 2, 3, 5);
    add_edge(&g, 3, 4, 4);
    display(g, 4);

    PRIM_MST(g);

    //display_MST(t, 4);

    return 0;
}
