#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

map<int,int, greater<int>> m;
vector<vector<int>> adj;
vector<int> visited;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    adj.resize(n+1); 
    visited.resize(n+1);
    for(int i = 0; i< edge.size(); i++){
        int u = edge[i][0]; int v = edge[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    int path = 1;
    while(!q.empty()){
        int qsize = q.size();
        for(int i = 0; i<qsize; i++){
            int curr = q.front(); q.pop();
            for(int next : adj[curr]){
                if(!visited[next]){
                    visited[next] = 1;
                    q.push(next);
                    m[path]++;
                }
            }   
        }
        path++;
    }
    
    for(auto const& [key, value] : m){
        answer = value; break;
    }
    
    return answer;
}