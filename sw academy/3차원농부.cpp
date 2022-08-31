#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

int lower_bound(const vector<int>& vec, int value) {
	int lo = 0, hi = vec.size() - 1;

	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (value <= vec[mid])
			hi = mid;
		else
			lo = mid + 1;
	}
	return lo;
}


int main(int argc, char** argv)
{
	cin.tie(NULL); ios::sync_with_stdio(false);

	// freopen("input.txt", "r", stdin);

	int test_case;
	int T; cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		// input
		int n, m; cin >> n >> m;
		int c1, c2; cin >> c1 >> c2;

		vector<int> cow; int tmp;
		for (int i = 0; i < n; i++) {
			cin >> tmp; cow.push_back(tmp);
		}
		sort(cow.begin(), cow.end());

		// solution
		int mn_dist = INT_MAX, mn_dist_cnt = 0;
		for (int i = 0; i < m; i++) {
			cin >> tmp;
			int cid = lower_bound(cow, tmp);

			int dist = abs(cow[cid] - tmp);
			if (dist < mn_dist) {
				mn_dist = dist;
				mn_dist_cnt = 1;
			}
			else if (dist == mn_dist) {
				mn_dist_cnt++;
			}

			cid -= 1;
			if (0 <= cid && cid < n && cow[cid] != tmp) {
				dist = abs(cow[cid] - tmp);
				if (dist < mn_dist) {
					mn_dist = dist;
					mn_dist_cnt = 1;
				}
				else if (dist == mn_dist) {
					mn_dist_cnt++;
				}
			}

		}

		// output
		printf("#%d %d %d\n", test_case, mn_dist + abs(c1 - c2), mn_dist_cnt);
	}
	return 0;
}