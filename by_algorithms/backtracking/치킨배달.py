n, m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]

house, chick = [], []
for i in range(n):
    for j in range(n):
        tmp = arr[i][j]
        if tmp == 1:
            house.append((i,j))
        elif tmp == 2:
            chick.append((i,j))

lh, lc = len(house), len(chick)
adj = [[0]*lh for _ in range(lc)]
for hid in range(lh):
    i, j = house[hid]
    for cid in range(lc):
        p, q = chick[cid]
        tmp = abs(i-p) + abs(j-q)
        adj[cid][hid] = tmp


visited = [False] * lc
ans = n*n * 2*n
def dfs(cid, cnt):
    global ans
    if cnt == m:
        mn = [n*n] * lh
        for c in range(lc):
            if not visited[c]: continue
            for hid in range(lh):
                mn[hid] = min(mn[hid], adj[c][hid])
        ans = min(ans, sum(mn))
    elif cnt >= m: return
    if cid == lc: return
    
    visited[cid] = True
    dfs(cid+1, cnt+1)
    visited[cid] = False
    dfs(cid+1, cnt)
    return

dfs(0,0)
print(ans)