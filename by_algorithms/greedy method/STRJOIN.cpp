#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#include <vector>
#include <queue>

int n;

int func(const vector<int>& arr) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < arr.size(); i++)
        pq.push(arr[i]);
    int ret = 0;
    while (pq.size() > 1) {
        int min1 = pq.top(); pq.pop();
        int min2 = pq.top(); pq.pop();
        pq.push(min1 + min2);
        ret += min1 + min2;
    }
    return ret;
}


int main()
{
    int C; cin >> C;
    while (C--) {
        cin >> n;
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            arr.push_back(tmp);
        }
        cout << func(arr) << endl;
    }
}
