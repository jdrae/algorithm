tc = int(input())
for _ in range(tc):
    n = int(input())
    arr = list(map(int,input().split()))
    m = int(input())
    dp = [0] * (m+1) # 주어진 동전들로 i 원을 만드는 경우의 수
    dp[0] = 1
    for i in range(n):
        for j in range(arr[i],m+1):
            dp[j] += dp[j-arr[i]]
    print(dp[m])