#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int MAX = 1000;
const int INF = 100000 * 1000;
typedef pair<int,int> P;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<P> adj[MAX];
    bool visited[MAX] = {0};
    int dist[MAX];
    priority_queue<P, vector<P>, greater<P>> pq;

    int n, m;
    cin >> n >> m;
    int u, v, w;
    for(int i = 0; i<m; i++){
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back(P(v,w));
        adj[v].push_back(P(v,w));
    }
    int start, end;
    cin >> start >> end;
    start--; end--;
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
            int nxt = p.first, d = p.second;
            if(dist[nxt] > dist[curr] + d){
                dist[nxt] = dist[curr] + d;
                pq.push(P(dist[nxt], nxt));
            }
        }
    }

    printf("%d\n", dist[end]);

}