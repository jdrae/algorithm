#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, arr[500], cache[501];

int func(int idx) {
    // if (idx == n) return 0; //안해도 for 문에서 걸러짐
    int& ret = cache[idx+1];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = idx + 1; i < n; i++) {
        if (idx == -1 || arr[idx] < arr[i]) {
            ret = max(ret, func(i) + 1);
        }
    }
    return ret;
}

int main()
{
    int C; cin >> C;
    while (C--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        memset(cache, -1, sizeof(cache));
        cout << func(-1) << endl;
    }
}
