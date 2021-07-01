#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100001
#define ll long long
const ll INF = 1000000000000; // line 53 N*n*d
ll h[MAX];
vector<pair<int,ll>> adj[MAX];

void dijkstra(ll dist[], int start){
    fill(dist, dist+MAX, INF);
    priority_queue<pair<ll,int>> pq;

    dist[start] = 0;
    pq.push({0, start});
    while(!pq.empty()){
        int curr = pq.top().second;
        ll d = -pq.top().first;
        pq.pop();
        if(dist[curr] < d) continue;
        
        for(auto& p: adj[curr]){
            int nxt = p.first; ll nd = p.second;
            if(dist[nxt] > nd+d){
                dist[nxt] = nd+d;
                pq.push({-dist[nxt], nxt});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; ll d, e;
    cin >> n >> m >> d >> e;
    for(int i = 1; i<=n; i++){
        cin >> h[i];
    }
    int a, b; ll w;
    for(int i = 0; i<m; i++){
        cin >> a>> b>> w;
        if(h[a] < h[b]) adj[a].push_back({b, w});
        else if(h[b] < h[a]) adj[b].push_back({a,w});
    }

    ll dist1[MAX], dist2[MAX];
    dijkstra(dist1, 1);
    dijkstra(dist2, n);

    ll ans = -INF;
    for(int i = 2; i<n; i++){
        if(dist1[i] >= INF || dist2[i] >= INF) continue;
        ll comp = h[i]*e - (dist1[i] + dist2[i])*d;
        ans = max(ans, comp);
    }
    if(ans == -INF) 
        printf("Impossible\n");
    else
        printf("%lld\n", ans);
}