#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#include <vector>

#define MAX 10001
int n, eat[MAX], mic[MAX];

int func() {
    vector<pair<int, int>> order;
    for (int i = 0; i < n; i++)
        // 음수로 내림차순 정렬 구현
        // 후에 인덱스로 원래 배열 값에 접근
        order.push_back(make_pair(-eat[i], i));
    sort(order.begin(), order.end());
    int ret = 0, beginEat = 0;
    for (int i = 0; i < n; i++) {
        int idx = order[i].second;
        beginEat += mic[idx];
        ret = max(ret, beginEat + eat[idx]);
    }
    return ret;
}

int main()
{
    int C; cin >> C;
    while (C--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> mic[i];
        for (int i = 0; i < n; i++)
            cin >> eat[i];
        cout << func() << endl;
    }
}
