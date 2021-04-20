#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#include <vector>

int n, k, w;
vector<vector<int>> adj;
int times[1000], cache[1000];

int func(int curr){ // 0 에서 curr 까지 최소 시간
    int& ret = cache[curr];
    if(ret != -1) return ret;
    ret = 0;
    // printf("%d visited\n", curr+1);
    for(int before: adj[curr]){
        ret = max(ret, func(before));
    }
    return ret += times[curr];
}

int main(){
    int t; cin >> t;
    while(t--){
        memset(cache,-1, sizeof(cache));
        adj.clear();

        cin >> n >> k;
        adj.resize(n);
        for(int i = 0; i<n; i++)
            cin >> times[i];
        int u, v; 
        for(int i = 0; i<k; i++){
            cin >> u >> v;
            adj[v-1].push_back(u-1);
        }
        cin >> w;
        printf("%d\n", func(w-1));
    }
}