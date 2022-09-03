#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 401;
const int INF = 1000000000;
int c[MAX][MAX], f[MAX][MAX];
vector<int> adj[MAX];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int n, p; cin >> n >> p;
    int u, v;
    while(p--){
        cin >> u >> v;
        c[u][v] = 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int total = 0, s = 1, e = 2;
    while(1){
        int prev[MAX]; fill(prev, prev+MAX, -1);
        queue<int> q; q.push(s);
        while(!q.empty() && prev[e] == -1){
            int curr = q.front(); q.pop();
            for(int nxt: adj[curr]){
                if(c[curr][nxt] - f[curr][nxt] > 0 && prev[nxt] == -1){
                    q.push(nxt);
                    prev[nxt] = curr;
                    if(nxt == e) break;
                }
            }
        }
        if(prev[e] == -1) break; 

        for(int i=e; i!=s; i=prev[i]){ 
            f[prev[i]][i] += 1;
            f[i][prev[i]] -= 1;
        }
        total += 1;
    }

    printf("%d\n",total);
}
