#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
const int MAX = 20000;
int cnt, dfsn[MAX], scc_size, sccn[MAX];
bool finished[MAX];
vector<int> adj[MAX];
stack<int> st;

inline int oppo(int n){return n%2 ? n-1 : n+1;} // 자신의 반대 정점 번호

int dfs(int curr){
    dfsn[curr] = ++cnt;
    st.push(curr);

    int result = dfsn[curr];
    for(int nxt : adj[curr]){
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
    int n, m; cin >> n>> m;
    for(int i = 0; i<m; i++){
        int u, v; cin >> u >> v;
        // tip: 양수 정점과 음수 정점 번호매기기 1(0):(0,1) 2(1):(2,3) 3(2):(4,5) ... 
        u = (u<0 ? -(u+1)*2 : u*2-1);
        v = (v<0 ? -(v+1)*2 : v*2-1);
        // u or v 이기 때문에 ~u->v 와 ~v->u 추가
        adj[oppo(u)].push_back(v);
        adj[oppo(v)].push_back(u);
    }

    // scc
    for(int i = 0; i<n*2; i++)
        if(dfsn[i] == 0) dfs(i);

    // result
    // 원래 번호는 [1,n] 었지만 [0,n) 으로 iterate
    for(int i = 0; i<n; i++){
        if(sccn[i*2] == sccn[i*2+1]){
            puts("0");
            return 0;
        }
    }
    puts("1");
}