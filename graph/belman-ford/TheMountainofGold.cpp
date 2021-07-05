// https://github.com/kks227/BOJ/blob/master/10300/10360.cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> P;
const int MAX = 1000;
const int INF = 1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc;
    for(int t = 1; t<=tc; t++){
        vector<P> adj[MAX];
        int n, m;
        cin >> n>> m;
        while(m--){
            int a, b, c;
            cin >> a >> b>> c;
            adj[a].push_back({b,c});
        }

        queue<int> q;
        bool in_cycle[MAX] = {false, };

        // belman-ford
        int dist[MAX]; fill(dist, dist+MAX, INF);
        dist[0] = 0;
        for(int i= 0; i<n; i++){
            for(int j= 0; j<n; j++){
                for(auto& p : adj[j]){
                    int nxt = p.first; int d = dist[j] + p.second;
                    if(dist[j] != INF && dist[nxt]>d){
                        dist[nxt] = d;
                        if(i==n-1){
                            in_cycle[i] = true; // tip: 음의 사이클을 포함하는 경로
                            q.push(i);
                        }
                    }
                }
            }
        }
        // bfs: 음의 사이클을 지나는 정점들로만 bfs 진행
        bool result = (dist[0] < 0); // 양수면 false, while 문 실행 안됨
        while(!q.empty()){
            int curr = q.front(); q.pop();
            if(curr == 0){
                result = true; // 0 을 지나게 되면 possible
                break;
            }
            for(auto &p: adj[curr]){
                int nxt = p.first;
                if(!in_cycle[nxt]){
                    in_cycle[nxt] = true;
                    q.push(nxt);
                }
            }
        }

        printf("Case #%d: %s\n", t, result ? "possible" : "not possible");
    }
}