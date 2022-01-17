"""
LIS
뒤섞인 번호의 개수를 알기 위해 올바르게 정렬된 번호를 구하면 된다.
"""

n = int(input())
arr = [int(input()) for _ in range(n)]

mx = 0
dp = [0] * n
for i in range(n):
    dp[i] = 1
    for j in range(i):
        if arr[j] < arr[i] and dp[j] + 1 > dp[i]:
            dp[i] = dp[j] + 1
    mx = max(mx, dp[i])
print(n-mx)

# with func // 1초 시간초과
dp = [0] * (n+1)
def func(pos):
    ret = dp[pos+1]
    if ret: return ret
    ret = 0
    for i in range(pos+1, n):
        if pos == -1 or arr[pos] < arr[i]:
            ret = max(ret, func(i) + 1)
    return ret
print(n-func(-1))