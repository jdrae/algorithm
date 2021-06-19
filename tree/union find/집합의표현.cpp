#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

vector<int> p;

int find(int n){
    if(p[n] < 0) return n;
    p[n] = find(p[n]);
    return p[n];
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    p[b] = a;
}

int main(){
    int n,m;
    scanf("%d %d",&n, &m);
    p.resize(n+1); fill(p.begin(), p.end(), -1);
    int cmd, a, b;
    for(int i = 0; i<m; i++){
        scanf("%d %d %d",&cmd, &a, &b);
        if(cmd){
            if(find(a) == find(b)) printf("YES\n");
            else printf("NO\n");
        }
        else merge(a,b);
    }
}