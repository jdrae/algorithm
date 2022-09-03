"""
lower_bound, upper_bound 내장함수 사용하기
속도는 비슷하지만 구현이 빠름
https://jackpot53.tistory.com/33
"""
from bisect import bisect_left, bisect_right

n = int(input())
arr = sorted((map(int,input().split())))
m = int(input())
cmd = list(map(int,input().split()))


for num in cmd:
    # ub = upper_bound(num)
    # lb = lower_bound(num)
    ub = bisect_right(arr, num)
    lb = bisect_left(arr,num)
    print(ub - lb, end = " ")
print()

def lower_bound(num):
    lo, hi = 0, n
    while lo < hi:
        mid = (lo+hi)//2
        if num <= arr[mid]:
            hi = mid
        else:
            lo = mid + 1
    return lo

def upper_bound(num):
    lo, hi = 0, n
    while lo < hi:
        mid = (lo+hi)//2
        if num >= arr[mid]:
            lo = mid + 1
        else:
            hi = mid
    return lo