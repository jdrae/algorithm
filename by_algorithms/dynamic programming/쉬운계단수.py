"""
계단수: 인접한 모든 자리의 차이가 1. ex)45656
"""
n = int(input())
MOD = 10**9

dp = [[0]*10 for _ in range(n+1)]
for j in range(1,10):
    dp[1][j] = 1
for i in range(2,n+1):
    for j in range(10):
        if j > 0:
            dp[i][j] = (dp[i][j] + dp[i-1][j-1]) %MOD
        if j < 9:
            dp[i][j] = (dp[i][j] + dp[i-1][j+1]) %MOD

print(sum(dp[n])%MOD)