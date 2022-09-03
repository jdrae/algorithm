"""
mid 는 정답의 예측값. 최솟값을 출력하라 했으므로 lowerbound 를 출력.
각 gem 개수를 mid 로 나눈 것은 해당 gem 를 나눠가진 학생의 수.
이 수를 모두 더하면 예측한 전체 학생 수가 나온다.
만약 예측한 전체 학생 수가 실제 학생 수보다 작거나 같으면
예측 정답(mid)이 크다는 뜻이므로 hi 를 내려준다. (한명이 가져가는 gem의 수를 줄임)
"""

n,m = map(int,input().split())
arr = [int(input()) for _ in range(m)]

lo, hi = 1, 10**9+1
while lo < hi:
    mid = (lo+hi)//2
    pred_n  = 0
    for gem in arr:
        if gem % mid == 0:
            pred_n += gem // mid
        else:
            pred_n += (gem//mid) + 1
    if pred_n <= n:
        hi = mid
    else:
        lo = mid + 1
    
print(lo)