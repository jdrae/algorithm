#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#define MAX 1500
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int p[MAX * MAX];

int find(int a) {
    if (p[a] < 0) return a;
    return p[a] = find(p[a]);
}

void merge(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return;
    p[b] = a;
}

int main() {
    int r, c; scanf("%d%d", &r, &c);
    int pos[2], cnt = 0;
    char arr[MAX][MAX];
    for (int i = 0; i < r; i++) {
        getchar();
        for (int j = 0; j < c; j++) {
            arr[i][j] = getchar(); // tip
            if (arr[i][j] == 'L') pos[cnt++] = i * MAX + j; // tip
        }
    }

    queue<int> q;
    fill(p, p + MAX * MAX, -1);
    // initial union
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] == 'X') continue;
            for (int d = 0; d < 4; d++) {
                int ny = i + dy[d]; int nx = j + dx[d];
                if (ny < 0 || ny >= r || nx < 0 || nx >= c || arr[ny][nx] == 'X') continue;
                merge(i * MAX + j, ny * MAX + nx);
            }
            q.push(i * MAX + j);
        }
    }

    // bfs
    int level = 0;
    while (find(pos[0]) != find(pos[1])) {
        int qSize = q.size();
        while (qSize--) {
            int i = q.front() / MAX; int j = q.front() % MAX; // tip
            q.pop();
            for (int d = 0; d < 4; d++) {
                int ny = i + dy[d]; int nx = j + dx[d];
                if (ny < 0 || ny >= r || nx < 0 || nx >= c || arr[ny][nx] != 'X') continue;
                arr[ny][nx] = '.';
                merge(i * MAX + j, ny * MAX + nx);
                q.push(ny * MAX + nx);

                for (int dd = 0; dd < 4; dd++) {
                    int nny = ny + dy[dd]; int nnx = nx + dx[dd];
                    if (nny < 0 || nny >= r || nnx < 0 || nnx >= c || arr[nny][nnx] == 'X') continue;
                    merge(ny * MAX + nx, nny * MAX + nnx);
                }
            }
        }
        level++;
    }
    printf("%d\n", level);
}