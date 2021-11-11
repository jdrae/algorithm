# https://www.acmicpc.net/board/view/50440
import time

n = int(input())
arr = [list(map(int,input().split())) for _ in range(n)]

visited = [False] * n

def backtrack(pos, prev):
    mn = 1000000
    if pos == n//2:
        A, B = [], []
        for i in range(n):
            (A if visited[i] else B).append(i)
        
        a, b = 0, 0
        for i in A:
            for j in A:
                a += arr[i][j]
        for i in B:
            for j in B:
                b += arr[i][j]
        return abs(a-b)

    for i in range(prev, n):
        if visited[i]: continue
        visited[i] = True
        mn = min(mn, backtrack(pos+1, i))
        visited[i] = False

    return mn

# tip: 시간 재기
s = time.time()
mn = backtrack(0, 0)
e = time.time()
print(mn)
print((e-s)*1000,"ms")