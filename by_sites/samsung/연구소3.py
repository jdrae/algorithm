# 순열 -> itertools.combinations(virus, m) 쓰기
from collections import deque
import sys
dy = [-1,1,0,0]
dx = [0,0,-1,1]
MAX = 2501
n, m = map(int,sys.stdin.readline().split())
arr = [list(map(int,sys.stdin.readline().split())) for _ in range(n)]

virus = []
for i in range(n):
    for j in range(n):
        if arr[i][j] == 2:
            virus.append((i,j))

answer = MAX
v = len(virus)
bomb = set()
def dfs(idx, cnt):
    global answer
    if cnt == 0:
        chk, lev = bfs()
        if chk: answer = min(answer, lev)
        return

    for nxt in range(idx+1, v):
        y, x = virus[nxt]
        bomb.add((y,x))
        dfs(nxt,cnt-1)
        bomb.discard((y,x))

def bfs():
    visited = [[0]*n for _ in range(n)]
    q = deque()
    for y, x in bomb:
        q.append((y,x))
        visited[y][x] = 1

    level = 1
    while q:
        y,x = q.popleft()
        for d in range(4):
            ny, nx = y+dy[d], x+dx[d]
            if not (0<=ny<n and 0<=nx<n): continue
            if visited[ny][nx] or arr[ny][nx] == 1: continue
            q.append((ny,nx))
            visited[ny][nx] = visited[y][x] + 1
            if arr[ny][nx] != 2:
                level = max(level, visited[ny][nx])

    check = 1
    for i in range(n):
        for j in range(n):
            if arr[i][j] != 1 and visited[i][j] == 0:
                check = 0
                break
        if not check:
            break
    return check, level - 1

if m == n*n:
    answer = 0
else:
    dfs(-1, m)
if answer == MAX: answer = -1
print(answer)
