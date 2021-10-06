#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string num;
int cache[10000];
const int MAX = 987654321;

int check(int idx, int len) {
    // [idx, idx+len)
    string M = num.substr(idx, len); 
    // string(size, 'a') : size개의 'a'
    if (M == string(M.size(), M[0])) return 1;
    // 등차수열 검사
    bool progressive = true;
    for (int i = 0; i < M.size() - 1; i++)
        if (M[i + 1] - M[i] != M[1] - M[0]) //***
            progressive = false;
    // 1씩 증가 혹은 감소
    if (progressive && abs(M[1] - M[0]) == 1)
        return 2;
    // 두 수가 번갈아 등장
    bool alternating = true;
    for (int i = 0; i < M.size(); i++)
        if (M[i] != M[i % 2]) //***
            alternating = false;

    if (alternating) return 4;
    if (progressive) return 5;
    return 10;
}

int func(int idx) {
    if (idx == num.size()) return 0;
    int& ret = cache[idx];
    if (ret != -1) return ret;
    ret = MAX;
    for (int i = 3; i <= 5; i++)
        if(idx + i <= num.size()) //***
            ret = min(ret, check(idx, i) + func(idx + i));
    return ret;
}

int main()
{
    int C; cin >> C;
    while (C--) {
        cin >> num;
        memset(cache, -1, sizeof(cache));
        cout << func(0) << endl;
    }
}
