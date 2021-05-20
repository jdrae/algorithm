#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
    int n, m, arr[100000];
    cin >> n >> m;
    int mx = 0;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }

    int lo = mx, hi = 100000 * 10000;
    int mid = mx;
    while(lo + 1 < hi){
        mid = (lo+hi) / 2;
        int cnt = 1, sum = 0;
        for(int i = 0; i<n; i++){
            if(sum + arr[i] <= mid) sum += arr[i];
            else{
                cnt++; sum = arr[i];
            }
        }
        if(cnt > 3) lo = mid + 1;
        else hi = mid - 1;
    }
    printf("%d %d %d\n", lo, mid, hi);
}