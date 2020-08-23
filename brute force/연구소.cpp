#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;


pair<int,int> moveDir[4] = { {0,1}, {0,-1}, {1,0},{-1,0} };

int N, M;
int lab[8][8];
int temp[8][8];
int result;

void copyLab(int (*a)[8], int (*b)[8]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0;j < M; j++) {
			a[i][j] = b[i][j];
		}
	}
}

void countSafe() {
	int safe = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (temp[i][j] == 0)
				safe++;
	result = max(result, safe);
}

void virusBFS() {
	copyLab(temp, lab);

	queue<pair<int,int>> q;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (temp[i][j] == 2)
				q.push(make_pair(i, j));

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nY = y + moveDir[i].first;
			int nX = x + moveDir[i].second;
			if (0 <= nY && nY < N && 0 <= nX && nX < M) {
				if (temp[nY][nX] == 0) {
					temp[nY][nX] = 2;
					q.push(make_pair(nY, nX));
				}
			}
		}
	}
	countSafe();
}

void wall(int cnt) {
	if (cnt == 3) {
		virusBFS();
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (lab[i][j] == 0) {
				lab[i] [j] = 1;
				wall(cnt + 1);
				lab[i][j] = 0;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> lab[i][j];

	wall(0);
	cout << result << endl;
}