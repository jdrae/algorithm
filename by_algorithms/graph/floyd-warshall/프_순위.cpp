#include <string>
#include <vector>
const int MAX = 101;
using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    int adj[MAX][MAX] = {0};
    for(int i = 0; i<results.size(); i++){
        adj[results[i][0]][results[i][1]] = 1;
    }
    
    for(int k = 1; k<=n; k++){
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(adj[i][k] & adj[k][j]) adj[i][j] = 1;
            }
        }
    }
    
    
    for(int i = 1; i<=n; i++){
        int cnt = 0;
        for(int j = 1; j<=n; j++){
            if(adj[i][j] || adj[j][i]) cnt++;
        }
        if(cnt == n-1) answer++;
    }
    
    return answer;
}