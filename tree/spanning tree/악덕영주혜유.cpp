#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 1001;

int n,m;
vector<pair<int,int>> path[MAX];
int visited[MAX];

int uf[MAX];
int find(int a){
    if(uf[a]<0) return a;
    return uf[a] = find(uf[a]);
}
int merge(int a, int b){
    a = find(a); b = find(b);
    if(a==b) return false;
    uf[b] = a;
    return true;
}

// 현재 value 일 때, curr 에서 출발하여 마지막으로 도착하는(nxt 가 없을 때까지) 값의 최대값
int dfs(int curr, int value){
    visited[curr] = 1;
    int res = 0;
    for(auto &p : path[curr]){
        int nxt = p.first, w = p.second;
        if(visited[nxt]) continue;
        res = max(res, dfs(nxt, value+w));
    }
    if(res == 0) return value; // nxt 가 없는 마지막 값
    return res;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n>> m;
    int u, v, w;
    priority_queue<pair<int, pair<int, int> > > pq;
    for(int i = 0; i<m; i++){
        cin >> u >> v>> w;
        pq.push({-w,{u,v}});
    }
    fill(uf, uf+MAX,-1);
    int mst = 0, cnt = 0;
    while(!pq.empty()){
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        int w = -pq.top().first;
        if(merge(u, v)){
            mst += w;
            path[u].push_back({v,w});
            path[v].push_back({u,w});
            if(++cnt == m-1) break;
        }
        pq.pop();
    }

    int mx = 0;
    for(int i = 0; i<n; i++){
        fill(visited, visited+MAX, 0);
        mx = max(mx, dfs(i, 0));
    }

    printf("%d\n%d\n", mst, mx);
}
