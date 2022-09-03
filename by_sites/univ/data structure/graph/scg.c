#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define TRUE 1
#define FALSE 0

typedef struct{
    int n, m;
    int adj_mat[SIZE][SIZE];
} GraphType;

void init(GraphType* g){
    for(int row = 0; row < SIZE; row++)
        for(int col = 0; col<SIZE; col ++)
            g->adj_mat[row][col] = 0;
}

void insert_edge(GraphType* g, int start, int end){
    if ((start >= g->n) || (end >= g->n)){
        printf("cannot insert an edge\n");
        return;
    }
    g->adj_mat[start][end] = 1;
}

void print_adj_mat(GraphType* g){
    printf("\n");
    for(int row = 0; row<g->n; row++){
        for(int col = 0; col < g->n; col++){
            printf("%d ", g->adj_mat[row][col]);
        }
        printf("\n");
    }
}

void dfs_mat(GraphType* g, int visited[], int v){
    visited[v] = TRUE;
    printf("vertex[%d] ", v+1);
    for(int w = 0; w<g->n; w++)
        if(g->adj_mat[v][w] && !visited[w])
            dfs_mat(g, visited, w);
}

void rev_mat(GraphType* g, int v){
    GraphType r;
    init(&r);
    r.n = g->n;
    int visited[SIZE] = {FALSE, };

    for(int row = 0; row<g->n; row++)
        for(int col = 0; col<g->n; col++)
            r.adj_mat[col][row] = g->adj_mat[row][col];

    print_adj_mat(&r); printf("\n");
    dfs_mat(&r,visited, v-1);
}

void main(){
    GraphType g;
    init(&g);
    int n, m, v;
    int start, end;
    printf("vertex edge: ");
    scanf("%d %d", &g.n, &g.m);

    printf("edge_u edge_v: ");
    for(int i = 0; i<g.m; i++){
        scanf("%d %d", &start, &end);
        insert_edge(&g, start-1, end-1);
    }
    print_adj_mat(&g);

    int visited[SIZE] = {FALSE, };
    printf("start edge: ");
    scanf("%d", &v);
    printf("\n");
    dfs_mat(&g, visited, v-1);
    printf("\n");
    rev_mat(&g, v);
    printf("\n");
    /*
    vertex edge: 7 12
    edge_u edge_v: 
    1 3
    1 4
    1 6
    2 6
    3 7
    4 5
    4 7
    5 2
    6 4
    6 5
    7 1
    7 2
    */
}