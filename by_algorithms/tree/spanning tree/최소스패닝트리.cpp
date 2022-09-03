#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

struct Edge{
    int u, v, w;
    bool operator<(const Edge& E) { return w < E.w;}
};

int uf[10000];
int find(int a){
    if(uf[a] < 0) return a;
    return uf[a] = find(uf[a]);
}

int merge(int a, int b){
    a = find(a); b = find(b);
    if(a==b) return false;
    uf[b] = a;
    return true;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    

    int n,m; cin >> n >> m;
    Edge E[100000];
    fill(uf, uf+n, -1);
    int u, v, w;
    for(int i = 0; i<m; i++){
        cin >> u >> v >> w;
        E[i] = {u-1, v-1, w};
    }

    sort(E, E+m);
    long long sum = 0, cnt = 0;
    for(int i = 0; ; i++){
        if(merge(E[i].u, E[i].v)){
            sum += E[i].w;
            if(++cnt == n-1) break;
        }
    }
    cout << sum << endl;
}
