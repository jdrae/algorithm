#include <iostream>
using namespace std;
int r, c, ans = 0; 
char arr[20][20];
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};
bool alp[26];

void dfs(int y, int x, int cnt){
    if(ans < cnt) ans = cnt;
    alp[arr[y][x] - 'A'] = true;
    for(int i = 0; i<4; i++){
        int ny = y +dy[i]; int nx = x + dx[i];
        if(ny < 0 || ny >= r || nx < 0 || nx>=c) continue;
        if(!alp[arr[ny][nx] - 'A']){
            dfs(ny,nx,cnt+1);
            alp[arr[ny][nx] - 'A'] = false;
        }
    }
}

int main(){
    cin >> r >> c;
    for(int i = 0; i<r; i++){
        cin >> arr[i];
    }
    dfs(0,0, 1);
    cout << ans << endl;
}