#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 15

typedef struct{
    int key;
    char value[10];
} element;

typedef struct{
    element dict[SIZE];
    int size;
} DictType;

void init(DictType* d){
    d->size = 0;
}

void insertKey(DictType* d){
    for(int i = 0; i<SIZE; i++){
        d->dict[i].key = rand() % 30 +1;
        for(int j = 0; j<i; j++)
            if(d->dict[i].key == d->dict[j].key) i--;
    }
}

void insertValue(DictType* d){
    for(int i = 0; i<SIZE; i++){
        for(int j = 0; j<5; j++)
            d->dict[i].value[j] = rand()%26 + 97;
        d->size++;
    }
}

void insertion_sort(DictType* d){
    int i, j;
    element item;
    for(i = 1; i<SIZE; i++){
        item = d->dict[i];
        for(j = i-1; j>=0 && d->dict[j].key > item.key; j--)
            d->dict[j+1] = d->dict[j];
        d->dict[j+1] = item;
    }
}

int rFindElement(DictType* d, int key, int l , int r){
    int mid;
    if(l<=r){
        mid = (l+r) / 2;
        if(key == d->dict[mid].key) return mid;
        else if(key < d->dict[mid].key)
            return rFindElement(d, key, l, mid-1);
        else
            return rFindElement(d, key, mid+1, r);
    }
    return -1;
}

int findElement(DictType* d, int key, int l , int r){
    int mid;
    while(l<=r){
        mid = (l+r) / 2;
        if(key == d->dict[mid].key) return mid;
        else if(key < d->dict[mid].key)
            r = mid-1;
        else
            l = mid+1;
    }
    return -1;
}

element removeElement(DictType* d,int key){
    int index = findElement(d, key, 0, d->size-1);
    if(index == -1){
        printf("no index to remove\n");
        return;
    }
    else{
        element item = d->dict[index];
        for(int i = index; i<d->size-1; i++)
            d->dict[i] = d->dict[i+1];
        d->size--;
        return item;
    }
}

void printDict(DictType* d){
    printf("\n===========\n");
    for(int i = 0; i<d->size; i++){
        printf("%2d ", d->dict[i].key);
        for(int j = 0; j<5; j++){
            printf("%c",d->dict[i].value[j]);
        }
        printf("\n");
    }
}

void makeDict(DictType* d){
    insertKey(d);
    insertValue(d);
}

int main(){
    DictType d;
    init(&d);
    srand(time(NULL));
    makeDict(&d);
    insertion_sort(&d);
    printDict(&d);

    int key = 15;
    printf("\nfind %d\n",key );
    int index = rFindElement(&d, key, 0, SIZE-1);
    if(index==-1)
        printf("no index");
    else{
        printf("location %d key %d: ", index+1, key);
        for(int j = 0; j<5; j++)
            printf("%c", d.dict[index].value[j]);
    }
    key = 22;
    printf("\nfind %d\n",key );
    index = findElement(&d, key, 0, SIZE-1);
    if(index==-1)
        printf("no index");
    else{
        printf("location %d key %d: ", index+1, key);
        for(int j = 0; j<5; j++)
            printf("%c", d.dict[index].value[j]);
    }

    printf("\ndelete:");
    scanf("%d", &key);
    removeElement(&d, key);
    printDict(&d);
}