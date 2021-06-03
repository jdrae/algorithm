#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void dfs(Vertex* v){
    IncidentEdge* q;
    if(v->visited == 0){
        printf("[%d] ", v->num);
        v->visited = 1;
    }
    for(q = v->top; q!= NULL; q= q->next){
        v = findVertex(q->adjVertex);
        if(v->visited == 0)
            dfs(v);
    }
}

int main(){
    for(int i = 0; i<9; i++)
        makeVertices();
    insertEdges(1,2);
    insertEdges(1,3);
    insertEdges(2,4);
    insertEdges(2,5);
    insertEdges(3,5);
    insertEdges(3,6);
    insertEdges(4,7);
    insertEdges(5,7);
    insertEdges(5,8);
    insertEdges(6,8);
    insertEdges(7,9);
    insertEdges(8,9);
    print();

    dfs(vHead);
}