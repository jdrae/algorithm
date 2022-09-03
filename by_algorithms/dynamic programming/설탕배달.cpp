#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF 1000000
int cache[5001];

int sugar(int k) {
	if (k == 0) return 0;
	if (k < 0) return INF;

	int& ret = cache[k];
	if (ret != -1) return ret;
	ret = 0;
	ret = 1 + min(sugar(k - 5), sugar(k - 3));
	return ret;
}

int main() {
	int n; cin >> n;
	memset(cache, -1, sizeof(cache));

	if (INF <= sugar(n)) cout << -1 << endl;
	else cout << sugar(n) << endl;
}