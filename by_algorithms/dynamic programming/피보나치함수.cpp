#include <iostream>
using namespace std;
const int MAX = 100;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int tc; cin >>tc;
    int arr0[41] = {0};
    int arr1[41] = {0};
    arr0[0] = arr1[1] = 1;
    for(int i = 2; i<=40; i++){
        arr0[i] = arr0[i-1] + arr0[i-2];
        arr1[i] = arr1[i-1] + arr1[i-2];
    }
    while(tc--){
        int n; cin >> n;
        printf("%d %d\n", arr0[n], arr1[n]);
    }
}
