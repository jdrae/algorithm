from collections import defaultdict, deque

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = defaultdict(list)
        indegree = [0] * (numCourses)
        for a, b in prerequisites:
            adj[a].append(b) # a -> b: a 를 듣고 b 를 들어야
            indegree[b] += 1
        
        q = deque([])
        for i in range(numCourses):
            if indegree[i] == 0: q.append(i)
        for i in range(numCourses):
            if not q:
                return False
            curr = q.popleft()
            for nxt in adj[curr]:
                indegree[nxt] -= 1
                if indegree[nxt] == 0: q.append(nxt)
        return True
            