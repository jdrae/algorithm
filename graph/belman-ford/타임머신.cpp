#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> P;
const long long INF = 1e18;
const int MAX = 501;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long dist[MAX];
    vector<P> adj[MAX];

    int n, m; cin >> n >> m;
    int u, v, w;
    while(m--){
        cin >> u>> v>> w;
        adj[u].push_back({v,w});
    }

    bool minusCycle = false;
    fill(dist, dist+MAX, INF);
    dist[1] = 0;
    for(int i = 0; i<n; i++){
        for(int j = 1; j<=n; j++){
            for(auto &p :adj[j]){
                int nxt = p.first, d = p.second;
                if(dist[j] != INF && dist[nxt] > dist[j] + d){
                    dist[nxt] = dist[j] + d;
                    if(i == n-1) minusCycle = true;
                }
            }
        }
    }

    if(minusCycle) puts("-1");
    else
        for(int i = 2; i<=n; i++)
            printf("%lld\n", dist[i] != INF ? dist[i] : -1);
        
}