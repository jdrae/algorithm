#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 200000;

int uf[MAX];
int find(int a) {
    if (uf[a] < 0) return a;
    return uf[a] = find(uf[a]);
}

bool merge(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return false;
    uf[b] = a;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
        priority_queue<pair<int, pair<int, int>>> pq;
        fill(uf, uf + MAX, -1);

        int V, E; cin >> V >> E;
        if(V == 0) break;
        
        int u, v, w; int sum = 0;
        for (int i = 0; i < E; i++) {
            cin >> u >> v >> w;
            pq.push({ -w,{u,v} });
            sum += w;
        }

        int mst = 0, cnt = 0;
        while (!pq.empty()) {
            if (merge(pq.top().second.first, pq.top().second.second)) {
                mst += pq.top().first;
                if (++cnt == V - 1) break;
            }
            pq.pop();
        }
        printf("%d\n", sum+mst);

    }
}