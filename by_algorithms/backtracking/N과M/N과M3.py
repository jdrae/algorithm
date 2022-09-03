# 중복순열
# 뽑힌 숫자 내의 구성에서 같은 숫자가 있을 수 있음.
# (1,1) (1,2) (1,3) (2,1) (2,2) (2,3) (3,1) (3,2) (3,3)

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