#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#include <vector>

string W, S;
string arr[50];
int cache[101][101];

int func(int w, int s) {
    int& ret = cache[w][s];
    if (ret != -1) return ret;
    while (w < W.size() && s < S.size()
            && (W[w] == S[w] || W[w] == '?') ) {
        return ret = func(w + 1, s + 1);
    }

    if (w == W.size()) return ret = (s == S.size());

    if (W[w] == '*') {
        if (func(w + 1, s) || s < S.size() && func(w, s + 1))
            return ret = 1;
    }

    return ret = 0;
}

int main()
{
    int C; cin >> C;
    while(C--){
        cin >> W;
        int n;  cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<string> res;

        for (int i = 0; i < n; i++) {
            S = arr[i];
            memset(cache, -1, sizeof(cache));
            if (func(0, 0) == 1) res.push_back(arr[i]);
        }

        sort(res.begin(), res.end());
        for (string str : res) {
            cout << "R" << str << endl;
        }

    }
}
