MOD = 1000000007

tc= int(input())
arr = [int(input().strip()) for _ in range(tc)]
dp = [0] * 5001
dp[0] = dp[2] = 1
mx = max(arr)
for num in range(4, mx+1,2):
    for i in range(2, num+1,2):
        dp[num] += dp[i-2] * dp[num-i]
    dp[num] %= MOD

for num in arr:
    print(dp[num])