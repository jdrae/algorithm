s1, s2 = input(), input()
l1, l2 = len(s1)+1, len(s2)+1
dp = [[0 for j in range(l2)] for i in range(l1)]

for i in range(1,l1):
    for j in range(1, l2):
        if s1[i-1] == s2[j-1]:
            dp[i][j] = dp[i-1][j-1] + 1
        else:
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])

print(dp[-1][-1])
ans = []
i, j = l1-1, l2-1
while i > 0 and j > 0:
    if dp[i][j] == dp[i-1][j]:
        i -= 1
    elif dp[i][j] == dp[i][j-1]:
        j -= 1
    else:
        ans.append(s1[i-1])
        i -= 1
        j -= 1

for c in ans[::-1]: print(c, end='')
print()