#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
const int MAX = 100001;
int cnt, dfsn[MAX], scc_size, sccn[MAX];
bool finished[MAX];
vector<int> adj[MAX];
stack<int> st;

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
            if(t==curr) break;
        }
        scc_size++;
    }

    return result;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n,m; cin >> n>>m;
        while(m--){
           int x, y; cin >> x>> y;
           x--;y--;
           adj[x].push_back(y);
        }
        for(int i = 0; i<n; i++)
            if(dfsn[i] == 0) dfs(i);

        // count indegree
        int indegree[MAX] = {0};
        for(int i=0;i<n; i++)
            for(int j : adj[i])
                if(sccn[i] != sccn[j]) ++indegree[sccn[j]];

        int result = 0;
        for(int i = 0; i<scc_size; i++)
            if(indegree[i] == 0) result++;
        printf("%d\n",result);

        cnt = scc_size = 0;
        fill(dfsn,dfsn+n,0);
        fill(sccn, sccn+n,0);
        fill(finished, finished+n,0);
        for(int i = 0; i<n; i++) adj[i].clear();
    }
}
