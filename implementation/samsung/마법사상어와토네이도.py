# setting
# 하우상좌
dy = [1,0,-1,0]
dx = [0,1,0,-1]
dic = '하우상좌'
# a 의 위치 하우상좌
left = [(1, 1, 0.01), (-1, 1, 0.01), (1, 0, 0.07), (-1, 0, 0.07), (2, 0, 0.02), (-2, 0, 0.02), (1, -1, 0.1), (-1, -1, 0.1), (0, -2, 0.05)]
per = [
    [(-x, y, p) for y, x, p in left],
    [(y, -x, p) for y, x, p in left],
    [(x, y, p) for y, x, p in left],
    left,
]

# input
n = int(input())
arr = [list(map(int,input().split())) for _ in range(n)]

# calculate
def func(y,x,d):
    # print(f'{y},{x}의 모래 {arr[y][x]} 가 {dic[d]}방향으로 밀린다')
    ans = 0
    alpha = arr[y][x]
    for ddy, ddx, p in per[d]:
        ny,nx = y+ddy, x+ddx
        # percentage
        sand = int(arr[y][x]*p)
        alpha -= sand
        # update
        if 0<=ny<n and 0<=nx<n:
            arr[ny][nx] += sand
        else:
            ans += sand
    # alpha
    ny,nx = y+dy[d], x+dx[d]
    if 0 <= ny < n and 0 <= nx < n:
        arr[ny][nx] += alpha
    else:
        ans += alpha
    arr[y][x] = 0
    return ans

# do
answer = 0
y, x, k = n//2, n//2, 0
while True:
    for d in range(4):
        for _ in range(k):
            # print(f'{y},{x}에서 {dic[d]}방향으로 바람이분다')
            y += dy[d]
            x += dx[d]
            if arr[y][x]: answer += func(y,x,d)
        if d == 3:
            # print(f'{y},{x}에서 {dic[d]}방향으로 바람이분다')
            sy, sx = y + dy[d], x + dx[d]
            if arr[sy][sx]: answer += func(sy, sx, 3)
    if y == x == 0: break
    y -= 1
    x -= 1
    k += 2

# output
print(answer)
