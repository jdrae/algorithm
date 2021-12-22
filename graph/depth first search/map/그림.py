import sys
sys.setrecursionlimit(3000000)

n,m = map(int,input().split())
arr = [] # board
for _ in range(n):
    arr.append(list(map(int,input().split())))

dy = [-1,1,0,0] # 상하좌우
dx = [0,0,-1,1]
def dfs(cy, cx):
    arr[cy][cx] = 0
    size = 1
    for d in range(4):
        ny = cy + dy[d]
        nx = cx + dx[d]
        if 0<=ny<n and 0<=nx<m:
            if arr[ny][nx] == 1:
                size += dfs(ny,nx)
    return size

num = 0
mx = 0
for i in range(n):
    for j in range(m):
        if arr[i][j] == 1:
            mx = max(mx, dfs(i,j))
            num +=1
print(num)
print(mx)