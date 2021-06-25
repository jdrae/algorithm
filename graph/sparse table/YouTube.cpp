#include <iostream>
using namespace std;
#define MAX 100001
#define MAX_D 30

int main() {
    int n, k, m; scanf("%d%d%d", &n, &k, &m);
    int arr[MAX], next[MAX][MAX_D];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= k; i++) {
        scanf("%d", &next[i][0]);
    }

    for (int j = 1; j < MAX_D; j++) {
        for (int i = 1; i <= k; i++) {
            next[i][j] = next[next[i][j - 1]][j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        int x = arr[i]; int step = m-1;
        for (int j = MAX_D - 1; j >= 0; j--) {
            if (step >= 1 << j) {
                step -= 1 << j;
                x = next[x][j];
            }
        }
        printf("%d ", x);
    }
    printf("\n");
}