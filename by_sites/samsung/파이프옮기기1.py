# https://www.acmicpc.net/board/view/34633

"""
물체가 두 칸이더라도 끝부분만 파악해도 되는 경우.
dp 적용할 수 있다면 무조건 적용하기.
불가능한 상황 확인하기(끝에 도달 못하는 경우)
"""

n = int(input())
arr = [input().split() for _ in range(n)]

dirs = [(0,1), (1,0), (1,1)] # 가로, 세로, 대각선
dp = [[[0]*3 for _ in range(n)] for _ in range(n)]
def func(y, x, d):
    if y == n-1 and x == n-1:
        return 1
    if dp[y][x][d]:
        return dp[y][x][d]
    
    for nd in range(3):
        if (nd == 0 and d == 1) or (nd== 1 and d == 0):
            continue

        ny, nx = y+dirs[nd][0], x+dirs[nd][1]
        if not (0<=ny<n and 0<=nx<n and arr[ny][nx] == "0"):
            continue
        if nd == 2:
            if (arr[y][x+1] == "1") or (arr[y+1][x] == "1"):
                continue

        dp[y][x][d] += func(ny,nx,nd)

    return dp[y][x][d]

if arr[n-1][n-1] == "0":
    print(func(0,1,0))
else:
    print(0)