#include <iostream>
using namespace std;

int arr[10001], p[10001];

int find(int a){
    if(p[a] < 0) return a;
    p[a] = find(p[a]);
    return p[a];
}

void merge(int a, int b){
    a = find(a); b = find(b);
    if(a==b) return; // tip
    if(arr[a] <= arr[b]) p[b] = a;
    else p[a] = b;
}

int main(){
    int n, m, k, a, b;
    scanf("%d %d %d", &n, &m, &k);
    fill(p, p + n + 1, -1);
    
    for(int i =1; i<=n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < m ; i++){
        scanf("%d %d", &a, &b);
        merge(a,b);
    }

    int cost = 0;
    for(int i = 1; i<=n; i++){
        if(p[i] == -1) cost += arr[i];
    }

    if(cost <= k) printf("%d\n", cost);
    else printf("Oh no\n");
    return 0;
}