#include <iostream>
using namespace std;
#include <algorithm>

int arr[100][100];
int m, n, k;

int dfs(int i, int j) {
	arr[i][j] = 0;
	int node = 1;
	if (0 <= j - 1 && arr[i][j - 1]) node += dfs(i, j - 1);
	if (j + 1 < m && arr[i][j + 1]) node += dfs(i, j + 1);
	if (0 <= i - 1 && arr[i - 1][j]) node += dfs(i - 1, j);
	if (i + 1 < n && arr[i + 1][j]) node += dfs(i + 1, j);

	return node;
}

int main() {
	cin >> n >> m >> k;
	arr[100][100] = { 0, };
	while(k--) {
		int r, c; cin >> r >> c;
		arr[r - 1][c - 1] = 1;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j]) 
				ans = max(ans, dfs(i, j));
		}
	}

	cout << ans << endl;
}

