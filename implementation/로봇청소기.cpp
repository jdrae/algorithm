#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, r, c, d, arr[50][50];
int visited[50][50] = {0, };
int x[4] = {0,1,0,-1};
int y[4] = {-1,0,1,0};

bool check(int r, int c){
    if(r>=n || c >=m || r<0 || c < 0) return false;
    if(arr[r][c]) return false;
    return true;
}

int func(int r, int c, int d){
    int ans = 0;
    if(!visited[r][c]){
        ans++;
        visited[r][c] = 1;
    }
    int goBack = true;
    for(int i = 0; i < 4; i++){
        d = (d + 3) % 4;
        int ny = r+y[d], nx = c+x[d];
        if(check(ny,nx) && !visited[ny][nx]){
            ans += func(ny,nx,d);
            goBack = false;
            break;
        }
    }
    if(goBack){
        int bd = (d+2) %4;
        int ny = r+y[bd], nx = c+x[bd];
        // printf("%d\t now: %d,%d\tto: %d, %d\n",d,r,c,ny,nx);
        if(check(ny,nx)) ans += func(ny,nx, d);
    }
    return ans;
}

int main(){
    cin >> n >> m;
    cin >> r >> c >> d;
    for(int i =0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    cout << func(r,c,d) << endl;
}