#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1000;

// tip: 엣지 구조체. 가중치 기준 오름차순 정렬.
struct Edge {
    int u, v, w;
    Edge() : Edge(-1, -1, 0) {}
    Edge(int u1, int v1, int w1) : u(u1), v(v1), w(w1) {}
    bool operator <(const Edge& O)const { return w < O.w; }
};

// union-find
int uf[MAX];

int find(int a) {
    if (uf[a] < 0) return a;
    return uf[a] = find(uf[a]);
}

bool merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    uf[b] = a;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Edge e[100000];
    int n, m; cin >> n >> m;
    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        e[i] = Edge(u, v, w);
    }
    sort(e, e + m);

    int result = 0, cnt = 0;
    fill(uf, uf + n, -1);
    for (int i = 0; ; i++) {
        if (merge(e[i].u, e[i].v)) {
            result += e[i].w;
            if (++cnt == n - 1) break;
        }
    }
    printf("%d\n", result);
}