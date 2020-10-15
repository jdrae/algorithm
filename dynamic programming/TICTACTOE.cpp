#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#include <vector>

vector<string> board;
int cache[19683];

bool isFinished(const vector<string>& board, char turn){
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

int bijection(const vector<string>& board){
    int ret = 0;
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            ret = ret * 3;
            if (board[y][x] == 'o') ret += 1;
            else if (board[y][x] == 'x') ret += 2;
        }
    }
    return ret;
}

int canWin(vector<string>& board, char turn){
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

    if (minValue == 3 || minValue == 1)
        return ret = 1;

    return ret = 2 - minValue; //0이면 2. 2면 0.
}

int main(void)
{
    int C; cin >> C;

    while(C--){
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
        cnt % 2 ? start = 'o' : start = 'x';

        switch (canWin(board, start))
        {
        case 0:
            cout << (char)('x' + 'o' - start) << endl;
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
