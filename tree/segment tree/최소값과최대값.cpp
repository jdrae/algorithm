#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define ST_MAX 262144 + 1
#define MAX 1000000001
#define MIN 0

struct MinSegTree{
    int start, arr[ST_MAX];
    MinSegTree(int n){
        start = 1;
        while(start < n) start *= 2;
        fill(arr, arr+ST_MAX, MAX);
    }
    void construct(){
        for(int i = start-1; i>0; i--)
            arr[i] = min(arr[i*2], arr[i*2+1]);
    }
    int find(int l, int r, int node, int nl, int nr){
        if(nl > r || nr < l) return MAX;
        if(l <= nl && nr <= r) return arr[node];
        int mid = (nl+nr) /2;
        return min(find(l,r,node*2, nl, mid), find(l,r,node*2+1,mid+1,nr));
    }
};

struct MaxSegTree{
    int start, arr[ST_MAX];
    MaxSegTree(int n){
        start = 1;
        while(start < n) start *= 2;
        fill(arr, arr+ST_MAX, MIN);
    }
    void construct(){
        for(int i = start-1; i>0; i--)
            arr[i] = max(arr[i*2], arr[i*2+1]);
    }
    int find(int l, int r, int node, int nl, int nr){
        if(nl > r || nr < l) return MIN;
        if(l <= nl && nr <= r) return arr[node];
        int mid = (nl+nr) /2;
        return max(find(l,r,node*2, nl, mid), find(l,r,node*2+1,mid+1,nr));
    }
};


int main(){
    int n,m; scanf("%d%d",&n,&m);
    MinSegTree MinST(n);
    MaxSegTree MaxST(n);
    int tmp;
    for(int i = 0; i<n; i++){
        scanf("%d", &tmp);
        MinST.arr[MinST.start + i] = tmp;
        MaxST.arr[MaxST.start + i] = tmp;
    }
    MinST.construct();
    MaxST.construct();

    int a, b;
    for(int i = 0; i<m; i++){
        scanf("%d%d",&a,&b);
        printf("%d %d\n", MinST.find(a,b,1,1,MinST.start), MaxST.find(a,b,1,1,MaxST.start));
    }
}