#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1010;

int n;
int neigh[MAX];
int adj[MAX][MAX];
int degree[MAX] = { 0, };
vector<int> path;

void dfs(int curr) {
    // tip: 그래프 시간초과 - 멈춘 위치에서 다시 탐색하기
    for (int& nxt = neigh[curr]; nxt <= n; nxt++) {
    // for (int nxt = 1; nxt<=n; nxt++){
        while (adj[curr][nxt]) {
            adj[curr][nxt]--;
            adj[nxt][curr]--;
            dfs(nxt);
        }
    }
    path.push_back(curr);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
            degree[i] += adj[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        if (degree[i] % 2 == 1) {
            puts("-1");
            return 0;
        }
    }

    for (int i = 1; i <= n; i++) neigh[i] = 1;

    dfs(1);

    for (int i : path){
        cout << i << ' ';
    }
}

/*
=======1======
1 2 stop            <--- 2 에서 멈춤
=======2======
1 2 3 stop
=======3======
1 2 3 4 stop
=======4======
1 stop
=======1======
2 3 4 5 stop        <--- 2 부터 탐색
=======5======
1 2 stop
=======2======
3 4 stop
=======4======
1 2 3 4 5 stop
=======5======
2 3 4 5 6 stop
=======6======
1 stop
=======1======
5 6 2 3 4 5 6 6 5 6 5 6
==================
1 6 5 4 2 5 1 4 3 2 1
*/