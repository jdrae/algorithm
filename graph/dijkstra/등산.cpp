#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100001
#define INF 200000 * 10000
typedef pair<int,int> P;
int h[MAX];
vector<P> adj[MAX];

void dijkstra(long dist[], int start){
    fill(dist, dist+MAX, INF);
    priority_queue<P> pq;

    dist[start] = 0;
    pq.push({0, start});
    while(!pq.empty()){
        int curr = pq.top().second;
        int d = -pq.top().first;
        pq.pop();
        if(dist[curr] < d) continue;
        
        for(auto& p: adj[curr]){
            int nxt = p.first; int nd = p.second;
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
    int n, m, d, e;
    cin >> n >> m >> d >> e;
    for(int i = 1; i<=n; i++){
        cin >> h[i];
    }
    int a, b, w;
    for(int i = 0; i<m; i++){
        cin >> a>> b>> w;
        if(h[a] < h[b]) adj[a].push_back({b, w});
        else if(h[b] < h[a]) adj[b].push_back({a,w});
    }

    long dist1[MAX], dist2[MAX];
    dijkstra(dist1, 1);
    dijkstra(dist2, n);

    vector<long> ans;
    for(int i = 1; i<=n; i++){
        ans.push_back(h[i]*e - (dist1[i] + dist2[i])*d );
    }
    sort(ans.begin(), ans.end());
    int res = ans[ans.size()-1];
    if(res < -INF) printf("Impossible\n");
    else cout << res << endl;

}