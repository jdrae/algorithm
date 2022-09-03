"""
정답으로 가능한 값이 정해져있다면
해당 값들을 배열의 인덱스로 쓰기
"""

n, s, m = map(int, input().split())
arr = list(map(int, input().split()))
dp = [[False] * (m+1) for _ in range(n+1)]
dp[0][s] = True

for i in range(1,n+1):
    for j in range(0,m+1):
        if not dp[i-1][j]: continue
        val = arr[i-1]
        if j - val >= 0:
            dp[i][j-val] = True
        if j + val <= m:
            dp[i][j+val] = True

ans = -1
for j in range(m,-1,-1):
    if dp[n][j]:
        ans = j
        break

print(ans)