#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
    int n, m, mx = 0;
    int arr[10000];

    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }
    cin >> m;

    int lo = 0, hi = mx;
    while(lo + 1 < hi){
        int mid = (lo + hi) / 2;
        long long sum = 0;
        for(int i = 0; i<n; i++){
            if(arr[i] > mid) sum += mid;
            else sum += arr[i];
        }
        if(sum <= m) lo = mid;
        else hi = mid;
    }
    
    if(hi == mx) lo = mx;
    printf("%d\n", lo);
}