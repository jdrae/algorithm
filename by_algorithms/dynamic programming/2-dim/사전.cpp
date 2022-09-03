#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 1000000000 + 1;
int N, M, K;
int bino[201][201];

void init() {
	memset(bino, 0, sizeof(bino));
	for (int i = 0; i < 201; i++) {
		bino[i][0] = bino[i][i] = 1;
		for (int j = 1; j < i; j++) {
			bino[i][j] = min(MAX, bino[i - 1][j - 1] + bino[i - 1][j]);
		}
	}
}

string solve(int n, int m, int skip) {
	if (n == 0) return string(m, 'z');
	//첫글자가 a
	if (skip < bino[n + m - 1][n - 1])
		return 'a' + solve(n - 1, m, skip); //skip 안함
	// 첫글자가 z
	else
		return 'z' + solve(n, m - 1, skip - bino[n + m - 1][n - 1]); //skip 함
}

int main() {
	cin >> N >> M >> K;
	init();
	if (K > bino[N + M][N]) {
		cout << -1 << endl;
		return 0;
	}
	else
		cout << solve(N, M, K - 1) << endl;
}