#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "queue.h"

int in[6];

void inDegree(){
    Vertex* p = vHead;
    IncidentEdge* q;
    for(;p!=NULL; p=p->next)
        for(q = p->top; q!=NULL; q= q->next)
            in[q->adjVertex-1]++;
}

void topologicalSort(){
    Queue q;
    initQueue(&q);
    Vertex* p;
    IncidentEdge* r;
    inDegree();

    for(int i = 0; i<6; i++){
        if(in[i] == 0)
            enqueue(&q, i+1);
    }

    while(!isEmpty(&q)){
        int w = dequeue(&q);
        printf("[%d] ", w);
        p = findVertex(w);
        r = p->top;
        while(r != NULL){
            in[r->adjVertex - 1] --;
            if(in[r->adjVertex-1] == 0)
                enqueue(&q, r->adjVertex);
            r=r->next;
        }
    }
}

int main(){
    for(int i = 0; i<6; i++)
        makeVertices();
    insertDirectionEdges(1,2);
    insertDirectionEdges(1,5);
    insertDirectionEdges(2,3);
    insertDirectionEdges(4,5);
    insertDirectionEdges(5,2);
    insertDirectionEdges(5,3);
    insertDirectionEdges(5,6);
    insertDirectionEdges(6,3);
    print();

    topologicalSort();
}