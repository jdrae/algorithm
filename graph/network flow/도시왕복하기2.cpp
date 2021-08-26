#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 802;
int c[MAX][MAX], f[MAX][MAX];
vector<int> adj[MAX];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int n, p; cin >> n >> p;
    int u, v;
    while(p--){
        // 들어오는 방향의 정점과 나가는 방향 정점 분리
        // in: 3(1) 5(2) 7(3) ... 801(400)
        // out: 2(1) 4(2) 6(3) ... 800(400)
        cin >> u >> v;
        adj[u*2].push_back(v*2+1); // out(u) -> in(v)
        adj[v*2+1].push_back(u*2); // 역방향간선
        c[u*2][v*2+1] = 1; // 방향간선
        adj[v*2].push_back(u*2+1); // out(v) -> in(u)
        adj[u*2+1].push_back(v*2);
        c[v*2][u*2+1] = 1;
    }

    for(int i = 1; i<=n;i++){ // in(n) -> out(n) 연결
        adj[i*2+1].push_back(i*2);
        adj[i*2].push_back(i*2+1);
        c[i*2+1][i*2] = 1;
    }

    int total = 0, s = 1*2, e = 2*2+1; // out(1) 과 in(2)
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

/*
5 6
1 4
1 5
4 3
4 5
4 2
3 2
ans: 1

6 7
1 3
3 4
4 2
1 6
6 4
3 5
5 2
ans: 2
*/