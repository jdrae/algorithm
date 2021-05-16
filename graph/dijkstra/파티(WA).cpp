#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int MAX = 1000;
const int INF = 10000 * 100;
typedef pair<int,int> P;
vector<P> adj[MAX];
vector<vector<int>> dist(MAX, vector<int>(MAX, INF));

int main(){
    int n, m, x;
    cin >> n >> m >> x;
    int u, v, w;
    for(int i = 0; i<m; i++){
        cin >> u >> v >> w;
        adj[--u].push_back(P(w, --v));
    }

    for(int i = 0; i<n; i++){
        priority_queue<P> pq;
        pq.push(P(0,i));
        dist[i][i] = 0;
        while(!pq.empty()){
            int curr = pq.top().second;
            pq.pop();
            
            for(auto &p : adj[curr]){
                int nxt = p.second; int d = p.first;
                if(dist[i][nxt] > dist[i][curr] + d){
                    dist[i][nxt] = dist[i][curr] + d;
                    pq.push(P(dist[i][nxt], nxt));
                }
            }
        }
    }

    int mx = 0;
    for(int i = 0; i<n; i++){
        mx = max(mx, dist[i][x] + dist[x][i]);
    }
    cout << mx << endl;
}