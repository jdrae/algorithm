#include <stdio.h>
#include <stdlib.h>

typedef struct Edge{
    int vNum1;
    int vNum2;
    int isTree;
    struct Edge* next;
}Edge;

typedef struct IncidentEdge{
    int adjVertex;
    Edge* e;
    struct IncidentEdge* next;
}IncidentEdge;

typedef struct Vertex{
    int num;
    int visited;
    struct Vertex* next;
    IncidentEdge* top;
}Vertex;

Vertex* vHead = NULL; Edge* eHead = NULL;
int vCount = 0; int eCount = 0;

void makeVertices(){
    Vertex* p = (Vertex*)malloc(sizeof(Vertex));
    p->num = ++vCount;
    p->top = NULL;
    p->next = NULL;
    p->visited = 0;

    Vertex* q = vHead;
    if(q==NULL)
        vHead = p;
    else{
        while(q->next!=NULL)
            q = q->next;
        q->next = p;
    }
}

Vertex* findVertex(int v){
    Vertex* p = vHead;
    while(p->num != v)
        p = p->next;
    return p;
}

void insertIncidentEdge(Vertex* v, int av, Edge* e){
    IncidentEdge* p = (IncidentEdge*)malloc(sizeof(IncidentEdge));
    p->adjVertex = av;
    p->e = e;
    p->next = NULL;
    IncidentEdge* q = v->top;
    if(q==NULL)
        v->top = p;
    else{
        while(q->next != NULL)
            q = q->next;
        q->next = p;
    }

}

void insertEdges(int v1, int v2){
    Edge* p = (Edge*)malloc(sizeof(Edge));
    p->vNum1 = v1;
    p->vNum2 = v2;
    p->isTree = 0;
    p->next = NULL;
    Edge* q = eHead;

    if(q==NULL)
        eHead = p;
    else{
        while(q->next!=NULL)
            q = q->next;
        q->next = p;
    }

    Vertex* v = findVertex(v1);
    insertIncidentEdge(v, v2, p);
    v = findVertex(v2);
    insertIncidentEdge(v, v1, p);
}

void print(){
    Vertex* p = vHead;
    IncidentEdge* q;
    for(; p!=NULL; p=p->next){
        printf("Vertex %d: ", p->num);
        for(q=p->top; q!=NULL; q=q->next){
            printf("[%d] ", q->adjVertex);
        }
        printf("\n");
    }
}