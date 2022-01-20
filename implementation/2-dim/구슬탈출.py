from collections import deque

# direction
dx = [0,0,1,-1]
dy = [1,-1,0,0]

# input
n, m = map(int, input().split())
arr = [input() for _ in range(n)]
for i in range(n):
    for j in range(m):
        if arr[i][j] == 'R':
            ry, rx = i, j
        if arr[i][j] == 'B':
            by, bx = i, j

# implementation
# tip: 보드에서 한방향으로 움직이기
def move(y, x, d):
    while True:
        y += dy[d]
        x += dx[d]
        if arr[y][x] == '#':
            y -= dy[d]
            x -= dx[d]
            break
        elif arr[y][x] == 'O':
            break
    return y, x

# bfs
q = deque([])
q.append([ry,rx,by,bx])
visited = [[[[0] * m for _ in range(n)] for _ in range(m)] for _ in range(n)]
visited[ry][rx][by][bx] = 1

answer, level = -1,0
while q:
    qSize = len(q)
    for _ in range(qSize):
        ry,rx,by,bx = q.popleft()
        if arr[ry][rx] == 'O':
            answer = level
            break
        for i in range(4):
            nry, nrx = move(ry,rx,i)
            nby, nbx = move(by,bx,i)
            if arr[nby][nbx] == 'O':
                continue
            if nry == nby and nrx == nbx:
                if i == 0: # down
                    if ry < by: nry -= 1
                    else: nby -= 1
                elif i == 1: # up
                    if ry < by: nby += 1
                    else: nry += 1
                elif i == 2: # right
                    if rx < bx: nrx -= 1
                    else: nbx -= 1
                elif i == 3: # left
                    if rx < bx: nbx += 1
                    else: nrx += 1
            
            if visited[nry][nrx][nby][nbx] == 0:
                q.append([nry,nrx,nby,nbx])
                visited[nry][nrx][nby][nbx] = 1
    level += 1
    if answer != -1 or level > 10: break

print(answer)
# 반례: https://www.acmicpc.net/board/view/46338