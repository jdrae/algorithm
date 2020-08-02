#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, L, I;
int dp[33][33];


int init(int n, int l) {
	int& ret = dp[n][l];
	if (ret != -1) return ret;
	if (l == 0 || n == 0) return ret = 1;
	
	ret = init(n - 1, l);
	if(l > 0) ret += init(n - 1, l - 1);
	return ret;
}



/* 왜 안될까
void init(int n, int l) {
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i <= n; i++) {
		dp[i][0] = dp[i][i] = 1;
		for (int j = 1; j <= i; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}
}*/

string solve(int n, int l, int skip) {
	if (l == 0) return string(n-l, '0');
	//첫글자가 0
	if (skip < dp[n-1][l])
		return '0' + solve(n - 1, l, skip); //skip 안함
	// 첫글자가 1
	else
		return '1' + solve(n - 1, l - 1, skip - dp[n - 1][l]); //skip 함
}

int main() {
	cin >> N >> L >> I;
	memset(dp, -1, sizeof(dp));
	init(N, L);
	cout << solve(N, L, I - 1) << endl;
}