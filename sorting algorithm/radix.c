#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 15
#define BUCKETS 10
#define DIGITS 2
#define SWAP(x,y,t) ((t)=(x), (x)=(y),(y)=(t))

typedef int element;
typedef struct{
    element data[MAX_SIZE];
    int front, rear;
}Queue;

void init_queue(Queue* q){
    q->front = q->rear = 0;
}

int is_empty(Queue* q){
    return q->front == q->rear;
}

int is_full(Queue* q){
    return (q->rear+1)%MAX_SIZE == q->front;
}

void enqueue(Queue* q, element item){
    if(is_full(q)) exit(1);
    q->rear= (q->rear +1) %MAX_SIZE;
    q->data[q->rear] = item;
}

element dequeue(Queue* q){
    if(is_empty(q)) exit(1);
    q->front = (q->front + 1)% MAX_SIZE;
    return q->data[q->front];
}


void radix_sort(int list[], int n){
    int i, bucket, digit, factor = 1;
    Queue qs[BUCKETS];

    for(bucket = 0; bucket < BUCKETS; bucket++){
        init_queue(&qs[bucket]);
    }
    for(digit = 0; digit<DIGITS; digit++){
        for(int i = 0; i<n; i++){
            enqueue(&qs[(list[i]/factor) % 10], list[i]);
        }
        for(bucket = i = 0; bucket < BUCKETS; bucket++){
            while(!is_empty(&qs[bucket])){
                list[i++] = dequeue(&qs[bucket]);
            }
        }
        factor += 10;
    }
}

int main(){
    int list[MAX_SIZE];
    srand(time(NULL));
    for(int i = 0; i<MAX_SIZE; i++){
        list[i] = rand() % 100;
        for(int j = 0; j<i; j++)
            if(list[i] == list[j]) i--;
    }
    for(int i = 0; i<MAX_SIZE; i++)
        printf("%d ", list[i]);
    printf("\n");

    radix_sort(list, MAX_SIZE);
    for(int i = 0; i<MAX_SIZE; i++)
        printf("%d ", list[i]);
    printf("\n");
}