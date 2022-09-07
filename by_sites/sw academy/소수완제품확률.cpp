#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

using namespace std;

int n = 18;
int prime[7] = { 2,3,5,7,11,13,17 };
int comb[19][19];

void init() {
	comb[1][0] = comb[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		comb[i][0] = 1;
		for (int j = 1; j <= n; j++)
			comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
	}
}

int main(int argc, char** argv)
{
	cin.tie(NULL); ios::sync_with_stdio(false);

	init();

	int T; cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		double a, b; cin >> a >> b;
		a /= 100; b /= 100;

		double a_t = 0.0, b_t = 0.0;
		for (int r : prime) {
			a_t += comb[n][r] * pow(a, r) * pow(1 - a, n - r);
			b_t += comb[n][r] * pow(b, r) * pow(1 - b, n - r);
		}
		double answer = 1 - ((1 - a_t) * (1 - b_t));

		printf("#%d %.6f\n", test_case, answer);
	}
	return 0;
}
