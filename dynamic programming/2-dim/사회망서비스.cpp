#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#include <vector>

const int MAX = 1000000;
vector<int> adj[MAX], child[MAX];
bool visited[MAX], picked[MAX][2];
int n, cache[MAX][2];

void dfs(int curr){
    visited[curr] = true;
    for(int next: adj[curr]){
        if(!visited[next]){
            child[curr].push_back(next);
            dfs(next);
        }
    }
}

int func(int curr, bool pe){
    int &ret = cache[curr][pe];
    if(ret != -1) return ret;

    int notpick = MAX+1, pick = 1;
    for(int next: child[curr])
        pick += func(next, true);
        
    if(pe){
        notpick = 0;
        for(int next: child[curr])
            notpick += func(next, false);
    }
    picked[curr][pe] = (pick < notpick);
    return ret = min(notpick, pick);
}

void track(int curr, bool pe){
    int notpick = MAX + 1, pick = 1;
    for(int next: child[curr])
        pick += func(next, true);
    if(pe){
        notpick = 0;
        for(int next:child[curr])
            notpick += func(next, false);
    }
    if(pick < notpick){
        printf("%dth man is EA\n", curr+1);
        for(int next: child[curr])
            track(next, true);
    }
    else{
        for(int next: child[curr])
            track(next, false);
    }
}

void track2(int curr, bool pe){
    if(picked[curr][pe]){
        printf("%dth man is EA\n", curr+1);
        for(int next: child[curr])
            track2(next, true);
    }
    else{
        for(int next: child[curr])
            track2(next, false);
    }
}

int main(){
    cin >> n;
    for(int i = 0; i<n-1; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);

    memset(cache, -1, sizeof(cache));
    cout << func(0, true) << endl;
    track2(0, true);
}