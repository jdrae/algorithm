#include <iostream>
#include <algorithm> 
#include <cstring>
using namespace std;

int N;
int T[15], P[15];
int dp[15];

int func(int idx) {
	if (N <= idx) return 0;
	int& ret = dp[idx];
	if (ret != -1) return ret;

	ret = func(idx + 1);
	if (idx + T[idx] <= N)
		ret = max(P[idx] + func(idx + T[idx]), ret);
	return ret;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << func(0);
}
