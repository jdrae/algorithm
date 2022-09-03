#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 11;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int n,m;
int arr[MAX][MAX], visited[MAX][MAX], mn[MAX][MAX];
vector<pair<int,int>> coor[MAX];
priority_queue<pair<int,pair<int,int>>> pq;

void color(int y, int x, int num){
    visited[y][x] = 1;
    arr[y][x] = num;
    coor[num].push_back({y,x});
    for(int d= 0; d<4; d++){
        int ny = y+dy[d], nx = x+dx[d];
        if(ny<0||ny>=n||nx<0||nx>=m||arr[ny][nx]==0||visited[ny][nx]) continue;
        color(ny,nx, num);
    }
}

void dfs(int y, int x, int u, int w, int d){
    int v = arr[y][x];
    if(v != 0){ // 땅: 끝
        if(u != v && w > 1 && mn[u][v] > w){
            mn[u][v] = mn[v][u] = w;
            pq.push({-w, {u,v}});
        }
        return;
    }
    else{ // 바다: 계속 탐색
        int ny = y+dy[d], nx = x+dx[d];
        if(ny<0||ny>=n||nx<0||nx>=m) return;
        dfs(ny,nx,u,w+1,d);
    }
}

int uf[MAX];
int find(int a){
    if(uf[a]<0) return a;
    return uf[a] = find(uf[a]);
}
bool merge(int a, int b){
    a = find(a), b = find(b);
    if(a==b) return false;
    uf[b] = a;
    return true;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n>> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    // find nodes
    memset(visited, 0, sizeof(visited));
    int num = 1;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(arr[i][j] && visited[i][j] == 0) color(i,j,num++);
        }
    }
    // puts("");
    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<m; j++){
    //         printf("%d ", arr[i][j]);
    //     }
    //     puts("");
    // }

    // find edges
    memset(mn, 100, sizeof(mn));
    for(int i = 1; i<num; i++){
        for(auto& p: coor[i]){
            int y = p.first, x = p.second;
            for(int d= 0; d<4; d++){
                int ny = y+dy[d], nx = x+dx[d];
                if(ny<0||ny>=n||nx<0||nx>=m||arr[ny][nx]==1) continue;
                dfs(ny,nx,i,0,d);
            }
        }
    }

    // mst
    fill(uf, uf+MAX, -1);
    int mst = 0, cnt = 0;
    while(!pq.empty()){
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        int w = -pq.top().first;
        // printf("%d->%d: %d\n", u, v, w);
        if(merge(u, v)){
            // printf("->MERGED!\n");
            mst += w;
            if(++cnt == num-1)break;
        }
        pq.pop();
    }

    // 모든 섬이 연결 되었는지 확인
    int root = 0;
    for(int i=1; i<num; i++){
        if(uf[i]==-1) root += 1;
    }
    if(root == 1) printf("%d\n",mst);
    else puts("-1");
}
