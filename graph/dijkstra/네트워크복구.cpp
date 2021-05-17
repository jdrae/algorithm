#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int,int> P;
const int MAX = 1001;
const int INF = 1000 * 10 + 1;

int main(){
    vector<P> adj[MAX];
    int dist[MAX];
    int prev[MAX];
    priority_queue<P> pq;

    int n, m; cin >> n >> m;
    int u, v, w;
    for(int i = 0; i<m; i++){
        cin >> u >> v >> w;
        adj[u].push_back(P(w,v));
        adj[v].push_back(P(w,u));
    }

    fill(dist, dist+MAX, INF);
    pq.push(P(0,1));
    dist[1] = 0;

    while(!pq.empty()){
        int curr = pq.top().second;
        int currd = -pq.top().first;
        pq.pop();

        if(dist[curr] < currd) continue;

        for(auto &p : adj[curr]){
            int nxt = p.second; int d = p.first;
            int nd = d + dist[curr];
            if(dist[nxt] > nd){
                dist[nxt] = nd;
                prev[nxt] = curr;
                pq.push(P(-dist[nxt], nxt));
            }
        }
    }

    printf("%d\n", n-1);
    for(int i = 2; i<=n; i++){
        printf("%d %d\n", prev[i], i);
    }
}