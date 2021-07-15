#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void init_graph(graph *g, int size){
    g->vertices = size;
    g->matrix = (int**)malloc(sizeof(int*)*size);
    for(int i=1; i<=size; i++){
        g->matrix[i] = (int*)malloc(sizeof(int)*size);
        for(int j = 1; j <= size; j++){
            g->matrix[i][j] = INT_MAX;
        }
    }
    return;
}


void add_edge(graph *g, int source, int destination, int cost){
    g->matrix[source][destination] = cost;
    g->matrix[destination][source] = cost;
    return;
}


void display(graph g,int size){
    for(int i=1; i <= size ; i++){
        for(int j=1; j <= size ; j++){
            if(g.matrix[i][j] != INT_MAX){
                printf("%d\t", g.matrix[i][j]);
            }
            else{
                printf("%d",INT_MAX);
            }
        }
        printf("\n");
    }
    return;
}


void PRIM_MST(graph g){

    //vertices index start from 0.
    int* near = (int *)malloc(sizeof(int)*g.vertices);

    for (int i = 0; i <= g.vertices; i++){

        near[i] = INT_MAX;

    }

    int **MST = (int *)malloc(sizeof(int *)*2);

    MST[0] = (int*)malloc(sizeof(int)*(g.vertices-1));
    MST[1] = (int*)malloc(sizeof(int)*(g.vertices-1));

    int u, v, min = INT_MAX;

    for (int i = 0; i < g.vertices; i++){

        for (int j = i; j < g.vertices; j++){

            if (g.matrix[i][j] < min){

                min = g.matrix[i][j];
                u = i;
                v = j;

            }

        }

    }

    MST[0][0] = u;
    MST[1][0] = v;


    for (int p = 1; p < g.vertices-1; p++){


        //mark visited for u, v in near array.
        near[u] = 0;
        near[v] = 0;

        //update the near array for previously found edge
        for (int i = 0; i < g.vertices; i++){

            // if (near[i] == -1){

            //     continue;

            // }

            if (near[i] != 0 && g.matrix[i][u] < g.matrix[i][v]){

                near[i] = u;

            }

            else {
                if (near[i] != 0)
                    near[i] = v;

            }

        }


        min = INT_MAX;

        //find the new, adjacent edge in the spanning tree from the given graph.
        for (int q = 0; q < g.vertices; q++){


            if (near[q] != 0){

                if (g.matrix[q][near[q]] < min){

                    min = g.matrix[q][near[q]];
                    u = q;
                    v = near[q];

                }

            }

        }


        MST[0][p] = v;
        MST[1][p] = u;


    }

    for(int i=0;i<2;i++){
        printf("\n");
        for(int j=0;j<g.vertices-1;j++){
            printf("%d ",MST[i][j]);
        }
        printf("\n");
    }
    return;

}




