n = 9
arr = [list(map(int,input().split())) for _ in range(n)]

pairs = []
for i in range(n):
    for j in range(n):
        if not arr[i][j]:
            pairs.append((i,j))
m = len(pairs)

def backtrack(pos):
    if pos == m:
        return True
    y, x = pairs[pos][0], pairs[pos][1]
    chk = set([1,2,3,4,5,6,7,8,9])
    cand = set([1,2,3,4,5,6,7,8,9])
    # 행
    tmp = set([])
    for j in range(n):
        tmp.add(arr[y][j])
    cand &= (chk - tmp)
    # 열
    tmp = set([])
    for i in range(n):
        tmp.add(arr[i][x])
    cand &= (chk - tmp)
    # 칸
    tmp = set([])
    r, c = (y//3)*3, (x//3)*3
    for i in range(r,r+3):
        for j in range(c, c+3):
            tmp.add(arr[i][j])
    cand &= (chk - tmp)
    
    for c in cand:
        arr[y][x] = c
        if backtrack(pos+1):
           return True
        arr[y][x] = 0 
    return False

backtrack(0)

for ar in arr:
    print(*ar, sep=" ")