#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct{
    int element[N];
    int front, rear;
} Queue;

void initQueue(Queue* q){
    q->front = 0;
    q->rear = 0;
}

int isEmpty(Queue* q){
    return q->rear == q->front;
}

int isFull(Queue* q){
    return (q->rear + 1) % N == q->front;
}

void enqueue(Queue* q, char elem){
    if(isFull(q)){
        printf("FULL\n");
        return;
    }
    q->rear = (q->rear+1) % N;
    q->element[q->rear] = elem;
}

char dequeue(Queue* q){
    if(isEmpty(q)){
        printf("EMPTY\n");
        return "e";
    }
    q->front = (q->front+1)%N;
    return q->element[q->front];
}