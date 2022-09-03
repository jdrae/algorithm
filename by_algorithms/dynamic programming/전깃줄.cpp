#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Cable {
	int a, b;
};

bool comp(Cable c1, Cable c2) {
	if (c1.a == c2.a) return c1.b < c2.b;
	return c1.a < c2.a;
}

int n, cache[101];
Cable arr[100];

int count(int idx) { // 안 겹치는 최대 전기줄 개수
	if (idx == n) return 0; // 실행안됨
	int& ret = cache[idx+1];
	if (ret != -1) return ret;

	ret = 0;
	for (int next = idx + 1; next < n; next++) {
		if (idx == -1 || arr[idx].b < arr[next].b) {
			ret = max(ret, count(next));
		}
	}
	if (idx == -1) return ret;
	else return ret += 1;
 }

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i].a >> arr[i].b;
	memset(cache, -1, sizeof(cache));

	sort(arr, arr + n, comp);

	// 제거해야할 최소 전기줄 개수 = 전체 개수 - 반환값
	cout << n - count(-1) << endl; 

}