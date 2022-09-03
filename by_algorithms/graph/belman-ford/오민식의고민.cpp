#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> P;
#define ll long long
const int MAX = 100;
const long long INF = 1LL<<60;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<P> adj[MAX];
    int value[MAX], visit[MAX][MAX] = {0};
    int n, s, e, m; cin >> n>>s>>e>>m;
    int u, v, w; 
    while(m--){
        cin >>u>>v>>w;
        adj[u].push_back({v,w});
        visit[u][v] = 1;
    }
    for(int i = 0; i<n; i++){
        cin >> value[i];
        visit[i][i] = 1;
    }

    // tip: 임의의 정점에서 다른 정점으로 방문 가능한지 파악(플로이드)
    for(int k = 0; k<n; k++)
        for(int i = 0; i<n; i++)
            for(int j = 0; j<n; j++)
                if(visit[i][k] && visit[k][j]) visit[i][j] = 1;
    
    // belman-ford
    ll dist[MAX]; fill(dist, dist+MAX, INF);
    dist[s] = -value[s];
    bool cycle = false;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            for(auto &p: adj[j]){
                int nxt = p.first;
                ll d = p.second + dist[j] - value[nxt];
                if(dist[j] != INF && dist[nxt] > d){
                    dist[nxt] = d;
                    if(i == n-1 && visit[nxt][e]){
                        cycle = true;
                    }
                }
            }
        }
    }
    
    if(cycle) printf("Gee\n"); // tip: 싸이클이 있고, 그 싸이클에서 도달이 가능해야 (독립적이지 않음)
    else if(dist[e] == INF) printf("gg\n");
    else printf("%lld\n", -dist[e]);
}

/*
4 0 3 4
0 1 0
0 3 5
1 2 0
2 1 0
0 5 5 10
답: 5

5 0 4 6
0 1 10000
1 2 0
2 1 0
1 3 0
0 3 0
3 4 0
0 0 1 0 0
답: Gee
*/