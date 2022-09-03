#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 15
#define SWAP(x,y,t) ((t)=(x), (x)=(y),(y)=(t))

void insertion_sort(int list[], int n){
    int i, j, save;
    for(i = 1; i<n; i++){
        save = list[i];
        for(j = i-1; j>=0 && list[j] > save; j--)
            list[j+1] = list[j];
        list[j+1] = save;
    }
}

void main(){
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

    insertion_sort(list, MAX_SIZE);
    for(int i = 0; i<MAX_SIZE; i++)
        printf("%d ", list[i]);
    printf("\n");
}