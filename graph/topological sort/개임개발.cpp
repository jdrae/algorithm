#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 501

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> adj[MAX];
    int value[MAX], result[MAX] = {0}, indegree[MAX] = {0};
    queue<int> q;

    int n, prev; cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> value[i];
        while(true){
            cin >> prev;
            if(prev == -1) break;
            adj[prev].push_back(i);
            indegree[i]++;
        }
        if(indegree[i] == 0){
            q.push(i);
            result[i] = value[i];
        }

    }
    for(int i = 1; i<=n; i++){
        int curr = q.front();
        q.pop();
        for(int nxt:adj[curr]){
            result[nxt] = max(result[nxt], result[curr] + value[nxt]);
            if(--indegree[nxt] == 0) q.push(nxt);
        }
    }
    
    // 싸이클 있을 경우 출력 정의하지 않았기에 싸이클 입력 없음
    for(int i = 1; i<=n; i++){
        printf("%d\n", result[i]);
    }
}