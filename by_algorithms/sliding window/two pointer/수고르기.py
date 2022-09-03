n, m = map(int,input().split())
arr = [int(input()) for _ in range(n)]
arr.sort()

s, e = 0,0
mn = -1
while s < n and e < n:
    diff = abs(arr[e]-arr[s])
    if diff >= m:
        if mn == -1: mn = diff
        else: mn = min(mn, diff)
        s += 1
    else:
        e += 1
print(mn)