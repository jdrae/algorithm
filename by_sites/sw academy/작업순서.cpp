#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1001
int v, e;
vector<int> adj[MAX];
int indegree[MAX];

void init() {
	for (int i = 0; i < MAX; i++) {
		adj[i].clear();
		indegree[i] = 0;
	}
}

int main(int argc, char** argv)
{
	cin.tie(NULL); ios::sync_with_stdio(false);

	// freopen("input.txt", "r", stdin);


	for (int test_case = 1; test_case <= 10; ++test_case)
	{
		init();

		// input
		cin >> v >> e;
		int a, b;
		for (int i = 0; i < e; i++) {
			cin >> a >> b;
			adj[a].push_back(b);
			indegree[b]++;
		}

		// solution - topological sort
		queue<int> q;
		for (int i = 1; i <= v; i++) {
			if (indegree[i] == 0)
				q.push(i);
		}

		vector<int> result;
		while (!q.empty()) {
			int curr = q.front(); q.pop();
			result.push_back(curr);
			for (int nxt : adj[curr]) {
				if (--indegree[nxt] == 0) {
					q.push(nxt);
				}
			}
		}

		// output
		printf("#%d", test_case);
		for (int node : result)
			printf(" %d", node);
		printf("\n");
		
	}
	return 0;
}