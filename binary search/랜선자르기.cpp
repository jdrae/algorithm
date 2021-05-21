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

    long long lo = 0;
    long long hi = (long long)mx + 1;
    while(lo + 1< hi){
        long long mid = (lo+hi) / 2;
        int cnt = 0;
        for(int i = 0; i<n; i++){
            cnt += arr[i] / mid;
        }
        if(cnt < m)
            hi = mid;
        else
            lo = mid;
    }
    printf("%lld\n",lo);
}