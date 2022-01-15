
if __name__ == "__main__":
    n, m, k = map(int, input().split())

    dp = [[0]*(m+1) for _ in range(n+1)]
    dp[0][1] = 1
    for i in range(1,n+1):
        for j in range(1,m+1):
            dp[i][j] = dp[i-1][j] + dp[i][j-1]
    
    if k:
        k -= 1
        ky, kx = k//m, k%m
        print(dp[ky+1][kx+1] * dp[n-ky][m-kx])
    else:
        print(dp[n][m])