# input
n = int(input())
arr = [0 for _ in range(n)]
for i in range(n):
    arr[i] = list(map(int,input().split()))

# bit masking
bit = (1<<n) - 1
dp = [[0]*(1<<n) for _ in range(n)] # cache[i][j]: 상태 j 로 i 번 정점에 방문했을 때의 비용
INF = 1000000000

# dp
def func(curr, state):
    if state == bit:
        return arr[curr][0] or INF # 현재 노드에서 0 으로 갈 수 있어야
    if dp[curr][state]:
        return dp[curr][state]
    
    mn = INF
    for nxt in range(n):
        if arr[curr][nxt] != 0 and not (state & (1<<nxt)):
            mn = min(mn, func(nxt,(state | (1<<nxt))) + arr[curr][nxt])
    dp[curr][state] = mn
    return mn

print(func(0,1 << 0))