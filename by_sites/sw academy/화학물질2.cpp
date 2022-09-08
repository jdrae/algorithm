#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <queue>
#include <deque>
#include <climits>

using namespace std;

typedef pair<int, int> Matrix; // row, col
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int n;
int arr[100][100];

Matrix find_matrix(int y, int x) {
	int y1, x1, y2, x2;
	y1 = x1 = n; y2 = x2 = -1;

	queue<pair<int, int>> q;
	q.push({ y,x });
	arr[y][x] = 0;

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		y1 = min(y1, cy); x1 = min(x1, cx);
		y2 = max(y2, cy); x2 = max(x2, cx);

		for (int d = 0; d < 4; d++) {
			int ny = cy + dy[d]; int nx = cx + dx[d];
			if (!(0 <= ny && ny < n && 0 <= nx && nx < n) || arr[ny][nx] == 0) continue;
			q.push({ ny,nx });
			arr[ny][nx] = 0;
		}
	}

	return { y2 - y1 + 1, x2 - x1 + 1 };
}

// 가능한 순서 1개
deque<Matrix> order_matrix(const vector<Matrix>& vec){
	deque<Matrix> dq;
	bool visited[20] = { 0, };
	int s = vec[0].first; int e = vec[0].second;
	dq.push_back(vec[0]);
	for (int i = 1; i < vec.size(); i++) {
		for (int j = 1; j < vec.size(); j++) {
			if (visited[j]) continue;
			if (vec[j].first == e) {
				dq.push_back(vec[j]);
				visited[j] = true;
				e = vec[j].second;
			}
			else if (vec[j].second == s) {
				dq.push_front(vec[j]);
				visited[j] = true;
				s = vec[j].first;
			}
		}
		if (dq.size() == vec.size()) break;
	}
	return dq;
}

int calculate(const deque<Matrix>& mat) {
	// dp[i][j]: i 번째 행렬부터 j 번째 행렬까지 최소 연산 횟수
	// k 번째에서 괄호로 좌우가 나뉜다고 했을 때 dp[i][j] 의 최소값은
	// dp[i][k] + dp[k+1][j] + ( mat[i].row * mat[k].col * mat[j].col ) 과 비교.
	int len = mat.size();

	int dp[20][20] = {0, };
	for (int a = 0; a < len; a++) { 
		for (int b = 0; b < len - a; b++) {
			int i = b; int j = b + a;
			if (i == j) {
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = INT_MAX;
			for (int k = i; k < j; k++) {
				dp[i][j] = min(dp[i][j],
					dp[i][k] + dp[k + 1][j] + (mat[i].first * mat[k].second * mat[j].second));
			}
		}
	}
	return dp[0][len - 1];
}

int main(int argc, char** argv)
{
	cin.tie(NULL); ios::sync_with_stdio(false);

	//freopen("input.txt", "r", stdin);

	int test_case;
	int T; cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> arr[i][j];

		vector<Matrix> vec;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (arr[i][j] != 0)
					vec.push_back(find_matrix(i, j));

		deque<Matrix> mat = order_matrix(vec);

		int answer = calculate(mat);
		printf("#%d %d\n", test_case, answer);
	}
	return 0;
}