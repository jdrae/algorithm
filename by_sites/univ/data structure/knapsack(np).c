#include <stdio.h>
#include <stdlib.h>

#define N 100

int weight[N], value[N], cap;
int maxSet[N], maxSetSize= 0; maxValue = 0;

void print(int arr[], int n){
    for(int i = 0; i < n; i ++){
        printf("[%d] ", arr[i]);
    }
    printf("\n");
}

void eval_knapsack(int arr[], int setSize){
    int currWeight = 0, currValue = 0;
    for(int i = 0; i<setSize; i++){
        currWeight += weight[arr[i]];
        currValue += value[arr[i]];
    }
    if(currWeight > cap) return;
    if(currValue > maxValue){
        maxValue = currValue;
        maxSetSize = setSize;
        for(int i = 0; i<setSize; i++)
            maxSet[i] = arr[i];
    }
}

void subset_knapsack(int arr[], int setSize, int n, int idx){
    if(idx == n){
        // print(arr, setSize);
        eval_knapsack(arr, setSize);
        return;
    }
    arr[setSize] = idx;
    subset_knapsack(arr, setSize+1, n, idx + 1); // 포함
    subset_knapsack(arr, setSize, n, idx + 1);
}

int main(){
    int arr[N], n;
    scanf("%d %d", &n, &cap);
    for(int i = 0; i<n; i++)
        scanf("%d", &value[i]);
    for(int i = 0; i<n; i++)
        scanf("%d", &weight[i]);
    subset_knapsack(arr,0,n,0);

    printf("max value: %d\n", maxValue);
    print(maxSet, maxSetSize);
}