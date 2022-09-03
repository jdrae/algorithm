// binary search/가장긴증가하는부분수열2.py 참고

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int arr[1000];
int cache[1000];

int lis(int start) {
	if (start == n) return 1;
	int& ret = cache[start+1];
	if (ret != -1) return ret;

	ret = 1; // wae!!
	for (int next = start+1; next < n; next++) {
		if (start == -1 || arr[start] < arr[next]) {
			ret = max(ret, lis(next) + 1);
		}
	}
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	memset(cache, -1, sizeof(cache));
	cout << lis(-1) -1 << endl; //WAE!!!
}