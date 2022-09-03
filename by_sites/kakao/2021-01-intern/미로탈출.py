"""
노드가 함정인지 아닌지에 따라 간선이 바뀐다.
만약 함정이라면 활성화됐는지 아닌지에 따르는데,
즉 함정이면서 활성화 되었을 경우와 나머지 경우로 나뉘고 2x2 경우의 수가 생긴다.
해당 경우의 수에서 두 노드 상태가 같을 경우만 순방향 간선을 사용한다.
"""

from collections import defaultdict
import heapq

INF = float('inf')

def toggle(state, idx):
    return state ^ (1 << idx)

def is_active(state, idx):
    return state & (1<<idx) != 0  # 0이면 false 0이 아니면 true

def get_dir(curr, nxt, state, traps_idx):
    is_cur_trap_on, is_nxt_trap_on = False, False
    if curr in traps_idx:
        is_cur_trap_on = is_active(state, traps_idx[curr])
    if nxt in traps_idx:
        is_nxt_trap_on = is_active(state, traps_idx[nxt])
    return is_cur_trap_on != is_nxt_trap_on # true 면 역방향

def solution(n, start, end, roads, traps):
    # setting
    answer = INF
    adj = defaultdict(list)
    for u, v, w in roads:
        adj[u].append((v, w, False))
        adj[v].append((u, w, True))
    BIT = (1 << len(traps))
    traps_idx = {k:v for v,k in enumerate(traps)}

    # dijkstra
    # dist[node][state]: node 를 방문해서 state 상태가 됐을 때 결과
    dist = [[INF]*BIT for _ in range(n+1)]
    pq = []

    state = 0
    dist[start][state] = 0
    heapq.heappush(pq, (dist[start][state], start, state))
    while pq:
        d, curr, state = heapq.heappop(pq)
        if curr == end:
            answer = d
            break
        if dist[curr][state] < d: continue

        for nxt, nd, is_reverse in adj[curr]:
            # 방향 체크
            if is_reverse != get_dir(curr, nxt, state, traps_idx):
                continue
            # 뒤집기
            nxt_state = state
            if nxt in traps_idx:
                nxt_state = toggle(nxt_state, traps_idx[nxt])
            # 큐
            if dist[nxt][nxt_state] > nd+d:
                dist[nxt][nxt_state] = nd+d
                heapq.heappush(pq, (dist[nxt][nxt_state], nxt, nxt_state))

    return answer

print(solution(4,1,4,[[1, 2, 1], [3, 2, 1], [2, 4, 1]],[2,3]),4)