"""
size 만큼 배열 나누기
for sy in range(0,n,size):
    for sx in range(0,n,size):
        tmp = [arr[i][sx:sx+size] for i in range(sy,sy+size)]

배열 시계방향으로 회전
rotated = list(map(list,zip(*tmp[::-1])))
"""
from collections import deque

# 상하좌우
dy = [-1,1,0,0]
dx = [0,0,-1,1]

# input
m, q = map(int,input().split())
n = 2**m
arr = [list(map(int,input().split())) for _ in range(n)]
cmd = list(map(int,input().split()))

# do
for lev in cmd:
    # rotate
    size = 2**lev
    if size > 1:
        for sy in range(0,n,size):
            for sx in range(0,n,size):
                tmp = [arr[i][sx:sx+size] for i in range(sy,sy+size)]
                rotated = list(map(list,zip(*tmp[::-1])))
                # print(sy,sx)
                for i in range(size):
                    arr[sy+i][sx:sx+size] = rotated[i]

    # melt
    melt_ice = []
    for y in range(n):
        for x in range(n):
            if arr[y][x] < 1: continue
            cnt = 0
            for d in range(4):
                ny, nx = y + dy[d], x + dx[d]
                if not (0 <= ny < n and 0 <= nx < n): continue
                if arr[ny][nx] > 0: cnt += 1
            if cnt < 3:
                melt_ice.append((y,x))
    for y, x in melt_ice:
        arr[y][x] -= 1

# output
visited = [[0]*n for _ in range(n)]
def bfs(y,x):
    q = deque([])
    ret = 1
    visited[y][x] = 1
    q.append((y,x))
    while q:
        y, x = q.popleft()
        visited[y][x] = 1
        for d in range(4):
            ny, nx = y+dy[d], x+dx[d]
            if (0<=ny<n and 0<=nx<n) and not visited[ny][nx] and arr[ny][nx]:
                    ret += 1
                    visited[ny][nx] = 1
                    q.append((ny,nx))
    return ret

total, mx = 0, 0
for y in range(n):
    for x in range(n):
        if arr[y][x]:
            total += arr[y][x]
            if not visited[y][x]:
                mx = max(mx, bfs(y,x))
print(total, mx, sep="\n")

