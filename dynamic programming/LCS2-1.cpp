#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

string s1;
string s2;
int cache[1001][1001];
vector<string> ans;

int LCS2(int idx1, int idx2) {
	if (idx1 == s1.size() || idx2 == s2.size()) return 0;

	int& ret = cache[idx1][idx2];
	if (ret != -1) return ret;

	ret = 0;
	if (s1[idx1] == s2[idx2]) {
		ret = max(ret, 1 + LCS2(idx1 + 1, idx2 + 1));
	}
	ret = max(ret, LCS2(idx1 + 1, idx2));
	ret = max(ret, LCS2(idx1, idx2 + 1));

	return ret;
}

void show(int idx1, int idx2) {
	if (idx1 == s1.size() || idx2 == s2.size()) return;
	int& ret = cache[idx1][idx2];
	if (ret == 0) return;
	
	if (ret == cache[idx1 + 1][idx2]) show(idx1 + 1, idx2);
	else if (ret == cache[idx1][idx2 + 1]) show(idx1, idx2 + 1);
	else {
		cout << s1[idx1];
		show(idx1+1, idx2+1);
	}
}

int main() {
	cin >> s1 >> s2;
	memset(cache, -1, sizeof(cache));
	cout << LCS2(0, 0) << endl;
	show(0, 0);
}