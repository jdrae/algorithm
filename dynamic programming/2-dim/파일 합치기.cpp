#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int k;
int arr[501], sum[501];
int cache[501][501];

int count(int from, int to) {
	int& ret = cache[from][to];
	if (ret != 0x3f3f3f3f) return ret;
	if (from == to) return ret = 0;
	if (from + 1 == to) return ret = arr[from] + arr[to];

	for (int mid = from; mid < to; mid++) {
		int left = count(from, mid);
		int right = count(mid + 1, to);
		ret = min(ret, left + right);
	}
	return ret += sum[to] - sum[from - 1];
}

int main() {
	int t;  cin >> t;
	while (t--) {
		cin >> k;
		for (int i = 1; i <= k; i++) {
			cin >> arr[i];
			sum[i] = sum[i - 1] + arr[i];
		}
		memset(cache, 0x3f, sizeof(cache));
		cout << count(1, k) << endl;
	}
}