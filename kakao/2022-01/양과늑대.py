"""
1. dfs 로 경로를 따라갔다가 다시 돌아오는 것은 구현할 필요가 없음.
dfs 자체가 막히면 원 경로로 돌아오는 것이기 때문
print(curr)
for nxt in adj[curr]:
    dfs(nxt)
    print(curr)
2. 따라서 정확한 경로의 노드를 하나하나 따라간다기 보다,
현재 노드에서 갈 수 있는 다음 노드를 선택하면, 왔던 경로를 따라 가게 된다고 생각할 수 있음.
0 -> 1 을 진행했을 때 1 의 다음 노드인 2 를 선택하면 0 -> 1 -> 2 의 경로가 되고
0 의 다음 노드인 3 을 선택하면 0 -> 1 -> (0) -> 2 가 된다
3. 다음노드를 방문할 때마다 노드의 상태값을 업데이트해서 파라미터로 전달한다.
현재노드는 다음노드 방문 전, 즉 업데이트 이전 값으로 다음 노드를 방문할 수 있다.
"""

from collections import defaultdict


def solution(info, edges):
    answer = 0
    adj = defaultdict(list)
    for u, v in edges:
        adj[u].append(v)

    def get_next_nodes(curr, prev_nodes):
        next_nodes = set(prev_nodes)
        next_nodes.discard(curr)
        for nxt in adj[curr]:
            next_nodes.add(nxt)
        return next_nodes

    def dfs(curr, lamb, wolf, prev_nodes):
        # prev_nodes 를 사용해서 curr 까지 왔을 때 lamb 와 wolf 의 상태 확인
        nonlocal answer
        answer = max(answer, lamb)
        if lamb <= wolf:
            return
        next_nodes = get_next_nodes(curr, prev_nodes)
        for node in next_nodes:
            if info[node] == 0:
                dfs(node, lamb+1, wolf, next_nodes)
            else:
                dfs(node, lamb, wolf+1, next_nodes)

    dfs(0,1,0,{0})
    return answer

print(solution([0,0,1,1,1,0,1,0,1,0,1,1], 	[[0,1],[1,2],[1,4],[0,8],[8,7],[9,10],[9,11],[4,3],[6,5],[4,6],[8,9]]))