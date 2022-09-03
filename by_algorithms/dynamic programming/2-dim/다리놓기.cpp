#include <iostream>
using namespace std;

int main(){
    int arr[30][30] = {0};
    for(int i = 1; i<=30; i++){
        for(int j = i; j<=30; j++){
            if(i==1) arr[i][j] = j;
            else if(i==j) arr[i][j] = 1;
            else{
                for(int k = 1; k<j; k++)
                    arr[i][j] += arr[i-1][k];
            }
        }
    }
    int tc; scanf("%d",&tc);
    while(tc--){
        int n, m; scanf("%d %d",&n,&m);
        printf("%d\n", arr[n][m]);
    }
}
