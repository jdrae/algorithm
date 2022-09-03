#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

int arr[50][50];
int m, n, k;

void dfs(int i, int j) {
	arr[i][j] = 0;

	if (0 <= i - 1 && arr[i - 1][j]) dfs(i - 1, j);
	if(i+1<n && arr[i + 1][j]) dfs(i+1, j);
	if (0 <= j - 1 && arr[i][j-1]) dfs(i, j-1);
	if (j + 1 < m && arr[i][j+1]) dfs(i, j+1);
}

int main() {
	int t; cin >> t;
	while (t--) {
		cin >> m >> n >> k;
		arr[50][50] = { 0, };
		for (int i = 0; i < k; i++) {
			int x, y; cin >> x >> y;
			arr[y][x] = 1;
		}
		int component = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j]) {
					dfs(i, j);
					component++;
				}
			}
		}
		cout << component << endl;
	}
}
