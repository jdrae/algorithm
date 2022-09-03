#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k;
int arr[100];
int dp[10001] = { 0, };

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = arr[i]; j <= k; j++) {
			if (j - arr[i] >= 0)
				dp[j] += dp[j - arr[i]];
		}
	}
	cout << dp[k] << endl;
}