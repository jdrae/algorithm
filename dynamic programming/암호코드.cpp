#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

//거꾸로 세는법 시도해볼것

#define MOD 1000000
int n, cache[5000];
string arr;

int count(int idx) {
	if (idx >= n) return 1;
	if (arr[idx] - '0' == 0) return 0;
	if (idx == n - 1) return 1; //마지막 수이면서 0이 아님

	int& ret = cache[idx];
	if (ret != -1) return ret;

	ret = 0;
	ret += count(idx + 1); //현재 수를 하나로 보고 다음 수부터 카운트
	if (arr[idx] - '0' == 1 && arr[idx + 1] - '0' <= 9)
		ret += count(idx + 2);
	if (arr[idx] - '0' == 2 && arr[idx + 1] - '0' <= 6)
		ret += count(idx + 2);
	return ret % 1000000;
 }

int main() {
	cin >> arr;
	n = arr.size();
	memset(cache, -1, sizeof(cache));
	cout << count(0) << endl;
}