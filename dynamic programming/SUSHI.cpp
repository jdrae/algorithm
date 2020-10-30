#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, price[20], pref[20];

/*
* 배열크기로 메모리 초과
#define MAX 1000000000
int cache[MAX + 1];
int func(int budget) {
    int& ret = cache[budget];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i < n; i++) {
        if (budget < price[i]) continue;
        ret = max(ret, func(budget - price[i]) + pref[i]);
    }
    return ret;
}
*/

/*
* 실행횟수로 시간 초과 
int cache[20001]; //슬라이딩 윈도 기법
int func() {
    int ret = 0;
    cache[0] = 0; // 안하면 x
    for (int budget = 1; budget <= m; budget++) {
        int cand = 0;
        for (int i = 0; i < n; i++) {
            if (budget < price[i]) continue;
            cand = max(cand, cache[(budget - price[i]) % 20001] + pref[i]);
        }
        cache[budget % 20001] = cand;
        ret = max(ret, cand);
    }
    return ret;
}
*/

int cache[201]; // 값이 100의 배수이므로 100으로 나눔
int func() {
    int ret = 0;
    cache[0] = 0;
    for (int budget = 1; budget <= m; budget++) { // budget 의 최대는 1천만 (10억 / 100)
        int cand = 0;
        for (int i = 0; i < n; i++) {
            if (budget < price[i]) continue;
            cand = max(cand, cache[(budget - price[i]) % 201] + pref[i]);
        }
        cache[budget % 201] = cand;
        ret = max(ret, cand);
    }
    return ret;
}

void init() {
    for (int i = 0; i < n; i++) {
        price[i] = int(price[i] / 100);
    }
    m = m / 100;
}

int main(void)
{
    int C; cin >> C;
    while(C--){
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> price[i] >> pref[i];

        init(); // 100으로 나눔
        cout << func() << endl;
    }
}
