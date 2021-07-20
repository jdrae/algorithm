#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 32001;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    vector<int> adj[MAX];
    int indegree[MAX] = {0};

    int n, m; cin >> n>>m;
    int a, b;
    while(m--){
        cin >> a>> b;
        adj[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;
    for(int i = 1; i<=n; i++)
        if(indegree[i]==0) q.push(i);

    for(int i = 1; i<=n; i++){
        if(q.empty()){
            printf("%d ", i);
            continue;
        }
        int curr = q.front();
        q.pop();
        printf("%d ", curr);
        for(int nxt: adj[curr])
            if(--indegree[nxt] == 0) q.push(nxt);
    }
}
