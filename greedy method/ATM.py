n = int(input())
p = list(map(int, input().split()))
p.sort()
ans = 0
for i, v in enumerate(p):
    ans += v * (n-i)
print(ans)