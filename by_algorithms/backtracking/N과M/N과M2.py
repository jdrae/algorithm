# 조합
# 뽑힌 숫자의 순서 상관없이 뽑는 경우. 뽑힌 숫자 안의 구성이 같은게 있어서는 안됨.
# (1,2) (1,3) (2,3)

n,m = map(int,input().split())

ans = [0] * m
visited = [False] * (n+1)

def backtrack(cnt):
    if cnt == m:
        print(*ans, sep=" ")
        return

    for i in range(1, n+1):
        if visited[i]: continue
        if cnt != 0 and ans[cnt-1] >= i: continue
        visited[i] = True
        ans[cnt] = i
        backtrack(cnt+1)
        visited[i] = False

backtrack(0)