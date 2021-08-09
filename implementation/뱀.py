from collections import deque

# input
n = int(input())
k = int(input())
arr = [[0 for _ in range(n)] for __ in range(n)]
for _ in range(k):
    y, x = map(int, input().split())
    arr[y-1][x-1] = 1
l = int(input())
cmd = {}
for _ in range(l):
    x, c = input().split()
    cmd[int(x)] = c

# direction
dx = [1,0,-1,0] # rdlu
dy = [0,1,0,-1]
def change(dir, c):
    if c == "D":
        return (dir+1)%4
    else:
        return (dir+3)%4

# implementation
dir, answer = 0, 0
y, x = 0,0
body = deque([(y,x)])
arr[y][x] = 2
while True:
    answer += 1
    y, x = y + dy[dir], x + dx[dir]
    if 0<=y<n and 0<=x<n and arr[y][x] != 2:
        if arr[y][x] == 0:
            ty, tx = body.popleft() # tail
            arr[ty][tx] = 0
        arr[y][x] = 2
        body.append((y,x))
    else:
        break
    
    if answer in cmd:
        dir = change(dir, cmd[answer])


print(answer)