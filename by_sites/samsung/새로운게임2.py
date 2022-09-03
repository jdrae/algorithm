from collections import deque
# 우좌상하
dy = [0,0,-1,1]
dx = [1,-1,0,0]
op = [1,0,3,2]

# input
n, k = map(int,input().split())
arr = [list(map(int,input().split())) for _ in range(n)]
moved = [[deque() for _ in range(n)] for _ in range(n)]

pawn = []
for idx in range(k):
    y, x, d = map(int,input().split())
    pawn.append([y-1,x-1,d-1])
    moved[y-1][x-1].append(idx)
m = len(pawn)

# simulate
time, ended = 0, False
while True:

    # turn
    for idx in range(m):
        y, x, d = pawn[idx]
        ny, nx = y+dy[d], x+dx[d]
        # blue
        if not (0<=ny<n and 0<=nx<n) or arr[ny][nx] == 2:
            ny, nx = y+dy[op[d]], x+dx[op[d]]
            pawn[idx][2] = op[d]
            if not (0<=ny<n and 0<=nx<n) or arr[ny][nx] == 2: continue
        
        # white/red
        if arr[ny][nx] == 0:
            cnt = len(moved[y][x])
            found = False
            for _ in range(cnt):
                midx = moved[y][x].popleft()
                if not found and idx != midx:
                    moved[y][x].append(midx)
                    continue
                found = True
                moved[ny][nx].append(midx)
                pawn[midx][0], pawn[midx][1] = ny, nx
        elif arr[ny][nx] == 1:
            cnt = len(moved[y][x])
            for _ in range(cnt):
                midx = moved[y][x].pop()
                if idx != midx:
                    moved[ny][nx].append(midx)
                    pawn[midx][0], pawn[midx][1] = ny, nx
                    continue
                moved[ny][nx].append(midx)
                pawn[midx][0], pawn[midx][1] = ny, nx
                break
        if len(moved[ny][nx]) >= 4:
            ended=True
            break

    # time
    time += 1
    if time == 1000 or ended:
        break

# output
if time >= 1000: time = -1
print(time)