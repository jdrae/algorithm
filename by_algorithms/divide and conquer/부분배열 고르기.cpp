#include <iostream>
#include <algorithm> 
using namespace std;
typedef long long ll;
const int MAX = 1000001;

int N;
int A[MAX];

ll calc(int l, int r) {
    if (l == r) return (ll)A[l] * A[l];
    int mid = (l + r) / 2;
    ll res = max(calc(l, mid), calc(mid + 1, r));

    int i = mid;
    int j = mid + 1;

    ll sum = A[i] + A[j];
    ll mn = min(A[i], A[j]);
    res = max(res, sum * mn);

    while (l < i || j < r) {
        if (j < r && (i == l || A[i - 1] < A[j + 1])) {
            sum += A[++j];
            mn = min(mn, (ll)A[j]);
        }
        else {
            sum += A[--i];
            mn = min(mn, (ll)A[i]);
        }
        res = max(res, sum * mn);
    }
    return res;
}

int main() {
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cout << calc(0, N - 1);
}