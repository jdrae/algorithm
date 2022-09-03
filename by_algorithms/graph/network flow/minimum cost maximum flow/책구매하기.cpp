#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 101 * 2;
const int INF = 1000000000;
int s = 0, e = MAX-1;
int c[MAX][MAX] = {0}, f[MAX][MAX] = {0}, d[MAX][MAX]={0};
vector<int> adj[MAX];
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int n, m; cin >> n>>m;
    for(int i = 1+m; i<=n+m; i++){ // 101 ... 200
        cin >> c[i][e]; // 사려는 개수가 e로 흘릴 수 있는 유량
        adj[e].push_back(i);
        adj[i].push_back(e);
    }
    for(int i = 1; i<=m; i++){ // 1 ... 100
        cin >> c[s][i]; // 팔려는 개수가 s에서 흘릴 수 있는 유량
        adj[s].push_back(i);
        adj[i].push_back(s);
    }
    for(int book_store = 1; book_store<=m; book_store++){
        for(int person = 1+m; person <= n+m; person++){
            cin >> d[book_store][person];
            d[person][book_store] = -d[book_store][person]; // 역방향 간선 비용: 순방향 * -1
            c[book_store][person] = INF; // 서점과 사람 사이의 용량은 INF
            adj[book_store].push_back(person);
            adj[person].push_back(book_store);
        }
    }

    int mn_cost = 0;
    while(1){
        int prev[MAX]; fill(prev, prev+MAX, -1);
        int dist[MAX]; fill(dist, dist+MAX, INF);
        bool in_q[MAX] = {0};
        queue<int> q;
        dist[s] = 0; in_q[s] = true; q.push(s);
        // SPFA: 다익스트라에서 pq 대신 q, in_q 배열
        while(!q.empty()){
            int curr = q.front(); q.pop();
            in_q[curr] = false;
            for(int nxt: adj[curr]){
                // 용량이 있으면서 최단경로
                if(c[curr][nxt] > f[curr][nxt] && dist[nxt] > dist[curr] + d[curr][nxt]){
                    dist[nxt] = dist[curr] + d[curr][nxt];
                    prev[nxt] = curr;
                    if(!in_q[nxt]){
                        q.push(nxt);
                        in_q[nxt] = true;
                    }
                }
            }
        }
        if(prev[e] == -1) break;

        int flow = INF;
        for(int i = e; i!=s; i=prev[i])
            flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
        for(int i = e; i!=s; i=prev[i]){
            mn_cost += flow * d[prev[i]][i];
            f[prev[i]][i] += flow;
            f[i][prev[i]] -= flow;
        }
    }
    printf("%d\n", mn_cost);
}
