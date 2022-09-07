#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
using namespace std;

typedef unsigned long long ull;

string s;
int cnt[26];
ull per[21];
ull answer;

void init() {
    per[0] = per[1] = 1;
    for (int i = 2; i < 21; i++)
        per[i] = per[i - 1] * i;

    for (int i = 0; i < 26; i++)
        cnt[i] = 0;

    answer = 0;
}

ull calculate(int len) {
    ull ret = per[len];
    for (int i = 0; i < 26; i++)
        if (cnt[i] > 1)
            ret /= per[cnt[i]];
    return ret;
}

int main(int argc, char** argv)
{
    cin.tie(NULL); ios::sync_with_stdio(false);

    init();

    int T; cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case)
    {
        cin >> s;
        for (char c : s)
            cnt[c - 'A']++;

        int len = s.size();
        ull answer = 0;
        for (char c : s) {
            len--;
            for (int i = c - 'A' - 1; i >= 0; i--) {
                if (cnt[i] < 1) continue;
                cnt[i]--;
                answer += calculate(len);
                cnt[i]++;
            }
            cnt[c - 'A']--;
        }

        printf("#%d %lld\n", test_case, answer);
    }
    return 0;
}