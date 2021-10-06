#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int MAX = 100001;
vector<int> adj[MAX];
int dp[MAX]; // 노드 i 를 루트로 하는 서브트리의 정점 개수

int dfs(int curr, int prev){
    int& ret = dp[curr];
    if(ret != -1) return ret;
    ret = 1;
    for(int nxt: adj[curr]){
        if(nxt == prev) continue;
        ret += dfs(nxt, curr);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    memset(dp,-1,sizeof(dp));
    int n, r, q; cin >> n>> r>> q;
    int a,b;
    for(int i = 0; i<n-1; i++){
        cin >> a>> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(r,0);

    int root;
    for(int i = 0; i<q; i++){
        cin >> root;
        printf("%d\n",dp[root]);
    }
}
