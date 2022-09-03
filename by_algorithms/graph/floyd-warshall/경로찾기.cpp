#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 101;
const int INF = 1000000000;

int main(){
    int n; cin >> n;
    int adj[MAX][MAX];
    for(int i =0; i<n; i++)
        for(int j = 0; j<n; j++)
            cin >> adj[i][j];

    for(int k = 0; k<n; k++)
        for(int i = 0; i<n; i++)
            for(int j = 0; j<n; j++)
                if(adj[i][k] && adj[k][j]) adj[i][j] = 1;
    
    for(int i =0; i<n; i++){
        for(int j = 0; j<n; j++)
            printf("%d ", adj[i][j]);
        puts("");
    }

}