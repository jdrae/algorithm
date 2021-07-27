from collections import deque

def solution(begin, target, words):
    if target not in words:
        return 0
    
    words.append(begin)
    answer = 0
    n = len(words)
    adj = [ [0 for j in range(n)] for i in range(n) ]
    
    wtoi = {k: v for v,k in enumerate(words)}
    
    for i in range(n):
        for j in range(n):
            if len(words[i]) != len(words[j]): continue
            cnt = 0
            for k in range(len(words[i])):
                if words[i][k] == words[j][k]: continue
                cnt += 1
            if cnt == 1:
                adj[wtoi[words[i]]][wtoi[words[j]]] = 1
    
    dq = deque()
    visited = [0 for i in range(n)]
    dq.append(wtoi[begin])
    visited[wtoi[begin]] = 1
    while dq:
        size = len(dq)
        while(size > 0):
            size -= 1
            curr = dq.popleft()
            for nxt,value in enumerate(adj[curr]):
                if not visited[nxt] and value == 1:
                    if words[nxt] == target:
                        return answer + 1
                    visited[nxt] = 1
                    dq.append(nxt)
        answer += 1
    return answer - 1