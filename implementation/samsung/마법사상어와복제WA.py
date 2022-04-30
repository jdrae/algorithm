from copy import deepcopy

# 좌 좌상 상 우상 우 우하 하 좌하
dy = [0, -1, -1, -1, 0, 1, 1, 1]
dx = [-1, -1, 0, 1, 1, 1, 0, -1]

# 상좌하우
sdy = [-1, 0, 1, 0]
sdx = [0, -1, 0, 1]

# input
m, s = map(int, input().split())
fish = [list(map(lambda x: int(x) - 1, input().split())) for _ in range(m)]
sy, sx = map(lambda x: int(x) - 1, input().split())

# init
n = 4
arr = [[[] for _ in range(n)] for __ in range(n)]
for y, x, d in fish:
    arr[y][x].append(d)
dead = [[0]*n for __ in range(n)]


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
            while arr[y][x]:
                d = arr[y][x].pop()
                nd, moved = d, False
                for _ in range(8):
                    ny, nx = y + dy[nd], x + dx[nd]
                    if not (0 <= ny < n and 0 <= nx < n) or ((ny, nx) == (sy, sx)) or (dead[ny][nx] != 0):
                        nd = (nd + 8 - 1) % 8
                        continue
                    else:
                        move_fish.append((ny, nx, nd))
                        moved = True
                        break
                if not moved: move_fish.append((y, x, d))
    for y, x, d in move_fish:
        arr[y][x].append(d)
    # print_arr("fish move")

    # shark move
    mx = -1
    path = []
    visited = [[0] * n for _ in range(n)]
    for a in range(4):
        for b in range(4):
            for c in range(4):
                ny, nx = sy, sx
                cnt = 0
                tmp = []
                for d in [a, b, c]:
                    ny, nx = ny + sdy[d], nx + sdx[d]
                    if (0 <= ny < n and 0 <= nx < n):
                        if not visited[ny][nx]:
                            cnt += len(arr[ny][nx])
                            visited[ny][nx] = 1
                        tmp.append([ny, nx])
                    else:
                        cnt = 0
                        break
                for i in range(len(tmp)):
                    y, x = tmp[i]
                    visited[y][x] = 0
                if len(tmp) == 3 and cnt > mx:
                    mx = cnt
                    path = tmp[:]
    for y, x in path:
        if arr[y][x]:
            dead[y][x] = 3
            arr[y][x] = []
    sy, sx = path[-1]
    # print_arr("shark move")

    # remove dead
    for y in range(n):
        for x in range(n):
            if dead[y][x] > 0:
                dead[y][x] -= 1

    # copy fish
    for y in range(n):
        for x in range(n):
            arr[y][x] += copy_arr[y][x]
    # print_arr("copy fish")

# output
answer = 0
for y in range(n):
    for x in range(n):
        answer += len(arr[y][x])
print(answer)