from typing import List
from collections import defaultdict


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = defaultdict(list)
        for a, b in prerequisites:
            adj[a].append(b)
        visited = [0] * numCourses
        def dfs(curr): # False 가 사이클
            if visited[curr] == -1: return False # 방문 중인 경우
            if visited[curr] == 1: return True # 방문이 끝난 경우
            
            visited[curr] = -1
            for nxt in adj[curr]:
                if not dfs(nxt):
                    return False
            visited[curr] = 1
            return True # 문제 없이 방문이 끝날 경우
        
        for i in range(numCourses):
            if not dfs(i):
                return False
        return True
