#include <iostream>
using namespace std;

int n, s, arr[20];
int cnt, sum;

void dfs(int curr){
    if(curr == n) return;
    if(sum + arr[curr] == s) cnt++;

    dfs(curr+1);

    sum += arr[curr];
    dfs(curr+1);

    sum -= arr[curr];
}

int main(){
    cin >> n >> s;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    dfs(0);
    cout << cnt << endl;
}