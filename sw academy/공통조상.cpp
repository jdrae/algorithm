#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void make_tree(int, int, int);
int lca(int, int);
int count(int);

// init
const int MAX = 10001;
const int MAXLV = (int)floor(log2(MAX));
int v, e, a, b;
vector<int> adj[MAX];
int parent[MAX][15];
int level[MAX];

int main(int argc, char** argv)
{
	cin.tie(NULL); ios::sync_with_stdio(false);

	// freopen("input.txt", "r", stdin);

	int test_case;
	int T; cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		// init
		for (int i = 0; i < MAX; i++)
			adj[i].clear();

		// input
		cin >> v >> e >> a >> b;
		int u, v;
		for (int i = 0; i < e; i++) {
			cin >> u >> v;
			adj[u].push_back(v);
			//adj[v].push_back(u);
		}

		// solution - LCA, Lowest Common Ancestor
		make_tree(1, 0, 1);
		int common = lca(a, b);
		int size = count(common);

		// output
		printf("#%d %d %d\n", test_case, common, size);

	}
	return 0;
}

void make_tree(int node, int pnode, int lv) {
	level[node] = lv;
	parent[node][0] = pnode;
	
	// curr 의 i 번째 부모: curr 의 i-1번째 부모의 i-1 번째 부모
	for (int i = 1; i <= MAXLV; i++) {
		parent[node][i] = parent[ parent[node][i - 1] ][i - 1];
	}

	for (int i = 0; i < adj[node].size(); i++) {
		int child = adj[node][i];
		if (child == pnode) continue;
		make_tree(child, node, lv + 1);
	}
}

int lca(int a, int b) {
	if (a == 1 || b == 1) return 1;

	int target = a, compare = b; 
	if (level[a] < level[b]) swap(target, compare);

	// target 의 레벨을 compare 의 레벨까지 높임
	if (level[target] != level[compare]) {
		for (int i = MAXLV; i >= 0; i--) {
			// target i 번째 부모가 compare 보다 레벨이 높거나 같다면
			// 해당 노드로 target 을 변경
			if (level[parent[target][i]] >= level[compare])
				target = parent[target][i];
		}
	}

	// 공통 조상 탐색
	int ret = target;

	if (target != compare) {
		for (int i = MAXLV; i >= 0; i--) {
			if (parent[target][i] != parent[compare][i]) {
				target = parent[target][i];
				compare = parent[compare][i];
			}
			ret = parent[target][i];
		}
	}

	return ret;
}

int count(int node) {
	int ret = 0;
	queue<int> q;
	bool visited[MAX] = { 0, };
	q.push(node);
	visited[node] = 1;
	while (!q.empty()) {
		int curr = q.front(); q.pop();
		ret++;
		for (int nxt : adj[curr]) {
			if (visited[nxt]) continue;
			q.push(nxt);
			visited[nxt] = 1;
		}
	}
	
	return ret;
}