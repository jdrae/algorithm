#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#include <vector>

int n, k, m, L[50], Q[10];
double T[50][50];

vector<double> func() {
    //c[time][song]: time분 후에 song 번 노래가 시작될 확률
    double cache[5][50]; // 한곡의 길이 최대 4분
    memset(cache, 0, sizeof(cache));
    cache[0][0] = 1.0;
    for (int time = 1; time <= k; time++) {
        for (int song = 0; song < n; song++) { 
            double& prob = cache[time % 5][song]; //슬라이딩 윈도. 마지막 값은 k 번후에 재생되는 노래의 확률들이 됨.
            prob = 0;
            for (int last = 0; last < n; last++) { //song 이전에 재생되는 모든 곡들
                prob += cache[(time - L[last] + 5) % 5][last] * T[last][song];
            }
        }
    }
    
    vector<double> ret(n);
    for (int song = 0; song < n; song++) {
        for (int start = k - L[song] + 1; start <= k; start++) {
            ret[song] += cache[start % 5][song];
        }
    }
    return ret;
}

int main(void)
{
    int C; cin >> C;
    while(C--){
        cin >> n >> k >> m;
        for (int i = 0; i < n; i++)
            cin >> L[i];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> T[i][j];
        for (int i = 0; i < m; i++)
            cin >> Q[i];

        vector<double> result = func();
        cout << "RES: ";
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
        cout << endl;
    }
}
