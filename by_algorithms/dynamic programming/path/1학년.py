n = int(input())
arr = list(map(int,input().split()))
start, end = arr[0], arr[-1]

dp = [[0]*(21) for _ in range(n)]
dp[0][start] = 1

for i in range(1,n):
    for k in range(21):
        if dp[i-1][k]:
            if k + arr[i] <= 20:
                dp[i][k+arr[i]] += dp[i-1][k] 
            if k - arr[i] >= 0:
                dp[i][k-arr[i]] += dp[i-1][k] 
print(dp[n-2][end])