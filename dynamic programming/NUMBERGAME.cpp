#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int EMPTY = -987654321;
int n, arr[50];
int cache[50][50];

int play(int left, int right) {
    if (left > right) return 0; //모든 수가 다 없어졌을 때
    int& ret = cache[left][right];
    if(ret != EMPTY) return ret;

    ret = max(arr[left] - play(left + 1, right),
        arr[right] - play(left, right - 1));
    if (right - left + 1 >= 2) {
        ret = max(ret, -play(left + 2, right));
        ret = max(ret, -play(left, right - 2));
    }

    return ret;
}

void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cache[i][j] = EMPTY;
        }
    }
}

int main(void)
{
    int C; cin >> C;
    while(C--){
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        init();
        cout << play(0, n-1) << endl;

    }
}
