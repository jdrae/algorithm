# solve again
from queue import PriorityQueue
from collections import defaultdict

def solution(tickets):
    answer = []
    adj = defaultdict(PriorityQueue) # tip: 인접리스트
    for [u, v] in tickets:
        adj[u].put(v)
    
    # dfs
    stack = ["ICN"]
    path = []
    while stack:
        curr = stack[-1]
        if curr not in adj or adj[curr].qsize() == 0:
            path.append(stack.pop())
        else:
            stack.append(adj[curr].get())
    answer = path[::-1]
    return answer


print(solution([["ICN", "JFK"], ["HND", "IAD"], ["JFK", "HND"]]))
print(solution([["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL", "ICN"], ["ATL","SFO"]]))
print(solution([["ICN", "AAA"], ["ICN", "BBB"], ["BBB", "ICN"]]))