# 우하좌상
dy = [0,1,0,-1]
dx = [1,0,-1,0]

# input
n,m = map(int,input().split())
y,x = 0,0

answer = 0
visited = [[0]*m for _ in range(n)]
d, cnt = 0, n*m
while True:
    visited[y][x] = 1
    if cnt == 1:
        break
    ny, nx = y+dy[d], x+dx[d]
    if not (0<=ny<n and 0<=nx<m) or visited[ny][nx]:
        d = (d+1)%4
        answer += 1
        continue
    y, x = ny, nx
    cnt -= 1
print(answer)