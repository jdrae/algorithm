"""
칸의 속성, 방문여부 파악해서 저장
"""

from collections import deque

dy = [-1,1,0,0]
dx = [0,0,-1,1]

def initial_dfs(y, x):
    visited[y][x] = 1
    for d in range(4):
        ny, nx = y+dy[d], x+dx[d]
        if 0<=ny<n and 0<=nx<m:
            if arr[ny][nx] == 0 and visited[ny][nx] == 0:
                initial_dfs(ny,nx)
            elif arr[ny][nx] == 1 and visited[ny][nx] == -1:
                q.append((y,x))

def melt_cheese():
    qsize = len(q)
    for _ in range(qsize):
        y, x = q.popleft()
        for d in range(4):
            ny, nx = y+dy[d], x+dx[d]
            if 0<=ny<n and 0<=nx<m:
                if arr[ny][nx] == 1:
                    arr[ny][nx] = 0
                    q.append((ny,nx))

def merge_air():
    tmp = deque(q)
    while tmp:
        y, x = tmp.popleft()
        for d in range(4):
            ny, nx = y+dy[d], x+dx[d]
            if 0<=ny<n and 0<=nx<m:
                if arr[ny][nx] == 0 and visited[ny][nx] == 0:
                    visited[ny][nx] = 1
                    tmp.append((ny,nx))
                    q.append((ny,nx))

def check():
    for i in range(n):
        for j in range(m):
            if arr[i][j] == 1:
                return False
    return True

if __name__ == "__main__":
    n, m = map(int,input().split())
    arr = [list(map(int,input().split())) for _ in range(n)]

    q = deque([])
    visited = [[0]*m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if arr[i][j]:
                visited[i][j] = -1
    initial_dfs(0,0)

    time = 0
    while True:
        if check() == True: break

        melt_cheese()
        final_size = len(q)
        merge_air()
        time+=1
            
    print(time)
    print(final_size)
