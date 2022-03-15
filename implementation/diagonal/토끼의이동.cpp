/*
대각선 규칙 찾기 문제.
배열을 만들지 말고 공식으로 풀기.
long long 사용하기.

1 2 6 7 15 16 
3 5 8 14 17 26 
4 9 13 18 25 27 
10 12 19 24 28 33 
11 20 23 29 32 34 
21 22 30 31 35 36
*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
long long n;

long long func(int y, int x){
    // 몇번째 대각선에 있는지
    int t = y + x; long long s = t;
    // 시작 번호
    long long num = 1;
    if(s>0){
        if(s>n){ // n-1, n-2, ... n-i 까지의 합 -> n*(i) - (1+2+...i)
            long long i = s - n;
            num += (n*i) - i*(i+1)/2;
            s = n; // 나머지 n 이전은 아래에서
        }
        num += s*(s+1)/2; // 1부터 t까지의 합
    }
    // 해당 좌표까지 이동
    int a = (t%2) ? x : y;
    if(t<n){
        num += (t-a);
    }
    else{
        num += (n-1 - a);
    }
    return num;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int dy[4] = {-1,1,0,0};
    int dx[4] = {0,0,-1,1};

    int k; cin >> n >> k;
    string s; cin >> s;

    // make array
    // int num = 1;
    // for(int t = 0; t <= (n-1)*2; t++){ // 대각선의 번호
    //     for(int a = 0; a<n; a++){
    //         int b = t - a;
    //         if(b < 0 || b >= n) continue;
    //         if(t%2) arr[a][b] = num++;
    //         else arr[b][a] = num++;
    //     }
    // }

    // jump
    int y = 0, x = 0;
    long long sum = 0;
    for(int i = 0; i<=k; i++){
        sum += func(y,x);

        if(i == k) break;
        char dir = s[i];
        int d;
        if(dir =='U') d = 0;
        else if(dir == 'D') d = 1;
        else if(dir == 'L') d = 2;
        else if(dir == 'R') d = 3;

        y += dy[d]; x += dx[d];
    }

    cout << sum << endl;
}
