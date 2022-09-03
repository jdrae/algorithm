"""
arr 에서 m 개의 구간을 선택하고, 구간의 합이 최대가 되는 값.
두 구간은 최소 1개의 인덱스를 사이에 두고 띄어야한다.
---
누적합은 편하게 1~n 으로 사용.
"""
n, m = map(int,input().split())
arr = [int(input()) for _ in range(n)]
INF = float('-inf')

# 누적합
psum = [0] * (n+1)
for i in range(1, n+1):
    psum[i] = psum[i-1] + arr[i-1]

# dp
dp = [[INF]*(m+1) for _ in range(n+1)]
dp[1][1] = arr[0]
for i in range(2, n+1):
    for j in range(1,min(m, (i+1)//2)+1):
        # 포함x: i 가 j 개의 구분선에 포함 안됨
        dp[i][j] = dp[i-1][j]
        # 포함o: k 번째 수가 이전 구간 m-1 에 포함 될때(dp[k][m-1]), 
        # 현재 구간에는 k+2 부터 합 계산(psum[i] - psum[k+1]). dp와 psum 의 합이 최대인 경우 저장.
        for k in range(-1,i-1): # [0, i-2]
            if m == 1 and k < 0:
                dp[i][j] = max(dp[i][j], psum[i]) # 구간이 하나일때, 첫번째 수 포함하는 경우 고려.
            else:
                dp[i][j] = max(dp[i][j], dp[k][m-1] + (psum[i] - psum[k+1]))

print(dp[n-1][m-1])

def WA():
    # dp[i][j][2]: i 번째까지의 수 중 j 개의 구분선을 선택했을 때(구간 j+1 개) 포함유무(1/0)에 따른 최댓값
    dp = [[[INF]*2 for _ in range(m)] for __ in range(n)]
    dp[0][0][0] = 0
    dp[0][0][1] = arr[0]
    for i in range(1, n):
        # for j in range(m):
        for j in range(min(m, (i+1)//2)):
            # 포함x:  i-1 까지의 수로 j 개의 구간을 나눈 최댓값
            dp[i][j][0] = max(dp[i-1][j][1], dp[i-1][j][0])
            # 포함o: (1) i-1 를 포함해 j 개의 구간을 나누어 현재값을 기존 구간에 추가
            # (2) i-1 를 포함하지 않고 j-1 구간. 현재값으로 새로운 구간 +1
            dp[i][j][1] = arr[i] + max(dp[i-1][j][1], dp[i-1][j-1][0])

    print(max(dp[n-1][m-1]))