#include <iostream>
#include <cstring>
using namespace std;

int coin[] = {500,100,50,10,5,1};

int main(){
    int n; cin >> n; n = 1000 - n;
    int cnt = 0;
    
    for(int i = 0; i<6; i++){
        if(n >= coin[i]){
            cnt += n / coin[i];
            n = n % coin[i];
        }
    }
    cout << cnt;
}