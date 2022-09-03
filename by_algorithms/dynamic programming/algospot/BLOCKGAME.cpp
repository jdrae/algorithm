#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#include <vector>

inline int cell(int y, int x) { return 1 << (y * 5 + x); }

vector<int> moves;
void precalc() { //모든 경우의 수 계산
    // 세 칸 블록
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            vector<int> squareCell;
            for (int dy = 0; dy < 2; dy++)
                for (int dx = 0; dx < 2; dx++)
                    squareCell.push_back(cell(y + dy, x + dx));
            // 4칸 사각형을 만들고, 한 칸씩 돌아가면서 빼면 L 자 블록
            int square = squareCell[0] + squareCell[1] + squareCell[2] + squareCell[3];
            for (int i = 0; i < 4; i++)
                moves.push_back(square - squareCell[i]);
        }
    }

    // 두 칸 블록
    for(int i = 0; i < 5; i++)
        for (int j = 0; j < 4; j++) {
            moves.push_back(cell(i, j) + cell(i, j + 1));
            moves.push_back(cell(j, i) + cell(j + 1, i));
        }
}

char cache[1 << 25];
char play(int board) {
    char& ret = cache[board];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i < moves.size(); i++) {
        if ((moves[i] & board) == 0) // 블록을 놓을 수 있음
            if (!play(board | moves[i])) { // 다음차례가 짐(0) == 현재차례에서 지지 않음
                ret = 1;
                break;
            }
    }
    return ret;
}

int board;
int main(void)
{
    precalc();
    int C; cin >> C;
    while(C--){
        board = 0;
        memset(cache, -1, sizeof(cache));

        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++) {
                char tmp; cin >> tmp;
                if (tmp == '#') {
                    board = board | cell(i, j);
                }
            }

        if (play(board)) cout << "WINNING" << endl;
        else cout << "LOSING" << endl;
    }
}
