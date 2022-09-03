#include <iostream>
#include <queue>
using namespace std;
#define MAX 1000
int arr[MAX][MAX];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int main(){
    int n, m, k; cin >> n>> m >> k;
    for (int i = 0; i < n; i++) {
        for(int j = 0; j<m; j++){
            scanf("%1d",&arr[i][j]);
        }
    }

    int ans = -1;
    int cache[MAX][MAX][11] = {0}; // tip: bool 대신 int 로 최단 경로 세기
    queue<pair<pair<int,int>, int>> q;

    q.push({{0,0}, k});
    cache[0][0][k] = 1;
    while(!q.empty()){
        int canBreak = q.front().second;
        int cy = q.front().first.first; int cx = q.front().first.second;
        q.pop();

        if(cy == n-1 && cx == m-1){
            ans = cache[cy][cx][canBreak];
            break;
        }

        for(int d = 0; d<4; d++){
            int ny = cy + dy[d]; int nx = cx + dx[d];
            if(ny<0||ny>=n||nx<0||nx>=m) continue;
            if(arr[ny][nx] == 0 && cache[ny][nx][canBreak] == 0){
                cache[ny][nx][canBreak] = cache[cy][cx][canBreak] + 1;
                q.push({{ny,nx}, canBreak});
            }
            else if(arr[ny][nx] == 1 && cache[ny][nx][canBreak-1] == 0 && canBreak > 0){
                cache[ny][nx][canBreak-1] = cache[cy][cx][canBreak] + 1;
                q.push({{ny,nx}, canBreak-1});
            }
        }
    }

    printf("%d\n",ans);
}