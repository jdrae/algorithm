#include <iostream>
using namespace std;
#include <vector>
#include <queue>
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int n, k;
int arr[2000][2000]={0,};
vector<int> p;
queue<pair<int,int>> q;

int find(int a){
    if(p[a] < 0) return a;
    return p[a] = find(p[a]);
}

void merge(int a, int b){
    a = find(a); b = find(b);
    if(a== b) return;
    p[b] = a;
    k--;
}

void print(int level){
    printf("===P %d k %d\n", level, k);
    for(int i = 0; i<p.size(); i++){
        printf("%d %d\n", i, p[i]);
    }
    printf("\n");
}

void parr(){
    printf("===ARR\n");
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main(){
    scanf("%d%d",&n,&k);
    p.resize(k+1); p[0] = 0;
    int x, y;
    for(int i = 1; i<=k; i++){
        scanf("%d %d", &x,&y); x--; y--;
        arr[y][x] = i; 
        q.push({x,y});
        p[i] = -1;
    }
    int level = 0;

    // check initial union
    for(int qs = 0; qs<k;qs++){
        int currx= q.front().first, curry = q.front().second;
        q.pop(); q.push({currx, curry});
        for(int i = 0; i<4; i++){
            int nx = currx + dx[i]; int ny = curry + dy[i];
            if(0<=nx && nx < n && 0<=ny && ny < n){
                if(arr[ny][nx] != 0){
                    merge(arr[curry][currx], arr[ny][nx]);
                }
            }
        }
    }
    if(k == 1)
        goto answer;

    // process 
    while(!q.empty()){
        int qSize = q.size();
        for(int qs = 0; qs<qSize;qs++){
            int currx= q.front().first, curry = q.front().second;
            q.pop();
            for(int i = 0; i<4; i++){
                int nx = currx + dx[i]; int ny = curry + dy[i];
                if(0<=nx && nx < n && 0<=ny && ny < n){
                    if(arr[ny][nx] == 0){
                        q.push({nx,ny});
                    } else{
                        merge(arr[curry][currx], arr[ny][nx]);
                    }
                    arr[ny][nx] = arr[curry][currx];
                }
            }
        }
        parr();
        print(level);
        level++;
        if(k==1) break;
    }
    answer:
        printf("%d\n", level);
}

/**
반례:
2 3
2 2
1 1
2 1
정답:0

3 2
1 2
3 2
정답: 1

4 3
1 4
2 1
3 3
정답: 1

2000 10 1355 934 1935 436 934 1249 435 1253 1423 1953 45 1054 1395 1943 943 4 642 23 643 124
정답: 627
*/