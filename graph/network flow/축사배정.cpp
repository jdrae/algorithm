#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 402;
int cap[MAX][MAX] = {0};
int flow[MAX][MAX] = {0};
vector<int> adj[MAX];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
 
    int n,m; cin >> n>> m;
    int total = 0, s = 0, e = n+m+1;
    for(int i = 1; i <= n; i++){
        int num, a; cin >> num;
        adj[s].push_back(i);
        adj[i].push_back(s);
        cap[s][i] = 1;
        while(num--){
            cin >> a;
            adj[i].push_back(a+n);
            adj[a+n].push_back(i);
            cap[i][a+n] = 1;
        }
    }
    for(int i = n+1; i <= m+n; i++){
        adj[i].push_back(e);
        adj[e].push_back(i);
        cap[i][e] = 1;
    }

    // ford fulkerson
    while(1){
        int prev[MAX];
        fill(prev, prev+MAX, -1);
        queue<int> q;
        q.push(s);
        while(!q.empty() && prev[e] == -1){
            int curr = q.front(); q.pop();
            for(int nxt: adj[curr]){
                if(cap[curr][nxt] - flow[curr][nxt] > 0 && prev[nxt] == -1){
                    q.push(nxt);
                    prev[nxt] = curr;
                    if(nxt == e) break;
                }
            }            
        }
        if(prev[e] == -1) break;
        for(int i = e; i!=s; i= prev[i]){
            flow[prev[i]][i] += 1;
            flow[i][prev[i]] -= 1;
        }
        total += 1;
    }

    printf("%d\n", total);
}
