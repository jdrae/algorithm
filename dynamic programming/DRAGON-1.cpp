#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

const int MAX = 1000000000 + 1;
int n, p, l;

int length[51];
void precalc() {
	length[0] = 1;
	for (int i = 1; i <= n; i++) {
		length[i] = min(MAX, length[i - 1] * 2 + 2);
	}
}

const string EXPAND_X = "X+YF";
const string EXPAND_Y = "FX-Y";
char expand(const string& dragonCurve, int generations, int skip) {
	if (generations == 0) {
		assert(skip < dragonCurve.size());
		return dragonCurve[skip];
	}
	for (int i = 0; i < dragonCurve.size(); i++) {
		if (dragonCurve[i] == 'X' || dragonCurve[i] == 'Y') {
			if (skip >= length[generations])
				skip -= length[generations];
			else if (dragonCurve[i] == 'X')
				return expand(EXPAND_X, generations - 1, skip);
			else
				return expand(EXPAND_Y, generations - 1, skip);
		}
		else if (skip > 0)
			--skip;
		else
			return dragonCurve[i];
	}
	return '#'; //이 줄은 수행되지 않음
}
/*
void curve(const string& seed, int generations) {
	if (generations == 0) {
		cout << seed;
		return;
	}
	for (int i = 0; i < seed.size(); i++) {
		if (seed[i] == 'X')
			curve("X+YF", generations - 1);
		else if (seed[i] == 'Y')
			curve("FX-Y", generations - 1);
		else
			cout << seed[i];
	}
}
*/
int main() {
	int C; cin >> C;
	while (C--) {
		cin >> n >> p >> l;
		precalc();
		for (int i = 0; i < l; i++) {
			cout << expand("FX", n, p - 1 + i);
		}
		cout << endl;
	}
}
