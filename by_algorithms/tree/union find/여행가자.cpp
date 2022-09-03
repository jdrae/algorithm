#include <iostream>
#include <vector>
using namespace std;

vector<int> p;

int find(int n){
    if(p[n] < 0) return n;
    p[n] = find(p[n]);
    return p[n];
}

void merge(int a, int b){
    a = find(a); b = find(b);
    if(a==b) return;
    p[b] = a;
}

int main(){
    int n, m, conn, tmp;
    scanf("%d %d", &n, &m);
    p.resize(n); fill(p.begin(), p.end(), -1);
    for(int i = 0 ; i<n; i++){
        for(int j = 0; j<n; j++){
            scanf("%d", &conn);
            if(conn){
                merge(i, j);
            }
        }
    }
    int set; int i;
    for(i = 0; i<m; i++){
        scanf("%d",&tmp); 
        int check_set = find(--tmp);
        if(i == 0){
            set = check_set; continue;
        }
        else if(set != check_set) break;
    }
    if (i == m)
        printf("YES\n");
    else
        printf("NO\n");
}