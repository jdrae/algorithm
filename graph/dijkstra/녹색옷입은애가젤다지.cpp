#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int MAX = 125;
const int INF = 125 * 10;
typedef pair<int,int> P;
vector<P> adj[MAX];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int main(){
    int n, num = 1;
    int dist[MAX][MAX];
    int cost[MAX][MAX];
    while(true){
        cin >> n;
        if(n==0) break;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                cin >> cost[i][j];
                dist[i][j] = INF;
            }
        }

        priority_queue<pair<int, P>> pq; // cost, coordinates
        pq.push(make_pair(-cost[0][0], P(0,0))); // 음수
        while(!pq.empty()){
            int d = - pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            for(int i = 0; i<4; i++){
                int nx = x + dx[i]; int ny = y + dy[i];
                if(0<=nx && nx< n && 0<=ny && ny < n){
                    int nd = d + cost[ny][nx];
                    if(dist[ny][nx] > nd){
                        dist[ny][nx] = nd;
                        pq.push(make_pair(-dist[ny][nx], P(nx,ny)));
                    }
                }
            }
        }
        printf("Problem %d: %d\n", num++, dist[n-1][n-1]);
    }
}