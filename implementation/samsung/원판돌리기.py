"""
deque 의 rotate 를 쓰면 k 칸 회전 구현 가능 (반대방향은 -k 칸으로 구현)
"""

n, m, t = map(int,input().split())
arr = [list(map(int,input().split())) for _ in range(n)]
cmd = [list(map(int,input().split())) for _ in range(t)]

for x, d, k in cmd:
    if d: k = m - k
    rot = [ (i+k)%m for i in range(m)]

    # rotate
    for i in range(n):
        if (i+1) % x: continue
        new_arr = [0] * m
        for j in range(m):
            new_arr[rot[j]] = arr[i][j]
        arr[i] = new_arr[:]

    # delete & count total
    removed = set()
    for i in range(n):
        if arr[i][0] != 0 and arr[i][0] == arr[i][m-1]:
            removed.add((i,0))
            removed.add((i,m-1))
        for j in range(m-1):
            if arr[i][j] == 0: continue
            if arr[i][j] == arr[i][j+1]:
                removed.add((i,j))
                removed.add((i,j+1))

    for j in range(m):
        for i in range(n-1):
            if arr[i][j] == 0: continue
            if arr[i][j] == arr[i+1][j]:
                removed.add((i,j))
                removed.add((i+1,j))

    for i in range(n):
        for j in range(m):
            if (i,j) in removed:
                arr[i][j] = 0
    if removed: continue

    # change & count total
    cnt, avg = 0, 0
    for i in range(n):
        for j in range(m):
            if arr[i][j] == 0: continue
            avg += arr[i][j]
            cnt += 1
    if cnt: avg /= cnt

    if avg == 0: break
    for i in range(n):
        for j in range(m):
            if arr[i][j] == 0: continue
            if arr[i][j] < avg:
                arr[i][j] += 1
            elif arr[i][j] > avg:
                arr[i][j] -= 1
                
# output
total = 0
for i in range(n):
    total += sum(arr[i])
print(total)