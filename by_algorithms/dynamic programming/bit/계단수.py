"""
길이가 N이면서 0부터 9까지 숫자가 "모두" 등장하는 계단 수가 총 몇 개 있는지
계단수: 인접한 모든 자리의 차이가 1
"""

n = int(input())
MOD = 10**9
BIT = (1<<10)

# dp[i][j][k]: 자리수가 i 일때, 끝나는 수가 j 이고 켜진 비트가 k 일때 가능한 개수
dp = [[[0]*BIT for _ in range(10)] for __ in range(n+1)]
for j in range(1,10):
    dp[1][j][(1<<j)] = 1

for i in range(2,n+1):
    for j in range(10):
        for prev in range(BIT):
            curr = prev | (1<<j)
            if j > 0:
                if dp[i-1][j-1][prev]:
                    dp[i][j][curr] += dp[i-1][j-1][prev]
                    dp[i][j][curr] %= MOD
            if j < 9:
                if dp[i-1][j+1][prev]:
                    dp[i][j][curr] += dp[i-1][j+1][prev]
                    dp[i][j][curr] %= MOD    
# 0~9 로 끝나는 모든 경우 합산
answer = 0
for j in range(10):
    answer += dp[n][j][BIT-1]
    answer %= MOD
print(answer)

# 힌트 확인
# total = 0
# for i in range(1,41):
#     tmp = 0
#     for j in range(10):
#         tmp += dp[i][j][BIT-1]
#         tmp %= MOD
#     total += tmp
# print(total, 5461847755, total == 5461847755)