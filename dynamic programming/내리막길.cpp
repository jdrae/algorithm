#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 1000000001

int m, n, arr[500][500], cache[500][500];

int func(int i, int j){
    if(i==m-1 && j==n-1) return 1;
    int& ret = cache[i][j];
    if(ret != -1) return ret;

    ret = 0;
    if(i+1 < m && arr[i+1][j] < arr[i][j]) ret += func(i+1, j);
    if(i-1 > -1 && arr[i-1][j] < arr[i][j]) ret += func(i-1, j);
    if(j+1 < n && arr[i][j+1] < arr[i][j]) ret += func(i, j+1);
    if(j-1 > -1 && arr[i][j-1] < arr[i][j]) ret += func(i, j-1);
    return ret;
}

int main(){
    cin >> m >> n;
    for(int i = 0 ; i < m; i++){
        for(int j = 0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    memset(cache, -1, sizeof(cache));
    cout << func(0,0) << endl;
}