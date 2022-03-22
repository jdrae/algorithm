/*
어려워보이는 문제일 수록, 규칙이 쉽다.
시간에 따라 변화하는 모습을 손으로 작성하고, 패턴을 파악할것.
*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int dy[] = {0,-1,0,1};
    int dx[] = {1,0,-1,0};
    int arr[101][101] = {0,};
    vector<int> curve;

    int n; scanf("%d",&n);
    int x,y,d,g;
    for(int _ = 0; _<n; _++){
        scanf("%d %d %d %d", &x,&y,&d,&g);
        curve.clear();

        arr[y][x] = 1;
        curve.push_back(d);
        y += dy[d]; x += dx[d];
        arr[y][x] = 1;

        for(int j = 0; j<g; j++){
            int curve_size = curve.size();
            for(int k = curve_size - 1; k >= 0; k--){
                int nd = (curve[k] + 1) % 4;
                curve.push_back(nd);
                y += dy[nd]; x += dx[nd];
                arr[y][x] = 1;
            }
        }
    }

    int cnt = 0;
    for(int i =  0 ; i<100; i++){
        for (int j = 0; j<100; j++){
            if(arr[i][j] && arr[i+1][j] && arr[i][j+1] && arr[i+1][j+1]) cnt++;
        }
    }
    printf("%d\n",cnt);
}
