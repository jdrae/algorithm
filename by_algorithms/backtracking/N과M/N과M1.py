# 순열
# 중복이 없이 n 개 중 m 개 선택. 순서 상관 있음
# (1,2) (1,3) (2,1) (2,3) (3,1) (3,2)

n,m = map(int,input().split())

ans = [0] * (m)
visited = [False] * (n+1)
def backtrack(cnt):
    if cnt == m:
        # tip: join 대신 배열 값 출력
        print(*ans, sep=" ")
        return

    for i in range(1,n+1):
        if visited[i]: continue
        visited[i] = True
        ans[cnt] = i
        backtrack(cnt+1)
        visited[i] = False

backtrack(0)