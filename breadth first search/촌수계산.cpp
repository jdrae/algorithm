#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    int from, to; cin >> from >> to;
    int m; cin >> m;

    vector<vector<int>> adj;
    adj.resize(n+1);
    while(m--){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<bool> visited(n+1, false);
    queue<int> Q;
    Q.push(from);
    visited[from] = true;
    int ans = 0;
    while(!Q.empty()){
        int curr = Q.front();
        Q.pop();
        cout << "node " << curr << " visited" << endl;
        if(curr == to) break;
        for(int next: adj[curr]){
            if(!visited[next]){
                visited[next] = true;
                Q.push(next);
                ans++;
            }
        }
    }
    if(ans == 0) ans = -1;
    cout << "R:" << ans << endl;
}