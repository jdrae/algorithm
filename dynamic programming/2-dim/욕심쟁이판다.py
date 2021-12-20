# tip: 파이썬 rescursion limit 해제
import sys
sys.setrecursionlimit(40000)

n = int(input())
arr = []
for _ in range(n):
    arr.append(list(map(int,input().split())))

dy = [-1,1,0,0]
dx = [0,0,-1,1]
dp = [[-1]*n for _ in range(n)]
def func(y,x):
    if dp[y][x] != -1: return dp[y][x]
    dp[y][x] = 1
    for d in range(4):
        ny, nx = y+dy[d], x+ dx[d]
        if not (0<=ny<n and 0<=nx<n): continue
        if arr[ny][nx] > arr[y][x]:
            dp[y][x] = max(dp[y][x], func(ny,nx)+1)
    return dp[y][x]

mx = 0
for i in range(n):
    for j in range(n):
        mx = max(mx,func(i,j))

print(mx)