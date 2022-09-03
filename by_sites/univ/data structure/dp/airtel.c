#include <stdio.h>
#include <stdlib.h>

#define max(x,y) (x>y) ? x : y
#define min(x,y) (x<y) ? x : y

int A[] = {0,1,3,6,11,17};
int H[] = {0,2,5,1,5,0};
int m[10];

// recursive
int rAirtelForward(int d){
    if (d==0) return 0;

    int minCost = 10000;
    int cost;

    for(int k = 0; k<d; k++){
        cost = rAirtelForward(k) + H[k] + A[d-k];
        minCost = min(minCost, cost);
    }
    return minCost;
}

// dp
int airtelForward(int n){
    m[0] = 0;
    int cost;
    for(int d = 1; d<n; d++){
        m[d] = 10000;
        for(int k = 0; k<d; k++){
            cost = m[k] + H[k] + A[d-k];
            m[d] = min(m[d], cost);
        }
    }
    return m[n-1];
}

int main(){
    // printf("%d", rAirtelForward(5));
    printf("%d", airtelForward(6));
    return 0;
}