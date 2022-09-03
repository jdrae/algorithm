#include <iostream>
using namespace std;
const int MAX = 500001;
const int MAX_D = 19; // 2^k >= MAX 인 최소의 k

int main() {
    int m, next[MAX][MAX_D]; // next[i][j]: i 에서 j 번 이동한 후의 (유일한) 정점
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &next[i][0]);
    }
    for (int j = 1; j < MAX_D; j++) {
        for (int i = 1; i <= m; i++) {
            next[i][j] = next[ next[i][j - 1] ][j - 1]; // tip
        }
    }

    int q, n, x; scanf("%d", &q);
    while (q--) {
        scanf("%d %d", &n, &x);
        for (int j = MAX_D - 1; j >= 0; j--) { // tip : 켜져있는 비트 확인하기
            if (n >= 1 << j) {
                n -= 1 << j;
                x = next[x][j];
            }
        }
        printf("%d\n", x);
    }
}