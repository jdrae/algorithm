#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 15;
int k;
string word[MAX];
int cache[MAX][1 << MAX], overlap[MAX][MAX];

void rmRepetition(){
	while (true) {
		bool removed = false;
		for (int i = 0; i < k && !removed; i++) { 
			for (int j = 0; j < k; j++) {
				if (i == j) continue;
				if (word[i].find(word[j]) != -1) {
					word[j] = word[k - 1]; 
					--k;
					removed = true;
				}
			}
		}
		if (!removed) break; //종료 안될경우?
	}
	word[k] = "";
}

void setOverlap() {
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			if (i == j) continue;
			string a = word[i];
			string b = word[j];

			for (int l = min(a.size(), b.size()); l > 0; l--) {
				if (a.substr(a.size() - l) == b.substr(0, l))
					overlap[i][j] = max(overlap[i][j], l);
			}

		}
	}
}

int restore(int last, int used) {
	if (used == (1 << k) - 1) return 0;
	int& ret = cache[last][used];
	if (ret != -1) return ret;
	ret = 0;
	for (int next = 0; next < k; next++) {
		if ((used & (1 << next)) == 0) {
			int cand = overlap[last][next] +
						restore(next, used + (1 << next));
			ret = max(ret, cand);
		}
	}
	return ret;
}

string reconstruct(int last, int used) {
	if (used == (1 << k) - 1) return "";
	for (int next = 0; next < k; next++) {
		if (used & (1 << next)) continue;
		int ifUsed = restore(next, used + (1 << next))
					+ overlap[last][next];
		if (restore(last, used) == ifUsed)
			return (word[next].substr(overlap[last][next]) +
				reconstruct(next, used + (1 << next)));
	}
	return "***oops***";
}



int main() {
	int C; cin >> C;
	while (C--) {
		cin >> k;
		for (int i = 0; i < k; i++)
			cin >> word[i];
		memset(cache, -1, sizeof(cache));
		memset(overlap, 0, sizeof(overlap));
		rmRepetition();
		setOverlap();

		cout << reconstruct(k, 0) << endl;
	}
}