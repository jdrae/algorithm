#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<ll, pair<int, int>> P;

struct compare {
	bool operator()(P a, P b) {
		return a.first > b.first;
	}
};

ll xarr[1000];
ll yarr[1000];

int uf[1000];
int find(int a) {
	if (uf[a] < 0) return a;
	return uf[a] = find(uf[a]);
}

int merge(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return false;
	uf[b] = a;
	return true;
}


int main(int argc, char** argv)
{
	cin.tie(NULL); ios::sync_with_stdio(false);

	// freopen("sample_input.txt", "r", stdin);

	int test_case;
	int T; cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		// init
		fill(uf, uf + 1000, -1);
		priority_queue<P, vector<P>, compare> pq;

		// input
		int n; cin >> n;
		for (int i = 0; i < n; i++)
			cin >> xarr[i];
		for (int i = 0; i < n; i++)
			cin >> yarr[i];
		double e; cin >> e;
		
		// solution - MST
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				ll dist = pow(xarr[i] - xarr[j], 2) + pow(yarr[i] - yarr[j], 2);
				pq.push({ dist, {i,j} });
			}
		}

		ll answer = 0; int cnt = 0;
		while (!pq.empty()) {
			int a = pq.top().second.first; int b = pq.top().second.second;
			if (merge(a, b)) {
				answer += pq.top().first;
				if (cnt++ == n - 1) break;
			}
			pq.pop();
		}

		// output
		printf("#%d %.f\n", test_case, round(answer * e));
	}

	return 0;
}