#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
const int SIZE = 2097152;

struct SegTree {
    int size, start;
    ll arr[SIZE];
    SegTree(int n) : size(n) {
        start = 1;
        while (start < size) start *= 2; // tip
        memset(arr, 0, sizeof(arr));
    }
    void construct() {
        for (int i = start - 1; i > 0; i--)
            arr[i] = arr[i * 2] + arr[i * 2 + 1];
    }
    void add(int a, ll b) {
        a += start;
        b -= arr[a];
        while (a > 0) {
            arr[a] += b;
            a /= 2;
        }
    }
    ll sum(int l, int r) { return sum(l, r, 1, 0, start); }
    ll sum(int l, int r, int node, int nl, int nr) {
        if (r <= nl || l >= nr) return 0;
        if (l <= nl && nr <= r) return arr[node];
        int mid = (nl + nr) / 2;
        return sum(l, r, node * 2, nl, mid) + sum(l, r, node * 2 + 1, mid, nr);
    }
};

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    SegTree ST(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", ST.arr + ST.start + i);
    }
    ST.construct();
    int a, b; ll c;
    for (int i = 0; i < m + k; i++) {
        scanf("%d%d%lld", &a, &b, &c);
        if (a == 1) {
            ST.add(b - 1, c);
        }
        else {
            printf("%lld\n", ST.sum(b - 1, c));
        }
    }
}