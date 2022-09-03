#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef struct pair<int, int> P;
#define ll long long
const int MAX = 101;
const ll INF = 2000000001;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<P> adj[MAX]; vector<int> revadj[MAX];
    // input
    int n, m; cin >> n>> m;
    int u, v, w;
    while(m--){
        cin >> u>> v >>w;
        adj[u].push_back({v,-w}); // tip: 최대경로 구하기
        revadj[v].push_back(u);
    }

    // bfs
    bool visited[MAX]; fill(visited, visited+MAX, 0);
    queue<int> q;
    visited[n] = 1; 
    q.push(n);
    while(!q.empty()){
        int to = q.front();
        q.pop();
        for(int from: revadj[to]){
            if(visited[from]) continue;
            visited[from] = 1;
            q.push(from);
        }
    }

    // belman-ford
    bool cycle = false;
    int prev[MAX] = {0}; // tip: 경로 저장하기
    ll dist[MAX]; fill(dist, dist+MAX, INF);
    dist[1] = 0;
    for(int i = 1; i<=n; i++){
        for(int v = 1; v<=n; v++){
            for(auto& p: adj[v]){
                int nxt = p.first; ll d = dist[v] + p.second;
                if(dist[v] != INF && dist[nxt] >  d){
                    dist[nxt] = d;
                    prev[nxt] = v;
                    if(i == n && visited[nxt])
                        cycle = true;
                }
            }
        }
    }

    //output
    if(cycle) printf("-1");
    else{
        vector<int> ans;
        int v = n;
        while(true){
            ans.push_back(v);
            if(v == 1) break;
            else v = prev[v];
        }
        for(int i = ans.size()-1; i >= 0; i--)
            printf("%d ", ans[i]);
    }
    printf("\n");
}