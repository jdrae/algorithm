#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int MAX = 10001;
int n, arr[MAX], chk[MAX];
int dp[MAX][2]; // dp[i][j]: i가 포함될경우(1)와 아닐경우의 최댓값
vector<int> adj[MAX], tree[MAX];
vector<int> path;

// 트리를 만들 필요 없이 parent 노드 건너뛰기
void func(int curr, int prev){
    for(int nxt:adj[curr]){
        if(nxt == prev) continue;
        func(nxt, curr); // leaf node 에서는 수행 안됨
    }
    dp[curr][0] = 0;
    dp[curr][1] = arr[curr];
    for(int nxt : adj[curr]){
        if(nxt == prev) continue;
        dp[curr][0] += max(dp[nxt][0], dp[nxt][1]);
        dp[curr][1] += dp[nxt][0];
    }
}

void track(int curr, int is_in, int prev){
    if(is_in){
        path.push_back(curr);
        for(int nxt: adj[curr]){
            if(nxt == prev) continue;
            track(nxt, 0, curr);
        }
    }
    else{
        for(int nxt: adj[curr]){
            if(nxt == prev) continue;
            if(dp[nxt][0] < dp[nxt][1]){
                track(nxt, 1, curr);
            }
            else{
                track(nxt, 0, curr);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i = 1; i<=n; i++)
        cin >> arr[i];
    
    // tip: 트리의 엣지 개수는 n-1
    int u, v;
    for(int i = 0; i<n-1; i++){
        cin >> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    func(1,0);
    printf("%d\n",max(dp[1][0], dp[1][1]));
    if(dp[1][0] < dp[1][1]) track(1,1,0); // 포함된 경우
    else track(1,0,0); // 아닐 경우
    sort(path.begin(), path.end());
    for(int node : path){
        printf("%d ",node);
    }
    printf("\n");
}
