n = int(input())

dp = [0] * (n+1)
for i in range(2,n+1):
    dp[i] = dp[i-1] + 1
    if i % 2 == 0:
        dp[i] = min(dp[i], dp[i//2] + 1)
    if i % 3 == 0:
        dp[i] = min(dp[i], dp[i//3] + 1)
print(dp[n])

i = n
while i > 0:
    print(i, end = " ")
    if i == 1:
        break
    comp = dp[i] - 1
    if comp == dp[i-1]:
        i = i-1
    elif i%2==0 and comp == dp[i//2]:
        i = i//2
    elif i%3 ==0 and comp == dp[i//3]:
        i = i//3
print()