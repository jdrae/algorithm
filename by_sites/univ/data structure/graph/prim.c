#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#define N 5
#define INF 10000
int dist[N];

int getMinVertex(){
    int v;
    Vertex* p = vHead;
    for(; p != NULL; p=p->next){
        if(p->visited == 0){
            v = p->num - 1;
            break;
        }
    }

    for(p=vHead; p != NULL; p=p->next){
        if(p->visited ==0 && (dist[p->num -1] < dist[v]))
            v = p->num -1;
    }

    return v;
}

void prim(Vertex* v){
    IncidentEdge* q;
    Vertex* p;
    int u;

    for(int i = 0; i<N; i++)
        dist[i] = INF;
    dist[v->num-1] = 0;

    for(int i = 0; i< N; i++){
        u = getMinVertex();
        p = findVertex(u+1);
        p->visited = 1;
        printf("[%d] ", p->num);

        for(q = p->top; q!=NULL; q = q->next){
            p = findVertex(q->adjVertex);
            if(p->visited == 0)
                dist[q->adjVertex-1] = q->weight;
        }
    }
}

int main(){
    for(int i =0; i<N; i++)
        makeVertices();

    insertWeightedEdges(1,2,1);
    insertWeightedEdges(1,4,2);
    insertWeightedEdges(1,5,4);
    insertWeightedEdges(2,3,6);
    insertWeightedEdges(2,5,7);
    insertWeightedEdges(3,5,5);
    insertWeightedEdges(4,5,3);

    print();
    prim(vHead);
}