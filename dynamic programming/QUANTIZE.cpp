#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 98765321;
int n, s, arr[100], sum[100], sqsum[100];
int cache[100][11];

void init() {
    sort(arr, arr + n);
    sum[0] = arr[0];
    sqsum[0] = arr[0] * arr[0];
    for (int i = 1; i < n; i++) {
        sum[i] = arr[i] + sum[i - 1];
        sqsum[i] = arr[i] * arr[i] + sqsum[i - 1];
    }
}

int rse(int lo, int hi) { // [lo,hi]
    int s = sum[hi] - (lo == 0 ? 0: sum[lo - 1]);
    int sq = sqsum[hi] - (lo == 0 ? 0 : sqsum[lo - 1]);
    // 반올림 처리
    int m = int(0.5 + (double)s / (hi - lo + 1));

    int ans = sq - 2*m*s + m*m*(hi - lo + 1);
    return ans;
}

int func(int from, int parts) {
    if (from == n) return 0;
    if (parts == 0) return INF;
    int& ret = cache[from][parts];
    if (ret != -1) return ret;
    ret = INF;
    for (int size = 1; from + size <= n; size++) {
        ret = min(ret,
                  func(from + size, parts - 1) + rse(from, from+size-1)
              );
    }
    return ret;
}

int main()
{
    int C; cin >> C;
    while (C--) {
        cin >> n >> s;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        memset(cache, -1, sizeof(cache));
        init();
        cout << func(0, s) << endl;
    }
}
