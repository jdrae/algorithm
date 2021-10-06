#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAX = 100001;
const int MOD = 1000000007;
int n;
int arr[MAX];
vector<int> adj[MAX];
ll dp[MAX][10][2];

ll dfs(int curr, int prev, int mx, int flag){
    ll& ret = dp[curr][mx][flag];
    if(ret != -1) return ret;
    ret = flag ? 1 : 0;
    for(int nxt : adj[curr]){
        if(nxt == prev) continue;
        if(arr[nxt] >= mx)
            ret += dfs(nxt, curr, arr[nxt], 1);
        ret += dfs(nxt, curr, mx, 0);
        ret %= MOD;
    }    
    return ret % MOD;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> arr[i];
    }
    int a, b;
    for(int i = 0; i<n-1; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(dp, -1, sizeof(dp));
    printf("%lld\n", (dfs(1, 0, arr[1], 1) + dfs(1, 0, 0, 0))%MOD );

}
