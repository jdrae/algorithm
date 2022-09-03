# 상 우상 ... 좌상
dy = [-1,-1,0,1,1,1,0,-1]
dx = [0,1,1,1,0,-1,-1,-1]

# input
n, m, k = map(int,input().split())
ball = [list(map(int,input().split())) for _ in range(m)]

# init
arr = [[ [] for _ in range(n)] for _ in range(n)]
for y,x,m,s,d in ball:
    arr[y-1][x-1].append([m,s,d])

def print_arr(msg):
    print("===",msg)
    for ar in arr:
        print(ar)

# do
for _ in range(k):
    # move
    move_ball = []
    for y in range(n):
        for x in range(n):
            while arr[y][x]:
                m,s,d = arr[y][x].pop()
                ny,nx = (y+dy[d]*s)%n, (x+dx[d]*s)%n
                assert 0<=ny<n and 0<=nx<n
                move_ball.append((ny,nx,m,s,d))

    for y,x,m,s,d in move_ball:
        arr[y][x].append([m,s,d])
    # print_arr("first")

    # sum & divide
    for y in range(n):
        for x in range(n):
            size = len(arr[y][x])
            if size < 2: continue
            nm, ns = 0, 0
            is_same = 0
            while arr[y][x]:
                m,s,d = arr[y][x].pop()
                nm += m
                ns += s
                is_same += d%2 # 1 또는 0이 더해짐
            nm //= 5
            ns //= size
            if nm:
                if is_same==size or is_same==0: dirs = (0,2,4,6)
                else: dirs = (1,3,5,7)
                for d in dirs:
                    arr[y][x].append([nm,ns,d])
    # print_arr("second")

# output
answer = 0
for y in range(n):
    for x in range(n):
        for ball in arr[y][x]:
            answer += ball[0]
print(answer)