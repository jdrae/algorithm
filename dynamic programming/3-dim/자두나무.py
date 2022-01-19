# solve again

t, w = map(int, input().split())
arr = [int(input()) for _ in range(t)]

dp = [[[0]*3 for _ in range(w+2)] for _ in range(t)]
if arr[0] == 1:
    dp[0][1][1] = 1 # 0초에 0번 움직여서 1번 자두
else:
    dp[0][2][2] = 1 # 0초에 1번 움직여서 2번 자두

for i in range(1,t):
    for j in range(1,w+2): # [0,w+1) 로 생각
        if arr[i] == 1:
            # i 초에 j 번 움직여서 1번 자두를 받는 경우는
            # i-1 초에 j 번 움직여서 1번 자두를 받았던 값과(안움직임)
            # i-1 초에 j-1 번 움직여서 2번 자두를 받았던 값 비교(움직임)
            dp[i][j][1] = 1 + max(dp[i-1][j][1], dp[i-1][j-1][2])
            dp[i][j][2] = max(dp[i-1][j-1][1], dp[i-1][j][2])
        else:
            dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][2])
            dp[i][j][2] = 1 + max(dp[i-1][j-1][1], dp[i-1][j][2])

mx = 0
for i in range(w+2):
    mx = max(mx, max(dp[t-1][i][1], dp[t-1][i][2]))
print(mx)