# n <= 150만. 재귀로 구현하면 RecursionError

n = int(input())
sch = [list(map(int,input().split())) for _ in range(n)]

dp = [0] * (n+1)

for i in range(n-1,-1,-1):
    if i + sch[i][0] <= n:
        dp[i] = dp[i+sch[i][0]] + sch[i][1]
    dp[i] = max(dp[i], dp[i+1])
answer = dp[0]
print(answer)


# def func(curr):
#     if curr >= n or (curr + sch[curr][0] > n):
#         return 0
#     ret = dp[curr]
#     if ret != -1:
#         return ret
    
#     ret = max(func(curr+1), func(curr+sch[curr][0]) + sch[curr][1])
#     dp[curr] = ret
#     return ret
# answer = func(0)