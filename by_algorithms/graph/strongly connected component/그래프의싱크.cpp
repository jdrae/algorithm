#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
const int MAX = 5001;
int cnt, dfsn[MAX], scc_size, sccn[MAX];
vector<int> adj[MAX];
bool finished[MAX];
stack<int> st;
vector<int> scc[MAX];

int dfs(int curr){
    dfsn[curr] = ++cnt;
    st.push(curr);

    int result = dfsn[curr];
    for(int nxt: adj[curr]){
        if(dfsn[nxt] == 0) result = min(result, dfs(nxt));
        else if(!finished[nxt]) result = min(result, dfsn[nxt]);
    }

    if(result == dfsn[curr]){
        vector<int> curr_scc;
        while(true){
            int t = st.top(); st.pop();
            curr_scc.push_back(t);
            finished[t] = true;
            sccn[t] = scc_size;
            if(t== curr) break;
        }
        scc[scc_size] = curr_scc;
        scc_size++;
    }

    return result;
}

int main(){
    while(true){
        // input
        int n; scanf("%d",&n);
        if(n==0) break;
        int m; scanf("%d",&m);
        for(int i = 0;i<m; i++){
            int u,v; scanf("%d %d",&u,&v);
            adj[u].push_back(v);
        }

        // scc
        for(int i = 1; i<=n; i++)
            if(dfsn[i] == 0) dfs(i);
        
        // outdegree
        int outdegree[MAX] = {0};
        for(int i = 1; i<=n; i++){
            for(int j: adj[i])
                if(sccn[i] != sccn[j]) ++outdegree[sccn[i]];
        }

        // result
        vector<int> result;
        for(int i = 0; i<scc_size; i++){
            if(outdegree[i] == 0){
                for(int t: scc[i]){
                    result.push_back(t);
                }
            }
        }
        sort(result.begin(), result.end());
        for(int t :result)
            printf("%d ", t);
        printf("\n");

        // clear
        fill(dfsn, dfsn+MAX, 0);
        fill(sccn, sccn+MAX, 0);
        fill(finished, finished+MAX, 0);
        for(int i = 1; i<= n; i++) adj[i].clear();
        for(int i = 0; i<scc_size;i++){
            scc[i].clear();
        }
        cnt = scc_size = 0;
    }
}