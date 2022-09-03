# 파이썬 전치: list(zip(*arr)) 또는 list(map(list,zip(*arr))) -> 튜플을 아예 없앨 경우
from collections import Counter

n, m = 3, 3
r,c,k = map(int,input().split())
arr = [list(map(int,input().split())) for _ in range(n)]

def func(arr):
    tmp = []
    mx = 0
    for i in range(len(arr)):
        cnt = [(k,v) for k, v in Counter(arr[i]).items() if k != 0]
        cnt.sort(key=lambda x: (x[1],x[0]))
        lst = []
        for a in cnt:
            lst.extend([*a])
        mx = max(mx, len(lst))
        tmp.append(lst)

    for i in range(len(tmp)):
        lst = tmp[i] + [0]*(mx - len(tmp[i]))
        tmp[i] = lst
    return tmp

def transpose(arr):
    # n,m = len(arr), len(arr[0])
    # return [ [arr[i][j] for i in range(n)] for j in range(m) ]
    return list(zip(*arr))


for time in range(102):
    n, m = len(arr), len(arr[0])
    # check
    if r<=n and c<=m:
        if arr[r-1][c-1] == k:
            break
    # update R
    if n >= m:
        arr = func(arr)
    # update C
    else:
        tmp = func(transpose(arr))
        arr = transpose(tmp)

if time == 101: time = -1
print(time)