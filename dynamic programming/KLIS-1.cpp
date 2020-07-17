#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, S[500];
const int MAX = 2147483647; //구하려는 LIS 의 최대 개수
int cacheLen[501], cacheCnt[501];

//start 에서 시작하는 LIS 의 길이
int lis(int start) {
	int& ret = cacheLen[start + 1]; //start 는 [-1,499]
	if (ret != -1) return ret;
	ret = 1; // 초기화 및 기저사례(start==499 일 경우)
	for (int next = start + 1; next < n; next++) {
		if (start == -1 || S[start] < S[next])
			ret = max(ret, lis(next) + 1);
	}
	return ret;
}

// start 에서 시작하는 LIS 의 개수
int count(int start) {
	if (lis(start) == 1) return 1; // 기저사례
	int& ret = cacheCnt[start + 1];
	if (ret != -1) return ret;
	ret = 0;
	for (int next = start + 1; next < n; next++) {
		if ((start == -1 || S[start] < S[next]) && lis(start) == lis(next) + 1)
			ret = min<long long>(MAX, (long long)ret + count(next));
	}
	return ret;
}

void reconstruct(int start, int skip, vector<int>& ans) {
	if (start != -1) ans.push_back(S[start]);
	vector<pair<int, int>> followers;
	for (int next = start + 1; next < n; next++) {
		if ((start == -1 || S[start] < S[next]) && lis(start) == lis(next) + 1)
			followers.push_back(make_pair(S[next], next));
	}
	sort(followers.begin(), followers.end());
	for (int i = 0; i < followers.size(); i++) {
		int idx = followers[i].second;
		int cnt = count(idx);
		if (cnt <= skip)
			skip -= cnt;
		else {
			reconstruct(idx, skip, ans);
			break;
		}
	}
}

int main() {
	int C; cin >> C;
	while (C--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> S[i];
		memset(cacheLen, -1, sizeof(cacheLen));
		memset(cacheCnt, -1, sizeof(cacheCnt));
		cout << lis(-1) -1 << endl;
		count(-1);
		vector<int> ans;
		reconstruct(-1, k - 1, ans);
		for (int i = 0; i < ans.size(); i++) {
			if (i < ans.size() - 1)
				printf("%d ", ans[i]);
			else
				printf("%d\n", ans[i]);
		}
	}
}
