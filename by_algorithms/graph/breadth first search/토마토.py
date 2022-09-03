"""
3차원 행렬 처리
"""
from collections import deque

di = [0,0,-1,1,0,0]
dj = [0,0,0,0,-1,1]
dk = [-1,1,0,0,0,0]

m, n, h = map(int, input().split())
arr = []
for k in range(h):
    arr.append([list(map(int,input().split())) for _ in range(n)])

total = 0
pq = deque([])
for k in range(h):
    for i in range(n):
        for j in range(m):
            if arr[k][i][j] == 1:
                pq.append((k,i,j))
            elif arr[k][i][j] == -1:
                total += 1

ans = -1
while pq:
    ans += 1
    qsize = len(pq)
    total += qsize
    for _ in range(qsize):
        k,i,j = pq.popleft()
        for d in range(6):
            nk, ni, nj = k+dk[d], i+di[d], j+dj[d]
            if not (0<=nk<h and 0<=ni<n and 0<=nj<m):
                continue
            if arr[nk][ni][nj] == 0:
                arr[nk][ni][nj] = 1
                pq.append((nk,ni,nj))

if total != n*m*h:
    ans = -1
print(ans)