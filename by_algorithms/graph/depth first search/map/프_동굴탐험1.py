def solution(n, path, order):
    # prep
    S = 0
    adj = [[] for _ in range(n)]
    prv_visit = [0 for _ in range(n)]
    nxt_visit = [0 for _ in range(n)]
    visited = [0 for _ in range(n)]

    for u, v in path:
        adj[u].append(v)
        adj[v].append(u)

    for u, v in order:
        prv_visit[v] = u
    if prv_visit[S]: return False

    # dfs
    def dfs(curr):
        if visited[curr]: return
        # 이전노드 방문하지 않았다면 이전노드의 다음노드가 현재노드
        if not visited[prv_visit[curr]]:
            # 이전노드를 방문하고 현재노드를 방문하게 됨
            nxt_visit[prv_visit[curr]] = curr
            return
        # 현재노드 방문처리 후 다음 방문해야하는 노드 방문
        visited[curr] = 1
        if nxt_visit[curr]:
            dfs(nxt_visit[curr])

        for nxt in adj[curr]:
            dfs(nxt)
        return

    # result
    visited[S] = 1
    for nxt in adj[S]:
        dfs(nxt)
    res = 0
    for v in visited:
        if v: res += 1
    return True if res == n else False

print(solution(9, [[0,1],[0,3],[0,7],[8,1],[3,6],[1,2],[4,7],[7,5]],	[[8,5],[6,7],[4,1]]),True)