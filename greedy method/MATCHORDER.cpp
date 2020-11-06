#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#include <vector>

int func(const vector<int>& rus, vector<int>& kor) {
    int ret = 0;
    for (int r = 0; r < rus.size(); r++) {
        for (int k = 0; k < kor.size(); k++) {
            if (rus[r] <= kor[k]) {
                kor.erase(kor.begin() + k);
                ret++; break;
            }
        }
    }
    return ret;
}

int main()
{
    int C; cin >> C;
    while (C--) {
        int n; cin >> n;
        vector<int> rus;
        vector<int> kor;
        int tmp;
        for (int i = 0; i < n; i++) {
            cin >> tmp; rus.push_back(tmp);
        }
        for (int i = 0; i < n; i++) {
            cin >> tmp; kor.push_back(tmp);
        }

        sort(kor.begin(), kor.end());
        cout << func(rus, kor) << endl;
    }
}
