n, m = map(int,input().split())
arr = list(map(int,input().split()))
cost = list(map(int,input().split()))

mx = sum(cost)
dp = [0] * (mx+1) # 비용이 j 일 때 얻을 수 있는 최대 메모리
for i in range(n):
    for j in range(mx, cost[i]-1, -1):
        if j < cost[i]: continue
        dp[j] = max(dp[j], dp[j-cost[i]] + arr[i])

ans = 0
for i in range(mx+1):
    if dp[i] >= m:
        ans = i
        break
print(ans)