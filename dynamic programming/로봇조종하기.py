# input
n,m = map(int,input().split())
arr = []
for _ in range(n):
    arr.append(list(map(int,input().split())))

# prep
dx = [0,-1,1] # 하좌우
dy = [1,0,0]

# dp
INF = -1000000000
dp = [[[INF]*3 for _ in range(m)] for __ in range(n)]
visited = [[0]*m for _ in range(n)] # 같은 행에서는 오른쪽으로만 가거나, 왼쪽으로 가거나
def func(y,x,cd):
    if y == n-1 and x == m-1: return arr[y][x]
    if dp[y][x][cd] != INF: return dp[y][x][cd]
    
    visited[y][x] = 1
    mx = INF
    for d in range(3):
        ny, nx = y+dy[d], x+dx[d]
        if ny<0 or ny>=n or nx<0 or nx>=m: continue
        if not visited[ny][nx] and (d==0 or d == cd or (y==0 and x == 0)):
            mx = max(mx, func(ny,nx, d))
    visited[y][x] = 0 # 방문 초기화
    dp[y][x][cd] = arr[y][x] + mx
    return dp[y][x][cd]

# result
print(func(0,0,0))