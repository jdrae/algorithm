#include <iostream>
#include <algorithm> 
#include <cstring>
using namespace std;
#include <vector>

vector<int> slice(const vector<int>& v, int a, int b) {
	return vector<int>(v.begin() + a, v.begin() + b);
}

void printPostOrder(const vector<int>& pre, const vector<int>& in) {
	const int N = pre.size();
	if (pre.empty()) return;
	const int root = pre[0];
	const int L = find(in.begin(), in.end(), root) - in.begin();
	const int R = N - 1 - L;
	printPostOrder(slice(pre, 1, L + 1), slice(in, 0, L));
	printPostOrder(slice(pre, L + 1, N), slice(in, L + 1, N));
	cout << root << ' ';
}

int main() {
	int C; cin >> C;
	while (C--) {
		int n, tmp; cin >> n;
		vector<int> pre, in;
		for(int i = 0; i<n; i++) {
			cin >> tmp;
			pre.push_back(tmp);
		}
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			in.push_back(tmp);
		}
		printPostOrder(pre, in);
	}
}
