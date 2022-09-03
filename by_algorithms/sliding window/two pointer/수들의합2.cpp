#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, arr[10000];

int main(){
    cin >> n >> m;
    for(int i = 0; i<n; i++)
        cin >> arr[i];

    int s = 0, e = 0, ans = 0;
    int sum = 0;
    while(s!=n+1 && e!=n+1){
        if(sum == m) ans++;
        if(sum < m){
            sum += arr[e]; e++;
        }
        else{
            sum -= arr[s]; s++;
        }
    }
    printf("%d\n", ans);
}