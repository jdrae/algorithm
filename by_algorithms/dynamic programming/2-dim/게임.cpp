#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int INF = 1000000000;
int n, m;
vector<string> arr;
int dp[50][50], visited[50][50];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int func(int y, int x){
    if(y<0 || x<0 || y>=n || x>=m) return 0;
    if(arr[y][x] == 'H') return 0;

    // 한 경로 내에서 똑같은 곳 방문 했을 경우 ret 상관없이 INF(사이클)
    if(visited[y][x]) return INF; 
    int& ret = dp[y][x];
    // 한 경로 내에서 for 처리는 아직 안했지만(visited 아님)
    // 다른 경로를 구할 때 해당 좌표의 최댓값은 구해져있는 경우(메모이제이션)
    if(ret != -1) return ret; 

    visited[y][x] = 1; 

    int num = arr[y][x] - '0';
    for(int d = 0; d<4;d++){
        int ny = y + dy[d]*num; int nx = x + dx[d]*num;
        ret = max(ret, 1 + func(ny,nx));
        if(ret >= INF) break;
    }
    // 같은 곳을 두번 방문하더라도 경로가 다를 수 있기 때문에 방문여부 지워줌
    visited[y][x] = 0; 
    return ret;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        string s; cin >> s;
        arr.push_back(s);
    }

    memset(dp, -1, sizeof(dp));

    int ans = func(0,0);
    if(ans >= INF) ans = -1;
    cout << ans << endl;
}   

/*
4 3
133
5HH
HHH
21H

답: 5
*/