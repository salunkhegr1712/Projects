#include<stdio.h>
#include<stdlib.h>

typedef struct graph{
    int vertices;
    int **matrix;

}graph;

void init_graph(graph *g,int size);
void add_edge(graph *g,int source,int destination, int cost);
void display(graph g,int size);
void PRIM_MST(graph g);
//void display_MST(int **MST, int vertices);
