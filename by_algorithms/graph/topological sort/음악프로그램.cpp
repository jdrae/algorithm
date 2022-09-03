#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1001
vector<int> adj[MAX];
int indegree[MAX] = {0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    int num, curr, prev = 0;
    while(m--){
        cin >> num;
        while(num--){
            cin >> curr;
            adj[prev].push_back(curr);
            if(prev != 0)indegree[curr]++;
            prev = curr;
        }
        prev = 0;
    }


    int result[MAX];
    queue<int> q;
    for(int i = 1; i<=n; i++)
        if(indegree[i] == 0) q.push(i);
    

    for(int i = 1; i<=n; i++){
        if(q.empty()){
            puts("0");
            return 0;
        }

        int curr = q.front();
        q.pop();
        result[i] = curr;
        for(int nxt: adj[curr])
            if(--indegree[nxt] == 0) q.push(nxt);
    }

    for(int i = 1; i<=n; i++)
        printf("%d\n", result[i]);
    
}  