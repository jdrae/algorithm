#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 400;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int adj[MAX][MAX] = {0};

    int n, k; cin >> n>>k;
    int u,v;     
    while(k--){
        cin >> u>> v; u--;v--;
        adj[u][v] = 1;
    }

    for(int k = 0; k<n; k++)
        for(int i = 0; i<n; i++)
            for(int j = 0; j<n; j++)
                if(adj[i][k] && adj[k][j]) adj[i][j] = 1;
    
    int s; cin >> s;
    while(s--){
        cin >> u>>v; u--;v--;
        if(adj[u][v]) puts("-1");
        else if(adj[v][u]) puts("1");
        else puts("0");
    }    
}