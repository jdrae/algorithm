#include <vector>
#include <cstring>
#include <stack>
#include <iostream>
using namespace std;

// 0: 왼쪽에서 1: 위에서
int dy[2] = { 0,-1 };
int dx[2] = { -1,0 };

int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;

    long long cache[500][500][2];
    memset(cache, 0, sizeof(cache));
    cache[0][0][1] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue;
            if (city_map[i][j] == 1) continue; 
            for (int d = 0; d < 2; d++) {
                int py = i + dy[d], px = j + dx[d];
                if (0 > py || py >= m || 0 > px || px >= n) continue;
                cache[i][j][d] = (cache[i][j][d] + cache[py][px][d])%MOD;
                if (city_map[py][px] == 0)
                    cache[i][j][d] = (cache[i][j][d] + cache[py][px][(d+1)%2])%MOD;
            }
        }
    }
    answer = (cache[m - 1][n - 1][0] % MOD + cache[m - 1][n - 1][1] % MOD) % MOD;
    return answer;
}

int main() {
    cout << solution(3, 6, { {0, 2, 0, 0, 0, 2}, {0, 0, 2, 0, 1, 0}, {1, 0, 0, 2, 2, 0} }) << endl; // 2
}