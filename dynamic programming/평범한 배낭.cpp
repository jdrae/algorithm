#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Prop {
	int w; int v;
};

int n, k;
Prop arr[100];
int cache[100][100001];

int value(int pos, int weight) {
	if (pos == n) return 0;
	
	int& ret = cache[pos][weight];
	if (ret != -1) return ret;

	ret = value(pos + 1, weight);
	if (arr[pos].w <= weight)
		ret = max(ret, arr[pos].v + value(pos + 1, weight - arr[pos].w));
	

	return ret;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i].w >> arr[i].v;
	memset(cache, -1, sizeof(cache));
	cout << value(0, k) << endl;
}