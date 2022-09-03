"""
n 자리의 비트를 만드는 방법: (1<<n) - 1
배열 행 toggle 하기:  for i in range(n): arr[idx][i] ^= 1
"""

from copy import deepcopy

n = int(input())
arr = [list(map(int,input().split())) for _ in range(n)]
clone = deepcopy(arr)

def toggleY(idx):
    if idx == -1: return
    for i in range(n):
        arr[idx][i] ^= 1

def toggleX(idx):
    if idx == -1: return
    for i in range(n):
        arr[i][idx] ^= 1

def count():
    one = sum(row.count(1) for row in arr)
    zero = sum(row.count(0) for row in arr)
    return min(one, zero)

answer = 10000
BIT = (1<<2*n) - 1
for b in range(BIT):
    cnt = 0
    # 처음 n개 비트는 행 뒤집기
    for i in range(n):
        if b & (1<<i): 
            cnt += 1
            toggleY(i)
    # [n,2*n) 개 비트는 열 뒤집기
    for i in range(n):
        if b & (1<<(i+n)): 
            cnt += 1
            toggleX(i)

    # 돌 1개를 뒤집어야 할 때
    cnt += count()
    answer = min(answer, cnt)
    
    # 원상복구
    arr = deepcopy(clone)
print(answer)