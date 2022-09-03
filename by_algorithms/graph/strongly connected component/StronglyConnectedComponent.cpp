#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
const int MAX = 10000;

int v, e, cnt, dfsn[MAX], scc_size, scc_group[MAX];
vector<int> adj[MAX];
bool finished[MAX];
stack<int> st;
vector<vector<int>> scc;

int dfs(int curr){
    dfsn[curr] = ++cnt;
    st.push(curr);

    int result = dfsn[curr];
    for(int nxt : adj[curr]){
        if(dfsn[nxt] == 0) result = min(result, dfs(nxt));
        else if(!finished[nxt]) result = min(result, dfsn[nxt]);
    }

    if(result == dfsn[curr]){
        vector<int> curr_scc;
        while(1){
            int t = st.top(); st.pop();
            curr_scc.push_back(t);
            finished[t] = true;
            scc_group[t] = scc_size;
            if(t == curr) break;
        }
        sort(curr_scc.begin(), curr_scc.end());
        scc.push_back(curr_scc);
        scc_size++;
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>v>>e;
    for(int i = 0; i<e; i++){
        int a, b; cin >>a>>b;
        adj[a-1].push_back(b-1);
    }

    for(int i = 0; i<v; i++)
        if(dfsn[i] == 0) dfs(i);
    sort(scc.begin(), scc.end());
    
    printf("%d\n", scc_size);
    for(auto& curr_scc: scc){
        for(int curr: curr_scc)
            printf("%d ",curr+1);
        puts("-1");
    }
}
