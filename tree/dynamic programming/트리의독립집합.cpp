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

// tip: 트리 구조를 만들어 탐색 순서 정합
void dfs(int curr, int prev){
    for(int nxt: adj[curr]){
        if(nxt != prev){
            tree[curr].push_back(nxt);
            dfs(nxt, curr);
        }
    }
}

int func(int curr, bool is_in){
    int &ret = dp[curr][is_in];
    if(ret != -1) return ret;
    ret = 0;
    if(is_in){ // 포함할 경우
        for(int nxt : tree[curr]) // 트리에서 탐색
            ret += func(nxt, 0);
        return ret += arr[curr];
    }
    else{
        for(int nxt : tree[curr]){
            int chd0 = func(nxt, 0);
            int chd1 = func(nxt, 1);
            if(chd0 < chd1) chk[nxt] = 1;
            else chk[nxt] = 0;
            ret += max(chd0, chd1);
        }
    }
    return ret;
}

void track(int curr, int is_in){
    if(is_in){
        path.push_back(curr);
        for(int nxt: tree[curr])
            track(nxt, 0);
    }
    else{
        for(int nxt : tree[curr])
            track(nxt, chk[nxt]);
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
    dfs(1,1);

    int dp0 = func(1,0);
    int dp1 = func(1,1);
    if(dp0 < dp1) chk[1] = 1;
    else chk[1] = 0;
    printf("%d\n",max(dp0,dp1));
    track(1, chk[1]);
    sort(path.begin(), path.end());
    for(int nxt: path){
        printf("%d ", nxt);
    }
    printf("\n");
}
