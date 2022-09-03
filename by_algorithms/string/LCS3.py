s1, s2, s3 = input(),input(),input()
l1, l2, l3 = len(s1)+1, len(s2)+1, len(s3)+1
dp = [[[0 for i in range(l1)] for j in range(l2)] for k in range(l3)]

for k in range(1, l3):
    for j in range(1, l2):
        for i in range(1, l1):
            if s1[i-1] == s2[j-1] == s3[k-1]:
                dp[k][j][i] = dp[k-1][j-1][i-1] + 1
            else:
                dp[k][j][i] = max(dp[k-1][j][i], dp[k][j-1][i], dp[k][j][i-1])
                dp[k][j][i] = max(dp[k][j][i], dp[k-1][j-1][i], dp[k-1][j][i-1], dp[k][j-1][i-1])

print(dp[-1][-1][-1])