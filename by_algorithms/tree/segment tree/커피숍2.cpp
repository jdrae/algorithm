#include <iostream>
#include <algorithm>
using namespace std;
#define ST_MAX 262144

struct SegTree {
    int start;
    long long arr[ST_MAX];
    SegTree(int n) {
        start = 1;
        while (start < n) start *= 2;
        fill(arr, arr + ST_MAX, 0);
    }
    void construct() {
        for (int i = start - 1; i > 0; i--)
            arr[i] = arr[i * 2] + arr[i * 2 + 1];
    }
    void update(int idx, int val) {
        idx = idx + start - 1;
        arr[idx] = val;
        while (idx > 1) {
            idx /= 2;
            arr[idx] = arr[idx * 2] + arr[idx * 2 + 1];
        }
    }
    long long sum(int l, int r) { return sum(l, r, 1, 1, start); }
    long long sum(int l, int r, int node, int nl, int nr) {
        if (nl > r || nr < l) return 0;
        if (l <= nl && nr <= r) return arr[node];
        int mid = (nl + nr) / 2;
        return sum(l, r, node * 2, nl, mid) + sum(l, r, node * 2 + 1, mid + 1, nr);
    }
};

int main() {
    int n, q; scanf("%d%d", &n, &q);
    SegTree ST(n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &ST.arr[ST.start + i]);
    ST.construct();
    int x, y, a, b, l, r;
    while (q--) {
        scanf("%d%d%d%d", &x, &y, &a, &b);
        l = min(x, y); r = max(x, y);
        printf("%lld\n", ST.sum(l, r));
        ST.update(a, b);
    }
}