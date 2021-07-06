#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> P;
#define ll long long
const int MAX = 501;
const int INF = 1000000000;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc;
    while(tc--){
        vector<P> adj[MAX];
        int n, m, w; cin >> n>> m>>w;
        int s, e, t;
        while(m--){
            cin >> s>> e>> t;
            adj[s].push_back({e,t});
            adj[e].push_back({s,t});
        }
        while(w--){
            cin >> s>> e>> t;
            adj[s].push_back({e,-t});
        }

        // belman-ford
        int visited[MAX]; fill(visited, visited+MAX, 0);
        int dist[MAX]; fill(dist, dist+MAX, INF); // tip: 음의 사이클 존재 여부만 알기 위해서는 초기화 값 상관 없음
        bool cycle = false;
        for(int k = 1; k<=n; k++){
            if(visited[k]) continue; // tip: 컴포넌트가 여러개 일 경우
            visited[k] = true;
            dist[k] = 0;
            for(int i = 0; i<n; i++){
                for(int j = 1; j <=n; j++){
                    for(auto& p: adj[j]){
                        int nxt = p.first; int d = dist[j] + p.second;
                        if(dist[j] != INF && dist[nxt] > d){ // https://www.acmicpc.net/board/view/50494
                            dist[nxt] = d;
                            visited[nxt] = true;
                            if(i == n-1) cycle = true;
                        }
                    }
                }
            }
            if(cycle) break;
        }
        puts(cycle ? "YES" :"NO");
    }
}