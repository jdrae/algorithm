#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int arr[1000], cache[1001];

int biglis(int start) {
	if (start == n) return 0;
	int& ret = cache[start + 1];
	if (ret != -1) return ret;

	ret = 0;
	for (int next = start+1; next < n; next++) {
		if (start == -1 || arr[start] < arr[next]) {
			ret = max(ret, biglis(next));
		}
	}
	if (start != -1) ret = arr[start] + ret;
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	memset(cache, -1, sizeof(cache));
	cout << biglis(-1) << endl;
}