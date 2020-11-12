#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;
int n, cache[101];

int func(int tile) {
    if (tile <= 1) return 1;
    int& ret = cache[tile];
    if (ret != -1) return ret;
    return ret = (func(tile - 1) + func(tile - 2)) % MOD;
}

int main()
{
    int C; cin >> C;
    while (C--) {
        cin >> n;
        memset(cache, -1, sizeof(cache));
        cout << func(n) << endl;
    }
}
