#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
const int MAX = 10000, DMAX=MAX*2;
int cnt, dfsn[DMAX], scc_size, sccn[DMAX];
bool finished[DMAX];
vector<int> adj[DMAX];
stack<int> st;

inline int oppo(int x){return x%2? x-1 : x+1;}

int dfs(int curr){
    dfsn[curr] = ++cnt;
    st.push(curr);

    int result = dfsn[curr];
    for(int nxt: adj[curr]){
        if(dfsn[nxt] == 0) result = min(result, dfs(nxt));
        else if(!finished[nxt]) result = min(result, dfsn[nxt]);
    }

    if(result == dfsn[curr]){
        while(1){
            int t = st.top(); st.pop();
            finished[t] = true;
            sccn[t] = scc_size;
            if(t== curr) break;
        }
        scc_size++;
    }

    return result;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int n, m; cin >> n >> m;
    for(int i = 0; i<n; i++){
        int u, v; cin >> u >> v;
        u = (u<0 ? -(u+1)*2 : u*2-1);
        v = (v<0 ? -(v+1)*2 : v*2-1);
        adj[oppo(u)].push_back(v);
        adj[oppo(v)].push_back(u);
    }

    // scc
    for(int i = 0; i<n*2; i++)
        if(dfsn[i] == 0) dfs(i);

    // result
    for(int i = 0; i<n; i++){
        if(sccn[i*2] == sccn[i*2+1]){
            puts("OTL");
            return 0;
        }
    }
    puts("^_^");
}