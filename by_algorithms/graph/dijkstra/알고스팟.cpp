#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int,int> P;
const int MAX = 100;
const int INF = 1 * 100 * 100;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int main(){
    int n, m; cin >> m >> n;
    int cost[MAX][MAX];
    int dist[MAX][MAX];
    for(int i = 0 ; i<n; i++){
        for(int j = 0; j<m;j++){
            scanf("%1d", &cost[i][j]);
            dist[i][j] = INF;
        }
    }

    priority_queue<pair<int, P>> pq;
    pq.push(make_pair(0, P(0,0)));
    dist[0][0] = 0;
    while(!pq.empty()){
        int d = -pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();
        for(int i = 0; i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0<=ny&&ny<n && 0<=nx&&nx<m){
                int nd = d + cost[ny][nx];
                if(dist[ny][nx] > nd){
                    dist[ny][nx] = nd;
                    pq.push(make_pair(-dist[ny][nx], P(ny,nx)));
                }
            }
        }
    }

    printf("%d\n", dist[n-1][m-1]);
}