from queue import PriorityQueue

def solution(operations):
    answer = [0,0]
    mnq, mxq = PriorityQueue(),PriorityQueue()
    visited = [0 for _ in range(1000000)]
    for s in operations:
        if s[0] == "I":
            num = int(s[2:])
            mnq.put(num)
            mxq.put(-num)
        elif s[2] == "-":
            while not mnq.empty():
                num = mnq.get()
                if visited[num] == 0:
                    visited[num] = 1
                    break
        else:
            while not mxq.empty():
                num = -mxq.get()
                if visited[num] == 0:
                    visited[num] = 1
                    break
            
    while not mxq.empty():
        num = -mxq.get()
        if visited[num] == 0:
            answer[0] = num
            break
    while not mxq.empty():
        num = mnq.get()
        if visited[num] == 0:
            answer[1] = num
            break
    return answer