from collections import deque 

n, k = map(int, input().split())
arr = list(map(int, input().split()))
N = 2*n

phase = 0
robot = deque([])
visit = [0] * N
start, end = 0, n-1
while True:
    phase += 1
    start = start - 1 if start else N-1
    end = end - 1 if end else N-1

    size = len(robot)
    for _ in range(size):
        pos = robot.popleft()
        visit[pos] = 0
        if pos == end:
            continue
        else:
            newpos = (pos + 1) % N
            if arr[newpos] and visit[newpos] == 0:
                arr[newpos] -= 1
                if newpos == end:
                    continue
                robot.append(newpos)
                visit[newpos] = 1
            else:
                robot.append(pos)
                visit[pos] = 1

    if arr[start] and visit[start] == 0:
        arr[start] -= 1
        robot.append(start)
        visit[start] = 1

    zero = 0
    for a in arr:
        if a == 0:
            zero += 1
    if zero >= k:
        break

print(phase)
