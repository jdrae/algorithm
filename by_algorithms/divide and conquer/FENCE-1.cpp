#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
vector<int> h;

/*int bruteForce(const vector<int>& h) {
	int ret = 0;
	int N = h.size();
	for (int left = 0; left < N; ++left) {
		int minHeight = h[left];
		for (int right = left+1; right < N; ++right) {
			minHeight = min(minHeight, h[right]);
			ret = max(ret, (right - left + 1) * minHeight);
		}
	}
	return ret;
}*/

int solve(int l, int r) {
	if (l == r) return h[l];
	int mid = (l + r) / 2;
	int ret = max(solve(l, mid), solve(mid + 1, r));

	int lo = mid, hi = mid + 1;
	int height = min(h[lo], h[hi]);
	ret = max(ret, height * 2);

	while (l < lo || hi < r) {
		if (hi < r && (lo == l || h[lo - 1] < h[hi + 1])) {
			++hi;
			height = min(height, h[hi]);
		}
		else {
			--lo;
			height = min(height, h[lo]);
		}
		ret = max(ret, height * (hi - lo + 1));
	}
	return ret;
}

int main() {
	int C; cin >> C;
	int tmp;
	while (C--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			h.push_back(tmp);
		}

		cout << solve(0, N - 1) << endl;
		h.erase(h.begin(), h.end());
	}

}