#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;


int main(int argc, char** argv)
{
	cin.tie(nullptr)->sync_with_stdio(false);

	// freopen("input.txt", "r", stdin);

	int test_case;
	int T; cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		// input
		int n, m; cin >> n >> m;
		int cost[101], weight[10001];
		for (int i = 1; i <= n; i++) {
			cin >> cost[i];
		}
		for (int i = 1; i <= m; i++) {
			cin >> weight[i];
		}

		// solution
		priority_queue<int, vector<int>, greater<int>> place;
		for (int i = 1; i <= n; i++) {
			place.push(i);
		}
		queue<int> wait;
		int parked[10001] = {0,};

		int answer = 0;
		for (int i = 0; i < 2 * m; i++) {
			int x; cin >> x;
			if (x > 0) // in
				wait.push(x);
			else if (x < 0) // out
				place.push(parked[-x]);

			while (!wait.empty() && !place.empty()) {
				int cid = wait.front(); wait.pop();
				int pid = place.top(); place.pop();
				parked[cid] = pid;
				answer += weight[cid] * cost[pid];
			}
		}

		// output
		printf("#%d %d\n", test_case, answer);
	}
	return 0;
}