#include <vector>
#include <cstring>
#include <stack>
#include <iostream>
using namespace std;

struct Car {
    int y;
    int x;
    int dir; // 이전 위치에서의 방향 0: 오른쪽 1: 아래
};

int dy[2] = { 0,1 };
int dx[2] = { 1,0 };

int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;

    // dfs
    stack<Car> st;
    st.push({ 0,0,0 });
    while (!st.empty()) {
        int cy = st.top().y, cx = st.top().x, cd = st.top().dir; st.pop();
        if (cy == m - 1 && cx == n - 1) {
            answer++;
            continue;
        }
        for (int d = 0; d < 2; d++) {
            if (city_map[cy][cx] == 2 && d != cd) continue;
            int ny = cy + dy[d], nx = cx + dx[d];
            if (0 <= ny && ny < m && 0 <= nx && nx < n && city_map[ny][nx] != 1) {
                st.push({ ny,nx,d });
            }
        }
        if (answer > MOD) answer %= MOD;
    }

    return answer;
}

int main() {
    cout << solution(3, 6, { {0, 2, 0, 0, 0, 2}, {0, 0, 2, 0, 1, 0}, {1, 0, 0, 2, 2, 0} }) << endl; // 2
}