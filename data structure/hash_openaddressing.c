#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 13

typedef struct{
    int key;
    int probeCount;
} Bucket;

typedef struct{
    Bucket arr[M];
} HashType;

void initHash(HashType* h){
    for(int i = 0; i<M; i++){
        h->arr[i].key = 0;
        h->arr[i].probeCount = 0;
    }
}

int hash(int key){
    return key % M;
}

int hash2(int key){
    return 11 - (key % 11);
}

int getNextBucketLinear(int v, int i){
    return (v+i) % M;
}


int getNextBucketQuadratic(int v, int i){
    return (v+i*i) % M;
}


int getNextBucketDouble(int v, int i, int key){
    return (v+i * hash2(key)) % M;
}


int isEmpty(HashType* h, int b){
    return h->arr[b].key == 0;
}

void insertItem(HashType* h, int key){
    int v = hash(key);
    int i = 0;
    int count = 0;
    while(i<M){
        count ++;
        int b = getNextBucketLinear(v,i);
        // int b = getNextBucketQuadratic(v,i);
        // int b = getNextBucketLinear(v,i);
        if(isEmpty(h, b)){
            h->arr[b].key = key;
            h->arr[b].probeCount = count;
            return;
        }
        else i++;
    }
}

int findElement(HashType* h, int key){
    int v = hash(key);
    int i = 0;
    while(i<M){
        int b = getNextBucketLinear(v,i);
        // int b = getNextBucketQuadratic(v,i);
        // int b = getNextBucketLinear(v,i);
        if(isEmpty(h, b)){
            return 0;
        }
        else if(h->arr[b].key == key){
            return key;
        }
        else{
            i++;
        }
    }
    return 0;
}

int removeElement(HashType* h, int key){
    int v = hash(key);
    int i = 0;

    while(i<M){
        int b = getNextBucketLinear(v,i);
        if(isEmpty(h, b)) return 0;
        else if(h->arr[b].key == key){
            h -> arr[b].key = 0;
            return key;
        }
        else i++;
    }
    return 0;
}

void printHashTable(HashType* h){
    printf("Bucket  Key  Probe\n");
    printf("======================\n");
    for(int i = 0; i<M; i++)
        printf("HT[%02d]: %2d   %d\n", i, h->arr[i].key, h->arr[i].probeCount);
}

int main(){
    HashType h;
    initHash(&h);
    insertItem(&h, 25);
    insertItem(&h, 13);
    insertItem(&h, 16);
    insertItem(&h, 15);
    insertItem(&h, 7);
    insertItem(&h, 28);
    insertItem(&h, 31);
    insertItem(&h, 20);
    insertItem(&h, 1);
    insertItem(&h, 38);

    printHashTable(&h);

    int key = 20;
    if(findElement(&h, key)){
        printf("\nfound element %d", key);
    } else{
        printf("\nnot found element %d", key);
    }

    key = 20;
    if(removeElement(&h, key)){
        printf("\nremoved element %d", key);
    } else{
        printf("\nnot found element %d", key);
    }

    printHashTable(&h);

}