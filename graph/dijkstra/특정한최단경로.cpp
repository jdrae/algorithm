#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int MAX = 800;
const int INF = 800 * 1000;
typedef pair<int,int> P;
vector<P> adj[MAX];
int dist[MAX];
int n, e;

int dijkstra(int start, int end){
    bool visited[MAX] = {0};
    priority_queue<P, vector<P>, greater<P>> pq;
    
    fill(dist, dist+MAX, INF);
    dist[start] = 0;
    pq.push(P(0, start));
    while(!pq.empty()){
        int curr;
        do{
            curr = pq.top().second;
            pq.pop();
        } while(!pq.empty() && visited[curr]);
        if(visited[curr]) break;

        visited[curr] = true;
        for(auto &p : adj[curr]){
            int nxt = p.second, d = p.first;
            if(dist[nxt] > dist[curr] + d){
                dist[nxt] = dist[curr] + d;
                pq.push(P(dist[nxt], nxt));
            }
        }
    }

    return dist[end];
}

int makepath(int v1, int v2){
    return dijkstra(0, v1) + dijkstra(v1, v2) + dijkstra(v2, n-1);
}

int main(){
    cin >> n >> e;
    int u, v, w;
    for(int i = 0; i<e; i++){
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back(P(w,v));
        adj[v].push_back(P(w,u));
    }
    int v1, v2;
    cin >> v1 >> v2;
    v1--; v2--;
    
    int ans = min(makepath(v1, v2), makepath(v2, v1));
    if(ans >= INF) ans = -1;
    cout << ans << endl;
}