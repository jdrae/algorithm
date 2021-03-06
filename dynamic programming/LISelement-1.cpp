#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int cache[101], S[100], choices[101];

int lis4(int start) {
	int& ret = cache[start + 1];
	if (ret != -1) return ret;
	ret = 1;
	int bestNext = -1;
	for (int next = start + 1; next < n; next++) {
		if (start == -1 || S[start] < S[next]) {
			int cand = lis4(next) + 1;
			if (cand > ret) {
				ret = cand;
				bestNext = next;
			}
		}
	}
	choices[start + 1] = bestNext;
	return ret;
}

void reconstruct(int start, vector<int>& seq) {
	if (start != -1) seq.push_back(S[start]);
	int next = choices[start + 1];
	if (next != -1) reconstruct(next, seq);
}

int main() {
	int testCase; cin >> testCase;
	while (testCase--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> S[i];
		}
		memset(cache, -1, sizeof(cache));
		memset(choices, -1, sizeof(cache));
		
		int length = lis4(-1) - 1;
		vector<int> seq;
		reconstruct(-1, seq);
		printf("reconstruct: ");
		for (int i = 0; i < seq.size(); i++) {
			printf("%d ", seq[i]);
		}
		printf("\n");
		printf("choices: ");

		int i = 0;
		while(choices[i] != -1) {
			printf("%d ", choices[i]);
			i++;
		}
		printf("\n");
	}

}