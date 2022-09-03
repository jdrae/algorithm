#include <iostream>
#include <queue>
using namespace std;
const int MAX = 101;
const int INF = 50000000;
int main(){
    int n,m; cin >> n>>m;
    
    int dist[MAX][MAX];
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            dist[i][j] = i==j ? 0 : INF;

    int a,b;
    while(m--){
        cin >> a>> b;
        a--; b--;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }

    for(int k = 0; k<n; k++){
        for(int i = 0; i<n; i++)
            for(int j = 0; j<n; j++)
                if(dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    }

    priority_queue<pair<int,int>> pq;
    for(int i = 0; i<n; i++){
        int ans = 0;
        for(int j = 0; j<n; j++)
            ans += dist[i][j];
        pq.push({-ans, -(i+1)});
    }

    printf("%d\n", -pq.top().second);
}