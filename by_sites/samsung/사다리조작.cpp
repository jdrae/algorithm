#include <iostream>
#include <vector>
using namespace std;
int n, h, m;
int ans = 4;
int arr[31][31] = {0,};

vector<pair<int,int>> cand;

int dy[3] = {1,0,0}; // 하우좌
int dx[3] = {0,1,-1};

bool check(){
    for(int org_x = 0; org_x<m; org_x++){
        int x = org_x, y = 0;
        int prev_x=-1, prev_y=-1;
        while(y < n){
            int d = arr[y][x];
            int ny = y + dy[d]; int nx = x+dx[d];
            if(d != 0 && (ny==prev_y && nx == prev_x)){
                ny = y+dy[0]; nx = x + dx[0];
            }
            prev_y = y, prev_x = x;
            y = ny; x = nx;
        }
        if(org_x != x) return false;
    }
    return true;
}

void dfs(int idx, int cnt){
    if(cnt >= ans){
        return;
    }
    if(cnt < ans && check()){
        ans = cnt;
        return;
    }
    // 1-2-3 과 1-3-2
    // 즉, 같은 숫자의 다른 경로가 중복되지 않도록 할때 자신보다 높은 인덱스만 탐색해도록 함.
    for(int i = idx+1; i<cand.size(); i++){ 
        int y = cand[i].first, x = cand[i].second;
        if(arr[y][x] != 0 || arr[y][x+1] != 0) continue;
        arr[y][x] = 1; arr[y][x+1] = 2;
        dfs(i,cnt+1);
        arr[y][x] = 0; arr[y][x+1] = 0;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> m >> h >> n;
    int a, b;
    for(int i = 0; i<h; i++){
        cin >> a >> b; a--; b--;
        arr[a][b] = 1;
        arr[a][b+1] = 2;
    }

    // 넣을 수 있는 사다리
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m-1; j++){
            if(arr[i][j] == 0 && arr[i][j+1] == 0){
                cand.push_back({i,j});
            }
        }
    }
    // 초기화 -1 로 0~끝까지 각각하나만 넣은 경우 탐색 
    dfs(-1,0);
    if(ans > 3) ans = -1;
    cout << ans << endl;
}   
