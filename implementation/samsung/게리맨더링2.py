n = int(input())
_arr = [list(map(int,input().split())) for _ in range(n)]
arr = [[0]*(n+1) for _ in range(n+1)]
for i in range(1,n+1):
    for j in range(1,n+1):
        arr[i][j] = _arr[i-1][j-1]
MAX = 2000

def func(x,y,d1,d2):
    # x 행 y 열
    # check
    if not ((x<x+d1+d2<=n) and (1<=y-d1<y<y+d2<=n)):
        return MAX

    # allocate
    count = [0] * 5
    visited = [[0]*(n+1) for _ in range(n+1)]
    
    for r in range(1,x+d1):
        for c in range(1,y+1):
            if r >= x and c >= y - (r-x): continue
            count[0] += arr[r][c]
            visited[r][c] = 1

    for r in range(1,x+d2+1):
        for c in range(y+1,n+1):
            if r >= x and c <= y + (r-x): continue
            count[1] += arr[r][c]
            visited[r][c] = 2

    for r in range(x+d1, n+1):
        for c in range(1, y-d1+d2):
            if r <= x+d1+d2 and c >= (y-d1+d2) - (x+d1+d2 - r): continue 
            count[2] += arr[r][c]
            visited[r][c] = 3

    for r in range(x+d2+1, n+1):
        for c in range(y-d1+d2, n+1):
            if r <= x+d1+d2 and c <= (y-d1+d2) + (x+d1+d2 - r): continue
            count[3] += arr[r][c]
            visited[r][c] = 4

    for r in range(1,n+1):
        for c in range(1,n+1):
            if visited[r][c] == 0:
                count[4] += arr[r][c]

    # calculate
    count.sort()
    return count[-1] - count[0]


ans = MAX
for x in range(1,n+1):
    for y in range(1,n+1):
        for d1 in range(1,n):
            for d2 in range(1,n):
                ans = min(ans, func(x,y,d1,d2))

print(ans)