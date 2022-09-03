#include <vector>
#include <stack>
#include <iostream>
#include <cstring>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    // dfs
    int visited[100][100];
    memset(visited, 0, sizeof(visited));
    stack<pair<int, int>> st;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] != 0 && visited[i][j] == 0) {
                st.push({ i,j });
                visited[i][j] = 1;
                number_of_area++;
            }
            int size = 0;
            int group = picture[i][j];
            while (!st.empty()) {
                int cy = st.top().first, cx = st.top().second; st.pop();
                size ++;
                printf("%d %d size: %d\n", cy, cx, size);
                for (int d = 0; d < 4; d++) {
                    int ny = cy + dy[d], nx = cx + dx[d];
                    if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
                    if (picture[ny][nx] == group && visited[ny][nx] == 0) {
                        visited[ny][nx] = 1;
                        st.push({ ny,nx });
                    }
                }
            }
            if (size > max_size_of_one_area) max_size_of_one_area = size;
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main() {
    // tip: 벡터 파라미터 입력하기
    vector<int> answer = solution(6, 4, { {1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3} });
    cout << answer[0] << " " << answer[1];
}