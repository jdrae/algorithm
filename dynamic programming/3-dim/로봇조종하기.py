# solve again
"""
현재 행과 바로 윗 행만 값들이 서로 영향을 주므로,
3차원 배열에 전체값을 다 저장할 필요가 없다.
"""

L,R,D = 0,1,2

n, m = map(int,input().split())
arr = [list(map(int,input().split())) for _ in range(n)]

dp = [[[0]*3 for _ in range(m)] for __ in range(n)]
dp[0][0][D] = arr[0][0]
for j in range(1,m):
    dp[0][j][D] = dp[0][j-1][D] + arr[0][j]

for i in range(1,n):
    dp[i][0][R] = dp[i-1][0][D] + arr[i][0]
    dp[i][m-1][L] = dp[i-1][m-1][D] + arr[i][m-1]
    for j in range(1,m):
        dp[i][j][R] = max(dp[i-1][j][D], dp[i][j-1][R]) + arr[i][j]
    for j in range(m-2,-1,-1):
        dp[i][j][L] = max(dp[i-1][j][D], dp[i][j+1][L]) + arr[i][j]
    for j in range(m):
        dp[i][j][D] = max(dp[i][j][L], dp[i][j][R])

print(dp[n-1][m-1][D])