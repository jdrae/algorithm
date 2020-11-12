#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, arr[100][100], cache[100][100], cache2[100][100];

int path(int y, int x) {
    if (y == n || x == n) return 0;
    int& ret = cache2[y][x];
    if (ret != -1) return ret;
    return ret = max(path(y + 1, x), path(y + 1, x + 1)) + arr[y][x];
}

int func(int y, int x) {
    if (y == n - 1) return 1;
    int& ret = cache[y][x];
    if (ret != -1) return ret;
    ret = 0;
    if (path(y + 1, x) <= path(y + 1, x + 1)) ret += func(y + 1, x + 1);
    if (path(y + 1, x) >= path(y + 1, x + 1)) ret += func(y + 1, x);
    return ret;
}

int main()
{
    int C; cin >> C;
    while (C--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= i; j++)
                cin >> arr[i][j];
        memset(cache, -1, sizeof(cache));
        memset(cache2, -1, sizeof(cache2));
        cout << func(0, 0) << endl;
    }
}
