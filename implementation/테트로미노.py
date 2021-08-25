# prep
dy = [0,0,1,-1]
dx = [1,-1,0,0]
non = [
    [(0,0),(0,1),(0,2),(-1,1)],
    [(0,0),(0,1),(0,2),(1,1)],
    [(0,0),(1,0),(2,0),(1,1)],
    [(0,0),(1,0),(2,0),(1,-1)],
]

# input
n,m = map(int,input().split())
arr = []
for i in range(n):
    arr.append(list(map(int,input().split())))

# solve
# tip: 배열 초기화 시 [[0]*m]*n 과 같이 하면 안됨
visited = [([0] * m) for _ in range(n)]

def dfs(y, x, cnt):
    if cnt == 4:
        return arr[y][x]
    
    res = 0
    for d in range(4):
        ny, nx = y + dy[d], x + dx[d]
        if(0<=ny<n and 0<=nx<m and visited[ny][nx]==0):
            visited[ny][nx] = 1
            res = max(res, arr[y][x] + dfs(ny, nx, cnt+1))
            visited[ny][nx] = 0
    return res

def non_dfs(y,x):
    res = 0
    for block in non:
        tmp = 0
        for by,bx in block:
            ny, nx = y+by, x + bx
            if(0<=ny<n and 0<=nx<m):
                tmp += arr[ny][nx]
            else:
                tmp = 0
                break
        res = max(res,tmp)
    return res


# result
mx = 0
for i in range(n):
    for j in range(m):
        visited[i][j] = 1
        mx = max(mx, dfs(i,j,1))
        visited[i][j] = 0
        mx = max(mx, non_dfs(i,j))
print(mx)