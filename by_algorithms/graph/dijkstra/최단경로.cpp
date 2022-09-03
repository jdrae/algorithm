#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int MAX = 20000;
const int INF = 1000000000;
typedef pair<int,int> P;

int main(){
    vector<P> adj[MAX];
    bool visited[MAX] = {0};
    int dist[MAX];
    priority_queue<P, vector<P>, greater<P>> pq;

    int n, e, start;
    cin >> n >> e >> start;
    start--;
    for(int i = 0; i<e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u-1].push_back(P(v-1,w));
    }

    fill(dist, dist+MAX, INF);
    dist[start] = 0;
    pq.push(P(0,start));
    while(!pq.empty()){
        int curr;
        do{
            curr = pq.top().second;
            pq.pop();
        } while(!pq.empty() && visited[curr]);
        if(visited[curr]) break;

        visited[curr] = true;
        for(auto &p: adj[curr]){
            int nxt = p.first, d = p.second;
            if(dist[nxt] > dist[curr] + d){
                dist[nxt] = dist[curr] + d;
                pq.push(P(dist[nxt], nxt));
            }
        }
    }

    for(int i = 0; i<n; i++){
        if(dist[i] == INF) puts("INF");
        else printf("%d\n", dist[i]);
    }

}