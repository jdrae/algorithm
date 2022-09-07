#include <iostream>

using namespace std;
#define MOD 1000000007

int main(int argc, char** argv)
{
	cin.tie(NULL); ios::sync_with_stdio(false);

	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		int n; long long k; cin >> n >> k;
		int arr[2000];
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		long long add = 0, mul = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j > i && arr[i] > arr[j]) add++;
				if (arr[i] < arr[j]) mul++;
			}
		}

		unsigned long long mid = (k * (k-1))/2 % MOD;
		long long answer = (mul * mid) % MOD;
		answer += (k * add) % MOD;
		printf("#%d %lld\n", test_case, answer % MOD);
	}
	return 0;
}