#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 6
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

void bubble_sort(int list[], int n){
    int temp;
    for(int i = n-1; i > 0; i--){
        printf("\nSTEP %d>> ", n-i);
        for(int j = 0; j < i; j++){
            if(list[j] > list[j+1])
                SWAP(list[j], list[j+1], temp);
        }
        for (int t =0; t<n; t++){
            printf("%3d ", list[t]);
        }
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

    bubble_sort(list, MAX_SIZE);
}