n = int(input())
arr = list(map(int,input().split()))
INF = -100000000

dp = [[0]*2 for _ in range(n)]
dp[0][0] = arr[0]
dp[0][1] = INF
mx = max(dp[0])
for i in range(1,n):
    dp[i][0] = max(dp[i-1][0] + arr[i], arr[i]) # 연속합 or 1개의 arr[i] 값
    dp[i][1] = max(dp[i-1][0], dp[i-1][1]+arr[i]) # 제거하지 않은 값(현재값제거) or 제거한값(현재값추가)
    mx = max(mx, max(dp[i]))
print(mx)