n = int(input())
arr = [input() for _ in range(n)]

visited = [0]*n
def dfs(curr, cnt):
    visited[curr] = 1
    if cnt == 2: return
    for j in range(n):
        if arr[curr][j] == 'Y':
            dfs(j,cnt+1)

mx = 0
for i in range(n):
    dfs(i,0)
    res = 0
    for j in range(n):
        if visited[j]: res += 1
    mx = max(mx, res-1)
    visited = [0]*n
print(mx)