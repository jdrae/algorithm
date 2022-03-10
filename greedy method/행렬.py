# https://www.acmicpc.net/board/view/13509
"""
자리수 분리: list(map(int,input()))
1/0 반전: a = 1 - a
"""

n,m = map(int,input().split())
from_arr = [list(map(int,input())) for _ in range(n)]
to_arr = [list(map(int,input())) for _ in range(n)]

ans = 0
changed = True
for i in range(n):
    for j in range(m):
        if from_arr[i][j] == to_arr[i][j]:
            continue
        if not (i+2 < n and j+2 < m):
            changed = False
            break
        for ii in range(i, i+3):
            for jj in range(j, j+3):
                from_arr[ii][jj] = 1- (from_arr[ii][jj])
        ans += 1
if not changed:
    ans = -1
print(ans)