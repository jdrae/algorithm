#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 1000;
const int INF = 10000 * 100;
typedef pair<int,int> P;
vector<P> adj[MAX], revadj[MAX];
int dist[MAX], revdist[MAX];

void dijkstra(const vector<P> adj[], int dist[], int start){ // tip
    priority_queue<P> pq; // tip: 음수로 저장
    fill(dist, dist+MAX, INF);
    bool visited[MAX] = {0};

    dist[start] = 0;
    pq.push({0, start});
    while(!pq.empty()){
        int curr;
        do{
            curr =  pq.top().second;
            pq.pop();
        }while(!pq.empty() && visited[curr]);
        if(visited[curr]) break;

        for(int i = 0; i<adj[curr].size(); i++){
            int nxt = adj[curr][i].first; 
            int nd = adj[curr][i].second + dist[curr];
            if(dist[nxt] > nd){
                dist[nxt] = nd;
                pq.push({-dist[nxt], nxt});
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, x;
    cin >> n >> m >> x;
    x--;
    int u, v, w;
    for(int i = 0; i<m; i++){
        cin >> u >> v >> w; 
        u--; v--;
        adj[u].push_back(P(v, w));
        revadj[v].push_back(P(u, w));
    }

    dijkstra(adj, dist, x); // x start: x 에서 i 로 가는 경우 (집으로 돌아가는 경우)
    dijkstra(revadj, revdist, x); // x start: i 에서 x 로 가는 경우 (파티장에 가는 경우)

    int mx = 0;
    for(int i = 0; i<n; i++){
        mx = max(mx, dist[i] + revdist[i]);
    }
    printf("%d\n", mx);
}