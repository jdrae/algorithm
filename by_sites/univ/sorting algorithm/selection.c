#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 15
#define SWAP(x,y,t) ((t)=(x), (x)=(y),(y)=(t))

void selection_sort(int list[], int n){
    int least, temp;
    for(int i = 0; i<n-1; i++){
        least = i;
        for(int j = i+1; j < n; j++){
            if(list[j] < list[least]) least = j;
        }
        SWAP(list[i], list[least], temp);
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

    selection_sort(list, MAX_SIZE);
    for(int i = 0; i<MAX_SIZE; i++)
        printf("%d ", list[i]);
    printf("\n");
}