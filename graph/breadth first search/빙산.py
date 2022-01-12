"""
문제에서 "한덩어리의 빙산이 주어질때" 라고 써놨는데
(그럼에도 불구하고) 처음부터 두덩어리 이상의 빙산이 주어질 경우도 고려해야함.
"""

from collections import deque

dy = [-1,1,0,0]
dx = [0,0,-1,1]

def bfs(i,j):
    cnt = 0
    visited = [[0]*m for _ in range(n)]
    q = deque([(i,j)])
    visited[i][j] = 1
    while q:
        y, x = q.pop()
        cnt += 1
        for d in range(4):
            ny, nx = y+dy[d], x+dx[d]
            if not (0<=ny<n and 0<=nx<m): continue
            if arr[ny][nx] and not visited[ny][nx]:
                q.append((ny,nx))
                visited[ny][nx] = 1
    return cnt

if __name__ == "__main__":
    n, m = map(int,input().split())
    arr = [list(map(int,input().split())) for _ in range(n)]
    time = 0
    init = True
    while True:
        ice = []
        for i in range(n):
            for j in range(m):
                if arr[i][j]:
                    water = 0
                    for d in range(4):
                        ny, nx = i+dy[d], j+dx[d]
                        if not (0<=ny<n and 0<=nx<m): continue
                        if arr[ny][nx] == 0:
                            water += 1
                    new = arr[i][j] - water
                    if new < 0: new = 0
                    ice.append((new, i, j))
                    if init:
                        init = False
                        init_cnt = bfs(i,j)
        if time == 0 and init_cnt != len(ice): #처음부터 두덩이 이상
            break

        for new, i, j in ice:
            arr[i][j] = new

        cnt, total = 0, 0
        for new, i, j in ice:
            if new:
                total += 1
                if not cnt:
                    cnt = bfs(i,j)


        time += 1
        if cnt != total:
            break
        elif total == 0:
            time = 0
            break
    print(time)