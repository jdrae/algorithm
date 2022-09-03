#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
const int MAX = 500001;
int id, dfsn[MAX], sccn[MAX], scc_size;
bool finished[MAX];
vector<int> adj[MAX];
stack<int> st;

int dfs(int curr){
    dfsn[curr] = ++id;
    st.push(curr);

    int group = dfsn[curr];
    for(int nxt: adj[curr]){
        if(dfsn[nxt] == 0) group = min(group, dfs(nxt));
        else if(!finished[nxt]) group = min(group, dfsn[nxt]);
    }

    if(group == dfsn[curr]){
        while(1){
            int t = st.top(); st.pop();
            finished[t] = true;
            sccn[t] = scc_size; 
            if(t==curr) break;
        }
        scc_size++;
    }
    return group;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int value[MAX], is_rest[MAX] = {0};
    // input
    int n, m; cin >> n>> m;
    for(int i = 0; i<m; i++){
        int u, v; cin >> u>>v;
        adj[u].push_back(v);
    }
    for(int i = 1; i<=n; i++)
        cin >>value[i];    
    
    int start, rests; cin >>start >> rests;
    for(int i = 0; i<rests;i++){
        int r; cin >> r;
        is_rest[r] = 1;
    }

    // scc
    for(int i= 1; i<=n; i++)
        if(dfsn[i] == 0) dfs(i);
    
    // create graph with scc as node
    vector<int> s_adj[MAX];
    int s_start, s_value[MAX] = {0}, s_in[MAX] = {0};
    bool s_rest[MAX] = {0};
    for(int i = 1; i<=n; i++){
        int group = sccn[i];
        s_value[group] += value[i];
        if(is_rest[i]) s_rest[group] = true;
        if(i == start) s_start = group;

        for(int j: adj[i]){
            int nxtgroup = sccn[j];
            if(group == nxtgroup) continue;
            s_adj[group].push_back(nxtgroup);
            s_in[nxtgroup]++;           
        }
    }

    // topological sort
    queue<int> q;
    int s_max[MAX]; 
    bool s_reach[MAX] = {0}; // 시작점에서 도달가능여부
    // 초기화
    for(int i = 0; i < scc_size; i++){
        s_max[i] = s_value[i]; 
        if(i == s_start) s_reach[i] = true;
        if(s_in[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int curr = q.front(); q.pop();
        for(int nxt: s_adj[curr]){
            if(s_reach[curr]){
                s_max[nxt] = max(s_max[nxt], s_max[curr] + s_value[nxt]); // 
                s_reach[nxt] = true;
            }
            if(--s_in[nxt] == 0) q.push(nxt);
        }
    }

    int result = 0;
    for(int i = 0; i<scc_size; i++)
        if(s_rest[i] && s_reach[i]) result = max(result, s_max[i]);
    printf("%d\n", result);
}
