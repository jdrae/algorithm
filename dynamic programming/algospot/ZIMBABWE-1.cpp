﻿#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;
string e, digits; //digist 은 e 를 정렬한 것
int n, m;
int cache[1 << 14][20][2];

//완전탐색 - 배수 확인 안함
/*
void generate(string price, bool taken[15]) {
	if (price.size() == n) {
		if (price < e) //string 이지만 자리수가 같기에 대소비교 가능
			cout << price << endl;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!taken[i] &&
			(i == 0 || digits[i - 1] != digits[i] || taken[i - 1])) {
			taken[i] = true;
			generate(price + digits[i], taken);
			taken[i] = false;
		}
	}
}
*/

int price(int index, int taken, int mod, int less) {
	if (index == n)
		return (less && mod == 0) ? 1 : 0;

	int& ret = cache[taken][mod][less];
	if (ret != -1) return ret;
	ret = 0;
	for (int next = 0; next < n; ++next) {
		if ( (taken & (1 << next)) == 0) {
			//과거 가격보다 새 가격이 작아야
			if (!less && e[index] < digits[next])
				continue;
			//같은 숫자는 한번만
			if(next>0&& digits[next-1] == digits[next] && 
				( taken& (1<<(next-1)) ) == 0)
				continue;

			int nextTaken = taken | (1 << next);
			int nextMod = (mod * 10 + digits[next] - '0') % m;
			int nextLess = less || e[index] > digits[next];
			ret += price(index + 1, nextTaken, nextMod, nextLess);
			ret %= MOD;
		}
	}
	return ret;
}

int main() {
	int c; cin >> c;
	while (c--) {
		cin >> e >> m;
		n = e.size();
		digits = e;
		sort(digits.begin(), digits.end());
		
		/*string p;
		bool taken[15];
		memset(taken, 0, sizeof(taken));
		generate(p, taken);*/

		memset(cache, -1, sizeof(cache));
		cout << price(0, 0, 0, 0) << endl;
	}
}