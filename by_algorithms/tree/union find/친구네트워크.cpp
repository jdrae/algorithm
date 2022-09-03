#include <iostream>
#include <unordered_map>
using namespace std;
#define MAX 2000001
int p[MAX];

int find(int a){
    if(p[a] < 0) return a;
    return p[a] = find(p[a]);
}

void merge(int a, int b){
    a = find(a); b = find(b);
    if(a== b) return;
    p[a] += p[b];
    p[b] = a;
}

int main(){
    int tc; scanf("%d",&tc);
    while(tc--){
        int f; scanf("%d", &f);
        unordered_map<string, int> m; // tip
        fill(p, p+MAX, -1);
        int n = 0;
        while(f--){
            char a[21], b[21]; scanf("%s %s", a, b); // tip
            if(m.count(a) == 0) m[a] = n++;
            if(m.count(b) == 0) m[b] = n++;

            merge(m[a], m[b]);
            printf("%d\n",-p[find(m[a])]);
        }
    }
}