# input
n = int(input())
target = int(input())

arr = [[0]*n for _ in range(n)]

def in_to_out():
    # 안쪽(1)부터 바깥까지
    # 우하좌상: 가장자리 네모 숫자가 커지는 방향순서
    dy = [0,1,0,-1]
    dx = [1,0,-1,0]
    y, x = n//2, n//2
    num = 1
    ans = []

    len = 0
    arr[y][x] = num
    if num == target:
        ans = [y+1, x+1]

    while True:
        for d in range(4):
            for _ in range(len):
                y += dy[d]
                x += dx[d]
                num += 1
                arr[y][x] = num
                if num == target:
                    ans = [y+1, x+1]
        if y == x == 0:
            break
        # 왼쪽 위 꼭지점으로 감
        y -= 1
        x -= 1
        # 한 방향당 길이
        len += 2
    return ans

def out_to_in():
    # 바깥에서 안으로. 범위 벗어날때 꺾기
    # 하우상좌
    dy = [1,0,-1,0]
    dx = [0,1,0,-1]
    y,x = 0, 0
    num = n**2
    ans = []

    d = 0
    while True:
        arr[y][x] = num
        if num == target:
            ans = [y+1, x+1]
        if num == 1:
            break
        ny, nx = y+dy[d], x+dx[d]
        if not (0<=ny<n and 0<=nx<n) or  arr[ny][nx] != 0:
            d = (d+1)%4
            continue

        y,x = ny,nx
        num -= 1
    arr[y][x] = 1
    return ans

# output
ans = in_to_out()
for i in range(n):
    print(*arr[i])
print(*ans)