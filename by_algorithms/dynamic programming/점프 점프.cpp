#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int INF = 100001;
int n;
int arr[1000];
int dp[1000]; // i 번째 칸부터 끝까지 도착하는 점프 개수의 최솟값


int func(int curr){
    if(curr == n-1) return 0;
    else if(curr >= n) return INF;

    int& ret = dp[curr];
    if(ret != -1) return ret;
    ret = INF;
    for(int i = 1; i<=arr[curr]; i++){
        ret = min(ret, 1 + func(curr+i));
    }
    return ret;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for(int i = 0; i<n; i++) cin >> arr[i];
    
    memset(dp, -1, sizeof(dp));
    int ans = func(0);
    if(ans >= INF) ans = -1;
    printf("%d\n", ans);
}   