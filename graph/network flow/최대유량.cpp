#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 52;
const int INF = 1000000000;
int cap[MAX][MAX] = {0};
int flow[MAX][MAX] = {0};
vector<int> adj[MAX];

inline int ctoi(char c){
    if(c <= 'Z') return c - 'A';
    return c - 'a' + 26;
}

int main(){
    int n; scanf("%d",&n);
    for(int i = 0; i<n; i++){
        char u, v; int w;
        // tip: scanf 입력시 앞에 띄어쓰기 하는 경우 (또는 getchar() 사용)
        scanf(" %c %c %d",&u, &v, &w);
        u = ctoi(u); v = ctoi(v);
        cap[u][v] = cap[v][u] += w; // 간선이 여러개일때 가중치
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int total = 0, s = ctoi('A'), e = ctoi('Z');
    while(1){
        int prev[MAX]; // 증가 경로 bfs 로 찾기
        fill(prev, prev+MAX, -1);
        queue<int> q;
        q.push(s);
        while(!q.empty() && prev[e] == -1){
            int curr = q.front(); q.pop();
            for(int nxt: adj[curr]){
                // 유량을 보낼 수 있고, 아직 방문하지 않았을때
                if(cap[curr][nxt] - flow[curr][nxt] > 0 && prev[nxt] == -1){
                    q.push(nxt);
                    prev[nxt] = curr;
                    if(nxt == e) break;
                }
            }
        }
        if(prev[e] == -1) break; // e 로 못갈때 탈출

        int mn = INF;
        for(int i=e; i!=s; i=prev[i]){ // 최소 cap 찾기
            mn = min(mn, cap[prev[i]][i] - flow[prev[i]][i]);
        }
        for(int i=e; i!=s; i=prev[i]){ // flow 갱신
            flow[prev[i]][i] += mn;
            flow[i][prev[i]] -= mn;
        }
        total += mn;
    }

    printf("%d\n", total);
}
