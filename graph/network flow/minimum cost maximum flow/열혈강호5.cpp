#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 401 * 2;
const int INF = 1000000000;
int s = 0, e = MAX-1;
int c[MAX][MAX] = {0}, f[MAX][MAX] = {0}, d[MAX][MAX]={0};
vector<int> adj[MAX];
int main(){
    int n, m; scanf("%d %d",&n,&m);
    int num, j, v;
    for(int i = 1+m; i<=n+m; i++){
        scanf("%d", &num);
        while(num--){
            scanf(" %d %d",&j, &v);
            d[i][j] = v; d[j][i] = -v;
            c[i][j] = 1;
            adj[i].push_back(j); adj[j].push_back(i);
        }
        c[s][i] = 1;
        adj[s].push_back(i); adj[i].push_back(s);
    }
    for(int j = 1; j<=m; j++){
        c[j][e] = 1;
        adj[j].push_back(e); adj[e].push_back(j);
    }

    int total = 0; int mn_cost = 0;
    while(1){
        int prev[MAX]; fill(prev, prev+MAX, -1);
        int dist[MAX]; fill(dist, dist+MAX, INF);
        bool in_q[MAX] = {0};
        queue<int> q;
        dist[s] = 0; in_q[s] = true; q.push(s);
        while(!q.empty()){
            int curr = q.front(); q.pop();
            in_q[curr] = false;
            for(int nxt: adj[curr]){
                if(c[curr][nxt] - f[curr][nxt] > 0 && dist[nxt] > dist[curr] + d[curr][nxt]){
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

        for(int i = e; i!=s; i=prev[i]){
            mn_cost += d[prev[i]][i];
            f[prev[i]][i]++;
            f[i][prev[i]]--;
        }
        total++;
    }
    printf("%d\n%d\n", total, mn_cost);
}
