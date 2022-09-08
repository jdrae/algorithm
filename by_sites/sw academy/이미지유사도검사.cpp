#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int n;
string x, y;

int main(int argc, char** argv)
{
	cin.tie(NULL); ios::sync_with_stdio(false);

	int test_case;
	int T; cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		cin >> x >> y;

		int lcs = 0;
		int arr[501][501] = {0, };
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (x[i-1] == y[j-1]) {
					arr[i][j] = arr[i - 1][j - 1] + 1;
				}
				else {
					arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
				}
				lcs = max(lcs, arr[i][j]);
			}
		}

		double answer = (double)lcs/n * 100;
		printf("#%d %.2f\n", test_case, answer);

	}
	return 0;
}