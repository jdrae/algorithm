#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, A[100], B[100], cache[101][101];
const long long NEGINF = numeric_limits<long long>::min();

int func(int a, int b) {
    int& ret = cache[a+1][b+1];
    if (ret != -1) return ret;
    // a, b 를 부분수열로 하는 jlis 구함. O(n^2)
    ret = 2;
    long long valueA = (a == -1 ? NEGINF : A[a]);
    long long valueB = (b == -1 ? NEGINF : B[b]);
    long long maxElement = max(valueA, valueB);

    for (int nextA = a + 1; nextA < n; nextA++)
        if (maxElement < A[nextA])
            ret = max(ret, func(nextA, b) + 1);
    for (int nextB = b + 1; nextB < m; nextB++)
        if (maxElement < B[nextB])
            ret = max(ret, func(a, nextB) + 1);
    return ret;
}

int main()
{
    int C; cin >> C;
    while (C--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> A[i];
        for (int i = 0; i < m; i++)
            cin >> B[i];
        memset(cache, -1, sizeof(cache));
        cout << func(-1, -1) - 2<< endl;
    }
}
