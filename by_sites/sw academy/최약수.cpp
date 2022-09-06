#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	cin.tie(NULL); ios::sync_with_stdio(false);

	// freopen("input.txt", "r", stdin);

	int T; cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		int n; cin >> n;
		int digit = to_string(n).size() + 1;
		if (digit > 9) digit = 9;
		int target = pow(10, digit);

		int answer = 1;
		for (int d = 0; d < digit; d++) {
			int mn = pow(10, d) + 1;
			int mx = pow(10, d+1);
			if (mn > n) break;
			for (int i = 1; i * i <= mx; i++) {
				if (mx % i == 0) {
					if (mn <= i && i <= n)
						answer++;

					if (mx / i != i && (mn <= mx / i && mx / i <= n))
							answer++;
				}
			}
		}
		printf("#%d %d\n", test_case, answer);
	}
	return 0;
}