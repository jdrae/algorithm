from collections import defaultdict, deque


tc = int(input())
while tc:
    tc -= 1

    adj = defaultdict(set)
    team = defaultdict(int)

    v, e = map(int,input().split())
    for _ in range(e):
        u, v = map(int,input().split())
        adj[u].add(v)
        adj[v].add(u)
    
    def bfs(start):
        pq = deque([start])
        if start not in team:
            team[start] = 1

        while pq:
            curr = pq.pop()
            for nxt in adj[curr]:
                opp = 3 - team[curr]
                if nxt not in team:
                    team[nxt] = opp
                    pq.append(nxt)
                else:
                    if team[nxt] != opp:
                        return False
        return True

    can = True
    for k in adj.keys():
        if k not in team:
            can = bfs(k)
            if not can:
                break

    if can:
        print("YES")
    else:
        print("NO")