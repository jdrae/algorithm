#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 101;
const int INF = 1000000000;

int main(){
    int n,m; cin >> n>> m;

    int dist[MAX][MAX];
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            dist[i][j] = i==j ? 0 : INF;

    int u, v, w;
    while(m--){
        cin >> u>> v>> w;
        u--; v--;
        dist[u][v] = min(dist[u][v], w);
    }

    for(int k = 0; k<n; k++)
        for(int i = 0; i<n; i++)
            for(int j = 0; j<n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++)
            dist[i][j] == INF ? printf("0 ") : printf("%d ", dist[i][j]);
        puts("");    
    }
}