#include <cstdio>
#include <iostream>
#include <unordered_map>

using namespace std;

// initial
unordered_map<string, int> dict = {
	{"0001101",0},
	{"0011001",1},
	{"0010011",2},
	{"0111101",3},
	{"0100011",4},
	{"0110001",5},
	{"0101111",6},
	{"0111011",7},
	{"0110111",8},
	{"0001011",9}
};


int main(int argc, char** argv)
{
	int test_case;
	int T;

	// freopen("sample_input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int answer = 0;

		// input
		int n, m; cin >> n >> m;
		string arr[50];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		// code start position
		bool fail = false;
		bool flag = false;
		int y1 = 0, x1 = 0, y2 = n - 1, x2 = m - 1;
		;		for (int i = n - 1; i >= 0; i--) {
			for (int j = m - 1; j >= 0; j--) {
				if (arr[i][j] == '1') {
					flag = true;
					y2 = i; x2 = j;
					x1 = j - 56 + 1;
					if (x1 < 0) fail = true;
					break;
				}
			}
			if (flag) break;
		}

		if (fail) {
			printf("#%d %d\n", test_case, answer);
			continue;
		}


		// check last 1 line
		string baseline = arr[y2].substr(x1, 56);
		char code[8];
		int pos = 0;
		for (int num = 0; num < 8; num++) {
			string tmp = baseline.substr(pos, pos + 7);
			auto item = dict.find(tmp);
			if (item != dict.end()) {
				code[num] = item->second;
			}
			else {
				fail = true;
				break;
			}
		}

		if (fail) {
			printf("#%d %d\n", test_case, answer);
			continue;
		}


		// check all line
		string zero = string(56, '0');
		for (int i = y2; i >= 0; i--) {
			string tmp = arr[i].substr(x1, 56);
			if (tmp.compare(zero) == 0) {
				break;
			}
			if (tmp.compare(baseline) != 0) {
				fail = true;
				break;
			}
		}

		if (fail) {
			printf("#%d %d\n", test_case, answer);
			continue;
		}

		// decode
		int plain[8];
		pos = 0;
		for (int num = 0; num < 8; num++) {
			string bit = baseline.substr(pos, 7);
			if (dict.find(bit) == dict.end()) {
				fail = true;
				break;
			}
			else {
				plain[num] = dict[bit];
			}
			pos += 7;
		}

		if (fail) {
			printf("#%d %d\n", test_case, answer);
			continue;
		}

		// calculate answer
		int odd = 0, even = 0;
		for (int i = 0; i < 8; i++) {
			if ((i+1) % 2) {
				odd += plain[i];
			}
			else {
				even += plain[i];
			}
		}

		if ((odd * 3 + even) % 10 == 0) {
			answer = odd + even;
		}

		printf("#%d %d\n", test_case, answer);
	}
	return 0;
}