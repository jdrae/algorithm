n,m = map(int, input().split())

ans = [0] * m
visited = [False] * (n+1)

def backtrack(pos):
    if pos == m:
        print(*ans, sep=" ")
        return

    for i in range(1, n+1):
        ans[pos] = i
        backtrack(pos+1)

backtrack(0)