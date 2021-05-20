#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
    int n, m;
    int* arr;

    cin >> n >> m;
    arr = new int[n]();
    for(int i = 0; i<n; i++)
        cin >> arr[i];

    int lo = 0, hi = 1000000000;
    while (lo+1 < hi){
        int mid = (lo+hi) / 2;
        long long sum = 0;
        for(int i = 0; i<n; i++){
            if(arr[i] > mid) sum += arr[i] - mid;
        }
        if(sum >= m) lo = mid;
        else hi = mid;
    }
    printf("%d\n", lo);

    delete[] arr;
}