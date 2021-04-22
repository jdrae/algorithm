#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n, tmp; cin >> n;
    int mx[2][3], mn[2][3]; // 1은 현재, 0은 이전
    memset(mx, 0, sizeof(mx));
    memset(mn, 0, sizeof(mn));
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin >> tmp;
            mx[1][j] = tmp + mx[0][j];
            mn[1][j] = tmp + mn[0][j];
            if(j-1 >= 0){
                mx[1][j] = max(mx[1][j], tmp + mx[0][j-1]);
                mn[1][j] = min(mn[1][j], tmp + mn[0][j-1]);
            }
            if(j+1 < 3){
                mx[1][j] = max(mx[1][j], tmp + mx[0][j+1]);
                mn[1][j] = min(mn[1][j], tmp + mn[0][j+1]);
            }
        }
        memcpy(mx[0], mx[1], sizeof(int)*3);
        memcpy(mn[0], mn[1], sizeof(int)*3);
    }
    sort(mx[1], mx[1]+3);
    sort(mn[1], mn[1]+3);
    printf("%d %d\n", mx[1][2], mn[1][0]);
}   