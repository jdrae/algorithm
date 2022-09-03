"""
테이블로 dp 를 구현할때, 2중 for 문으로 구현하면 채워지지 않은 값을 참조한다.
따라서 거리에 따라서 s,e 를 지정하는 3중 for 문으로 구현하고,
거리가 0, 1, 2 ... 일 때 순서대로 구한다.
왜냐하면 dp[i][j] = dp[i+1][j-1] 는 i~j 보다 거리가 2짧은 것이기 때문이다.
"""

import sys
n = int(sys.stdin.readline())
arr = list(map(int,sys.stdin.readline().split()))
m = int(sys.stdin.readline())

# 테이블
dp = [[0]*n for _ in range(n)]
for diff in range(n):
    for s in range(n-diff):
        e = s+diff
        if arr[s] == arr[e]:
            if diff < 2:
                dp[s][e] = 1
            else:
                dp[s][e] = dp[s+1][e-1]

# 재귀
def func(i, j):
    if i > j: return 0

    ret = dp[i][j]
    if ret != -1: return ret

    ret = 0
    if arr[i] == arr[j]:
        if j-i < 2: ret = 1
        else:
            ret = func(i+1, j-1)
            
    dp[i][j] = ret
    return ret

for i in range(n):
    for j in range(i,n):
        func(i,j)


for _ in range(m):
    s, e = map(int,sys.stdin.readline().split())
    print(dp[s-1][e-1])
