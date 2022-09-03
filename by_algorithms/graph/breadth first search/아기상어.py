"""
bfs level 대신에 dist[ny][nx] = dist[y][x] + 1 사용.
bfs 함수에서 다음 방문칸 바로 찾기.
"""

from collections import deque

dy = [-1,1,0,0]
dx = [0,0,-1,1]

def bfs(y,x):
    visited = [[0]*n for _ in range(n)]
    q = deque([(y,x)])
    visited[y][x] = 1
    level = 0
    while q:
        qSize = len(q)
        for _ in range(qSize):
            y,x = q.popleft()
            if y == cy and x == cx:
                break
            for d in range(4):
                ny, nx = y+dy[d], x+dx[d]
                if not (0<=ny<n and 0<=nx<n): continue
                if not visited[ny][nx] and size >= arr[ny][nx]:
                    q.append((ny,nx))
                    visited[ny][nx] = 1
        level+=1
        if visited[cy][cx]:
            return level
    return MAX

if __name__ == "__main__":
    n = int(input())
    MAX = n*n + 1
    arr = [list(map(int,input().split())) for _ in range(n)]
    fish = []
    for i in range(n):
        for j in range(n):
            if arr[i][j] == 9:
                cy, cx = i, j
                arr[i][j] = 0
            elif arr[i][j] != 0:
                fish.append((arr[i][j], i, j))

    fish.sort()
    eaten = [[0]* n for _ in range(n)]
    size, cnt = 2, 0
    time = 0
    while True:
        can_eat = []
        for fs, fy, fx in fish:
            if fs < size and not eaten[fy][fx]:
                can_eat.append((fy,fx))
        if not can_eat:
            break
        
        mn = MAX
        ny,nx = n,n
        for y,x in can_eat:
            dist = bfs(y,x)
            if dist == MAX:
                continue
            if mn >= dist:
                if mn == dist:
                    if y < ny:
                        ny, nx = y, x
                    elif y == ny and x < nx:
                        ny, nx = y, x
                else:
                    ny,nx = y, x
                mn = dist
        if mn == MAX: # 한칸도 움직일 수 없을 경우
            break
        
        cy, cx = ny, nx
        arr[ny][nx] = 0
        eaten[ny][nx] = 1
        cnt += 1
        if size == cnt:
            size += 1
            cnt = 0
        
        time += mn
    print(time)
    