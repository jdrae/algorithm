#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#include <vector>
vector<string> board;
int cache[19683]; //3^9

bool isFinished(const vector<string>& board, char turn) {
	int ldia = 0; int rdia = 0;

	for (int i = 0; i < 3; i++) {
		int hor = 0; int ver = 0; 
		
		if (board[i][i] == turn) ldia++;
		if (board[i][2 - i] == turn) rdia++;

		for (int j = 0; j < 3; j++) {
			if (board[i][j] == turn) hor++;
			if (board[j][i] == turn) ver++;

			if (hor == 3 || ver == 3) return true;
		}
	}
	if (ldia == 3 || rdia == 3) return true;
	return false;
}

int bijection(const vector<string>& board) {
	int ret = 0;
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			ret = ret * 3;
			if (board[y][x] == 'o') ret += 1;
			else if (board[y][x] == 'x') ret +=2;
		}
	}
	return ret;
}

int canWin(vector<string>& board, char turn) {
	if (isFinished(board, 'o' + 'x' - turn)) return 0;

	int& ret = cache[bijection(board)];
	if (ret != -1) return ret;

	int minValue = 3;
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			if (board[y][x] == '.') {
				board[y][x] = turn;
				minValue = min(minValue, canWin(board, 'o' + 'x' - turn));
				board[y][x] = '.';
			}
		}
	}
	
	// return ret = 2 - minValue;
	if (minValue == 0) return ret = 2; // 상대가 지면(0) 내가 이김(2)
	else if (minValue == 2) return ret = 0; // 상대가 이기면(2) 내가 짐(0)
	else return ret = 1;
}

int main() {
	int C;  cin >> C;
	while (C--) {
		int cnt = 0;
		board.clear();
		memset(cache, -1, sizeof(cache));
		
		for (int i = 0; i < 3; i++) {
			string tmp; cin >> tmp;
			board.push_back(tmp);
			for (int j = 0; j < 3; j++)
				if (tmp[j] != '.') cnt++;
		}
		
		char start;
		cnt % 2 ? start = 'o' : start = 'x'; //문제조건: x부터 시작
		switch (canWin(board, start)) {
		case 0:
			cout << 'x' + 'o' - start << endl;
			break;
		case 1:
			cout << "TIE" << endl;
			break;
		case 2:
			cout << start << endl;
			break;
		}
	}
}