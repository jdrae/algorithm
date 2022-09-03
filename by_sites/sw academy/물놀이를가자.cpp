#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <queue>

using namespace std;

char arr[1000][1000];
int visited[1000][1000];

int main(int argc, char** argv)
{
	int dy[4] = { -1,1,0,0 };
	int dx[4] = { 0,0,-1,1 };

	cin.tie(NULL); ios::sync_with_stdio(false);

	// freopen("input.txt", "r", stdin);

	int test_case;
	int T; cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		// settings
		int n, m;
		queue<pair<int, int>> q;
		for (int i = 0; i < 1000; i++) {
			for (int j = 0; j < 1000; j++) {
				visited[i][j] = -1;
			}
		}

		// input
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 'W') {
					q.push({ i,j });
					visited[i][j] = 0;
				}
			}
		}

		// solution - bfs from water
		int answer = 0;
		while (!q.empty()) {
			int cy = q.front().first; int cx = q.front().second;
			q.pop();

			for (int d = 0; d < 4; d++) {
				int ny = cy + dy[d]; int nx = cx + dx[d];
				if (!(0 <= ny && ny < n && 0 <= nx && nx < m)) continue;
				if (visited[ny][nx] != -1 || visited[ny][nx] == 'W') continue;

				q.push({ ny,nx });
				visited[ny][nx] = visited[cy][cx] + 1;

				answer += visited[ny][nx];
			}
		}

		// output
		printf("#%d %d\n", test_case, answer);

	}
	return 0;
}