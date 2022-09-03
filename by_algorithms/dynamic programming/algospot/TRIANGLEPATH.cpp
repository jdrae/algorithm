#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int arr[100][100], cache[100][100];

int func(int y, int x) {
    if (y == n || x > y) return 0;
    int& ret = cache[y][x];
    if (ret != -1) return ret;

    return ret = arr[y][x] + max(func(y + 1, x), func(y + 1, x + 1));
}

int main()
{
    int C; cin >> C;
    while (C--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i+1; j++)
                cin >> arr[i][j];

        memset(cache, -1, sizeof(cache));
        cout << func(0, 0) << endl;
    }
}
