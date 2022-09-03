#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
const int MAX = 10000, DMAX = MAX*2;
int cnt, dfsn[DMAX], scc_size, sccn[DMAX];
bool finished[DMAX];
vector<int> adj[DMAX];
stack<int> st;

inline int oppo(int n){return n%2 ? n-1 : n+1;}

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
            puts("0");
            return 0;
        }
    }

    int result[MAX]; // 각 변수의 true / false 여부
    memset(result, -1, sizeof(result));

    // sccn 이 dfs 방문 순서이므로, 순서를 뒤집으면 위상정렬 순서
    pair<int,int> p[DMAX];
    for(int i = 0; i<n*2; i++)
        p[i] = make_pair(sccn[i],i);
    sort(p, p+n*2);

    // x 를 먼저 마주치면 false, ~x 를 마주치면 x 를 true로 변수를 설정
    // scc 번호 순으로 방문하므로, 하나의 scc 에 속한 변수들은 같은 값으로 설정됨
    for(int i = n*2-1; i>=0; i--){
        int var = p[i].second;
        if(result[var/2] == -1) result[var/2] = !(var%2);
    }

    puts("1");
    for(int i = 0; i<n; i++)
        printf("%d ", result[i]);

}