n, m = map(int, input().split())
arr = list(map(int,input().split()))

lo, hi = 0, 10**12 # 1000000 분에 1개 만드는데 1000000 개 만들어야 할때
while lo < hi:
    mid = (lo+hi)//2
    pred_m = 0
    for a in arr:
        pred_m += (mid//a)
    if m <= pred_m:
        hi = mid
    else:
        lo = mid + 1

print(lo)


"""
1 1000000
1000000
1000000000000

2 1000000
1 1000000
1000000
"""