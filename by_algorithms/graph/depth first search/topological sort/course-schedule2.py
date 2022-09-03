from typing import List
from collections import defaultdict


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = defaultdict(list)
        for a, b in prerequisites:
            adj[a].append(b)
        visited = [0] * numCourses
        finished = [0] * numCourses
        def dfs(curr): # True 가 사이클
            if finished[curr]: return False # 방문이 끝난 경우
            if visited[curr]: return True # 방문 중인 경우인데 또 방문한 경우
            
            visited[curr] = 1
            for nxt in adj[curr]:
                if dfs(nxt):
                    return True
            finished[curr] = 1
            return False # 문제 없이 방문이 끝날 경우
        
        for i in range(numCourses):
            if dfs(i):
                return False
        return True

