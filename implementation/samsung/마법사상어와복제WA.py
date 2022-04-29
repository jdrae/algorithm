from copy import copy, deepcopy
# 좌 좌상 상 우상 우 우하 하 좌하
dy = [0,-1,-1,-1,0,1,1,1]
dx = [-1,-1,0,1,1,1,0,-1]

# 상좌하우
sdy = [-1,0,1,0]
sdx = [0,-1,0,1]


#input
m, s = map(int,input().split())
fish = [list(map(lambda x: int(x)-1,input().split())) for _ in range(m)]
sy, sx = map(lambda x: int(x)-1,input().split())

# init
n = 4
arr = [[ [] for _ in range(n)] for __ in range(n)]
for y,x,d in fish:
    arr[y][x].append(d)
dead = {(y,x):0 for y in range(n) for x in range(n)}

def print_arr(msg):
    print("=======", msg)
    for ar in arr:
        print(ar)

# do
for time in range(s):
    # copy fish
    copy_arr = deepcopy(arr)
    # fish move
    move_fish = []
    for y in range(n):
        for x in range(n):
            qsize = len(arr[y][x])
            for _ in range(qsize):
                d = arr[y][x].pop()
                nd = d
                moved = False
                for _ in range(8):
                    ny, nx = y+dy[nd], x+dx[nd]
                    if ((ny,nx) == (sy,sx)) or (dead[(y,x)] != 0) or not (0<=ny<n and 0<=nx<n):
                        nd = (nd+8-1)%8
                    else:
                        move_fish.append((ny,nx,nd))
                        moved = True
                        break
                if not moved: move_fish.append((y,x,d))
    for y, x, d in move_fish:
        arr[y][x].append(d)
    
    # shark move
    mx = 0
    path = []
    visited = [[0]*n for _ in range(n)]
    for a in range(4):
        for b in range(4):
            for c in range(4):
                ny,nx = sy,sx
                cnt = 0
                tmp = []
                for i,d in enumerate([a,b,c]):
                    ny,nx = ny+sdy[d], nx+sdx[d]
                    if (0<=ny<n and 0<=nx<n):
                        if not visited[ny][nx]:
                            cnt += len(arr[ny][nx])
                            visited[ny][nx] = True
                        tmp.append([ny,nx])
                    else:
                        cnt = 0
                        break
                for i in range(len(tmp)):
                    y,x = tmp[i]
                    visited[y][x] = False
                if (len(tmp) == 3 and not path) or cnt > mx:
                    mx = cnt
                    path = tmp[:]

    if arr[sy][sx]:
        dead[(sy,sx)] = 3
        arr[sy][sx] = []
    for y, x in path:
        if arr[y][x]:
            dead[(y,x)] = 3
            arr[y][x] = []
    sy, sx = path[-1]

    # remove dead
    for y in range(n):
        for x in range(n):
            if dead[(y,x)] > 0:
                dead[(y,x)] = -1
    
    # copy fish
    for y in range(n):
        for x in range(n):
            while copy_arr[y][x]:
                arr[y][x].append(copy_arr[y][x].pop())

# output
answer = 0
for y in range(n):
    for x in range(n):
        answer += len(arr[y][x])
print(answer)