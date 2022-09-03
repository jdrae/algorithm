"""
bfs: 912ms
dfs: 2060ms

웬만하면 bfs 쓰기
"""

import sys
sys.setrecursionlimit(15000)

dy = [-1,1,0,0]
dx = [0,0,-1,1]

def dfs(y,x,h):
    visited[y][x] = 1
    for d in range(4):
        ny,nx= y+dy[d], x+dx[d]
        if not (0<=ny<n and 0<=nx<n): continue
        if arr[ny][nx] > h and not visited[ny][nx]:
            dfs(ny,nx,h)
    return

def bfs(y,x,h):
    q = []
    visited[y][x] = 1
    q.append((y,x))
    while q:
        y,x = q.pop()
        for d in range(4):
            ny,nx= y+dy[d], x+dx[d]
            if not (0<=ny<n and 0<=nx<n): continue
            if arr[ny][nx] > h and not visited[ny][nx]:
                visited[ny][nx] = 1
                q.append((ny,nx))
    return


if __name__ == "__main__":
    n = int(input())
    arr = []
    height = set()
    for i in range(n):
        arr.append(list(map(int,input().split())))
        height.update(arr[i])
    height = sorted(list(height))

    mx = 1
    for h in height:
        res = 0
        visited = [[0]*n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                if arr[i][j] > h and not visited[i][j]:
                    bfs(i,j,h)
                    res += 1
        mx = max(mx, res)
    
    print(mx)