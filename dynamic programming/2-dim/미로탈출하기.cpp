#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n, m;
vector<string> arr;
int dp[500][500], visited[500][500];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int func(int y, int x){
    if(y < 0 || x < 0 || y>=n || x>=m) return 1;
    int& ret = dp[y][x];
    if(ret != -1) return ret; // 방문 안했는데 결과가 있을 순 없음. -1 이 아니면 무조건 방문해서 값 저장된것.
    if(visited[y][x]) return ret = 0; // 결과가 없는데 방문한 곳을 또 방문함. loop.

    visited[y][x] = 1;
    char c = arr[y][x];

    int d;
    if(c=='U') d = 0;
    else if(c=='D') d = 1;
    else if(c=='L') d = 2;
    else if(c=='R') d = 3;

    ret = func(y+dy[d], x+dx[d]);
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
    memset(visited, 0, sizeof(visited));

    int cnt = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cnt += func(i,j);
        }
    }
    cout << cnt << endl;
}   