from collections import deque
def solution(n, path, order):
    S = 0
    adj = [[] for _ in range(n)]

    for u, v in path:
        adj[u].append(v)
        adj[v].append(u)

    # bfs: 양방향 그래프에서 방향 그래프 만들기
    def bfs():
        dir_graph = [[] for _ in range(n)]
        q = deque([])
        q.append(S)
        chk1 = [0 for _ in range(n)]
        chk1[S] = 1
        while q:
            curr = q.popleft()
            for nxt in adj[curr]:
                if not chk1[nxt]:
                    chk1[nxt] = 1
                    dir_graph[curr].append(nxt)
                    q.append(nxt)
        return dir_graph

    dir_adj = bfs()
    for u, v in order:
        dir_adj[u].append(v)

    # dfs: 사이클 판단
    visited = [0 for _ in range(n)]
    chk2 = [0 for _ in range(n)]

    def dfs(curr):
        visited[curr] = 1
        chk2[curr] = 1
        for nxt in dir_adj[curr]:
            if not chk2[nxt]:
                if dfs(nxt):
                    return True
            if visited[nxt]:
                return True
        visited[curr] = 0
        return False

    is_cycle = dfs(S)
    return False if is_cycle else True

print(solution(9, [[0,1],[0,3],[0,7],[8,1],[3,6],[1,2],[4,7],[7,5]],	[[8,5],[6,7],[4,1]]),True)