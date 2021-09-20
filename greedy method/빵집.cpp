#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int MAX = 10000;
int n, m;
int visited[MAX][500];
string arr[MAX];
pair<int,int> dir[3] = {{-1,1},{0,1},{1,1}};

int dfs(int y, int x){
    visited[y][x] = true;
    if(x == m-1) return true;
    for(int d = 0; d<3; d++){
        int ny = y+dir[d].first, nx = x+dir[d].second;
        if(0<=ny&&ny<n&&0<=nx&&nx<m){
            if(!visited[ny][nx] && arr[ny][nx] == '.'){
                if(dfs(ny,nx)) return true;
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    // tip: char arr 입력
    for(int i = 0; i<n; i++)
        cin >> arr[i];

    int res = 0;
    for(int i = 0; i<n; i++)
        res += dfs(i,0);

    printf("%d\n",res);
}
