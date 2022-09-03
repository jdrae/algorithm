#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define MAX 500
#define INF 1000 * 500
typedef pair<int,int> P;
vector<P> adj[MAX];
vector<int> trace[MAX]; // tip: 최단 경로 저장

void dijkstra(int dist[], int start){
    fill(dist, dist+MAX, INF);
    priority_queue<P> pq;
    dist[start] = 0;
    pq.push({0, start});
    while(!pq.empty()){
        int d = -pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        if(dist[curr] < d) continue;
        
        for(auto& p : adj[curr]){
            int nxt = p.first; int nd = p.second;
            // 삭제된 간선 무시
            if(nd == -1) continue;

            if(dist[nxt] > nd + d){
                dist[nxt] = nd + d; 
                pq.push({-dist[nxt], nxt}); 
                
                // curr 에서 nxt 로 가기 위해 dist[nxt] 의 최소값 사용
                trace[nxt].clear();
                trace[nxt].push_back(curr);
            }
            else if(dist[nxt] == nd+d) { // 여러개의 최단 경로를 모두 저장
                trace[nxt].push_back(curr);
            }
        }
    }
}

void bfs(int end){
    bool visited[MAX][MAX]; // 간선의 방문 여부
    memset(visited, 0, sizeof(visited));

    queue<int> q;
    q.push(end);
    while(!q.empty()){
        int to = q.front(); // 역방향 탐색
        q.pop();
        for(int from: trace[to]){
            if(visited[to][from]) continue;
            visited[to][from] = true;
            for(auto& nxtV : adj[from]){
                if(nxtV.first == to)
                    nxtV.second = -1;
            }
            q.push(from);
        }
    }
}

void init(){
    memset(adj, 0, sizeof(adj));
    memset(trace, 0, sizeof(trace));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, s, e, u, v, w;
    while(true){
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        cin >> s >> e;
        init();
        for(int i = 0 ; i<m; i++){
            cin >> u >> v >> w;
            adj[u].push_back({v,w});
        }

        int dist[MAX];
        dijkstra(dist, s);
        bfs(e);
        dijkstra(dist, s);

        if(dist[e] == INF) cout << -1 << endl;
        else cout << dist[e] << endl;
    }
}