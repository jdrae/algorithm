dy = [-1,1,0,0]
dx = [0,0,1,-1]
opp = [1,0,3,2]

r, c, m = map(int,input().split())
arr = [[0]*c for _ in range(r)]

for _ in range(m):
    y,x,s,d,z = map(int,input().split())
    arr[y-1][x-1] = [s,d-1,z]

def move():
    tmp = [[0]*c for _ in range(r)]
    for i in range(r):
        for j in range(c):
            if arr[i][j] == 0: continue
            y,x, = i, j
            s,d,z = arr[i][j]
            speed = s
            while s:
                ny,nx= y+dy[d], x+dx[d]
                if (0<=ny<r and 0<=nx<c):
                    s -= 1
                    y, x = ny, nx
                else:
                    d = opp[d]
            if tmp[y][x] == 0 or tmp[y][x][2] < z:
                tmp[y][x] = [speed, d,z]
    return tmp

answer = 0
for j in range(c):
    # catch
    for i in range(r):
        if arr[i][j]:
            answer += arr[i][j][2]
            arr[i][j] = 0
            break
    # update
    arr = move()
    
print(answer)