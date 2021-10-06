#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int MAX = 10001;
int n;
int arr[MAX];
vector<int> adj[MAX];
int dp[MAX][2]; // dp[i][j]: i 번을 포함시켰는지(j=1) 아닌지(j=0)에 따른 최댓값

int dfs(int curr, int prev, int flag){
    int &ret = dp[curr][flag];
    if(ret != -1) return ret;
    ret = 0;
    for(int nxt: adj[curr]){
        if(nxt == prev) continue;
        if(flag)
            ret += dfs(nxt, curr, 0);
        else
            ret += max(dfs(nxt,curr,0), dfs(nxt,curr,1));
    }
    if(flag) ret += arr[curr];
    return ret;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for(int i = 1; i<=n; i++) cin >> arr[i];
    int u, v;
    for(int i = 0; i<n-1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(dp, -1,sizeof(dp));
    int ans = max(dfs(1, 0, 1), dfs(1,0,0));
    cout << ans << endl;
}
