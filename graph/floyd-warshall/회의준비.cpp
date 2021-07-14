#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 101;
const int INF = 100000;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin>>n>>m;
    
    int dist[MAX][MAX];   
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=n; j++)
            dist[i][j] = i==j ? 0 : INF;

    int a, b;
    while(m--){
        cin >>a>>b;
        dist[a][b] = dist[b][a] = 1;
    }

    for(int k = 1; k<=n; k++)
        for(int i = 1; i<=n; i++)
            for(int j = 1; j<=n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    vector<int> components[MAX]; int cnt = 0;
    // tip: dfs with stack
    bool visited[MAX] = {0};
    stack<int> st;
    for(int i = 1;i<=n; i++){
        if(!visited[i]){
            visited[i] = true;
            st.push(i);
            cnt++;
            components[cnt].push_back(i);
        }
        while(!st.empty()){
            int curr = st.top(); st.pop();
            for(int nxt = 1; nxt <=n; nxt++){
                if(dist[curr][nxt] != INF && !visited[nxt]){
                    visited[nxt] = true;
                    st.push(nxt);
                    components[cnt].push_back(nxt);
                }
            }
        }
    }
    
    vector<int> idx;
    for(int i = 1; i<=cnt; i++){
        int res = INF; int num;
        for(int curr : components[i]){
            int ans = 0;
            for(int dst : dist[curr]){
                if(dst != INF) ans = max(ans, dst);
            }
            if(ans < res){
                res = ans;
                num = curr;
            }
        }
        idx.push_back(num);
    }
    sort(idx.begin(), idx.end());
    printf("%d\n",cnt);
    for(int i = 0; i<cnt; i++)
        printf("%d\n", idx[i]);
}