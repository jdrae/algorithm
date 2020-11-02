#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, arr[100][100], cache[100][100];

int func(int y, int x) {
    if (y >= n || x >= n) return 0;
    if (y == n - 1 && x == n - 1) return 1;
    int& ret = cache[y][x];
    if (ret != -1) return ret;
    // 1 || 0 은 1
    return ret = func(y + arr[y][x], x) || func(y, x + arr[y][x]);
}

int main(void)
{
    int C; cin >> C;
    while(C--){
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        }
        memset(cache, -1, sizeof(cache));
        if (func(0, 0)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
